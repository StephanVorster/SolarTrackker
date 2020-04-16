#include "PowerMonitor.h"

float value = 0.0;
void setup() {
  Serial.begin(9600);
}


PowerMonitor* mon = new PowerMonitor(A5);

void loop() {
 mon->displayPower();
  delay(60000*5);

}
