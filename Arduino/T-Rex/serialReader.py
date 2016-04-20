# /usr/bin/python

import serial
import time

ser = serial.Serial("/dev/ttyACM0", 9600)

ser.setDTR(True)
time.sleep(1)
ser.setDTR(False)

while True:
    print ser.readline()

