#include "fuel.h"
using namespace std;

HANDLE& theOutputMutex()
{
	static HANDLE outputMutex;
	return outputMutex;
}

engine& theEngine()
{
	static engine myEngine;
	return myEngine;
}

fuelTank& theFuelTank()
{
	static fuelTank myTank;
	return myTank;
}

fuelPump& theFuelPump()
{
	static fuelPump myFuelPump;
	return myFuelPump;
}

void engine::setSpeed(int newSpeed)
{
	speed = newSpeed;
}

engine::engine()
{
	//Some things we need to do when the engine is first created
	active = false;
	speed = 0;
}

engine::~engine()
{
	//Nothing to do here in the destructor
}

int engine::getSpeed()
{
	//Set the speed of the engine
	return speed;
}

bool engine::engineStatus()
{
	//Query if the engine is on or off
	return active;
}

bool engine::startEngine()
{
	//Start the engine
	active = true;
	return true;
}
bool engine::stopEngine()
{
	//Turn off the engine
	active = false;
	return false;
}

fuelTank::fuelTank()
{
	currentVolume = tempFuelStart;
	capacity = tankCapacity;
	isPetrol = true;
}

fuelTank::~fuelTank()
{
	//Nothing to do here
}

void fuelTank::setFuel(float newVolume)
{
	//Replaces the current volume with a new volume
	currentVolume = newVolume;
}

float fuelTank::getCapacity()
{
	return capacity;
}

int fuelTank::getCurrentFuelLevelPercent()
{
	//Calculate a percentage value of the fuel level
	int fuelLevel = (currentVolume / capacity) * 100;

	return fuelLevel;
}

float fuelTank::getCurrentFuelLevel()
{
	return currentVolume;
}

void fuelTank::addFuel(float amountToAdd, bool isPetrolFilled)
{
	//Tops off the fuel level...
	currentVolume = currentVolume + amountToAdd;
	isPetrol = isPetrolFilled;
}

bool fuelTank::getFuelIsPetrol()
{
	//Return if there is petrol or diesel
	//If petrol this returns as true, else it will return as false
	return isPetrol;
}

fuelPump::fuelPump()
{
	//Constructor
	pressure = idlePressure;
	isPetrol = true;

	cout << endl << "Constructor has been called..." << endl;
}
fuelPump::~fuelPump()
{
	//Destructor
	//Nothing to do here
}
float fuelPump::getPressure()
{
	//Returns the current pressure set in the fuel pump
	return pressure;
}
bool fuelPump::fuelIsPetrol()
{
	//Returns if the fuel is petrol or not
	return isPetrol;

	//if return true, then it is petrol, else it is diesel
}
void fuelPump::setPressure(float newPressure)
{
	//Saves a new pressure for the fuel pump
	pressure = newPressure;

	getPressure();

}
void fuelPump::setFuelIsPetrol(bool newFuelStatus)
{
	//Saves a new fuel type to the fuel pump
	isPetrol = newFuelStatus;
}

unsigned int __stdcall engineManager(void* data)
{
	//Makes requests for fuel to the fuelPump when engine is active and based on speed - also check if there is fuel in the first place
	float pressureToSet = 0, engineFactor;
	float engineSpeed = 0;

	for (;;)
	{
		if (theEngine().engineStatus() == true)
		{
			//Engine is running
			//Request for fuel based on the speed
			//Ensure there is fuel... if there isn't, then should be that the engine cuts off now.
			if (theFuelTank().getCurrentFuelLevel() == 0)
			{
				//Fuel tank is empty
				theEngine().stopEngine();

				//Encase this cout in a mutex..

				WaitForSingleObject(theOutputMutex(), INFINITE);
				cout << endl << "Engine has run out of fuel!" << endl;
				ReleaseMutex(theOutputMutex());

				//Continue to the next iteration of the loop
				continue;
			}

			if (theFuelPump().fuelIsPetrol() == false)
			{
				//Stop the engine cause we are not using petrol anymore.
				theEngine().stopEngine();
				continue;
			}

			//By default, there is a minimum pressure for the fuel as long as the engine is idling - that is vehicle speed is 0. If not, the pressure will be proportionate to the speed
			if (theEngine().getSpeed() == 0)
			{
				//Engine is in idle
				theFuelPump().setPressure(idlePressure);

			}
			else
			{
				//Set the fuel pressure based on the engine speed
				engineSpeed = theEngine().getSpeed();
				pressureToSet = idlePressure;

				engineFactor = engineSpeed / 100;

				pressureToSet = pressureToSet + engineFactor;

				theFuelPump().setPressure(pressureToSet);
			}
		}
		else
		{
			//Engine is not on...

			//Ensure that the fuel pump pressure is set to 0
			theFuelPump().setPressure(0);
			//nothing else to do there.
		}

		//Sleep
		Sleep(500); //Don't want to query it always, once every half second should be fine...

	}
	return 0;
}
unsigned int __stdcall fuelPumpManager(void* data)
{
	//Gets fuel from  the fuel tank, based on pressure update the value of the tank

	float amountToReduce;
	float newFuelLevel;

	//The idea is that the fuel tank level will reduce faster as the fuel pressure increases...
	for (;;)
	{
		//As long as there is fuel available, we should try to get the fuel out

		//First, check and see what type of fuel we are getting
		theFuelPump().setFuelIsPetrol(theFuelTank().getFuelIsPetrol());


		//Since we know the type of fuel at the pump, the engine can then find out the type of fuel as it needs to...
		
		//Reduce the amount of fuel accordingly... Right now, we shall set the amount to be reduced is 10% of the corresponding pressure...

		amountToReduce = theFuelPump().getPressure() * 0.1;

		//Update the fuel quantity

		newFuelLevel = theFuelTank().getCurrentFuelLevel() - amountToReduce;
		

		//Note, should never let this become a negative. If it becomes a negative, pad it to 0
		if (newFuelLevel <= 0)
		{
			newFuelLevel = 0;
		}
		theFuelTank().setFuel(newFuelLevel);

		WaitForSingleObject(theOutputMutex(), INFINITE);

		cout << endl << "Pressure is " << theFuelPump().getPressure() << endl;
		cout << endl << "Amount reduced is : " << amountToReduce << endl << "Fuel level is: " << theFuelTank().getCurrentFuelLevel() << endl;

		ReleaseMutex(theOutputMutex());
		//Sleep for a while
		Sleep(500);

	}
	return 0;
}
unsigned int __stdcall  fuelTankManager(void* data)
{
	//make calls to car control panel as the fuel level goes down...

	//While there is still fuel, the pump will pull out the fuel from the tank
	//nothing much to do here for now
	for (;;)
	{

	}
	return 0;


}