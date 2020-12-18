#include <OneWire.h>
#include <DallasTemperature.h>

//  Set up OneWire PIN
#define ONE_WIRE_BUS 7
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensor(&oneWire);

const int BUTTON_MIN_DOWN_PIN = 2;
const int BUTTON_MIN_UP_PIN = 3;
const int BUTTON_MAX_DOWN_PIN = 4;
const int BUTTON_MAX_UP_PIN = 5;
const int FAN_PIN = 11;
int minTemperature = 29;
int maxTemperature = 31;
float temperature;
bool isFanOn = false;
bool isMinDownPressed = false;
bool isMinUpPressed = false;
bool isMaxDownPressed = false;
bool isMaxUpPressed = false;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start Temperature Control System");
  pinMode(FAN_PIN, OUTPUT);
  pinMode(BUTTON_MIN_DOWN_PIN, INPUT);
  pinMode(BUTTON_MIN_UP_PIN, INPUT);
  pinMode(BUTTON_MAX_DOWN_PIN, INPUT);
  pinMode(BUTTON_MAX_UP_PIN, INPUT);
  sensor.setWaitForConversion(false);
  sensor.requestTemperatures();
}

void createButtonListener(int buttonPin, bool &isPressed, void callback())
{
  bool buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !isPressed)
  {
    isPressed = true;
    callback();
  }
  else if (buttonState == LOW && isPressed)
  {
    isPressed = false;
  }
}

void createTemperatureListener(void callback(float temperature))
{
  if (sensor.isConversionComplete())
  {
    temperature = sensor.getTempCByIndex(0);
    callback(temperature);
    sensor.requestTemperatures();
  }
}

void loop()
{
  // Set up Temperature Listener
  createTemperatureListener([] {
    if (!isFanOn && temperature >= maxTemperature)
    {
      Serial.println("Start fan -> " + String(temperature) + " C");
      isFanOn = true;
      digitalWrite(FAN_PIN, HIGH);
    }
    else if (isFanOn && temperature <= minTemperature)
    {
      Serial.println("Shut down fan -> " + String(temperature) + " C");
      isFanOn = false;
      digitalWrite(FAN_PIN, LOW);
    }
    else
    {
      Serial.println("Temperature is " + String(temperature) + " C. " + String(minTemperature) + '-' + String(maxTemperature));
    }
  });
  // Set up Button Listeners
  createButtonListener(BUTTON_MIN_DOWN_PIN, isMinDownPressed, [] {
    minTemperature--;
    Serial.println("Decrease Temperature Lower Bound to " + String(minTemperature) + " C");
  });
  createButtonListener(
      BUTTON_MIN_UP_PIN, isMinUpPressed, [] {
        minTemperature++;
        Serial.println("Increase Temperature Lower Bound to " + String(minTemperature) + " C");
      });
  createButtonListener(BUTTON_MAX_DOWN_PIN, isMaxDownPressed, [] {
    maxTemperature--;
    Serial.println("Decrease Temperature Upper Bound to " + String(maxTemperature) + " C");
  });
  createButtonListener(BUTTON_MAX_UP_PIN, isMaxUpPressed, [] {
    maxTemperature++;
    Serial.println("Increase Temperature Upper Bound to " + String(maxTemperature) + " C");
  });
}
