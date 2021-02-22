#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output



const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(9, 10);

int elephant[3];
void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.setChannel(110);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

}
  
void loop() {  
  elephant[0] = digitalRead(SW_pin);
  elephant[1] = analogRead(X_pin);
  elephant[2] = analogRead(Y_pin);
  radio.write(elephant, sizeof(elephant));

  delayMicroseconds(100);
}
