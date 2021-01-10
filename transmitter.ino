#include <nRF24L01.h>
#include <RF24.h>

// Import installed libraries
#include <SPI.h>

// The 'pipe' or 'frequency'
// Same for sender and receiver
const uint64_t pipe = 0xE8E8F0F0E1LL;
// Declare object & Create Radio
RF24 radio(9, 10);
//Declare Variable 'elephant'
//as a 2 element array
int elephant[2];
void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
}
void loop() {
  elephant[0] = analogRead(A0);
  elephant[1] = 7;
  // send 'elephant'
  radio.write(elephant, sizeof(elephant));
}

/*
  #include <nRF24L01.h>
  #include <RF24.h>

  // Import installed libraries
  #include <SPI.h>

  // The 'pipe' or 'frequency'
  // Same for sender and receiver
  const uint64_t pipe = 0xE8E8F0F0E1LL;
  // Declare object & Create Radio
  RF24 radio(9, 10);
  //Declare Variable 'elephant'
  //as a 2 element array
  int elephant[2];
  void setup() {
  radio.begin();
  radio.openWritingPipe(pipe);
  }
  void loop() {
  elephant[0] = analogRead(A0);
  elephant[1] = 7;
  // send 'elephant'
  radio.write(elephant, sizeof(elephant));
  }
  */
