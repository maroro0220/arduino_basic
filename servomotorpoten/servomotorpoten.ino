#include <Servo.h>
Servo myservo; // 서보 오브젝트를 생성
// myservo는 변경할 수 있음
int potpin = 0;
int val;
void setup()
{
myservo.attach(6); // 11번에 모터를 연결
Serial.begin(9600);
}
void loop()
{
val = analogRead(potpin);
// 포텐쇼미터로부터 값을 읽음
val = map(val, 0, 1023, 0, 180);
// 읽은 값 (0~1023)을 0~179로 매칭시킴

myservo.write(val); // 모터를 회전시킴
Serial.println(val); 
delay(150);
}
