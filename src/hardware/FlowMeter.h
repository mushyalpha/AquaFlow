#pragma once

#include "IHardwareDevice.h"

#include <atomic>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>

#include <gpiod.hpp>

/**
 * @brief YF-S201 hall-effect flow sensor driver.
 *
 * Uses libgpiod v2 to detect falling edges (pulses) on the sensor's
 * signal pin in a dedicated thread (blocking I/O, no polling).
 *
 * Each pulse corresponds to a fixed volume of water (mlPerPulse).
 * The accumulated count is exposed via a poll-safe atomic API so that
 * FillingController can query volume without locking.
 *
 * Inherits IHardwareDevice for SOLID Liskov substitutability.
 */
class FlowMeter : public IHardwareDevice {
public:
    /**
     * @param chipNo      GPIO chip number (0 for Pi 1-4, 4 for Pi 5).
     * @param pinNo       BCM pin connected to sensor signal output.
     * @param mlPerPulse  Volume per pulse in millilitres (default 1.0 ml).
     */
    FlowMeter(unsigned int chipNo, unsigned int pinNo, float mlPerPulse = 1.0f)
        : chipNo_(chipNo), pinNo_(pinNo), mlPerPulse_(mlPerPulse) {}

    ~FlowMeter() override { shutdown(); }

    // ── IHardwareDevice interface ────────────────────────────────────────────

    /** @brief Set up GPIO and launch pulse-counting thread. */
    bool init() override;

    /** @brief Stop thread and release GPIO resources. */
    void shutdown() override;

    // ── Flow data API (safe to call from any thread) ─────────────────────────

    /** @brief Reset the pulse counter to zero (call before a new fill). */
    void resetCount();

    /** @brief Current pulse count since last reset. */
    int getPulseCount() const;

    /** @brief Accumulated volume in millilitres since last reset. */
    double getVolumeML() const;

    /** @brief True when accumulated volume >= targetVolumeML. */
    bool hasReachedTarget(double targetVolumeML) const;

private:
    void setupGpio();

    /** @brief Background thread: blocks on GPIO edge events, increments counter. */
    void edgeWorker();

    unsigned int chipNo_;
    unsigned int pinNo_;
    float mlPerPulse_;

    std::atomic<bool> running_{false};
    std::atomic<int>  pulseCount_{0};

    std::thread edgeThread_;
    std::shared_ptr<gpiod::chip>         chip_;
    std::shared_ptr<gpiod::line_request> request_;
};