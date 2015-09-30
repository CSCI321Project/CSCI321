#include "evHydro.h"

using namespace std;

evMotor& theEvMotor()
{
	static evMotor myEvMotor;
	return  myEvMotor;
}
evBattery& theEvBattery()
{
	static evBattery myEvBattery;
	return myEvBattery;
}

evMotor::evMotor()
{
	speed = 0;
	active = false;
	incline = 0;
}
evMotor::~evMotor()
{
	//nothing to do in the destructor
}

void evMotor::reset()
{
	//Initialises the motor back again...
	speed = 0;
	active = false;
	incline = 0;
}

void evMotor::setSpeed(int newSpeed)
{
	float amountToReduce = 0;
	float amountOfChargeToReturn = 0;
	if (speed > newSpeed)
	{
		//We are decelerating.
		//Need to add the reduction of speed as battery power - regenerative braking
		//Per kilometer reduced, we would add say 0.25% of battery charge
		amountToReduce = speed - newSpeed;

		amountOfChargeToReturn = amountToReduce * 0.25;
		theEvBattery().rechargeBattery(amountOfChargeToReturn);
		cout << endl << "A total of" << amountOfChargeToReturn <<  " was returned" << endl;
		cout << endl << "level is now " << theEvBattery().getCurrentLevel() << endl;
	}

	//If we are not decelerating nothing else to do.
	speed = newSpeed;

	cout << endl << "Speed is now : " << speed << endl;
}
int evMotor::getSpeed()
{
	return speed;
}
void evMotor::startMotor()
{
	active = true;
}
void evMotor::stopMotor()
{
	active = false;
}
bool evMotor::returnStatus()
{
	return active; //true if motor is running, else is false
}
void evMotor::setIncline(float newIncline)
{
	incline = newIncline;
	cout << endl << "New incline is " << incline << endl;
}
float evMotor::getIncline()
{
	return incline;
}

evBattery::evBattery()
{
	capacity = defaultEvBatteryCapacity;
	currentLevel = defaultEvBatteryCapacity;
}

evBattery::~evBattery()
{
	//nothing to do in the destructor
}

void evBattery::reset()
{
	//Resets all values in the ev battery to the standard values
	capacity = defaultEvBatteryCapacity;
	currentLevel = defaultEvBatteryCapacity;
}

void evBattery::setCapacity(float newCapacity)
{
	capacity = newCapacity;
}
float evBattery::getCapacity()
{
	return capacity;
}
void evBattery::setCurrentLevel(float newLevel)
{
	currentLevel = newLevel;
}
float evBattery::getCurrentLevel()
{
	return currentLevel;
}
void evBattery::reduceCurrentLevel(float amountToReduce)
{
	currentLevel = currentLevel - amountToReduce;

	//Pad to ensure currentLevel doesn't go below 0
	if (currentLevel < 0)
	{
		currentLevel = 0;
	}
}
void evBattery::rechargeBattery(float amountToTopOff)
{
	currentLevel = currentLevel + amountToTopOff;
	
	//Need to mask the current level to ensure it cannot go beyond 100.
	if (currentLevel > 100)
	{
		//Mask it
		currentLevel = 100;
	}
}

unsigned int __stdcall evMotorManager(void* data)
{
	//In an EV, the speed directly manipulates the power consumption
	//if the car is not moving, no power is actually used.

	//Hence the speed will directly manipulate the power consumption
	float powerConsumption = 0;
	float speed, incline;
	for (;;)
	{
		if (theEvMotor().returnStatus() == true)
		{
			//Motor is on , need to check the speed

			//First check if the battery is flat, if it is cut off the motor
			if (theEvBattery().getCurrentLevel() == 0)
			{
				//Battery is flat, turn off motor
				theEvMotor().stopMotor();
			}

			//Altitude has no effect on the operation of an electric motor, so we can disregard it
			//We would however need to check the incline, it has an effect on the power consumption
			speed = theEvMotor().getSpeed();
			incline = theEvMotor().getIncline();

			powerConsumption = (speed / 100);

			//Add on the incline factor to the powerConsumption
			powerConsumption = powerConsumption + (incline / 10);

			cout << endl << "Power consumed: " << powerConsumption << endl;
			//Nothing else to do here...
			//Now just deduct the power used from the battery
			theEvBattery().reduceCurrentLevel(powerConsumption);
			cout << endl << "New battery level: " << theEvBattery().getCurrentLevel() << endl;

		}
		else
		{
			//Motor is not on, just proceed with the next iteration of the loop
			cout << endl << "Motor is not on" << endl;
		}

		Sleep(1000);
	}

	return 0;
}
unsigned int __stdcall evBatteryManager(void* data)
{
	//nothing really to do here
	for (;;)
	{

	}

	return 0;
}