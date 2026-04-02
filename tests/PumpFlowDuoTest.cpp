#include "PinConfig.h"
#include "hardware/PumpController.h"
#include "hardware/FlowMeter.h"

#include <atomic>
#include <chrono>
#include <csignal>
#include <iomanip>
#include <iostream>
#include <thread>

// ─── Graceful shutdown on Ctrl+C ─────────────────────────────────────────────
static std::atomic<bool> keepRunning(true);

void signalHandler(int signum) {
    std::cout << "\n[Signal " << signum << "] Stopping...\n";
    keepRunning = false;
}

int main() {
    std::signal(SIGINT, signalHandler);

    std::cout << "=== Pump + Flow Meter Duo Test ===\n";
    std::cout << "Target : " << TARGET_VOLUME_ML << " ml\n";
    std::cout << "ml/pulse: " << ML_PER_PULSE << "\n\n";

    PumpController pump(GPIO_CHIP_NO, PUMP_PIN);
    FlowMeter      flow(GPIO_CHIP_NO, FLOW_PIN, static_cast<float>(ML_PER_PULSE));

    if (!pump.init()) { std::cerr << "ERROR: Pump init failed\n"; return 1; }
    if (!flow.init()) { std::cerr << "ERROR: FlowMeter init failed\n"; pump.shutdown(); return 1; }

    flow.resetCount();
    pump.turnOn();
    std::cout << "Pump ON — watching for flow...\n\n";

    while (keepRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        int    pulses = flow.getPulseCount();
        double vol    = flow.getVolumeML();

        std::cout << "\r  Pulses: " << std::setw(6) << pulses
                  << "   Vol: " << std::fixed << std::setprecision(1)
                  << std::setw(7) << vol << " ml"
                  << std::flush;

        if (flow.hasReachedTarget(TARGET_VOLUME_ML)) {
            std::cout << "\n\nTarget reached!\n";
            break;
        }
    }

    pump.turnOff();

    double finalVol = flow.getVolumeML();
    std::cout << "\nFinal : " << std::fixed << std::setprecision(2)
              << finalVol << " ml (" << flow.getPulseCount() << " pulses)\n";

    flow.shutdown();
    pump.shutdown();
    std::cout << "Test complete.\n";
    return 0;
}
