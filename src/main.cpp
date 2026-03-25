#include "PinConfig.h"
#include "hardware/UltrasonicSensor.h"
#include "hardware/PumpController.h"
#include "hardware/FlowMeter.h"
#include "state/FillingController.h"
#include "monitor/Monitor.h"
#include "utils/Timer.h"
#include "utils/Logger.h"

#include <lgpio.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <atomic>

// ─── Graceful shutdown on Ctrl+C ─────────────────────────────────────────────
static std::atomic<bool> running(true);

void signalHandler(int /*signum*/) {
    std::cout << "\nShutdown requested — stopping...\n";
    running = false;
}

// ─────────────────────────────────────────────────────────────────────────────

int main() {
    std::signal(SIGINT, signalHandler);

    // ── Open lgpio chip for PumpController (uses lgpio directly) ─────────────
    int lgHandle = lgGpiochipOpen(GPIO_CHIP);
    if (lgHandle < 0) {
        Logger::error("Failed to open GPIO chip " + std::to_string(GPIO_CHIP) +
                      " via lgpio");
        return 1;
    }

    // ── Construct hardware drivers ────────────────────────────────────────────
    // UltrasonicSensor and FlowMeter use libgpiod (chip number as first arg)
    UltrasonicSensor sensor(GPIO_CHIP_NO, TRIG_PIN, ECHO_PIN, SENSOR_PERIOD_MS);
    FlowMeter        flowMeter(GPIO_CHIP_NO, FLOW_PIN, static_cast<float>(ML_PER_PULSE));

    // PumpController uses lgpio (relay/transistor control via handle)
    PumpController pump(lgHandle, PUMP_PIN);

    // ── Initialise hardware ───────────────────────────────────────────────────
    if (!sensor.init()) {
        Logger::error("Failed to initialise UltrasonicSensor");
        lgGpiochipClose(lgHandle);
        return 1;
    }
    if (!pump.init()) {
        Logger::error("Failed to initialise PumpController");
        sensor.shutdown();
        lgGpiochipClose(lgHandle);
        return 1;
    }
    if (!flowMeter.init()) {
        Logger::error("Failed to initialise FlowMeter");
        pump.shutdown();
        sensor.shutdown();
        lgGpiochipClose(lgHandle);
        return 1;
    }

    // ── State machine + monitor ───────────────────────────────────────────────
    FillingController controller(sensor, pump, flowMeter,
                                 TARGET_DISTANCE_CM,
                                 DISTANCE_TOLERANCE_CM,
                                 HOLD_TIME_SECONDS,
                                 TARGET_VOLUME_ML);

    Monitor monitor;
    controller.registerMonitor([&](const std::string& state, double vol, int bottles) {
        monitor.onStateChange(state, vol, bottles);
    });

    Logger::info("=== AquaFlow Filling Machine Started ===");
    Logger::info("Target distance : " + std::to_string(TARGET_DISTANCE_CM) + " cm");
    Logger::info("Tolerance       : +-" + std::to_string(DISTANCE_TOLERANCE_CM) + " cm");
    Logger::info("Hold time       : " + std::to_string(HOLD_TIME_SECONDS) + " s");
    Logger::info("Target volume   : " + std::to_string(TARGET_VOLUME_ML) + " ml");
    Logger::info("Flow calibration: " + std::to_string(ML_PER_PULSE) + " ml/pulse");

    // ── RTES-compliant main loop: timerfd callback instead of sleep_for ───────
    Timer loopTimer(LOOP_INTERVAL_MS);
    loopTimer.registerCallback([&]() {
        if (!running) return;
        controller.tick();
    });
    loopTimer.start();

    // Block main thread with minimal CPU usage until Ctrl+C
    while (running) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // ── Shutdown (order: timer → flow → pump → sensor → gpio) ────────────────
    loopTimer.stop();
    flowMeter.shutdown();
    pump.shutdown();
    sensor.shutdown();
    lgGpiochipClose(lgHandle);

    Logger::info("AquaFlow stopped. Goodbye.");
    return 0;
}
