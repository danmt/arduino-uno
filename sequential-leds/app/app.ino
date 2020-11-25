const int firstLed = 3;
const int secondLed = 5;
const int thirdLed = 6;
const int ledCount = 3;
const int onDelaySeconds = 100;
const int offDelaySeconds = 200;
int leds[ledCount] = {firstLed, secondLed, thirdLed};

void setup()
{
  pinMode(firstLed, OUTPUT);
  pinMode(secondLed, OUTPUT);
  pinMode(thirdLed, OUTPUT);
}

void blink(int pinNumber, int onSeconds, int offSeconds)
{
  digitalWrite(pinNumber, HIGH);
  delay(onSeconds);
  digitalWrite(pinNumber, LOW);
  delay(offSeconds);
}

void blinkToRight()
{
  for (int i = 0; i < 3; i++)
  {
    blink(leds[i], onDelaySeconds, offDelaySeconds);
  }
}

void blinkToLeft()
{
  for (int i = ledCount; i >= 0; i--)
  {
    blink(leds[i], onDelaySeconds, offDelaySeconds);
  }
}

void turnLedsOff()
{
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}

void loop()
{
  for (int i = 0; i < 5; i++)
  {
    blinkToRight();
  }

  turnLedsOff();
  delay(500);

  for (int i = 0; i < 5; i++)
  {
    blinkToLeft();
  }

  turnLedsOff();
  delay(500);
}
