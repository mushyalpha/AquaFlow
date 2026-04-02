#include <atomic>
#include <chrono>
#include <csignal>
#include <iostream>
#include <lgpio.h>
#include <thread>

const int GPIO_CHIP = 4;     // usually 4 on Pi 5
const int PUMP_PIN = 18;     // GPIO18 (BCM)

std::atomic<bool> keepRunning(true);

void signalHandler(int signum) {
    std::cout << "\n[Signal " << signum << "] Stopping...\n";
    keepRunning = false;
}

int main() {
    std::signal(SIGINT, signalHandler);

    int handle = lgGpiochipOpen(GPIO_CHIP);
    if (handle < 0) {
        std::cerr << "Failed to open GPIO chip\n";
        return 1;
    }

    // Set pin as output and start LOW (pump OFF)
    if (lgGpioClaimOutput(handle, 0, PUMP_PIN, 0) < 0) {
        std::cerr << "Failed to claim GPIO pin\n";
        lgGpiochipClose(handle);
        return 1;
    }

    std::cout << "Starting pump test...\n";

    for (int i = 0; i < 3 && keepRunning; ++i) {
        std::cout << "Cycle " << i + 1 << ": PUMP ON\n";
        lgGpioWrite(handle, PUMP_PIN, 1);
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::cout << "Cycle " << i + 1 << ": PUMP OFF\n";
        lgGpioWrite(handle, PUMP_PIN, 0);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // Ensure OFF before exit
    lgGpioWrite(handle, PUMP_PIN, 0);

    lgGpiochipClose(handle);
    std::cout << "Test complete. Pump OFF.\n";

    return 0;
}
