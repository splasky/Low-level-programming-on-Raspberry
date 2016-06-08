import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
PIN4=4
GPIO.setup(PIN4,GPIO.IN,pull_up_down=GPIO.PUD_DOWN)

try:
    while range(1,100):
        print (GPIO.input(PIN4))
        time.sleep(1)
except:
    GPIO.cleanup()
finally:    
    GPIO.cleanup()
