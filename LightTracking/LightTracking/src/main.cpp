#include "M28BYJ48.h"
#include "LightSensor.h"

void setup() {
    Serial.begin(9600);
}

int mtmp[4] = {7,6,5,4};
M28BYJ48* bottom = new M28BYJ48(M28BYJ48::V9,mtmp);
int stmp[2] = {A3,A2};
LightSensor* sen = new LightSensor(stmp);

void loop() {
    int* val = sen->getSensorReadings();
    int diff = val[0]-val[1];
    sen->printSensors();
if( (diff > -15) && (diff < 15) ) {
    Serial.println("Staying");
}

else {
    if(val[1] > val[0]){

        bottom->multiStepBackwards(10);
        Serial.println("Moving Backwards");

        }
    else {
        bottom->multiStepForward(10);
        Serial.println("Moving Forward");

        }
    }
    //delay(100);

}
