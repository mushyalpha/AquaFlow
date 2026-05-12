#ifndef IPUMP_H
#define IPUMP_H

/**
 * @brief Abstract interface for a controllable water pump.
 *
 * FillingController depends on this interface rather than the concrete
 * PumpController, enabling mock substitution in unit tests and
 * hardware-free simulation mode (DIP / OCP).
 */
class IPump {
public:
    virtual ~IPump() = default;

    /** @brief Energise the pump and begin water flow. */
    virtual void turnOn() = 0;

    /** @brief Cut power to the pump, stopping water flow immediately. */
    virtual void turnOff() = 0;

    /** @brief Returns true while the pump is energised and running. */
    virtual bool isRunning() const = 0;
};

#endif // IPUMP_H
