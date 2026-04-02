import lgpio as GPIO

def check_chips():
    print("Checking for available GPIO chips on Raspberry Pi...")
    for i in range(10):
        try:
            h = GPIO.gpiochip_open(i)
            # Get chip info if possible (lgpio doesn't have a direct info call, 
            # but we can try to claim a line to see if it's the right one)
            print(f"Chip {i}: Found and opened successfully.")
            GPIO.gpiochip_close(h)
        except Exception as e:
            # Skip chips that are not available
            pass

if __name__ == "__main__":
    check_chips()
    print("\nNote: On Raspberry Pi 5, chip 4 is typically the main GPIO header.")
