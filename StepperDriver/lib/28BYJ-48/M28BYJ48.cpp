//
// Created by user on 2020/04/05.
//

#include "M28BYJ48.h"

M28BYJ48::M28BYJ48() {
    this->level = 9V;
}

M28BYJ48::~M28BYJ48() {
    this->motorPins = nullptr;
}

void M28BYJ48::setMotorPins(int *pins) {
    this->motorPins = pins;
}

M28BYJ48::M28BYJ48(M28BYJ48::Voltage level, int *pins) {
    this->level = level;
    this->motorPins = pins;
}

void M28BYJ48::setMotorPins(int *pins) {
    this->motorPins = pins;
}

void M28BYJ48::setVolatge(M28BYJ48::Voltage level) {
    this->level = level
}

void M28BYJ48::stepForward() {
    digitalWrite(this->motorPins[0], HIGH);
    digitalWrite(this->motorPins[0],LOW);
    digitalWrite(this->motorPins[1], HIGH);
    digitalWrite(this->motorPins[1],LOW);
    digitalWrite(this->motorPins[2], HIGH);
    digitalWrite(this->motorPins[2],LOW);
    digitalWrite(this->motorPins[3], HIGH);
    digitalWrite(this->motorPins[3],LOW);
}

void M28BYJ48::stepBackwards() {
    digitalWrite(this->motorPins[3], HIGH);
    digitalWrite(this->motorPins[3],LOW);
    digitalWrite(this->motorPins[2], HIGH);
    digitalWrite(this->motorPins[2],LOW);
    digitalWrite(this->motorPins[1], HIGH);
    digitalWrite(this->motorPins[1],LOW);
    digitalWrite(this->motorPins[0], HIGH);
    digitalWrite(this->motorPins[0],LOW);
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