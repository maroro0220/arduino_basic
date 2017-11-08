#define SENSOR 3 //디지털 핀 설정
//#define LED 13 //led 핀설정
#define BAUD 9600 //통신속도 설정
void setup() {
//  pinMode(LED,OUTPUT);
  pinMode(SENSOR,INPUT);
  Serial.begin(BAUD);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(SENSOR))//값이 LOW이면
  {
//    digitalWrite(LED,HIGH);
    Serial.println("DETECTED");
    while(!digitalRead(SENSOR)); //LOW인동안 계속 반복
  }
  else //LOW가 아니라면
  {
//    digitalWrite(LED,LOW);
    Serial.println("UNDETECTED");
    while(digitalRead(SENSOR)); // HIGH인동안 계속 반복
  }
  delay(100);
}
