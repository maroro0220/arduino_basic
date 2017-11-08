
#define ENA 3
#define LEFT_A1 2 //왼쪽 바퀴
#define LEFT_A2 4 //왼쪽 바퀴

#define RIGHT_B1 7 //오른쪽 바퀴
#define RIGHT_B2 6 //오른쪽 바퀴
#define ENB 5

#define SPEED 90
//초음파 센서 PIN 설정

#define LED1 12
#define LED2 13

#define IR_F A4
#define IR_B A5
void setup() {
  Serial.begin(9600);   //시리얼모니터 
 
  //모터 핀모드 설정
  pinMode(LEFT_A1, OUTPUT);
  pinMode(LEFT_A2, OUTPUT);
  
  pinMode(RIGHT_B1, OUTPUT);
  pinMode(RIGHT_B2, OUTPUT);  
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode (IR_F, INPUT);
  pinMode (IR_B, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

uint16_t get_gp2d12 (uint16_t value)
{
  if (value < 10) value = 10;
  return ((67870.0 / (value - 3.0)) - 40.0);
}

 volatile int tim,tim1;
volatile int cnt;
void loop() {

//=============distance===========
   uint16_t valuef = analogRead (IR_F);
   uint16_t distancef = get_gp2d12 (valuef)/10;
    
  Serial.print("\nDIstancef(cm) : ");
  Serial.println(distancef);
  
   uint16_t valueb = analogRead (IR_B);
   uint16_t distanceb = get_gp2d12 (valueb)/10;
  Serial.print("\nDIstanceb(cm) : ");
  Serial.println(distanceb);

//======================End==================

  if(distancef<80 ) {         //장애물 감지 
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

   
  else if(distanceb<80) {         //뒤장애물 감지 
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




