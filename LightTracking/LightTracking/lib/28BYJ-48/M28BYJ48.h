#ifndef M28BYJ48_H
#define M28BYJ48_H

#include <Arduino.h>
/**
 * Class used to drive the 28BYJ-48 stepper motor at different voltage levels(default 9V).
 * All refrences to volatge levels are for future use.
 */
class M28BYJ48 {

public:
    /**
     * The different volatge levels the motor can operate at
     * All refrences to volatge levels are for future use.
     */
    enum Voltage {V5,V9,V12,V15};
    /**
     * Constructor:
     * Sets the voltage level to 9V
     */
    M28BYJ48();
    /**
     * Constructor:
     * Sets the voltage level to desired Voltage.
     * Sets the pins that the motor will be connected to, pins will be set in the order they will be triggered for
     * counterclockwise rotation ie:
     * 0: (Blue)
     * 1: (Pink)
     * 2: (Yellow)
     * 3: (Orange)
     * @param level : The Voltage that the motor will be operating at;
     * @param pins : [bluePin,pinkPin,yellowPin,orangePin]
     */
    M28BYJ48(Voltage level, int* pins);
    ~M28BYJ48() = default;

    /**
     * Sets the voltage that will be used on the motor.
     * @param Voltage : The desired level the motor will operate at.
     */
    void setVolatge(Voltage level);
    /**
     * Voltage level the motor is operating at
     */
    Voltage level;
    /**
     * The pins the motor pins will be attached to thr board
     */
    int* motorPins;
    /**
     * Sets the pins that the motor will be connected to, pins will be set in the order they will be triggered for
     * counterclockwise rotation ie:
     * 0: (Pink)
     * 1: (Yellow)
     * 2: (Orange)
     * 3: (Blue)
     * @param pins : [pinkPin,yellowPin,orangePin,bluePin]
     */
    void setMotorPins(int* pins);
    /**
     * Moves the motor one step counterclockwise
     */
    void stepForward();
    /**
     * Moves the motor one step clockwise
     */
    void stepBackwards();
    /**
     * Moves the motor multiple steps counterclockwise
     * @param Steps: The amount of steps the motor should take
     */
    void multiStepForward(int Steps);
    /**
     * Moves the motor multiple steps clockwise
     * @param Steps: The amount of steps the motor should take
     */
    void multiStepBackwards(int Steps);

};


#endif M28BYJ48_H
