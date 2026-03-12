#include "state/FillingController.h"

#include <iostream>
#include <iomanip>

using Clock = std::chrono::steady_clock;

// ─────────────────────────────────────────────────────────────────────────────

FillingController::FillingController(UltrasonicSensor& sensor,
                                     PumpController& pump,
                                     double targetDistanceCM,
                                     double toleranceCM,
                                     int holdTimeSeconds)
    : sensor_(sensor),
      pump_(pump),
      targetDistanceCM_(targetDistanceCM),
      toleranceCM_(toleranceCM),
      holdTimeSeconds_(holdTimeSeconds),
      state_(SystemState::WAITING),
      holdStartTime_(),
      lastDistance_(-1.0)
{
}

// ─────────────────────────────────────────────────────────────────────────────

void FillingController::tick() {
    // --- Read distance from ultrasonic sensor ---
    lastDistance_ = sensor_.getDistanceCM();

    if (lastDistance_ < 0) {
        // Sensor timeout (matches Python: "Sensor timeout")
        std::cout << "Sensor timeout\n";

        // If we haven't started the pump yet, reset the hold timer
        if (state_ == SystemState::CONFIRMATION) {
            state_ = SystemState::WAITING;
        }
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Measured Distance = " << lastDistance_ << " cm\n";

    // --- State machine ---
    switch (state_) {

    case SystemState::WAITING:
        // Check if bottle is within target range
        if (sensor_.isBottlePresent(targetDistanceCM_, toleranceCM_)) {
            // Bottle detected — start hold timer
            // (matches Python: start_hold_time = time.time())
            holdStartTime_ = Clock::now();
            state_ = SystemState::CONFIRMATION;
            std::cout << targetDistanceCM_ << " cm detected, starting timer...\n";
        }
        break;

    case SystemState::CONFIRMATION: {
        // Check if bottle is still in range
        if (!sensor_.isBottlePresent(targetDistanceCM_, toleranceCM_)) {
            // Bottle moved away — reset timer
            // (matches Python: "Distance moved away from 12 cm, timer reset.")
            std::cout << "Distance moved away from " << targetDistanceCM_
                      << " cm, timer reset.\n";
            state_ = SystemState::WAITING;
            break;
        }

        // Bottle still present — check elapsed time
        double elapsed = getHoldElapsed();
        std::cout << "Held for " << std::fixed << std::setprecision(1)
                  << elapsed << " / " << holdTimeSeconds_ << " seconds\n";

        if (elapsed >= holdTimeSeconds_) {
            // Hold time reached — start pump!
            // (matches Python: GPIO.gpio_write(h, PUMP, 1))
            pump_.turnOn();
            state_ = SystemState::FILLING;
        }
        break;
    }

    case SystemState::FILLING:
        // Pump is running
        // TODO: integrate FlowMeter pulse counting here
        // When flow >= TARGET_VOLUME_ML → transition to FILL_COMPLETE
        std::cout << "Filling in progress...\n";
        break;

    case SystemState::FILL_COMPLETE:
        // Pump off, reset for next bottle
        pump_.turnOff();
        state_ = SystemState::WAITING;
        std::cout << "Fill complete. Waiting for next bottle...\n";
        break;
    }
}

// ─────────────────────────────────────────────────────────────────────────────

SystemState FillingController::getState() const {
    return state_;
}

std::string FillingController::getStateName() const {
    switch (state_) {
        case SystemState::WAITING:       return "WAITING";
        case SystemState::CONFIRMATION:  return "CONFIRMATION";
        case SystemState::FILLING:       return "FILLING";
        case SystemState::FILL_COMPLETE: return "FILL_COMPLETE";
        default:                         return "UNKNOWN";
    }
}

double FillingController::getHoldElapsed() const {
    if (state_ != SystemState::CONFIRMATION && state_ != SystemState::FILLING) {
        return 0.0;
    }
    auto now = Clock::now();
    return std::chrono::duration<double>(now - holdStartTime_).count();
}
