import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
PIN4=4

GPIO.setup(PIN4,GPIO.OUT)
while range(1,100):
    GPIO.output(PIN4,GPIO.HIGH)
    time.sleep(5)
    GPIO.output(PIN4,GPIO.LOW)
    time.sleep(5)
GPIO.cleanup()
