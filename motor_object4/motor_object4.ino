#define LEFT_A1 2 //왼쪽 바퀴
#define LEFT_B1 4 //왼쪽 바퀴
#define ENA 5
#define RIGHT_A2 9 //오른쪽 바퀴
#define RIGHT_B2 7 //오른쪽 바퀴
#define ENB 6
#define SPEED 90
//초음파 센서 PIN 설정

#define SENSOR 3 //디지털 핀 설정
 
void setup() {
  Serial.begin(9600);   //시리얼모니터 
 
  //모터 핀모드 설정
  pinMode(LEFT_A1, OUTPUT);
  pinMode(RIGHT_A2, OUTPUT);
  pinMode(LEFT_B1, OUTPUT);
  pinMode(RIGHT_B2, OUTPUT);  
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(SENSOR,INPUT);
}
 volatile int tim;
void loop() {
  float duration, distance;
   tim=random(3,10);
   int sl,sr;
  if(!digitalRead(SENSOR)) {         //장애물 감지 
     Serial.println("stop");
     stop();  //정지(1초)
     Serial.println("backward");
     tim=3;
     backward();  //후진(0.5초)
     
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();
     }else{
        Serial.println("left");
        left();
     }
   }else{         //장애물 없음
//     Serial.println("forward");
     int rm=random(4);
     delay(100);
//     forward();
 switch(rm){
    case 0:
    Serial.print("\nForward");
      forward();
//      delay(1000);
      break;
    case 1:
        Serial.print("\nRight");
      right();
   
//      delay(1000);
      break;
    case 2:
    Serial.print("\nLeft");
      left();
//      delay(500);
      break;
    case 3:
 Serial.print("\nBackward");
      tim=1;
      backward();
//      delay(500);
      break;
   
  }
   }
}
 
void forward(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
   analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);
       Serial.print(tim);
}
void backward(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);
       Serial.print(tim);
  delay(500*tim);
}
void left(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       Serial.print(tim);
  delay(1000*tim);
}
void right(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       Serial.print(tim);
  delay(1000*tim);
}
void stop(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, LOW);
  
  delay(500);
}




