#define pin A4

void setup ()
{
  Serial.begin (9600);
  pinMode (pin, INPUT);
}

void loop ()
{
  uint16_t value = analogRead (pin);
  uint16_t distance = get_gp2d12 (value)/10;
  Serial.print (distance);
  Serial.println (" mm");
  Serial.println ();
  delay (500);
}

uint16_t get_gp2d12 (uint16_t value)
{
  if (value < 10) value = 10;
  return ((67870.0 / (value - 3.0)) - 40.0);
}
