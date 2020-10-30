#ifndef sensors_h
#define sensors_h

#include <collections.h>

class SensorBase
{
  protected:
    unsigned short state;
    const unsigned short maxValue = 1024;
    const unsigned short minValue = 0;
  public:
    SensorBase();
    ~SensorBase();
    unsigned short getState();
    void setState(unsigned short);
    virtual void updateState();
};

class ToggleSensor : public SensorBase
{
  private:
    unsigned short sensorPin;
  public:
    ToggleSensor(unsigned short);
    ~ToggleSensor();
    unsigned short getState();
    void setState(unsigned short);
    void updateState();
};

class StepSensor : public SensorBase
{
  private:
    unsigned short sensorPin1;
    unsigned short sensorPin2;
    bool pinValue1;
    bool pinValue2;
  public:
    StepSensor(unsigned short, unsigned short);
    ~StepSensor();
    unsigned short getState();
    void setState(unsigned short);
    void updateState();
};

class SensorsManager
{
  private:
    static bool isChanged;
    static SensorsManager* instance;
    unsigned short value;
    List<SensorBase> sensors;
    SensorsManager();
  public:
    void add(SensorBase);
    void updateState();
    unsigned short getState();
    static SensorsManager* getInstance();
};

#endif
