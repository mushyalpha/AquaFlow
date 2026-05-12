#ifndef IFLOWMETER_H
#define IFLOWMETER_H

/**
 * @brief Abstract interface for a pulse-counting flow meter.
 *
 * Consumers (e.g. FillingController) depend only on this interface,
 * allowing the concrete YF-S401 driver to be swapped for a mock in
 * unit tests without any change to higher-level logic (DIP / OCP).
 */
class IFlowMeter {
public:
    virtual ~IFlowMeter() = default;

    /** @brief Reset the pulse counter to zero (call before each new fill). */
    virtual void resetCount() = 0;

    /** @brief Current pulse count accumulated since the last reset. */
    virtual int getPulseCount() const = 0;

    /** @brief Accumulated dispensed volume in millilitres since the last reset. */
    virtual double getVolumeML() const = 0;
};

#endif // IFLOWMETER_H
