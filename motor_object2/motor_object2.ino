// IN1, IN2, ENA (D2, D4, D5), IN3, IN4, ENB (D7, D8, D9)
//http://www.hardcopyworld.com/ngine/aduino/index.php/archives/159
#define IN1 2
#define IN2 4
#define ENA 5

#define IN3 9
#define IN4 7
#define ENB 6
#define SPEED 150

#define SENSOR 3 //디지털 핀 설정
 volatile int tim;
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(SENSOR,INPUT);
  //attachInterrupt(1, lineBackward, RISING);
  Serial.begin(9600);
}
int line;
//  void lineBackward(){
//       Backward(150,5);
//    delay(5000);
//    }
void Forward(int speed, int tim){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, speed);
        delay(1000*tim);
  }
  void Backward(int speed, int tim){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, speed);
      delay(1000*tim);
    }
    void Left(int speed, int tim){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, speed);
      delay(500*tim);
      }
      void Right(int speed, int tim){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, speed);
        delay(500*tim);
        }
        void Stop(){
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        delay(1000);
          }
void loop() {
  Stop();
  delay(1000);
  int ir ;

//    Serial.println(analogRead(0)/700);
//  if(distance < 20) {         //장애물 감지 (20cm 이내)
//    
//     backward();  //후진(0.5초)
//     int rnd = random(0,2);   //장애물 감지시 좌/우회전 랜덤처리
//     if(rnd == 0){
//        Serial.println("right");
//        right();
//     }else{
//        Serial.println("left");
//        left();
//     }
//   }

if(digitalRead(SENSOR)){
  int rm=random(4);
tim=random(3,10);
    Serial.print("random: ");
    Serial.print(rm);
    Serial.print("\n tim: ");
    Serial.print(tim);
  switch(rm){
    case 0:
    Serial.print("\nForward");
      Forward(SPEED,tim);
      
      break;
    case 1:
    Serial.print("\nBackward");
      Backward(SPEED,tim);
      break;
    case 2:
    Serial.print("\nLeft");
      Left(SPEED,tim);
      break;
    case 3:
    Serial.print("\nRight");
      Right(SPEED,tim);
      break;
//    case 4:
//    Serial.print("\nStop");
//      Stop(SPEED);
//      delay(100*tim);
//      break;
  }
}
else{ Serial.println("stop");
     Stop();  //정지(1초)
     Serial.println("backward");
   Backward(SPEED, 5);
  }
}

  

