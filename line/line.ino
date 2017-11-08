  void setup() {
  Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);
   attachInterrupt(1, led, HIGH);
}
 void led(){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  }
void loop() {
int ir = digitalRead(3);
  Serial.println(ir);
  delay(100);     
}
