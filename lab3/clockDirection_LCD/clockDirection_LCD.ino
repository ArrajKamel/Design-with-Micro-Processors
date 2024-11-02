//includes the LCD library
#include <LiquidCrystal.h>
#include <TimerOne.h>
#include "pitches.h"
/* LCD RS - pin 7
* LCD Enable - pinl 6
* LCD D4 - pin 5
* LCD D5 - pin 4
* LCD D6 - pin 3
* LCD D7 - pin 2
The 7-th pin of the LCD is connected to the display brightness
control potentiometer! */
// Init the LCD with the stated pin numbers
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
byte up[8] = {
B11011,
B11011,
B11011,
B11011,
B11111,
B11111,
B11111,
};

byte right[8] = {
B11111,
B11111,
B11111,
B11000,
B11111,
B11111,
B11111,
};
byte down[8] = {
B11111,
B11111,
B11111,
B11011,
B11011,
B11011,
B11011,
};

byte left[8] = {
B11111,
B11111,
B11111,
B00011,
B11111,
B11111,
B11111,
};


unsigned long time;


void setup()
{
  // Sets the no. of rows and columns of the LCD
  lcd.begin(16, 2);
  lcd.createChar(0, up);
  lcd.createChar(1, right);
  lcd.createChar(2, down);
  lcd.createChar(3, left);

  Timer1.initialize(1000000); // init the timing interval
  //for event triggering (1s = 10-6s)
  Timer1.attachInterrupt(playMusic); // The function is
  //called at the preset time interval
}


void playMusic(void){
  tone(A8, NOTE_F7 , 1000);
  noTone(A8);
}


void loop(){
  // Read the number of elapsed seconds from the program
  // start
  time = millis() / 1000;
  // Set the cursor on col 0, row 0 (first row)
  lcd.setCursor(0, 0);
  // Write a string of characters
  lcd.write(byte(0));
  // Move the cursor in the middle of the second row (row 1)
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.write(byte(1));
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.write(byte(2));
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.write(byte(3));
  delay(1000);
  // lcd.setCursor(0,0);
  // lcd.print("Inturrapts");
  
  // lcd.setCursor(0,1);
  // lcd.print("not ready YET");


}


