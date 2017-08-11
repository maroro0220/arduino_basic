int digit[10] = {0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110, 0b1101101, 0b1111101, 0b0000111, 0b11111111, 0b1101111};

int digit1, digit2;


#include <OneWire.h> 

int DS18S20_Pin = 10; //DS18S20 Signal pin on digital 2

//Temperature chip i/o
OneWire ds(DS18S20_Pin); // on digital pin 2

void setup(void) {
Serial.begin(9600);
  pinMode(11, OUTPUT);//릴레이
   for (int i = 2; i < 9; i++) 
  {
    pinMode(i, OUTPUT);
  }
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);;
}

void loop(void) {
float temperature = getTemp();
if(temperature>5){
  digitalWrite(11,LOW);
  }
else{
  digitalWrite(11, HIGH);
}
Serial.println(temperature);
delay(1000); //just here to slow down the output so it is easier to read

    
    digit2 =  (int)temperature / 10;
    digit1 = (int)temperature  % 10;

      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      dis(digit2);
    //  delay(10);

      digitalWrite(13, HIGH);
     digitalWrite(12, LOW);
      dis(digit1);
   //   delay(10);

}


float getTemp(){
//returns the temperature from one DS18S20 in DEG Celsius

byte data[12];
byte addr[8];

if ( !ds.search(addr)) {
//no more sensors on chain, reset search
ds.reset_search();
return -1000;
}

if ( OneWire::crc8( addr, 7) != addr[7]) {
Serial.println("CRC is not valid!");
return -1000;
}

if ( addr[0] != 0x10 && addr[0] != 0x28) {
Serial.print("Device is not recognized");
return -1000;
}

ds.reset();
ds.select(addr);
ds.write(0x44,1); // start conversion, with parasite power on at the end

byte present = ds.reset();
ds.select(addr); 
ds.write(0xBE); // Read Scratchpad


for (int i = 0; i < 9; i++) { // we need 9 bytes
data[i] = ds.read();
}

ds.reset_search();

byte MSB = data[1];
byte LSB = data[0];

float tempRead = ((MSB << 8) | LSB); //using two's compliment
float TemperatureSum = tempRead / 16;

return TemperatureSum;

}

void dis(int num) 
{
  for (int i = 2; i < 9; i++) 
  {
    digitalWrite(i, bitRead(digit[num], i - 2));
  }
}
