#include <Arduino.h>
#include "sensors.h"

StepSensor::StepSensor(unsigned short pin1, unsigned short pin2)
{
  this -> sensorPin1 = pin1;
  this -> sensorPin2 = pin2;
  this -> pinValue1 = false;
  this -> pinValue2 = false;
}

StepSensor::~StepSensor() = default;

void StepSensor::setState(unsigned short value)
{
  this -> state = value;
}

void StepSensor::updateState()
{
  
}

