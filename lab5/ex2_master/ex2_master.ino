// TRANSMITTER

#include <LiquidCrystal.h>

// include I2C library
#include <Wire.h>

String inputString = ""; // create an empty string to hold the incoming serial data
boolean stringComplete = false;


LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int x = 0;

void setup() {
  // Open I2C bus as master
    Serial.begin(9600); // implicit serial frame format
  inputString.reserve(200);
  Serial.println("Starting app...");
  Wire.begin();
  lcd.begin(16, 2);
  lcd.print("Transmitter");
}

void loop() {
  // Wire.beginTransmission(9); // transmit to device #9
  // Wire.write(x);
  // // transmit x
  // Wire.endTransmission();
  // // stop transmission
  // lcd.setCursor(0, 1);
  // lcd.print(x);
  // // display sent character on LCD
  // x++; // increment x
  // if (x > 5) x = 0; // reset x when it reaches 6
  // delay(500);

  if (stringComplete) {
    lcd.setCursor(0, 0);
    lcd.print(inputString);
    if(!inputString.equals("")){
    // Serial.print("> the arduino recived : ");
    // Serial.println(inputString);
    Wire.beginTransmission(9); // transmit to device #9
    Wire.println(inputString);
    }else 
    Serial.println("please type sth up there...");

    // empty the string
    inputString = "";
    // reset the flag
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // read the new received byte
    char inChar = (char)Serial.read();
    // check if new line character has been received; if
    //not, add it to the string
    // we do not add new line in input string since it
    //will show an extra character in the LCD
    if (inChar != '\n')
      inputString += inChar;
    // dif the receive character is new line, set the flag
    //so that the loop will know to display
    //the received data
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}