#include <OneWire.h>
#include <DallasTemperature.h>

//  Set up OneWire PIN
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

float temperature;
int fan = 5;
bool isFanOn = false;
int minTemperature = 27;
int maxTemperature = 29;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start Temperature Control System");
  pinMode(fan, OUTPUT);
}

void loop()
{
  sensor.requestTemperatures();
  temperature = sensor.getTempCByIndex(0);

  if (temperature >= maxTemperature)
  {
    Serial.println("Start fan -> " + String(temperature) + " C");
    isFanOn = true;
    digitalWrite(fan, HIGH);
  }
  else if (temperature <= minTemperature)
  {
    Serial.println("Shut down fan -> " + String(temperature) + " C");
    isFanOn = true;
    digitalWrite(fan, LOW);
  }
}