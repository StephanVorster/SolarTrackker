#include "M28BYJ48.h"




void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}
int tmp[4] = {3,5,6,9};
//Bl,Pi,Ye,Or
int hold = 0;
M28BYJ48* BottomMotor = new M28BYJ48(M28BYJ48::V9,tmp);
int tmp2[4] = {8,10,11,12};
M28BYJ48* TopMotor = new M28BYJ48(M28BYJ48::V9,tmp2);

void loop() {


  //512 cycles is roughly 360 degrees at 9V
  //Thus there is  roughly 0.703 degrees per cycle at 9V
  //Serial.println("Backwards:");
  //BottomMotor->multiStepBackwards(256);
    TopMotor->multiStepForward(32);

  delay(2500);
  //BottomMotor->multiStepForward(256);
  TopMotor->multiStepBackwards(32);
  delay(2500);

}
