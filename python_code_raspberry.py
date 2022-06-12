import requests, time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)

a = False

try:
        while True:
                # GET requests for Status from Express Server
                r = requests.get('http://192.168.20.10:3000/status')
                if r.text == "False" and a:
                        GPIO.output(18, GPIO.HIGH)
                        a = False
                        print("Door opened.")
                elif r.text == "True" and not a:
                        GPIO.output(18, GPIO.LOW)
                        a = True
                        print("Door closed.")


except KeyboardInterrupt:
        print("Stopping")
        GPIO.cleanup()