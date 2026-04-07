#include "PinConfig.h"
#include "hardware/PumpController.h"
#include "hardware/FlowMeter.h"
#include "hardware/GestureSensor.h"

#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <iomanip>
#include <thread>

// ─── Graceful shutdown on Ctrl+C ─────────────────────────────────────────────
static std::atomic<bool> keepRunning(true);

void signalHandler(int signum) {
    std::cout << "\n[Signal " << signum << "] Stopping...\n";
    keepRunning = false;
}

int main() {
    std::signal(SIGINT, signalHandler);

    std::cout << "=== Touchless Dispenser Terminal Test ===\n";
    std::cout << "Target volume : " << TARGET_VOLUME_ML << " ml\n";
    std::cout << "ML per pulse  : " << ML_PER_PULSE << "\n\n";

    // ── Construct ─────────────────────────────────────────────────────────────
    PumpController pump(GPIO_CHIP_NO, PUMP_PIN);
    FlowMeter      flow(GPIO_CHIP_NO, FLOW_PIN, static_cast<float>(ML_PER_PULSE));
    GestureSensor  gesture; // defaults to bus 1, addr 0x39, thresh 100

    // ── Initialise ────────────────────────────────────────────────────────────
    if (!pump.init()) {
        std::cerr << "ERROR: PumpController failed to init\n"; return 1;
    }
    if (!flow.init()) {
        std::cerr << "ERROR: FlowMeter failed to init\n";
        pump.shutdown(); return 1;
    }
    if (!gesture.init()) {
        std::cerr << "ERROR: GestureSensor failed to init\n";
        pump.shutdown(); flow.shutdown(); return 1;
    }

    std::atomic<bool> isDispensing(false);
    std::atomic<bool> targetReached(false);
    bool waitingMessagePrinted = false;

    gesture.registerEventCallback([&](const GestureEvent& ev) {
        if (ev.state == ProximityState::PROXIMITY_TRIGGERED) {
            std::cout << "\n>>> CUP DETECTED! Ready to dispense.\n";
            // Start pour only if we aren't already dispensing or haven't hit target yet
            if (!isDispensing && !targetReached) {
                flow.resetCount();
                isDispensing = true;
                waitingMessagePrinted = false;
                pump.turnOn();
            }
        } else if (ev.state == ProximityState::PROXIMITY_CLEARED) {
            std::cout << "\n>>> CUP REMOVED! Dispensing stopped.\n";
            isDispensing = false;
            targetReached = false; // reset for next cup
            waitingMessagePrinted = false;
            pump.turnOff();
        }
    });

    std::cout << "\n[-] System idle. Place a cup in front of sensor to begin...\n";

    // ── Live volume loop ──────────────────────────────────────────────────────
    while (keepRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        if (isDispensing) {
            double vol = flow.getVolumeML();
            int pulses = flow.getPulseCount();

            std::cout << "\r  [Pump RUNNING] Pulses: " << std::setw(5) << pulses
                      << "   Vol: " << std::fixed << std::setprecision(1)
                      << std::setw(7) << vol << " ml"
                      << std::flush;

            // Stop when target reached
            if (flow.hasReachedTarget(TARGET_VOLUME_ML)) {
                std::cout << "\n\n*** TARGET REACHED! ***\n";
                pump.turnOff();
                isDispensing = false;
                targetReached = true;
                waitingMessagePrinted = false;
            }
        } else if (targetReached) {
            if (!waitingMessagePrinted) {
                std::cout << "\n[-] Please remove your full cup.\n";
                waitingMessagePrinted = true;
            }
        } else {
            // Idle but no target reached and not dispensing
            if (!waitingMessagePrinted) {
                std::cout << "\n[-] System idle. Place a cup in front of sensor to begin...\n";
                waitingMessagePrinted = true;
            }
        }
    }

cleanup:
    pump.turnOff();
    pump.shutdown();
    flow.shutdown();
    gesture.shutdown();

    std::cout << "\nTest complete.\n";
    return 0;
}
