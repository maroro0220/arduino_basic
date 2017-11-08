const int LED=11;     //9번 핀을 사용하는 LED 상수 정의
const int BUTTON=2;   //버튼을 2번 핀에 지정

boolean lastButton=LOW;   //이전 버튼의 눌림 상태를 Boolean형 변수로 선언
boolean currentButton=LOW; //현재 버튼의 눌림 상태를 Boolean형 변수로 선언
boolean ledOn=false;   //현재 LED의 점멸 상태를 Boolean형 변수로 선언

void setup()
{
    pinMode(LED, OUTPUT);   //LED(9번 핀)를 출력으로 지정
    pinMode(BUTTON, INPUT); //BUTTON(2번 핀)을 입력으로 지정
}
/*
* 스위치 디바운싱 함수
* debounce() 함수에 이전 버튼 상태를 인수로 사용하여
* 디바운싱 처리된 현재 버튼 상태값을 반환
*/

boolean debounce(boolean last)
{
    boolean current=digitalRead(BUTTON); //현재 버튼 상태를 확인
    if(last!=current) //이전 버튼 상태와 현재 버튼 상태가 다름
    {
        delay(5); //5ms 동안 기다림
        current=digitalRead(BUTTON); //current에 현재 버튼 상태를 저장
    }
    return current; //current 변수값을 반환
}



void loop()
{
    currentButton=debounce(lastButton); //디바운싱 처리된 버튼값을 읽음
    if(lastButton==LOW && currentButton==HIGH) //버튼을 누름
    {
        ledOn=!ledOn; //LED 점멸 상태를 나타내는 ledOn 변수값을 바꿈
    }
    lastButton=currentButton; //이전 버튼값을 현재 버튼값으로 변경

    digitalWrite(LED, ledOn); //LED 점멸 상태를 바꿈
}

