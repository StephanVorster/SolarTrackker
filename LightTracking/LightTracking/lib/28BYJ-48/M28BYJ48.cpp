//
// Created by user on 2020/04/05.
//

#include "M28BYJ48.h"

M28BYJ48::M28BYJ48() {
    this->level = V9;
}

void M28BYJ48::setMotorPins(int *pins) {
    this->motorPins = pins;
}

M28BYJ48::M28BYJ48(M28BYJ48::Voltage level, int *pins) {
    this->level = level;
    this->motorPins = pins;
}

void M28BYJ48::setVolatge(M28BYJ48::Voltage level) {
    this->level = level;
}


void M28BYJ48::stepForward() {
    int* delayTime;
    *delayTime = 2;

    analogWrite(this->motorPins[0], 255);
    analogWrite(this->motorPins[1], 255);
    delay(*delayTime);//1100
    analogWrite(this->motorPins[0],0);
    delay(*delayTime);//0100
    analogWrite(this->motorPins[2], 255);
    analogWrite(this->motorPins[1],0);
    delay(*delayTime);//0010
    analogWrite(this->motorPins[3], 255);
    analogWrite(this->motorPins[2],0);
    delay(*delayTime);//0001
    analogWrite(this->motorPins[0], 255);
    delay(*delayTime);//1001
    analogWrite(this->motorPins[3],0);
    delay(*delayTime);//1000
    analogWrite(this->motorPins[0], 0);
    //0000*/
}

void M28BYJ48::stepBackwards() {
    int* delayTime;
    *delayTime = 2;

    analogWrite(this->motorPins[0], 255);
    delay(*delayTime);//1000
    analogWrite(this->motorPins[3], 255);
    delay(*delayTime);//1001
    analogWrite(this->motorPins[0], 0);
    delay(*delayTime);//0001
    analogWrite(this->motorPins[3], 0);
    analogWrite(this->motorPins[2],255);
    delay(*delayTime);//0010
    analogWrite(this->motorPins[2], 0);
    analogWrite(this->motorPins[1],255);
    delay(*delayTime);//0100
    analogWrite(this->motorPins[0], 255);
    delay(*delayTime);//1100
    analogWrite(this->motorPins[0], 0);
    analogWrite(this->motorPins[1], 0);
    //0000

}

void M28BYJ48::multiStepForward(int Steps) {
    for(int i=0;i<Steps;i++){
        this->stepForward();
    }
}

void M28BYJ48::multiStepBackwards(int Steps) {
    for(int i=0;i<Steps;i++){
        this->stepBackwards();
    }
}
