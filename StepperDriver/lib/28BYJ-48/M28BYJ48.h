#ifndef M28BYJ48_H
#define M28BYJ48_H

/**
 * Class used to drive the 28BYJ-48 stepper motor at different voltage levels(default 9V).
 */
class M28BYJ48 {

public:
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
     * 0: (Pink)
     * 1: (Yellow)
     * 2: (Orange)
     * 3: (Blue)
     * @param level : The Voltage that the motor will be operating at;
     * @param pins : [pinkPin,yellowPin,orangePin,bluePin]
     */
    M28BYJ48(Voltage level, int* pins);
    ~M28BYJ48() = default;
    /**
     * The different volatge levels the motor can operate at
     */
    enum Voltage {5V,9V,12V,15V};
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
