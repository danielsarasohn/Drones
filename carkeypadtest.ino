int Open = 0;
long Micros;
// Include Arduino Wire library for I2C
#include <Wire.h>
// Include LCD display library for I2C
#include <LiquidCrystal_I2C.h>
// Include Keypad library
#include <Keypad.h>

#include <Servo.h>
Servo myservo1;
// Length of password + 1 for null character
#define Password_Length 7
// Character to hold password input
char Data[Password_Length];
// Password
char Master[Password_Length] = "12345#";

// Pin connected to led
int lockOutput = 13;
int lockOut = 12;
// Counter for character entries
byte data_count = 0;

// Character to hold key input
char customKey;

// Constants for row and column sizes

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// Create LCD object
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Setup LCD with backlight and initialize
  lcd.init();
  lcd.backlight();
  pinMode(13, OUTPUT);
  // Set lockOutput as an OUTPUT pin
  Serial.begin(9600);

}

void loop() {
  // Initialize LCD and print
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  // Look for keypress
  customKey = customKeypad.getKey();
  if (customKey) {
    // Enter keypress into array and increment counter
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    digitalWrite(13, HIGH);
    lcd.print("*");
    Serial.print(customKey);
    data_count++;
    delay(100);
    digitalWrite(13,LOW);
  }

  // See if we have reached the password length
  if (data_count == Password_Length - 1) {
    lcd.clear();

    if (!strcmp(Data, Master)) {
      // Password is correct
      if (Open == 0)
      {
        Micros = micros();
        Serial.print("\n");
        Serial.println("Car Unlocking and Turning On");
        Serial.print("\n\n");
        digitalWrite(13, HIGH);
        delay(5000);
        digitalWrite(13, LOW);
        Open = 1;
      }
      else if (Open == 1)
      {
        if (Micros - micros() >= 5250000)
        {
          Micros = micros();
          Serial.print("\n");
          Serial.println("Car Locking and Turning Off");
          Serial.print("\n\n");
          digitalWrite(13, HIGH);
          delay(1250);
          digitalWrite(13, LOW);
          delay(1250);
          digitalWrite(13, HIGH);
          delay(1250);
          digitalWrite(13, LOW);
          delay(1250);
          Open = 0;
        }
      }
    }
    else {
      // Password is incorrect
      if (Open == 0)
      {
        Serial.print("\n");
        Serial.println("Incorrect Code Car not turning on");
        Serial.print("\n\n");
      }
      if (Open == 1)
      {
        Serial.print("\n");
        Serial.println("Car Locking and Shutting Down");
        Serial.print("\n\n");
      }
      lcd.print("Incorrect");
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      delay(500);
      digitalWrite(13, HIGH);
      delay(500);
      digitalWrite(13, LOW);
      
      clearData();
      return;
    }

    // Clear data and LCD display
    lcd.clear();
    clearData();
  }
}

void clearData() {
  // Go through array and clear data
  while (data_count != 0) {
    Data[data_count--] = 0;
  }
  return;
}
