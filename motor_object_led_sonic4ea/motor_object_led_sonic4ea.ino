
#define ENA 2
#define LEFT_A1 3 //왼쪽 바퀴
#define LEFT_A2 4 //왼쪽 바퀴

#define RIGHT_B1 5 //오른쪽 바퀴
#define RIGHT_B2 6 //오른쪽 바퀴
#define ENB 7

#define SPEED 90
//초음파 센서 PIN 설정

#define SONIC_FRONT_R_ECHO 8
#define SONIC_FRONT_R_TRIG 9
#define SONIC_FRONT_L_ECHO 10
#define SONIC_FRONT_L_TRIG 11

#define LED1 12
#define LED2 13

#define SONIC_BACK_R_ECHO A0
#define SONIC_BACK_R_TRIG A1
#define SONIC_BACK_L_ECHO A2
#define SONIC_BACK_L_TRIG A3
void setup() {
  Serial.begin(9600);   //시리얼모니터 
 
  //모터 핀모드 설정
  pinMode(LEFT_A1, OUTPUT);
  pinMode(LEFT_A2, OUTPUT);
  
  pinMode(RIGHT_B1, OUTPUT);
  pinMode(RIGHT_B2, OUTPUT);  
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(SONIC_FRONT_R_ECHO, INPUT);
  pinMode(SONIC_FRONT_R_TRIG, OUTPUT);
  pinMode(SONIC_FRONT_L_ECHO, INPUT);
  pinMode(SONIC_FRONT_L_TRIG, OUTPUT);
  
  pinMode(SONIC_BACK_R_ECHO, INPUT);
  pinMode(SONIC_BACK_R_TRIG, OUTPUT);
  pinMode(SONIC_BACK_L_ECHO, INPUT);
  pinMode(SONIC_BACK_L_TRIG, OUTPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

 volatile int tim,tim1;
 //volatile int SPEED;
volatile int cnt;
void loop() {
 float durationfr, distancefr,durationfl, distancefl;
 float durationbl, distancebl,durationbr, distancebr;
 
 //==========Front R=============
  digitalWrite(SONIC_FRONT_R_TRIG, HIGH);
  delay(10);
  digitalWrite(SONIC_FRONT_R_TRIG, LOW);
 
  // echoPin 이 HIGH를 유지한 시간
  durationfr = pulseIn(SONIC_FRONT_R_ECHO, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠주면 거리가 cm 로 나옴
  distancefr = ((float)(340 * durationfr) / 10000) / 2;
  Serial.print("\nDIstancefr : ");
  Serial.println(distancefr);

 //==========Front L=============
  digitalWrite(SONIC_FRONT_L_TRIG, HIGH);
  delay(10);
  digitalWrite(SONIC_FRONT_L_TRIG, LOW);
 
  // echoPin 이 HIGH를 유지한 시간
  durationfl = pulseIn(SONIC_FRONT_L_ECHO, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠주면 거리가 cm 로 나옴
  distancefl = ((float)(340 * durationfl) / 10000) / 2;
  Serial.print("\nDIstancefl : ");
  Serial.println(distancefl);


 //==========BACK R=============
  digitalWrite(SONIC_BACK_R_TRIG, HIGH);
  delay(10);
  digitalWrite(SONIC_BACK_R_TRIG, LOW);
 
  // echoPin 이 HIGH를 유지한 시간
  durationbr = pulseIn(SONIC_BACK_R_ECHO, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠주면 거리가 cm 로 나옴
  distancebr = ((float)(340 * durationbr) / 10000) / 2;
  Serial.print("\nDIstancebr : ");
  Serial.println(distancebr);

 //==========BACK L=============

  digitalWrite(SONIC_BACK_L_TRIG, HIGH);
  delay(10);
  digitalWrite(SONIC_BACK_L_TRIG, LOW);
 
  // echoPin 이 HIGH를 유지한 시간
  durationbl = pulseIn(SONIC_BACK_L_ECHO, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠주면 거리가 cm 로 나옴
  distancebl = ((float)(340 * durationbl) / 10000) / 2;
  Serial.print("\nDIstancebl : ");
  Serial.println(distancebl);
//======================End==================

  if(distancefl<10 || distancefr<10) {         //장애물 감지 
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);

    Serial.println("\nstop");
     stop1();  //정지(1초)
     Serial.println("\nbackward\ndetect");
     tim=6;
     backward();  //후진(0.5초)
     tim=random(1,6);   
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();
     }else{
        Serial.println("left");
        left();
  }
  Serial.println("\nfront detect finish");
   }

   
  else if(distancebl<10 || distancebr<10) {         //뒤장애물 감지 
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);

    Serial.println("\nstop");
     stop1();  //정지(1초)
     Serial.println("\nbackward\ndetect");
     tim=6;
     forward();  //전진(0.5초)
     tim=random(1,6);
     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
     if(rnd == 0){
        Serial.println("right");
        right();
     }else{
        Serial.println("left");
        left();
  }
  Serial.println("\nback detect finish");
   }
   

   
   else{         //장애물 없음
   digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
   tim=random(1,4);   
 //  SPEED=random(80,90);
     int rm=random(4);
     int n=random(1,2);
     delay(100);
 switch(rm){
  cnt++;
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
      backward();
      break;

  }
  if(cnt>=30){
 Serial.print("\nstop");
      tim1=random(1,5);
  stop1(); 
  cnt=0;
  }

   }
   }
   

void forward(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_A2, LOW);
  digitalWrite(RIGHT_B1, HIGH);
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
  digitalWrite(LEFT_A2, HIGH);
  digitalWrite(RIGHT_B1, LOW);
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
  digitalWrite(LEFT_A2, HIGH);
  digitalWrite(RIGHT_B1, HIGH);
  digitalWrite(RIGHT_B2, LOW);
  analogWrite(ENA, SPEED);
  analogWrite(ENB, SPEED);       
   Serial.print(tim);
  delay(500*tim);
}
void right(){
  digitalWrite(LEFT_A1, HIGH);
  digitalWrite(LEFT_A2, LOW);
  digitalWrite(RIGHT_B1, LOW);
  digitalWrite(RIGHT_B2, HIGH);
   analogWrite(ENA, SPEED);
   analogWrite(ENB, SPEED);       Serial.print(tim);
  delay(500*tim);
}
void stop1(){
  digitalWrite(LEFT_A1, LOW);
  digitalWrite(LEFT_A2, LOW);
  digitalWrite(RIGHT_B1, LOW);
  digitalWrite(RIGHT_B2, LOW);
  delay(1000*tim1);
}




