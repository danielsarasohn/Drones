#include <SoftwareSerial.h>
SoftwareSerial softSerial(10, 11);
void setup() {
  softSerial.begin(9600); Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {
    byte byteNow = Serial.read(); {
      softSerial.write(byteNow); //write, not Serial.print()
    }
  }
  if (softSerial.available()) {
    Serial.write(softSerial.read());
  }
}
