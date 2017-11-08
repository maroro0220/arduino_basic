//아날로그 0번핀 사용
int pinNum = A0; 
//거리값 변수 생성
int distance = 0;

void setup() {
  //시리얼 통신 초기화
  Serial.begin(9600); 
  //A0번핀을 INPUT으로 설정
  pinMode (pinNum, INPUT); 
}
 
void loop() {
//  //적외선 거리 센서로 부터 측정값을 읽어온다
//  int data = analogRead(pinNum); 
//  //측정한 volt값을 0에서 5000사이의 값으로 변환
//  int volt = map(data, 0, 1023, 0, 5000);
//  //측정값을 통해 거리를 계산
//  distance = (21.61/(volt-0.1696))*1000; 
//   //거리 출력
//  Serial.println(distance);
//  //지연시간을 500ms로 설정
//  delay(500); 
#define pin A0

void setup ()
{
  Serial.begin (9600);
  pinMode (pin, INPUT);
}

void loop ()
{
  uint16_t value = analogRead (pin);
  uint16_t range = get_gp2d12 (value);
  Serial.println (value);
  Serial.print (range);
  Serial.println (" mm");
  Serial.println ();
  delay (1000);
}

uint16_t get_gp2d12 (uint16_t value)
{
  if (value < 10) value = 10;
  return ((67870.0 / (value - 3.0)) - 40.0);
}

}
