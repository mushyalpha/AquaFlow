#include "hardware/PumpController.h"

#include <lgpio.h>
#include <iostream>

// ─────────────────────────────────────────────────────────────────────────────

PumpController::PumpController(int gpioHandle, int pumpPin)
    : handle_(gpioHandle),
      pumpPin_(pumpPin),
      running_(false),
      initialised_(false)
{
}

PumpController::~PumpController() {
    shutdown();
}

bool PumpController::init() {
    // Claim pump pin as output, start LOW (pump OFF)
    if (lgGpioClaimOutput(handle_, 0, pumpPin_, 0) != 0) {
        std::cerr << "ERROR: Failed to claim PUMP pin " << pumpPin_ << "\n";
        return false;
    }

    // Make sure pump is OFF at start (matches Python: GPIO.gpio_write(h, PUMP, 0))
    lgGpioWrite(handle_, pumpPin_, 0);
    running_ = false;
    initialised_ = true;

    std::cout << "PumpController initialised (PIN=" << pumpPin_ << ")\n";
    return true;
}

void PumpController::shutdown() {
    if (initialised_) {
        // Always turn pump OFF on shutdown (matches Python finally block)
        lgGpioWrite(handle_, pumpPin_, 0);
        lgGpioFree(handle_, pumpPin_);
        running_ = false;
        initialised_ = false;
        std::cout << "PumpController shut down (pump OFF).\n";
    }
}

void PumpController::turnOn() {
    if (initialised_ && !running_) {
        lgGpioWrite(handle_, pumpPin_, 1);
        running_ = true;
        std::cout << "Pump started!\n";
    }
}

void PumpController::turnOff() {
    if (initialised_ && running_) {
        lgGpioWrite(handle_, pumpPin_, 0);
        running_ = false;
        std::cout << "Pump stopped.\n";
    }
}

bool PumpController::isRunning() const {
    return running_;
}
