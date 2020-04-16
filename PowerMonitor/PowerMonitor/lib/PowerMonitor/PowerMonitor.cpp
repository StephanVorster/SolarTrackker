#include "PowerMonitor.h"

PowerMonitor::PowerMonitor(int pin){
    this->pin = pin;
}

PowerMonitor::displayPower(){
    value = analogRead(this->pin);
    value = (5*value)/1024;
    Serial.println(value);
}
