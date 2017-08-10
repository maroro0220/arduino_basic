int led8=8;
int led9=9;
int led10=10;
int bu=2;
int bd=3;
int bc=4;

int val=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);
  pinMode(led10,OUTPUT);
  pinMode(bu,INPUT);
  pinMode(bd,INPUT);
  pinMode(bc,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(val>7 || val<0)
   val=0;
   if(digitalRead(bu))
    val++;
   else if(digitalRead(bd))
    val--;
   else if(digitalRead(bc))
    val=0;
    
 Serial.println(val);    
  digitalWrite(led8,val%2);
  digitalWrite(led9,val&2);
  digitalWrite(led10,val&4);
  delay(200);
  
}
