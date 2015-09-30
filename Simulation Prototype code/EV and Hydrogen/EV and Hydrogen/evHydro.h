#include <iostream>
#include <Windows.h>
#include <synchapi.h>

#define defaultEvBatteryCapacity 100
class evMotor
{
private:
	int speed;
	bool active;
	float incline;

public:
	evMotor();
	~evMotor();
	void setSpeed(int);
	int getSpeed();
	void startMotor();
	void stopMotor();
	bool returnStatus();
	void setIncline(float);
	float getIncline();
	void reset();
};


class evBattery
{
private:
	float capacity;
	float currentLevel;

public:
	evBattery();
	~evBattery();
	void setCapacity(float);
	float getCapacity();
	void setCurrentLevel(float); //already in % value
	float getCurrentLevel();
	void reduceCurrentLevel(float);
	void rechargeBattery(float);
	void reset();
};

evMotor& theEvMotor();
evBattery& theEvBattery();

unsigned int __stdcall evMotorManager(void* data);
unsigned int __stdcall evBatteryManager(void* data);