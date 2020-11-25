const int ledWithPWM = 3;

void setup()
{
}

void fadeIn(int ledId, int seconds)
{
  for (int glow = 0; glow <= 255; glow++)
  {
    analogWrite(ledId, glow);
    delay(seconds);
  }
}

void fadeOut(int ledId, int seconds)
{
  for (int glow = 255; glow >= 0; glow--)
  {
    analogWrite(ledId, glow);
    delay(seconds);
  }
}

void loop()
{
  fadeIn(ledWithPWM, 3);
  fadeOut(ledWithPWM, 3);
}
