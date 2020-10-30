#include <Arduino.h>
#include "sensors.h"

SensorsManager::SensorsManager()
{
  this -> sensors = List<SensorBase>();
}

SensorsManager* SensorsManager::getInstance()
{
    if (!instance) 
    {
        instance = new SensorsManager();
    }
    return instance;
}

void SensorsManager::add(SensorBase sensor) 
{
    this -> sensors.add(&sensor);
}

void SensorsManager::updateState()
{
  unsigned short state = 0;
  Iterator<SensorBase> iterator = sensors.getIterator();

  while (iterator.hasNext())
  {
      iterator.next() -> updateState();
  }
}
