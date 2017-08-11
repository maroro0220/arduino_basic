const int TriggerPin = 11; //Trig pin
const int EchoPin = 12; //Echo pin
long Duration = 0;

int btn1=0, btn2=1;
int b9=9,b10=10;
bool dir=true;
bool start=false;
void setup(){
pinMode(TriggerPin,OUTPUT);//Trigger is an output pin
pinMode(EchoPin,INPUT); // Echo is an input pin
Serial.begin(9600); // Serial Output
pinMode(b9,OUTPUT);
pinMode(b10,OUTPUT);
//attachInterrupt(btn1,stopp,RISING);
//attachInterrupt(btn2,dirchange,RISING);
}

//void go(float dist){
//  if(dist>255)
//  dist=255;
//  if(dir==true){
///* Forward */
//analogWrite(b9,(int)dist);
//
//}
//else{
///* Backward */
//  analogWrite(b10,dist);
//  }
//}
//  void stopp(){
//  start=!start;
//    }
//void dirchange(){
//  dir=!dir;
//      }

void loop(){
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
Serial.print("Distance = "); // Output to serial
Serial.print(Distance_mm);
Serial.println(" mm");
int dist = (int)Distance_mm/2;
if(dist>255){
dist=255;}
//dist=map(dist, 0, 1500, 0, 255);
analogWrite(b9,LOW);
analogWrite(b10,dist);
delay(200); // Wait to do next measurement


//if(start==false){
///* Stop */
//digitalWrite(b9,LOW);
//digitalWrite(b10,LOW);
//delay(100);
//}
//
//else{
//delay(100);
//analogWrite(b9,LOW);
//analogWrite(b10,LOW);

//go(dist);
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
