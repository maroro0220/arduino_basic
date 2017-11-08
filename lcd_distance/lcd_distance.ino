#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int TriggerPin = 8; //Trig pin
const int EchoPin = 9; //Echo pin
long Duration = 0;

void setup(){
pinMode(TriggerPin,OUTPUT);//Trigger is an output pin
pinMode(EchoPin,INPUT); // Echo is an input pin
Serial.begin(9600); // Serial Output
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("hello, world!");
}

void loop(){
 lcd.setCursor(0, 0);
digitalWrite(TriggerPin, LOW);
delayMicroseconds(2);
digitalWrite(TriggerPin, HIGH); // Trigger pin to HIGH
delayMicroseconds(10); // 10us high
digitalWrite(TriggerPin, LOW); // Trigger pin to HIGH
Duration = pulseIn(EchoPin,HIGH);
// Waits for the echo pin to get high
// returns the Duration in microseconds
long Distance_mm = Distance(Duration);
// Use function to calculate the distance
lcd.print("Distance");
lcd.setCursor(0, 1);
lcd.clear();
lcd.print(Distance_mm);
delay(700); // Wait to do next measurement

}

long Distance(long time)
{
// Calculates the Distance in mm
// ((time)*(Speed of sound))/ toward and backward of object) * 10
long DistanceCalc; // Calculation variable
DistanceCalc = ((time /2.9) / 2);
// Actual calculation in mm
//DistanceCalc = time / 74 / 2;
// Actual calculation in inches
return DistanceCalc;
// return calculated value
}
