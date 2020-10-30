#include "sensors.h"

SensorBase::SensorBase()
{
  this -> state = 0;
}

unsigned short SensorBase::getState()
{
  return this -> state;
};

void SensorBase::setState(unsigned short value)
{
  this -> state = value % maxValue;
};

void SensorBase::updateState() { }
