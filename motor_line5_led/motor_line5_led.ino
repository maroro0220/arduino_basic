#define LEFT_A1 2 //왼쪽 바퀴
#define LEFT_B1 4 //왼쪽 바퀴
#define ENA 5
#define RIGHT_A2 9 //오른쪽 바퀴
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
  attachInterrupt(1, motor, RISING);

}
 volatile int tim;
 volatile bool intr;
 void motor(){
    intr=true;
  }
void loop() {
  float duration, distance;
   int ir = digitalRead(3);
  Serial.println(ir);
   int sl,sr;
   digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);
    digitalWrite(LED4,HIGH);
    digitalWrite(LED5,HIGH);
    digitalWrite(LED6,HIGH);
    digitalWrite(LED7,HIGH);
    digitalWrite(LED8,HIGH);
    digitalWrite(LED9,HIGH);
    digitalWrite(LED10,HIGH);
    digitalWrite(LED11,HIGH);
  if(intr) {         //장애물 감지 
//    delayMicroseconds(200000);
 digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    digitalWrite(LED4,LOW);
    digitalWrite(LED5,LOW);
    digitalWrite(LED6,LOW);
    digitalWrite(LED7,LOW);
    digitalWrite(LED8,LOW);
    digitalWrite(LED9,LOW);
    digitalWrite(LED10,LOW);
    digitalWrite(LED11,LOW);
   Serial.println("\nstop");
     stop();  //정지(1초)
     Serial.println("\nbackward\ndetect");
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
  Serial.println("\ndetect finish");
     intr=false;
   }
   else{         //장애물 없음
   tim=random(3,10);

     int rm=random(4);
     delay(100);
 switch(rm){
    case 0:
    Serial.print("\nForward");
      forward();
      break;
    case 1:
        Serial.print("\nRight");
      right();

      break;
    case 2:
    Serial.print("\nLeft");
      left();
      break;
    case 3:
 Serial.print("\nBackward");
      tim=1;
      backward();

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
       Serial.print(tim );delay(1000*tim);
}
void backward(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, LOW);
  digitalWrite(RIGHT_B2, HIGH);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);
       Serial.print(tim);delay(1000*tim);
}
void left(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_B1, HIGH);
  digitalWrite(RIGHT_A2, HIGH);
  digitalWrite(RIGHT_B2, LOW);
     analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       
  
   Serial.print(tim);delay(1000*tim);
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




