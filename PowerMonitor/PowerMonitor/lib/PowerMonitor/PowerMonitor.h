#ifndef POWERMONITOR_H
#define POWERMONITOR_H

#include <Arduino.h>

class PowerMonitor {

public:
    PowerMonitor() = default;
    /**
     * Constructor that sets the pin where the ADC will operate on.
     * @param pin
     */
    PowerMonitor(int pin);
    ~PowerMonitor() = default;
    /**
     * Sends the voltage read by the ADC over the serial port.
     */
    void displayPower();

private:
    /**
     * The pin the ADC will operate on.
     */
    int pin;


};


#endif //POWERMONITOR_H
