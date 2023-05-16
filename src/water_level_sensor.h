#pragma once
#include "Arduino.h"

class WaterLevelSensor
{
public:
  WaterLevelSensor(byte trig_pin, byte echo_pin) : m_trig_pin{trig_pin}, m_echo_pin{echo_pin}
  {
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
  }

  float meassure()
  {
    digitalWrite(m_trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(m_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(m_trig_pin, LOW);

    int duration = pulseIn(m_echo_pin, HIGH, 60000);
    int distance = int((duration * .0343) / 2 * 10);

    return distance;
  }

private:
  byte m_trig_pin;
  byte m_echo_pin;
};