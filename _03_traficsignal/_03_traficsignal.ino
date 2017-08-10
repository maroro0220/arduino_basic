int REDpin=6;
int YELLOWpin=5;
int GREENpin=4;
int BLUEpin=7;
void setup() {
  // put your setup code here, to run once:
pinMode(REDpin,OUTPUT);
pinMode(YELLOWpin,OUTPUT);
pinMode(GREENpin,OUTPUT);
pinMode(BLUEpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int i=0;
int count=4;
for(i;i<8;i++){
if(i<=3){
digitalWrite(count,HIGH);
delay(500);
digitalWrite(count,LOW);
count++;
}
else{
  if(i==4)
  count--;
count--;
digitalWrite(count,HIGH);
delay(500);
digitalWrite(count,LOW);

}
}
}
