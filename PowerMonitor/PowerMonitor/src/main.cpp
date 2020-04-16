#include <Arduino.h>

int pin = A5;
float value = 0.0;
float resistor = 1500.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pin);
  value = (5*value)/1024;
  value = value*value;
  value = value/resistor;
  Serial.println(value);
  delay(((60*5)*1000));

}
