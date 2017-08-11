const int LED1=10;     //9번 핀을 사용하는 LED 상수 정의
const int BUTTON1=2;   //버튼을 2번 핀에 지정
const int LED2=11;     //9번 핀을 사용하는 LED 상수 정의
const int BUTTON2=3;   //버튼을 2번 핀에 지정

boolean lastButton1=LOW;   //이전 버튼의 눌림 상태를 Boolean형 변수로 선언
boolean currentButton1=LOW; //현재 버튼의 눌림 상태를 Boolean형 변수로 선언
int ledOn1=0;   
boolean lastButton2=LOW;   //이전 버튼의 눌림 상태를 Boolean형 변수로 선언
boolean currentButton2=LOW; //현재 버튼의 눌림 상태를 Boolean형 변수로 선언
int ledOn2=0;  
boolean flag1=false;
boolean flag2=false;
void setup()
{
    pinMode(LED1, OUTPUT);   //LED(9번 핀)를 출력으로 지정
    pinMode(BUTTON1, INPUT); //BUTTON(2번 핀)을 입력으로 지정
    pinMode(LED2, OUTPUT);   //LED(9번 핀)를 출력으로 지정
    pinMode(BUTTON2, INPUT); //BUTTON(2번 핀)을 입력으로 지정
}
/*
* 스위치 디바운싱 함수
* debounce() 함수에 이전 버튼 상태를 인수로 사용하여
* 디바운싱 처리된 현재 버튼 상태값을 반환
*/

boolean debounce1(boolean last1)
{
    boolean current1=digitalRead(BUTTON1); //현재 버튼 상태를 확인
    if(last1!=current1) //이전 버튼 상태와 현재 버튼 상태가 다름
    {
        delay(5); //5ms 동안 기다림
        current1=digitalRead(BUTTON1); //current에 현재 버튼 상태를 저장
    }
    return current1; //current 변수값을 반환
}

boolean debounce2(boolean last2)
{
    boolean current2=digitalRead(BUTTON2); //현재 버튼 상태를 확인
    if(last2!=current2) //이전 버튼 상태와 현재 버튼 상태가 다름
    {
        delay(5); //5ms 동안 기다림
        current2=digitalRead(BUTTON2); //current에 현재 버튼 상태를 저장
    }
    return current2; //current 변수값을 반환
}


void loop()
{   delay(10);
    currentButton1=debounce1(lastButton1); //디바운싱 처리된 버튼값을 읽음
    if(lastButton1==LOW && currentButton1==HIGH) //버튼을 누름
    {
        flag1=!flag1;
    }
    lastButton1=currentButton1; //이전 버튼값을 현재 버튼값으로 변경
    if(flag1==true){
    analogWrite(LED1, ledOn1%256); //LED 점멸 상태를 바꿈
    ledOn1++;
    }
    else
    analogWrite(LED1, 0); //LED 점멸 상태를 바꿈
    
    currentButton2=debounce2(lastButton2); //디바운싱 처리된 버튼값을 읽음
    if(lastButton2==LOW && currentButton2==HIGH) //버튼을 누름
    {
        flag2=!flag2;
    }
    
    lastButton2=currentButton2; //이전 버튼값을 현재 버튼값으로 변경
    if(flag2==true){
    analogWrite(LED2, ledOn2%256); //LED 점멸 상태를 바꿈
    ledOn2++;
    }
    else
    analogWrite(LED2, 0); //LED 점멸 상태를 바꿈
    
}

