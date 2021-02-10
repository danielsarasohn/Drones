int enA = 3;
int in1 = 4;
int in2 = 5;
int enB = 6;
int in3 = 7;
int in4 = 8;


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
int rocket[3];



int motorSpeedA = 0;
int motorSpeedB = 0;
void off()
{
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
}
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

void loop() {
  const int SW_pin = rocket[0]; // digital pin connected to switch output
const int xAxis = rocket[1]; // analog pin connected to X output
const int yAxis = rocket[2]; // analog pin connected to Y output
  radio.read(rocket, sizeof(rocket));

  if (yAxis < 470) {
  Serial.print("X-axis: ");
  Serial.print(analogRead(xAxis));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(yAxis));
  Serial.print("\n\n");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    motorSpeedA = map(yAxis, 470, 0, 0, 255);
    motorSpeedB = map(yAxis, 470, 0, 0, 255);
  }
  else if (yAxis > 550) {
   Serial.print("X-axis: ");
  Serial.print(analogRead(xAxis));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(yAxis));
  Serial.print("\n\n");
    digitalWrite (in1, LOW);
    digitalWrite (in2, HIGH);
    digitalWrite (in3, LOW);
    digitalWrite (in4, HIGH);
    motorSpeedA = map(yAxis, 550, 1023, 0, 255);
    motorSpeedB = map(yAxis, 550, 1023, 0, 255);
  }
  else {
    motorSpeedA = 0;
    motorSpeedB = 0;
  }

  if (xAxis < 470) {
    int xMapped = map(xAxis, 470, 0, 0, 255);
    motorSpeedA = motorSpeedA - xMapped;
    motorSpeedB = motorSpeedB + xMapped;
    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }
  }
  if (xAxis > 550) {
    int xMapped = map(xAxis, 470, 0, 0, 255);
    motorSpeedA = motorSpeedA + xMapped;
    motorSpeedB = motorSpeedB - xMapped;

    if (motorSpeedA < 0) {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 255) {
      motorSpeedB = 255;
    }

  }
  if (motorSpeedB < 70) {
    motorSpeedB = 0;
  }
  if (motorSpeedA < 70) {
    motorSpeedA = 0;
  }
  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);
}
