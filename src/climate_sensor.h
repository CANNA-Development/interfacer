#pragma once
#include "Arduino.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11
#define DHTPIN 2

DHT_Unified dht(DHTPIN, DHTTYPE);

class ClimateSensor
{
public:
  ClimateSensor(byte data_pin) : m_data_pin{data_pin}
  {

    dht.begin();
  }

  float meassure_temperature()
  {
    sensors_event_t event;
    dht.temperature().getEvent(&event);

    return event.temperature;
  }

  float meassure_humidity()
  {
    sensors_event_t event;
    dht.humidity().getEvent(&event);

    return event.relative_humidity;
  }

private:
  byte m_data_pin;
};