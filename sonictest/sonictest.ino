#define LEFT_A1 10 //왼쪽 바퀴
#define LEFT_B1 4 //오른쪽 바퀴
#define ENA 5
#define RIGHT_A2 9 //왼쪽 바퀴
#define RIGHT_B2 7 //오른쪽 바퀴
#define ENB 6
#define SPEED 90
//초음파 센서 PIN 설정
#define LED1 8
#define LED2 10
#define LED3 11
#define LED4 12
#define LED5 13
#define LED6 A0
#define LED7 A1
#define LED8 A2
#define LED9 A3
#define LED10 A4
#define LED11 A5
//#define SENSOR 3 //디지털 핀 설정
//#define SENSOR2 2 //디지털 핀 설정
#define TRIG 3 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 2 //ECHO 핀 설정 (반사된 초음파 받는 핀)
 
void setup() {
  Serial.begin(9600);   //시리얼모니터 
 
  //모터 핀모드 설정
  pinMode(LEFT_A1, OUTPUT);
  pinMode(RIGHT_A2, OUTPUT);
  pinMode(LEFT_B1, OUTPUT);
  pinMode(RIGHT_B2, OUTPUT);  
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

   pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
}
 volatile int tim,tim1;
 volatile int intr=0;
 //volatile int SPEED;

  
     volatile int cnt;
void loop() {
 float duration, distance;
  digitalWrite(TRIG, HIGH);
  delay(10);
  digitalWrite(TRIG, LOW);
 
  // echoPin 이 HIGH를 유지한 시간
  duration = pulseIn(ECHO, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠주면 거리가 cm 로 나옴
  distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print("\nDIstance : ");
  Serial.println(distance);

  
   }
   

 
void forward(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, LOW);
   analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);
       Serial.print(tim);
       if(tim>2){
        tim=2;
        }
  delay(500*tim);
       
}
void backward(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);
       if(tim>2){
        tim=2;
        }
       Serial.print(tim);
  delay(500*tim);
}
void left(){

  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       
   Serial.print(tim);
  delay(500*tim);
}
void right(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       Serial.print(tim);
  delay(500*tim);
}
void stop1(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, LOW);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, LOW);
  delay(1000*tim1);
}




