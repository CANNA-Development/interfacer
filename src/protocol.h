#pragma once

#include <Arduino.h>

#define START_BYTE 0x7E
#define PROTOCOL_VERSION 0x01

void send_message(byte sensor_id, float sensor_value);
