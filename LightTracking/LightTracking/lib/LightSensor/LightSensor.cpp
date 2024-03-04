#include "LightSensor.h"

LightSensor::LightSensor() {
 this->numSensors = 0;
 this->sensorPins = nullptr;
}

LightSensor::~LightSensor() {
    delete this->sensorPins;
}

LightSensor::LightSensor(int *pins) {
    this->sensorPins = pins;
    this->numSensors = sizeof(pins);
}

int* LightSensor::getSensorReadings() {
    int * readings = new int[numSensors];
    for(int i=0;i<numSensors;i++){
        readings[i] = analogRead(this->sensorPins[i]);
    }
    return readings;
}

void LightSensor::setSensorPins(int *pins){
    this->sensorPins = pins;
    this->numSensors = sizeof(pins);

}

void LightSensor::printSensors() {

    int * val = new int[numSensors];
    val = getSensorReadings();
    for(int i=0;i<this->numSensors;i++){
        Serial.print("Pin ");
        Serial.print(i+1);
        Serial.print(": ");
        Serial.println(val[i]);
    }
}
