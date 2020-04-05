#include <Arduino.h>

int motorPin1 = 7;
int motorPin2 = 6;
int motorPin3 = 5;
int motorPin4 = 4;

/*
cycles through the motor pins in the order required for a forward motion eg:
    using the 28BYJ-48:
        1(Pink)
        2(Yellow)
        3(Orange)
        4(Blue)

Each cycle turns the motor roughly 0.703 degrees at 9V
*/
void forward(int cycles) {
  for(int i=0;i<=cycles;i++){
    digitalWrite(motorPin1, HIGH);
    Serial.println("Pin 1");
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, HIGH);
    Serial.println("Pin 2");
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin3, HIGH);
    Serial.println("Pin 3");
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin4, HIGH);
    Serial.println("Pin 4");
    digitalWrite(motorPin4,LOW);
  }
}

/*
cycles through the motor pins in the order required for a backwards motion eg:
    using the 28BYJ-48:
    4(Blue)
    3(Orange)
    2(Yellow)
    1(Pink)

Each cycle turns the motor roughly 0.703 degrees at 9V
*/

void backwards(int cycles) {
  for(int i=0;i<=cycles;i++){
    digitalWrite(motorPin4, HIGH);
    Serial.println("Pin 1");
    digitalWrite(motorPin4,LOW);
    digitalWrite(motorPin3, HIGH);
    Serial.println("Pin 2");
    digitalWrite(motorPin3,LOW);
    digitalWrite(motorPin2, HIGH);
    Serial.println("Pin 3");
    digitalWrite(motorPin2,LOW);
    digitalWrite(motorPin1, HIGH);
    Serial.println("Pin 4");
    digitalWrite(motorPin1,LOW);
  }
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  //512 cycles is roughly 360 degrees at 9V
  //Thus there is  roughly 0.703 degrees per cycle at 9V
  forward(512);
  //backwards(512);
  delay(1000);
}
