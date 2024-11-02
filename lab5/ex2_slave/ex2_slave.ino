#include <LiquidCrystal.h>

// include I2C library
#include <Wire.h>

int x = 0;
String inputString = ""; // create an empty string to hold the incoming serial data

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  // Start i2C slave at address 9
  Wire.begin(9);
 Serial.begin(9600); // implicit serial frame format
  inputString.reserve(200);
  Serial.println("Starting app...");
  // Attach a function to be called when we receive something on the I2C bus
  Wire.onReceive(receiveEvent);
  lcd.begin(16, 2);
  lcd.print("Receiver");
}

void receiveEvent(int bytes) {
  x = Wire.read(); // read I2C received character

}

void loop() {
  lcd.setCursor(0, 1); // display received character
  lcd.print(x);
  Serial.println(x);
}