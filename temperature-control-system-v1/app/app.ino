#include <OneWire.h>
#include <DallasTemperature.h>

//  Set up OneWire PIN
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

const int FAN_PIN = 5;
const int MIN_TEMPERATURE = 27;
const int MAX_TEMPERATURE = 29;
float temperature;
bool isFanOn = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start Temperature Control System");
  pinMode(FAN_PIN, OUTPUT);
}

void loop()
{
  sensor.requestTemperatures();
  temperature = sensor.getTempCByIndex(0);

  if (temperature >= MAX_TEMPERATURE)
  {
    Serial.println("Start fan -> " + String(temperature) + " C");
    isFanOn = true;
    digitalWrite(FAN_PIN, HIGH);
  }
  else if (temperature <= MIN_TEMPERATURE)
  {
    Serial.println("Shut down fan -> " + String(temperature) + " C");
    isFanOn = false;
    digitalWrite(FAN_PIN, LOW);
  }
}