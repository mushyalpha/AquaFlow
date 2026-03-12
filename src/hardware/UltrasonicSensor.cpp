#include "hardware/UltrasonicSensor.h"

#include <lgpio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include <iostream>

using Clock = std::chrono::steady_clock;
using Microseconds = std::chrono::microseconds;
using Milliseconds = std::chrono::milliseconds;

// Timeout for echo response (30 ms, matches Python prototype)
static constexpr double ECHO_TIMEOUT_SEC = 0.03;

// Speed of sound: distance = time * 17150 (same formula as Python code)
static constexpr double SPEED_FACTOR = 17150.0;

// ─────────────────────────────────────────────────────────────────────────────

UltrasonicSensor::UltrasonicSensor(int gpioHandle, int trigPin, int echoPin)
    : handle_(gpioHandle),
      trigPin_(trigPin),
      echoPin_(echoPin),
      initialised_(false)
{
}

UltrasonicSensor::~UltrasonicSensor() {
    shutdown();
}

bool UltrasonicSensor::init() {
    // Claim trigger as output, echo as input
    if (lgGpioClaimOutput(handle_, 0, trigPin_, 0) != 0) {
        std::cerr << "ERROR: Failed to claim TRIG pin " << trigPin_ << "\n";
        return false;
    }
    if (lgGpioClaimInput(handle_, 0, echoPin_) != 0) {
        std::cerr << "ERROR: Failed to claim ECHO pin " << echoPin_ << "\n";
        return false;
    }

    initialised_ = true;
    std::cout << "UltrasonicSensor initialised (TRIG=" << trigPin_
              << ", ECHO=" << echoPin_ << ")\n";
    return true;
}

void UltrasonicSensor::shutdown() {
    if (initialised_) {
        lgGpioWrite(handle_, trigPin_, 0);
        lgGpioFree(handle_, trigPin_);
        lgGpioFree(handle_, echoPin_);
        initialised_ = false;
        std::cout << "UltrasonicSensor shut down.\n";
    }
}

double UltrasonicSensor::getDistanceCM() {
    if (!initialised_) return -1.0;

    // --- Ensure trigger is LOW ---
    lgGpioWrite(handle_, trigPin_, 0);
    std::this_thread::sleep_for(Microseconds(50000));  // 50 ms settle

    // --- Send 10 µs trigger pulse ---
    lgGpioWrite(handle_, trigPin_, 1);
    std::this_thread::sleep_for(Microseconds(10));     // 10 µs
    lgGpioWrite(handle_, trigPin_, 0);

    // --- Wait for echo to go HIGH (with timeout) ---
    auto timeoutStart = Clock::now();
    while (lgGpioRead(handle_, echoPin_) == 0) {
        auto now = Clock::now();
        double elapsed = std::chrono::duration<double>(now - timeoutStart).count();
        if (elapsed > ECHO_TIMEOUT_SEC) {
            return -1.0;  // timeout — no echo received
        }
    }
    auto pulseStart = Clock::now();

    // --- Wait for echo to go LOW (with timeout) ---
    while (lgGpioRead(handle_, echoPin_) == 1) {
        auto now = Clock::now();
        double elapsed = std::chrono::duration<double>(now - pulseStart).count();
        if (elapsed > ECHO_TIMEOUT_SEC) {
            return -1.0;  // timeout — echo stuck HIGH
        }
    }
    auto pulseEnd = Clock::now();

    // --- Calculate distance ---
    double pulseDuration = std::chrono::duration<double>(pulseEnd - pulseStart).count();
    double distance = pulseDuration * SPEED_FACTOR;

    // Round to 2 decimal places (matches Python: round(distance, 2))
    return std::round(distance * 100.0) / 100.0;
}

bool UltrasonicSensor::isBottlePresent(double targetCM, double toleranceCM) {
    double distance = getDistanceCM();
    if (distance < 0) return false;  // timeout
    return (distance >= targetCM - toleranceCM) &&
           (distance <= targetCM + toleranceCM);
}
