import serial
import json
import datetime
import time

# Generates the formatted dict for to be converted to json objects
def generateJson(val) :
    date = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    valStore = {
        "Power (W)": val,
        "Timestamp": date
    }
    return valStore

# Writes json objects to a json file
def writeToFile(msg):
    with open("StillPower.json","a") as file:
        file.write(msg)


# Continuously monitors serial port for a new message
ser = serial.Serial("/dev/ttyACM0", 9600, timeout=None)

while 1:

    if(ser.inWaiting() != 0):
        msg = ser.readline()
        msg = msg.decode("utf-8")
        val = float(msg)
        valStore = generateJson(val)
        print(json.dumps(valStore))
        writeToFile(json.dumps(valStore))

    else:
        time.sleep(30)



