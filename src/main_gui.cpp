#include "PinConfig.h"
#include "gui/AquaFlowWindow.h"
#include "hardware/GestureSensor.h"
#include "hardware/PumpController.h"
#include "hardware/FlowMeter.h"
#include "hardware/LcdDisplay.h"
#include "state/FillingController.h"
#include "monitor/Monitor.h"
#include "utils/Timer.h"
#include "utils/Logger.h"

#include <QApplication>

#include <csignal>
#include <thread>
#include <atomic>

// POSIX terminal / read
#include <unistd.h>
#include <termios.h>

// This is the Qt GUI entry point for AquaFlow.
// It combines the existing headless real-time architecture (timerfd-driven
// state machine, GPIO interrupts, I2C sensors) with a Qt6 graphical front-end
// with:
// 1. Plotting values on screen (QCustomPlot real-time volume graph)
// 2. Mouse interaction (QPushButtons for size selection / reset)
// The Qt event loop (app.exec()) replaces the sigwait() block in the headless
// main.cpp. All real-time threads continue to run in the background.
 
int main(int argc, char* argv[]) {

    // Qt application must be created first  
    QApplication app(argc, argv);

    // Construct hardware drivers
    GestureSensor    gestureSensor(GESTURE_I2C_BUS, GESTURE_I2C_ADDR, GESTURE_THRESHOLD);
    PumpController   pump(GPIO_CHIP_NO, PUMP_PIN);
    FlowMeter        flowMeter(GPIO_CHIP_NO, FLOW_PIN, static_cast<float>(ML_PER_PULSE));
    LcdDisplay       lcd(LCD_I2C_BUS, LCD_I2C_ADDRESS);

    // Initialise hardware
    if (!gestureSensor.init()) {
        Logger::error("Failed to initialise GestureSensor");
        return 1;
    }
    if (!pump.init()) {
        Logger::error("Failed to initialise PumpController");
        gestureSensor.shutdown();
        return 1;
    }
    if (!flowMeter.init()) {
        Logger::error("Failed to initialise FlowMeter");
        pump.shutdown();
        gestureSensor.shutdown();
        return 1;
    }
    if (!lcd.init()) {
        Logger::error("Failed to initialise LcdDisplay — continuing without display");
    }

    Logger::info("=== AquaFlow Filling Machine (GUI Mode) ===");

    // State machine + monitor
    FillingController controller(gestureSensor, pump, flowMeter);
    Monitor           monitor;

    controller.registerMonitor([&monitor, &lcd, &controller, &flowMeter]
                               (const std::string& state, double vol, int cups)
    {
        monitor.onStateChange(state, vol, cups);

        // LCD updates (same logic as headless AquaFlowApp)
        static std::string lastLcdState;
        if (state == lastLcdState) return;
        lastLcdState = state;

        if (state.rfind("SELECT:", 0) == 0) {
            std::string sizeName = state.substr(7);
            int ml = 250;
            if (sizeName == "MEDIUM") ml = 400;
            else if (sizeName == "LARGE") ml = 500;
            lcd.print(0, sizeName + " (" + std::to_string(ml) + "ml)");
            lcd.print(1, "b=cycle  s=select");
        } else if (state == "PLACE CUP") {
            lcd.print(0, "Place cup...");
            std::ostringstream r1;
            r1 << "Target: " << static_cast<int>(controller.getTargetVolumeML()) << " ml";
            lcd.print(1, r1.str());
        } else if (state == "CONFIRMING") {
            lcd.print(0, "Cup detected!");
            lcd.print(1, "Hold steady...");
        } else if (state == "FILLING") {
            lcd.print(0, "Filling...");
        } else if (state == "COMPLETE") {
            lcd.print(0, "Done! Remove cup");
            std::ostringstream r1;
            r1 << std::fixed << std::setprecision(0)
               << vol << " ml  (cup " << cups << ")";
            lcd.print(1, r1.str());
        }
    });

    // Timer: drives state-machine ticks + LCD live volume
    Timer loopTimer(LOOP_INTERVAL_MS);
    loopTimer.registerCallback([&controller, &lcd, &flowMeter]() {
        controller.tick();

        // Live volume on LCD during filling
        if (controller.getState() == SystemState::FILLING) {
            std::ostringstream row;
            row << std::fixed << std::setprecision(0)
                << flowMeter.getVolumeML() << " / "
                << static_cast<int>(controller.getTargetVolumeML()) << " ml";
            lcd.print(1, row.str());
        }
    });
    loopTimer.start();

    // Keyboard thread
    std::atomic<bool> kbRunning{true};
    std::thread keyboardThread;

    if (isatty(STDIN_FILENO)) {
        keyboardThread = std::thread([&controller, &kbRunning]() {
            struct termios oldt{}, newt{};
            tcgetattr(STDIN_FILENO, &oldt);
            newt          = oldt;
            newt.c_lflag &= ~static_cast<tcflag_t>(ICANON | ECHO);
            newt.c_cc[VMIN]  = 0;
            newt.c_cc[VTIME] = 1;
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            while (kbRunning.load(std::memory_order_relaxed)) {
                char c = 0;
                if (::read(STDIN_FILENO, &c, 1) != 1) continue;
                switch (c) {
                    case 'b': case 'B': controller.onShortPress(); break;
                    case 's': case 'S': case '\r': case '\n': controller.onLongPress(); break;
                    default: break;
                }
            }
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        });
    }

    // Create and show the Qt GUI window
    AquaFlowWindow window(controller, flowMeter);
    window.show();
    window.startDAQ();

    Logger::info("GUI window opened — use the on-screen buttons or keyboard controls.");

    // Qt event loop (replaces sigwait in headless mode)
    int result = app.exec();

    // Shutdown
    Logger::info("GUI closed — shutting down.");

    loopTimer.stop();

    kbRunning.store(false, std::memory_order_relaxed);
    if (keyboardThread.joinable()) keyboardThread.join();

    lcd.clear();
    lcd.print(0, "AquaFlow");
    lcd.print(1, "Shutting down...");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    lcd.shutdown();
    flowMeter.shutdown();
    pump.shutdown();
    gestureSensor.shutdown();

    Logger::info("AquaFlow stopped. Goodbye.");
    return result;
}
