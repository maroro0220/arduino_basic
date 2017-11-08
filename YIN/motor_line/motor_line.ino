// IN1, IN2, ENA (D2, D4, D5), IN3, IN4, ENB (D7, D8, D9)
//http://www.hardcopyworld.com/ngine/aduino/index.php/archives/159
#define IN1 2
#define IN2 4
#define ENA 5

#define IN3 9
#define IN4 7
#define ENB 6
#define SPEED 150
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //attachInterrupt(1, lineBackward, RISING);
  Serial.begin(9600);
}
int line;
  void lineBackward(){
       Backward(150);
    delay(5000);
    }
void Forward(int speed){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, speed);
  }
  void Backward(int speed){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, speed);
    }
    void Left(int speed){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENB, speed);
      }
      void Right(int speed){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, speed);
        
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, speed);
        }
        void Stop(int speed){
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
          }
void loop() {
  Stop(SPEED);
  delay(1000);
  int ir ;

// int line;
 // ir= analogRead(0)/700;
  //  Serial.println(ir);
  //line=ir;
  //if(!line){
    //while(analogRead(0)>=800){
        int rm=random(5);
  int tim=random(3,10);
      Serial.println(analogRead(0)/700);
    Serial.print("random: ");
    Serial.print(rm);
    Serial.print("\n tim: ");
    Serial.print(tim);
  switch(rm){
    case 0:
    Serial.print("\nForward");
      Forward(SPEED);
      delay(1000*tim);
      break;
    case 1:
    Serial.print("\Backward");
      Backward(SPEED);
      delay(1000*tim);
      break;
    case 2:
    Serial.print("\nLeft");
      Left(SPEED);
      delay(500*tim);
      break;
    case 3:
    Serial.print("\nRight");
      Right(SPEED);
      delay(500*tim);
      break;
    case 4:
    Serial.print("\nStop");
      Stop(SPEED);
      delay(100*tim);
      break;
  }
//  }
 // }
// while(analogRead(0)<800){
 //        Serial.println(analogRead(0));
//  Backward(150);
//   delay(5000);
//  }
 // else if(line){
 //   Backward(150);
 //   delay(5000);
//    line=!line;
//    }
  
}
