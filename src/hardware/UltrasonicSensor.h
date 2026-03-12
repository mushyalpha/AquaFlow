#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "IHardwareDevice.h"

/**
 * @brief HC-SR04 Ultrasonic Distance Sensor driver.
 *
 * Sends a 10µs trigger pulse, measures the echo return time,
 * and converts it to distance in centimetres.
 *
 * Based on the working Python prototype using lgpio.
 */
class UltrasonicSensor : public IHardwareDevice {
public:
    /**
     * @param gpioHandle  Handle returned by lgGpiochipOpen().
     * @param trigPin     BCM pin number for trigger output.
     * @param echoPin     BCM pin number for echo input.
     */
    UltrasonicSensor(int gpioHandle, int trigPin, int echoPin);
    ~UltrasonicSensor() override;

    bool init() override;
    void shutdown() override;

    /**
     * @brief Measure distance to the nearest object.
     * @return Distance in centimetres, or -1.0 on timeout.
     */
    double getDistanceCM();

    /**
     * @brief Check if a bottle is within the target range.
     * @param targetCM   Centre of the target distance.
     * @param toleranceCM  Acceptable ± deviation.
     * @return true if measured distance is within [target - tol, target + tol].
     */
    bool isBottlePresent(double targetCM, double toleranceCM);

private:
    int handle_;
    int trigPin_;
    int echoPin_;
    bool initialised_;
};

#endif // ULTRASONICSENSOR_H
