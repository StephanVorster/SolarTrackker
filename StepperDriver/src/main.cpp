#include "M28BYJ48.h"




void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}
int tmp[4] = {7,6,5,4};
M28BYJ48* BottomMotor = new M28BYJ48();

void loop() {
  //512 cycles is roughly 360 degrees at 9V
  //Thus there is  roughly 0.703 degrees per cycle at 9V

  BottomMotor->setMotorPins(tmp);
  //BottomMotor->multiStepBackwards(128);
  BottomMotor->multiStepForward(512);
  delay(1000);
}
