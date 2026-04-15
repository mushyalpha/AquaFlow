#include "state/FillingController.h"

#include <chrono>

using Clock = std::chrono::steady_clock;

// ─────────────────────────────────────────────────────────────────────────────

FillingController::FillingController(IProximitySensor& gestureSensor,
                                     IPump&           pump,
                                     IFlowMeter&      flowMeter)
    : gestureSensor_(gestureSensor),
      pump_(pump),
      flowMeter_(flowMeter),
      state_(SystemState::WAITING),
      holdStartTime_(),
      bottleCount_(0),
      monitorCallback_(nullptr)
{
    // Register proximity callback on the sensor abstraction.
    // Called from the sensor worker thread on proximity state change.
    // Callback is intentionally minimal: release-store only — no I/O, no blocking.
    // memory_order_release pairs with the acquire-load in tick() to ensure the
    // stored value is visible to the Timer thread before it reads it.
    gestureSensor_.registerEventCallback([this](const GestureEvent& event) {
        if (event.getState() == ProximityState::PROXIMITY_TRIGGERED) {
            bottlePresent_.store(true,  std::memory_order_release);
        } else if (event.getState() == ProximityState::PROXIMITY_CLEARED) {
            bottlePresent_.store(false, std::memory_order_release);
        }

        if (event.getDirection() != GestureDir::NONE) {
            gestureDirection_.store(event.getDirection(), std::memory_order_release);
        }
    });
}

// ─────────────────────────────────────────────────────────────────────────────

void FillingController::tick() {

    switch (state_) {

    // ── WAITING: no cup detected yet ─────────────────────────────────────────
    case SystemState::WAITING: {
        // Clear any lingering gestures from before cup was placed
        gestureDirection_.store(GestureDir::NONE, std::memory_order_release);

        // acquire-load pairs with the release-store in the proximity callback
        if (bottlePresent_.load(std::memory_order_acquire)) {
            state_ = SystemState::AWAIT_SELECTION;
        }
        break;
    }

    // ── AWAIT_SELECTION: cup present, waiting for left/down/right swipe ──────
    case SystemState::AWAIT_SELECTION: {
        if (!bottlePresent_.load(std::memory_order_acquire)) {
            // Cup removed before selection
            state_ = SystemState::WAITING;
            break;
        }

        GestureDir dir = gestureDirection_.exchange(GestureDir::NONE, std::memory_order_acquire);
        
        if (dir == GestureDir::LEFT || dir == GestureDir::DOWN || dir == GestureDir::RIGHT) {
            if (dir == GestureDir::LEFT)       targetVolumeML_ = 200.0;
            else if (dir == GestureDir::DOWN)  targetVolumeML_ = 400.0;
            else /* RIGHT */                   targetVolumeML_ = 600.0;

            // Gesture confirmed — reset meter and start pump
            flowMeter_.resetCount();
            pump_.turnOn();
            state_ = SystemState::FILLING;
        }
        break;
    }

    // ── FILLING: pump running, counting flow pulses ───────────────────────────
    case SystemState::FILLING: {
        if (!bottlePresent_.load(std::memory_order_acquire)) {
            // Emergency Abort: Cup removed during fill
            pump_.turnOff();
            state_ = SystemState::WAITING;
            break;
        }

        double currentML = flowMeter_.getVolumeML();
        if (currentML >= targetVolumeML_) {
            pump_.turnOff();
            bottleCount_++;
            state_ = SystemState::FILL_COMPLETE;
        }
        break;
    }

    // ── FILL_COMPLETE: pump off, reset for next cup ───────────────────────────
    case SystemState::FILL_COMPLETE: {
        if (!bottlePresent_.load(std::memory_order_acquire)) {
            flowMeter_.resetCount();
            state_ = SystemState::WAITING;
        }
        break;
    }
    }

    // Notify observer (Monitor + LCD) after every tick — volume updates happen here
    if (monitorCallback_) {
        monitorCallback_(getStateName(), flowMeter_.getVolumeML(), bottleCount_);
    }
}

// ─────────────────────────────────────────────────────────────────────────────

SystemState FillingController::getState() const {
    return state_;
}

std::string FillingController::getStateName() const {
    switch (state_) {
        case SystemState::WAITING:         return "WAITING";
        case SystemState::AWAIT_SELECTION: return "SELECT SIZE";
        case SystemState::FILLING:         return "FILLING";
        case SystemState::FILL_COMPLETE:   return "COMPLETE";
        default:                           return "UNKNOWN";
    }
}

double FillingController::getCurrentVolumeML() const {
    return flowMeter_.getVolumeML();
}

double FillingController::getTargetVolumeML() const {
    return targetVolumeML_.load();
}

int FillingController::getBottleCount() const {
    return bottleCount_;
}
