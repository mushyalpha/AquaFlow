#pragma once

#include <string>
#include <functional>

/**
 * @brief Receives state-change events from FillingController and
 *        logs them to the console (and optionally to a file).
 *
 * Registered as a callback observer — FillingController calls
 * onStateChange() whenever a transition occurs.  This decouples
 * display/logging from the state machine (SOLID SRP).
 */
class Monitor {
public:
    using StateCallback = std::function<void(const std::string& state,
                                             double volumeML,
                                             int    bottleCount)>;

    /** @brief Register an external subscriber for state events. */
    void registerCallback(StateCallback cb) { callback_ = std::move(cb); }

    /**
     * @brief Called by FillingController on every tick.
     * @param state       Current state name (e.g. "FILLING").
     * @param volumeML    Volume dispensed so far in this fill cycle.
     * @param bottleCount Total bottles filled this session.
     */
    void onStateChange(const std::string& state, double volumeML, int bottleCount);

private:
    StateCallback callback_;
};
