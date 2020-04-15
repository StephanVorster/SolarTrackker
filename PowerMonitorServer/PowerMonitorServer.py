import serial
import json
import datetime
import time


def generateJson(val) :
    date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    valStore = {
        "Power (W)": val,
        "Timestamp": date
    }
    return valStore


ser = serial.Serial("/dev/ttyACM0", 9600, timeout=None)

while 1:

    if(ser.inWaiting() != 0):
        msg = ser.readline()
        msg = msg.decode("utf-8")
        val = float(msg)
        valStore = generateJson(val)
        print(json.dumps(valStore))

    else:
        time.sleep(5)



