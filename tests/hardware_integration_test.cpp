#include <iostream>
#include <lgpio.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <csignal>

// --- Configuration (Matches your wiring) ---
const int GPIO_CHIP = 4;    // Pi 5 Header
const int RELAY_PIN = 17;   // Solenoid (Physical Pin 11)
const int FLOW_PIN  = 27;   // Sensor Signal (Physical Pin 13)

std::atomic<int> pulseCount(0);
std::atomic<bool> running(true);

// Callback function: Increments on each rising edge (one pulse per spin)
void flowCallback(int count, lgGpioAlert_p events, void *userdata) {
    for (int i = 0; i < count; i++) {
        if (events[i].report.level == 1) { // Rising edge = one pulse
            pulseCount++;
        }
    }
}

void signalHandler(int signum) {
    running = false;
}

int main() {
    std::signal(SIGINT, signalHandler);

    // 1. Open GPIO Chip
    int handle = lgGpiochipOpen(GPIO_CHIP);
    if (handle < 0) {
        std::cerr << "Failed to open GPIO chip\n";
        return 1;
    }

    // 2. Setup Relay (Output)
    lgGpioClaimOutput(handle, 0, RELAY_PIN, 0); // Start with valve CLOSED (0)

    // 3. Setup Flow Sensor (Input with Pull-up and Callback)
    lgGpioClaimInput(handle, LG_SET_PULL_UP, FLOW_PIN);
    lgGpioSetAlertsFunc(handle, FLOW_PIN, flowCallback, nullptr);

    std::cout << "--- Hardware Test Starting ---\n";
    std::cout << "1. Opening Solenoid Valve...\n";
    lgGpioWrite(handle, RELAY_PIN, 1); // Open valve

    std::cout << "2. Valve is OPEN. Spin the flow meter now!\n";
    std::cout << "Press Ctrl+C to stop the test.\n\n";

    while (running) {
        std::cout << "\rPulses Detected: " << pulseCount.load() << "   " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // 4. Cleanup
    std::cout << "\n\nClosing valve and cleaning up...\n";
    lgGpioWrite(handle, RELAY_PIN, 0); // Close valve
    lgGpiochipClose(handle);
    
    return 0;
}
