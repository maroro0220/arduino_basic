#define LEFT_A1 2 //왼쪽 바퀴
#define LEFT_B1 4 //왼쪽 바퀴
#define ENA 5
#define RIGHT_A2 9 //오른쪽 바퀴
#define RIGHT_B2 7 //오른쪽 바퀴
#define ENB 6
#define SPEED 90
//초음파 센서 PIN 설정
 
#define SENSOR 3 //디지털 핀 설정
 long previousMillis = 0; 
 volatile int tim;
 volatile bool intr;
 
void forward(int l,int r){
 
//       Serial.print(l);
       
//       Serial.print(r);
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
 
   analogWrite(ENA, l*25);
   analogWrite(ENB, r*25);
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
 
}
void left(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);     
   Serial.print(tim);
 
}
void right(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);    
 
 
}
void stop(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, LOW);
  
  delay(500);
}
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
//  attachInterrupt(1, motor, RISING);
  delayMicroseconds(10000);
}
 
 void motor(){
    intr=true;
    
  delayMicroseconds(10000);
  }
  int cnt=0;
    int ls=8,rs=8,cr=4;
void loop() {
 
  
  
  float duration, distance;
    if(digitalRead(SENSOR))//값이 HIGH이면
  {
 tim=random(3,10);
 
     int rm=random(4);
    // delay(100);
 if(cnt>100*cr){
  ls=random(3,7);
  rs=random(3,7);
  cr=random(5,10);
  cnt=0;
  } 
    Serial.print("\nForward\n");
      forward(ls,rs);
    Serial.print("\ncnt:");
      Serial.print(cr);
 cnt++;
  
  }
  else //LOW라면
  { Serial.println("\nstop");
     stop();  //정지(1초)
     Serial.println("\nbackward\ndetect");
     tim=3;
     backward();  //후진(0.5초)  delay(500*tim);
     
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();  
        delay(1000*tim);
       }else{
        Serial.println("left");
        left();
        delay(1000*tim);
 
  }
 
  Serial.println("\ndetect finish");
 
   }
   
}
 
