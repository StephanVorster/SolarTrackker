#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include <Arduino.h>

class LightSensor {
public:
    /**
     * A constructor that initializes numSensors to zero
     */
    LightSensor();
    /**
     * A constructor that sets the pins that will be used as light sensors
     * @param array pins defines the pins that will be used as light sensors
     * The number of sensors will be automatically set
     * Pins will be assigned in chronological order ie: [<pin1>,<pin2>,.......,<pinN>]
     */
    LightSensor(int* pins);
    /**
     * A Destructor that deletes the sensorPins pointer array;
     */
    ~LightSensor();
    /**
     * Holds the number of pins in the sensor
     */
    int numSensors;
    /**
     * An array of the pins where the sensors are located
     */
    int* sensorPins;
    /**
     * Gets the readings from each of the pins in sensorPins
     * @return an array of each sensor pin reading
     */
    int* getSensorReadings();
    /**
     * Sets the sensor pins array to pins on the board
     * @param pins An array of pins that will be set to the sensorPins attribute
     */
    void setSensorPins(int* pins);
    /**
     * Prints out the getSensorReadings return value through the serial of the board
     */
    void printSensors();
};


#endif LIGHTSENSOR_H
