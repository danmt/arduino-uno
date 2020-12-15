#include <OneWire.h>
#include <DallasTemperature.h>

//  Set up OneWire PIN
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

float temperature;

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando Sensor de Temperatura Dallas");
}

void loop()
{
  sensor.requestTemperatures();
  temperature = sensor.getTempCByIndex(0);
  Serial.println("Temperatura: " + String(temperature));
}