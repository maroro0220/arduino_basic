// LED를 디지털 13번 핀에 연결합니다. 
int  led = 11;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
void setup() {
  // 디지털 13번핀을 출력 핀으로 설정합니다. 
  pinMode(led, OUTPUT);   
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행합니다.
void loop() {
  // LED를 ON 합니다.
  digitalWrite(led, HIGH);
  // 1초간 대기합니다.
  delay(1000);        
  // LED를 OFF 합니다.
  digitalWrite(led,LOW);
  // 1초간 대기합니다.
  delay(1000);    
}
