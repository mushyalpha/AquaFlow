#ifndef PINCONFIG_H
#define PINCONFIG_H

// ─── GPIO Pin Assignments (BCM numbering) ────────────────────────────────────
// HC-SR04 Ultrasonic Sensor
constexpr int TRIG_PIN = 23;   // GPIO23 — trigger output
constexpr int ECHO_PIN = 24;   // GPIO24 — echo input

// DC Water Pump (via TIP121 transistor)
constexpr int PUMP_PIN = 27;   // GPIO27 — pump control output

// YF-S401 Flow Meter
constexpr int FLOW_PIN = 17;   // GPIO17 — pulse input (to be confirmed)

// ─── Sensor Settings ─────────────────────────────────────────────────────────
constexpr double TARGET_DISTANCE_CM = 12.0;   // target bottle distance
constexpr double DISTANCE_TOLERANCE_CM = 1.0; // ±1 cm tolerance (11–13 cm)

// ─── Timing Settings ─────────────────────────────────────────────────────────
constexpr int HOLD_TIME_SECONDS = 60;          // bottle must be stable for 60s
constexpr int LOOP_INTERVAL_MS = 1000;         // main loop interval (1 second)

// ─── Flow Settings ───────────────────────────────────────────────────────────
constexpr double ML_PER_PULSE = 2.25;          // calibration constant
constexpr double TARGET_VOLUME_ML = 500.0;     // target fill volume

// ─── GPIO Chip ───────────────────────────────────────────────────────────────
constexpr int GPIO_CHIP = 0;                   // /dev/gpiochip0

#endif // PINCONFIG_H
