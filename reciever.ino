///*
// Import installed libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
// The 'pipe' or 'frequency'
// Same for sender and receiver
const uint64_t pipe = 0xE8E8F0F0E1LL;
// Declare object & Create Radio
RF24 radio(9, 10);
//Declare Variable 'rocket'
//as a 2 element array
int rocket[2];
void setup(){
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
Serial.begin(9600);
}
void loop(){
//read the incoming radio signal
//store the information in

radio.read(rocket, sizeof(rocket));
// print the values of 'rocket'
Serial.println(rocket[0]);
Serial.println(rocket[1]);
}
//*/
/*
 // Import installed libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int Speed;
// The 'pipe' or 'frequency'
// Same for sender and receiver
const uint64_t pipe = 0xE8E8F0F0E1LL;
// Declare object & Create Radio
RF24 radio(9, 10);
//Declare Variable 'rocket'
//as a 2 element array
int rocket[44];
void setup() {
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
  Serial.begin(9600);
}
void loop() {
  //read the incoming radio signal
  //store the information in

  radio.read(rocket, sizeof(rocket));
  // print the values of 'rocket'

  if (rocket[0] == 0)
  {
    Serial.println("disconnected");
    Serial.println(rocket[1]);
  }
  else if (rocket[0] != 0)
  {
    Speed = map(rocket[0], 684, 1023, 0, 100);
    Serial.print("analogRead(A0) = ");
    Serial.println(rocket[0]);
    Serial.print("Speed = ");
    Serial.println(Speed);
    Serial.println(rocket[1]);
  }
}
*/
