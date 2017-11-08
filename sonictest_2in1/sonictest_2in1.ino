
#define TRIG A1 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO A0 //ECHO 핀 설정 (반사된 초음파 받는 핀)
 
void setup() {
  Serial.begin(9600);   //시리얼모니터 
 
  //모터 핀모드 설정

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

}
 //volatile int SPEED;

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
delay(1000);
  
   }
   

 


