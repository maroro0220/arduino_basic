#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lm35 = A0;
void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("hello, world!");
}
void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 0);
int val = analogRead(lm35);
float dat = ((5.0*val*100.0)/1024.0); //temperature calculation
lcd.print("Temperature");
lcd.setCursor(0, 1);
lcd.print(dat);
}
