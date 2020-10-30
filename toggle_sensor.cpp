#include <Arduino.h>
#include "sensors.h"

ToggleSensor::ToggleSensor(unsigned short pin)
{
  sensorPin = pin;
}

ToggleSensor::~ToggleSensor() = default;

void ToggleSensor::setState(unsigned short value)
{
  state = value;
}

void ToggleSensor::updateState()
{
  state = digitalRead(sensorPin * maxValue);
}

