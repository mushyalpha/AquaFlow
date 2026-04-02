import lgpio as GPIO
import time
import sys

# HC-SR04 Pin Configuration
TRIG = 23
ECHO = 24

# For Raspberry Pi 5, the main GPIO header is typically chip 4.
# For Raspberry Pi 4 and earlier, it is typically chip 0.
CHIP_INDEX = 4 

try:
    h = GPIO.gpiochip_open(CHIP_INDEX)
    print(f"Using GPIO chip {CHIP_INDEX} (Pi 5 standard)")
except Exception:
    try:
        CHIP_INDEX = 0
        h = GPIO.gpiochip_open(CHIP_INDEX)
        print(f"Using GPIO chip {CHIP_INDEX} (Pi 4 standard)")
    except Exception as e:
        print(f"Error: Could not open any GPIO chip (tried 0 and 4). {e}")
        sys.exit(1)

# Claim pins
try:
    GPIO.gpio_claim_output(h, TRIG)
    GPIO.gpio_claim_input(h, ECHO)
except Exception as e:
    print(f"Error claiming GPIO pins: {e}")
    GPIO.gpiochip_close(h)
    sys.exit(1)

def get_distance():
    # 1. Ensure TRIG is LOW
    GPIO.gpio_write(h, TRIG, 0)
    time.sleep(0.05)

    # 2. Send 10us trigger pulse
    GPIO.gpio_write(h, TRIG, 1)
    time.sleep(0.00001)
    GPIO.gpio_write(h, TRIG, 0)

    # 3. Wait for ECHO to go HIGH
    timeout_start = time.time()
    pulse_start = time.time()
    
    while GPIO.gpio_read(h, ECHO) == 0:
        pulse_start = time.time()
        if pulse_start - timeout_start > 0.1: # Increased timeout to 100ms
            return "TIMEOUT_WAITING_FOR_HIGH"

    # 4. Wait for ECHO to go LOW
    timeout_start = time.time()
    pulse_end = time.time()
    
    while GPIO.gpio_read(h, ECHO) == 1:
        pulse_end = time.time()
        if pulse_end - timeout_start > 0.1: # Increased timeout to 100ms
            return "TIMEOUT_WAITING_FOR_LOW"

    # 5. Calculate distance
    pulse_duration = pulse_end - pulse_start
    # sound speed = 34300 cm/s -> distance = (duration * 34300) / 2
    distance = pulse_duration * 17150
    return round(distance, 2)

print("Starting Ultrasonic Sensor measurement (HC-SR04)...")
print(f"Control+C to stop. Pins: TRIG={TRIG}, ECHO={ECHO}")

try:
    while True:
        result = get_distance()
        
        if isinstance(result, str):
            if result == "TIMEOUT_WAITING_FOR_HIGH":
                print("Error: Timeout waiting for ECHO to go HIGH (is it connected to GPIO 24?)")
            elif result == "TIMEOUT_WAITING_FOR_LOW":
                print("Error: Timeout waiting for ECHO to go LOW (pulse never ended)")
        else:
            print(f"Distance: {result:.2f} cm")
            
        time.sleep(1)

except KeyboardInterrupt:
    print("\nStopped by user")
finally:
    if 'h' in locals():
        GPIO.gpiochip_close(h)
