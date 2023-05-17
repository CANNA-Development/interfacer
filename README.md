# Sensor Interfacer

This is a repository for the Sensor Interfacer on the Arduino.

This code runs on the Arduino and is responsible for reading the sensors and sending the values via the serial port. It acts as an interface between the sensors and the Raspberry Pi, allowing the Raspberry Pi to access the most recent sensor values.

## Protocol Spec v1.0.0

The protocol used for the CANNA Grow Monitor is a simple message-based protocol for sending sensor data from the Arduino to the Raspberry Pi over the serial port. As the current implementation only requires data transmission from the Arduino to the Raspberry Pi, the protocol is kept minimalistic without incorporating any command functionalities. However, it can be expanded and improved in the future to support bidirectional communication or additional features.

### Protocol Format

The protocol format consists of a start delimiter, sensor id, sensor value, and end delimiter. The start delimiter `###` indicates the beginning of a message, and the end delimiter `$$$` indicates the end of a message.

The message structure is as follows:

```
###<sensor_id>:<sensor_value>$$$
```

- `<sensor_id>` represents the id of the sensor being read.
- `<sensor_value>` represents the value read from the sensor.

Please note that this protocol is a basic implementation, designed for simplicity and efficiency in the current scope of the project. However, it can be further enhanced and customized in the future to accommodate additional features. For instance, you could consider adding a checksum for message integrity verification or an acknowledgement message (e.g., "OK") to confirm successful reception.

These enhancements can provide better reliability and error detection capabilities to the protocol, making it more robust for potential future requirements.
