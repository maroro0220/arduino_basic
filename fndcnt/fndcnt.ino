int a=0,b=1,c=2,d=3,e=4,f=5,g=6,h=7;
int cnt=0;
void setup() {
  // put your setup code here, to run once:
pinMode(a,OUTPUT);pinMode(b,OUTPUT);pinMode(c,OUTPUT);pinMode(d,OUTPUT);
pinMode(e,OUTPUT);pinMode(f,OUTPUT);pinMode(g,OUTPUT);pinMode(h,OUTPUT);
}
void setMode(int mode){
  if(mode==0){
  digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);  digitalWrite(h,LOW);
  }
  else if(mode==1){
  digitalWrite(a,LOW);  digitalWrite(b,LOW);
  digitalWrite(c,LOW);  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);  digitalWrite(h,LOW);    
    }
  else if(mode==2){
      digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==3){
      digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==4){
      digitalWrite(a,LOW);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,LOW);
  digitalWrite(e,LOW);  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==5){
      digitalWrite(a,HIGH);  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==6){
      digitalWrite(a,HIGH);  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==7){
      digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,LOW);
  digitalWrite(e,LOW);  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);  digitalWrite(h,LOW);
    }
  else if(mode==8){
      digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  digitalWrite(h,LOW);
    }
  else if(mode==9){
      digitalWrite(a,HIGH);  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);   digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  digitalWrite(h,HIGH);
    }
  }
void loop() {
 /* setMode(cnt);
  delay(300);
  cnt++;
  if(cnt>9)
  cnt=0;*/setMode(5);
  delay(300);setMode(9);
  delay(300);
  // put your main code here, to run repeatedly:

}
