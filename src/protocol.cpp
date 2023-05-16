#include <Arduino.h>
#include "protocol.h"

void send_message(byte sensor_type, float sensor_value)
{
  Serial.print("###");
  Serial.print(sensor_type);
  Serial.print(":");
  Serial.print(sensor_value);
  Serial.print("$$$");
  Serial.println();
}