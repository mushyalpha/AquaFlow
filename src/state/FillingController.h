#ifndef FILLINGCONTROLLER_H
#define FILLINGCONTROLLER_H

#include "IProximitySensor.h"
#include "IPump.h"
#include "IFlowMeter.h"
#include <atomic>
#include <chrono>
#include <functional>
#include <string>

/**
 * @brief System states for the filling cycle.
 *
 * WAITING         — No bottle detected, system idle
 * AWAIT_SELECTION — Proximity established, waiting for directional swipe
 * FILLING         — Pump ON, counting flow pulses
 * FILL_COMPLETE   — Target volume reached, pump OFF, resetting
 */
enum class SystemState {
    WAITING,
    AWAIT_SELECTION,
    FILLING,
    FILL_COMPLETE
};

/**
 * @brief Main state machine that orchestrates the filling cycle.
 *
 * Cup detection is now event-driven: IProximitySensor fires a proximity
 * callback which sets a thread-safe flag.  tick() reads that flag on
 * each timer cycle — no polling, no distance measurements.
 *
 * The FillingController depends only on behavior abstractions
 * (IProximitySensor, IPump, IFlowMeter), supporting OCP and DIP.
 */
class FillingController {
public:
    /**
     * @param gestureSensor    Reference to a proximity/gesture source abstraction.
     * @param pump             Reference to a pump actuator abstraction.
     * @param flowMeter        Reference to a flow measurement abstraction.
     */
    FillingController(IProximitySensor& gestureSensor,
                      IPump&           pump,
                      IFlowMeter&      flowMeter);

    /**
     * @brief Run one cycle of the state machine.
     *
     * Call this repeatedly (e.g. from a Timer callback).
     * After each tick, calls the registered monitor callback (if any)
     * with the current state, volume, and bottle count.
     */
    void tick();

    /**
     * @brief Register a callback that is called after every tick.
     *
     * Used to wire in Monitor or any other observer without coupling
     * FillingController to a specific output class (SOLID OCP).
     */
    using MonitorCallback = std::function<void(const std::string& state,
                                               double volumeML,
                                               int    bottleCount)>;
    void registerMonitor(MonitorCallback cb) { monitorCallback_ = std::move(cb); }

    /** @brief Get the current system state. */
    SystemState getState() const;

    /** @brief Get a human-readable name for the current state. */
    std::string getStateName() const;

    /** @brief Get the current volume dispensed in ml. */
    double getCurrentVolumeML() const;

    /** @brief Get the target volume in ml. */
    double getTargetVolumeML() const;

    /** @brief Get the total number of bottles filled this session. */
    int getBottleCount() const;

private:
    // Hardware references
    IProximitySensor& gestureSensor_;
    IPump& pump_;
    IFlowMeter& flowMeter_;

    // Target Volume, determined dynamically by user gesture
    std::atomic<double> targetVolumeML_{0.0};

    // State
    SystemState state_;
    std::chrono::steady_clock::time_point holdStartTime_;
    int bottleCount_;

    /**
     * @brief Thread-safe flag set by the IProximitySensor proximity callback.
     *
     * true  = cup/bottle is currently detected in range
     * false = no cup detected
     *
     * Written from the sensor worker thread, read from the Timer
     * callback thread — std::atomic ensures no data race.
     */
    std::atomic<bool> bottlePresent_{false};

    /**
     * @brief Thread-safe flag capturing the last directional gesture.
     */
    std::atomic<GestureDir> gestureDirection_{GestureDir::NONE};

    MonitorCallback monitorCallback_;  ///< Optional observer, called after each tick.
};

#endif // FILLINGCONTROLLER_H
