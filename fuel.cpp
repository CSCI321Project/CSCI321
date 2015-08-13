#include "fuel.h"
using namespace std;

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

void fuelTank::setFuel(float newVolume)
{
	//Replaces the current volume with a new volume
	currentVolume = newVolume;
}

float fuelTank::getCapacity()
{
	return currentVolume;
}

int fuelTank::getCurrentFuelLevel()
{
	//Calculate a percentage value of the fuel level
	int fuelLevel = (currentVolume / capacity) * 100;

	return fuelLevel;
}

void fuelTank::addFuel(float amountToAdd)
{
	//Tops off the fuel level...
	currentVolume = currentVolume + amountToAdd;
}

fuelPump::fuelPump()
{
	//Constructor
	pressure = 0;
	isPetrol = true;
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
}
void fuelPump::setFuelIsPetrol(bool newFuelStatus)
{
	//Saves a new fuel type to the fuel pump
	isPetrol = newFuelStatus;
}