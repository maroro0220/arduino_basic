const int BUTTON_INT1=0;
const int BUTTON_INT2=1;
const int GREEN=11;
const int BLUE=10;
bool btn1=false;
bool btn2=false;

void setup() {
  // put your setup code here, to run once:
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  attachInterrupt(BUTTON_INT1,swap1,FALLING);
  attachInterrupt(BUTTON_INT2,swap2,FALLING);
}
void swap1(){
btn1=!btn1;
delay(100);
}
void swap2(){
btn2=!btn2;
delay(100);
}
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<256;i++){
    if(btn1==true)
    analogWrite(BLUE,i);
    
    else
    analogWrite(BLUE,0);
    
    if(btn2==true)
    analogWrite(GREEN,i);
    else
    analogWrite(GREEN,0);
    delay(10);
    }
    for(int i=255;i>=0;i--){
    if(btn1==true)
    analogWrite(BLUE,i);
    else
    analogWrite(BLUE,0);
     if(btn2==true)
    analogWrite(GREEN,i);
    else
    analogWrite(GREEN,0);
    delay(10);
    }
}
