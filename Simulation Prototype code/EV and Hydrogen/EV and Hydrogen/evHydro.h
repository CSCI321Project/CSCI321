#include <iostream>
#include <Windows.h>
#include <synchapi.h>

#define defaultEvBatteryCapacity 100
#define defaultStackPressure 0
#define defaultHydrogenTankCapacity 100
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

class hydrogenMotor
{
private:
	int speed;
	bool active;
	float incline;

public:
	hydrogenMotor();
	~hydrogenMotor();
	void setSpeed(int);
	int getSpeed();
	void startMotor();
	void stopMotor();
	bool returnStatus();
	void setIncline(float);
	float getIncline();
	void reset();
};

class hydrogenStack
{
	//Acts as the equivalent to the fuel pump
	//In real life it converts the hydrogen to electricity

private:
	float pressure; //more hydrogen coming in, more electricity

public:
	hydrogenStack();
	~hydrogenStack();
	void setPressure(float);
	float getPressure();
	void reset();
};

class hydrogenTank
{
private:
	float capacity;
	float currentLevel;

	public:
		hydrogenTank();
		~hydrogenTank();
		void setCapacity(float);
		float getCapacity();
		void setCurrentLevel(float);
		float getCurrentLevel(); //note that since the tank capacity is 100, hence technically it is a percent value already
		void reduceCurrentLevel(float);
		void topUpHydrogen(float);
		void reset();
};

hydrogenMotor& theHydrogenMotor();
hydrogenStack& theHydrogenStack();
hydrogenTank& theHydrogenTank();

unsigned int __stdcall hydrogenMotorManager(void* data);
unsigned int __stdcall hydrogenStackManager(void* data);
unsigned int __stdcall hydrogenTankManager(void* data);