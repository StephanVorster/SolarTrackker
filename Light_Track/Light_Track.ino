// Include the Arduino Stepper Library
#include <Stepper.h>

 int LeftLight  = A0; 
 int val = 0;
 boolean inits = true;
 bool clockwise = true;

 // Number of steps per output rotation
const int stepsPerRevolution = 20;
// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 12, 11, 10, 9);



void setup() {
 // put your setup code here, to run once:
    Serial.begin(9600);
    // set the speed at 160 rpm:
    myStepper.setSpeed(160);

}

void loop() {
    
  if(inits){
  init_function();
  Serial.println("Ending init");
  }

  int prevVal = val;
  val = Read();
  if(val != prevVal){
    if(clockwise){
      Serial.println("Moving stepper forward");
      myStepper.step(stepsPerRevolution);
    }
    else {
      Serial.println("Moving stepper backward");
      myStepper.step(-stepsPerRevolution);
    }
  }
  
}

int Read() {//read analogg value and compare to the previous reading 
   int tmp = analogRead(LeftLight);
   if(tmp > val + 10) {
    Serial.println(tmp);
    clockwise = true;
    return tmp;
   }
   else if(tmp < val - 15){
    Serial.println(tmp);
    clockwise = false;
    return tmp;
   }
   else
    return val;
  
}


void init_function() {//gatther initial readings
  inits = false;
  Serial.println("In init");
  int* tmp = new int[7];
  
  for(int i =0;i<7;i++){
    tmp[i] = analogRead(LeftLight);
    delay(100);
  }
  
  for(int i =0;i<7;i++){
    Serial.println(tmp[i]);
  }
}
