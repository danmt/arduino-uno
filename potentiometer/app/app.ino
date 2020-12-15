const int ledId = 3;
const int pontenciometerOutput = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int potentiometerReading = analogRead(pontenciometerOutput);      // get the reading from the potentiometer
  int readingAsWrite = map(potentiometerReading, 40, 1024, 1, 255); // map the reading into [1, 255]
  analogWrite(ledId, readingAsWrite);                               // write the reading into the LED
}
