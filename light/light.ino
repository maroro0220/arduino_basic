#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //LiquidCrystal(rs, enable, d4, d5, d6, d7) 
int apin=10;
int potpin=5;
//set analog interface #0 to connect photocell
int ledpin=13;
int ledpin2=7;
int val=0; //define variable val
int lm35 = A0;
int i=0;
void setup()
{
pinMode(ledpin,OUTPUT);
pinMode(ledpin2,OUTPUT);
pinMode(apin,OUTPUT);
//set digital interface #11 as output
Serial.begin(9600); //set baud rate as 9600
lcd.begin(16, 2);
}
void loop()
{int val1 = analogRead(lm35);
val=analogRead(potpin); //read analog
float dat = ((5.0*val1*100.0)/1024.0); //temperature calculation
Serial.println(val);
delay(300); //delay 0.01 s
if(val<30)
digitalWrite(ledpin,HIGH);
else
digitalWrite(ledpin,LOW);

if(dat>30)
digitalWrite(ledpin2,HIGH);
else
digitalWrite(ledpin2,LOW);

analogWrite(apin,i);
i++;
if(i>255)
i=0;

lcd.setCursor(0, 0);
lcd.print("Temper: ");
lcd.print(dat);
lcd.setCursor(0, 1);
lcd.print("Light: ");
lcd.print(val);
lcd.print(" /  ");
lcd.print(i);
}
