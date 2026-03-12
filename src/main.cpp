#include "PinConfig.h"
#include "hardware/UltrasonicSensor.h"
#include "hardware/PumpController.h"
#include "state/FillingController.h"

#include <lgpio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <atomic>

// ─── Graceful shutdown on Ctrl+C (matches Python: except KeyboardInterrupt) ──
static std::atomic<bool> running(true);

void signalHandler(int signum) {
    std::cout << "\nMeasurement stopped by User\n";
    running = false;
}

// ─────────────────────────────────────────────────────────────────────────────

int main() {
    // Register Ctrl+C handler
    std::signal(SIGINT, signalHandler);

    // --- Open GPIO chip (matches Python: h = GPIO.gpiochip_open(0)) ---
    int handle = lgGpiochipOpen(GPIO_CHIP);
    if (handle < 0) {
        std::cerr << "ERROR: Failed to open GPIO chip " << GPIO_CHIP << "\n";
        return 1;
    }
    std::cout << "GPIO chip opened (handle=" << handle << ")\n";

    // --- Create hardware objects ---
    UltrasonicSensor sensor(handle, TRIG_PIN, ECHO_PIN);
    PumpController pump(handle, PUMP_PIN);

    // --- Initialise hardware ---
    if (!sensor.init()) {
        lgGpiochipClose(handle);
        return 1;
    }
    if (!pump.init()) {
        sensor.shutdown();
        lgGpiochipClose(handle);
        return 1;
    }

    // --- Create the state machine ---
    FillingController controller(sensor, pump,
                                  TARGET_DISTANCE_CM,
                                  DISTANCE_TOLERANCE_CM,
                                  HOLD_TIME_SECONDS);

    std::cout << "\n=== SmartFlowX Filling Machine Started ===\n\n";

    // --- Main loop (matches Python: while True, with 1 second sleep) ---
    while (running) {
        controller.tick();
        std::cout << "[State: " << controller.getStateName() << "]\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(LOOP_INTERVAL_MS));
    }

    // --- Cleanup (matches Python: finally block) ---
    std::cout << "\nShutting down...\n";
    pump.shutdown();
    sensor.shutdown();
    lgGpiochipClose(handle);
    std::cout << "GPIO chip closed. Goodbye.\n";

    return 0;
}
