int btn1=0, btn2=1;
int b9=9,b10=10;

bool dir=true;
bool start=false;

void setup() {
pinMode(b9,OUTPUT);
pinMode(b10,OUTPUT);
attachInterrupt(btn1,stopp,RISING);
attachInterrupt(btn2,dirchange,RISING);
}
void go(){
  if(dir==true){
/* Forward */
for(int i=0;i<256;i++){
analogWrite(b9,i);
delay(50);
}
}
else{
/* Backward */
for(int i=0;i<256;i++){
analogWrite(b10,i);
delay(50);
}

  }
  }
  void stopp(){
  start=!start;
    }
    void dirchange(){
  dir=!dir;
      }
void loop() {
if(start==false){
/* Stop */
digitalWrite(b9,LOW);
digitalWrite(b10,LOW);
delay(2000);
}
else{
delay(500);
analogWrite(b9,LOW);
analogWrite(b10,LOW);
go();}
}
