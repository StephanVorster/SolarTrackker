import json
import datetime
from matplotlib import pyplot as plt
import numpy as np


def splitDays():

    jsonFile = open("StillPower.json", "r")
    firstDay = []
    secondDay = []
    for i in jsonFile:
        jsonData = json.loads(str(i))
        date = datetime.datetime.strptime(jsonData["Timestamp"], "%Y-%m-%d %H:%M:%S")
        day = int(date.strftime("%d"))
        if day == 16:
            firstDay.append(jsonData["Voltage (V)"])
        else:
            secondDay.append(jsonData["Voltage (V)"])
    jsonFile.close()

    for i in range(1, 8):
        firstDay.pop(i)

    return [firstDay,secondDay]

def plotGraphs():

    time = np.arange(0,250,5)
    days = splitDays()
    firstDay = days[0]
    secondDay = days[1]
    #for i in range(1,8):
        #firstDay.pop(i)

    print("First day: " + str(len(firstDay)))
    for i in range(0,len(firstDay)):
        power = float(firstDay[i])**2
        firstDay[i] = power/1500
        print(str(firstDay[i]) + " W")



    print("Second day: " + str(len(secondDay)))

    for i in range(0,len(secondDay)):
        power = float(secondDay[i]) ** 2
        secondDay[i] = power / 1500
        print(str(secondDay[i]) + " W")



    plt.xlabel("Tyd (min)")
    plt.ylabel("Krag opgewek (W)")
    line1, = plt.plot(time, firstDay, label="Line1")
    line2, = plt.plot(time, secondDay, label="Line2")
    plt.legend((line1,line2),("Still staande" , "Son volger"))
    plt.show()

def calculateAvg ():
    measurements = splitDays()
    firstDay = measurements[0]
    secondDay = measurements[1]
    firstAvg = 0.00
    for i in firstDay:
        firstAvg = float(firstAvg +float(i))
    firstAvg = float(firstAvg/(len(firstDay)))

    secondAvg = 0.00
    for i in secondDay:
        secondAvg = float(secondAvg + i)
    secondAvg = float(secondAvg / len(secondDay))

    return [firstAvg,secondAvg]

def createTable():

    measurements = splitDays()
    firstDay = measurements[0]
    secondDay = measurements[1]
    time = 0
    for i in range(0 , len(firstDay)):
        print(str(time) + "&" +str(firstDay[i]) + "&" + str(secondDay[i])  + "\\" + "\\")
        time = time + 5

def createBarGraph():
    avgs = calculateAvg()
    firstAvg = avgs[0]
    secondAvg = avgs[1]
    print(firstAvg)
    print(secondAvg)


    objects = ("Stillstande", "Son Volger")
    y_pos = np.arange(len(objects))
    performance = [firstAvg, secondAvg]

    plt.bar(y_pos, performance, align='center', alpha=0.5)
    plt.xticks(y_pos, objects)
    plt.ylabel('Krag opgewek in 4 ure en 10 min(W)')
    plt.title('Grafiek van krag wat opgewek was deur panele in 4 ure en 10 min')

    plt.show()

createBarGraph()