#include <LiquidCrystal.h>

int speakerpin = 8; //스피커가 연결된 디지털핀 설정
int note[] = {2093,2349,2637,2793,3136,3520,3951,4186};

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("Maroro, world!");
}
void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
// print the number of seconds since reset:
int t=millis()/1000;
lcd.print(t);
if(t>9)
if(t%10==0){
tone(speakerpin,500,500);
//for(int i=0;i<10;i++){
//tone(speakerpin,note[6]);
//delay(50);
//tone(speakerpin,note[7]);
//delay(50);
//}
}
}
