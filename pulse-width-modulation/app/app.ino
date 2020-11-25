const int firstLed = 3;
const int onDelaySeconds = 100;
const int offDelaySeconds = 200;

void setup()
{
  pinMode(firstLed, OUTPUT);
}

void loop()
{
  digitalWrite(firstLed, HIGH);
  delay(500);
  digitalWrite(firstLed, LOW);
  delay(500);
}
