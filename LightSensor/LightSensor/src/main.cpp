#include "LightSensor.h"

void setup() {
  	Serial.begin(9600);
}

int tmp[2]  = {A3,A2};
LightSensor* sen = new LightSensor(tmp);

void loop() {

    sen->printSensors();
    int* val = sen->getSensorReadings();
    if((val[0]-val[1])>-15 && (val[0]-val[1])<15) {
        Serial.println("Same");
    }
    else {
        Serial.println("Diffrent");
    }


    delay(1000);

}

// -15<x<15
