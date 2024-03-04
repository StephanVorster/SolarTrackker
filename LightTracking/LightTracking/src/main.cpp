#include "M28BYJ48.h"
#include "LightSensor.h"
#include "PowerMonitor.h"
#include "TimerOne.h"

int counter = 0;
float min = 5.00;

PowerMonitor* monitor =  new PowerMonitor(A5);
int mtmp[4] = {7,6,5,4};
M28BYJ48* bottom = new M28BYJ48(M28BYJ48::V9,mtmp);
int stmp[2] = {A3,A2};
LightSensor* sen = new LightSensor(stmp);

void timerIsr()
{
    if(counter >= int((min*60.00)/9)+1 ) {
        monitor->displayPower();
        counter = 0;
    }
    else {
        counter++;
    }
}

void setup() {

    Serial.begin(9600);
    Timer1.initialize(1000000*(600));
    Timer1.attachInterrupt( timerIsr );
}




void loop() {
    int* val = sen->getSensorReadings();
    int diff = val[0]-val[1];
    //sen->printSensors();
if( (diff > -15) && (diff < 15) ) {
    //Serial.println("Staying");
}

else {
    if(val[1] > val[0]){

        bottom->multiStepBackwards(10);
        //Serial.println("Moving Backwards");

        }
    else {
        bottom->multiStepForward(10);
        //Serial.println("Moving Forward");

        }
    }
    delay(200);

}
