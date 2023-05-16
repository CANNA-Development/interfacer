#include <Arduino.h>
#include <Adafruit_Sensor.h>
// #include <DHT.h>
#include "protocol.h"

#include "water_level_sensor.h"
#include "climate_sensor.h"

const int MEASSUREMENT_INTERVAL = 10; /* meassurement interval in seconds */

const byte WL1_TRIG_PIN = 3;
const byte WL1_ECHO_PIN = 4;

const byte WL2_TRIG_PIN = 5;
const byte WL2_ECHO_PIN = 6;

const byte C1_DATA_PIN = 2;

WaterLevelSensor wl1(WL1_TRIG_PIN, WL1_ECHO_PIN);
WaterLevelSensor wl2(WL2_TRIG_PIN, WL2_ECHO_PIN);

ClimateSensor c1(C1_DATA_PIN);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  auto wl1_value = wl1.meassure();
  auto wl2_value = wl2.meassure();

  auto c1_temp_value = c1.meassure_temperature();
  auto c1_hum_value = c1.meassure_humidity();

  send_message(1, wl1_value);
  send_message(2, wl2_value);
  send_message(3, c1_temp_value);
  send_message(4, c1_hum_value);
  delay(MEASSUREMENT_INTERVAL * 1000);
}