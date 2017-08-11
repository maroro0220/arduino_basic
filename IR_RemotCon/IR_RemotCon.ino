
/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * -0xFFE01F : 16769055
--------------------------
  +0xFFA857 : 16754775

 */

/* https://github.com/z3t0/Arduino-IRremote */
#include <IRremote.h>

int RECV_PIN = 11;

int lux=127;
IRrecv irrecv(RECV_PIN);
long pass;
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

}
int i1 = 0;
int i2 = 0;
int i3 = 0;
int i4 = 0;
int i5 = 0;

void loop() {
  if (irrecv.decode(&results)) {
    delay(10);
    Serial.print("0x");
    Serial.print(results.value, HEX);
    Serial.print(" : ");
    Serial.println(results.value);
    Serial.println("--------------------------");
    irrecv.resume(); // Receive the next value
    if(results.value==16754775){
      if(lux>255)
      lux=255;
      else
     lux+=5;
     analogWrite(3, lux*i1);
     analogWrite(5, lux*i2);
     analogWrite(6, lux*i3);
     analogWrite(9, lux*i4);
     analogWrite(10, lux*i5);
     }
     else if(results.value==16769055){
      if(lux<0)
      lux=0;
      else
      lux-=5;
     analogWrite(3, lux*i1);
     analogWrite(5, lux*i2);
     analogWrite(6, lux*i3);
     analogWrite(9, lux*i4);
     analogWrite(10, lux*i5);
      }
      Serial.println("lux :");
      Serial.println(lux);

    //button 1
    if(i1 == 0 && results.value == 16724175)
    {
      analogWrite(3,lux);
      i1 = 1;
    }
    else if(i1 == 1 && results.value == 16724175)
    {
      digitalWrite(3, LOW);
      i1 = 0;
    }
    //button 2
     else if(i2 == 0&&results.value == 16718055)
    {
      analogWrite(5, lux);
      i2 = 1;
    }
    else if(i2 == 1 && results.value == 16718055)
    {
      digitalWrite(5, LOW);
      i2 = 0;
    }
    //button 3
    else if(i3 == 0 && results.value == 16743045)
    {
       analogWrite(6, lux);
      i3 = 1;
    }
    else if(i3 == 1 && results.value == 16743045)
    {
      digitalWrite(6, LOW);
      i3 = 0;
    }
    //button 4
    else if(i4 == 0 && results.value == 16716015)
    {
      analogWrite(9, lux);
      i4 = 1;
    }
    else if(i4 == 1 && results.value == 16716015)
    {
      digitalWrite(9, LOW);
      i4 = 0;
    }
    //button 5
    else if(i5 == 0 && results.value == 16726215)
    {
      analogWrite(10, lux);
      i5 = 1;
    }
    else if(i5 == 1 && results.value == 16726215)
    {
      digitalWrite(10, LOW);
      i5 = 0;
    }
    
  }
}

