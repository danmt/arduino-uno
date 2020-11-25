const int firstLed = 3;
const int secondLed = 5;
const int thirdLed = 6;

void setup()
{
  pinMode(firstLed, OUTPUT);
  pinMode(secondLed, OUTPUT);
  pinMode(thirdLed, OUTPUT);
}

void gradualGlow(int ledId, int glowPercentage)
{
  int offPercentage = 100 - glowPercentage;

  if (glowPercentage == 0)
  {
    glowPercentage = 1;
  }
  if (offPercentage == 0)
  {
    offPercentage = 1;
  }

  digitalWrite(ledId, HIGH);
  delayMicroseconds(glowPercentage);
  digitalWrite(ledId, LOW);
  delayMicroseconds(offPercentage);
}

void loop()
{
  gradualGlow(firstLed, 10);
  gradualGlow(secondLed, 50);
  gradualGlow(thirdLed, 100);
}
