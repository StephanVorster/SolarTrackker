int pin = A5;
float value = 0.0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pin);
  value = (5*value)/1024;
  Serial.print(value);
  Serial.println("V");
  delay(1000);

}
