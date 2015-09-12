#pragma once

#include <process.h>
#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <Synchapi.h>

#define tankCapacity 50 // macro definition of the capacity of the fuel tank, we use a macro definition here to ensure that we can easily modify this value
#define idlePressure 0.3  //Minimum fuel pressure
#define tempFuelStart 40

class engine
{
private:
	int speed; //vehicle speed
	bool active; //Stores if the engine is on or off, true if engine is on, false if engine is off

public:
	void setSpeed(int);
	engine();
	~engine();
	int getSpeed();
	bool engineStatus();
	bool startEngine();
	bool stopEngine();
};

class fuelTank
{

private:
	float currentVolume = tempFuelStart;
	float capacity = tankCapacity;
	bool isPetrol; //true if is petrol, false if it is diesel

public:
	fuelTank();
	~fuelTank();
	void setFuel(float);
	float getCapacity();
	int getCurrentFuelLevelPercent();
	float getCurrentFuelLevel();
	void addFuel(float, bool);
	bool getFuelIsPetrol();

};
class fuelPump
{
private:
	float pressure = idlePressure;
	bool isPetrol;

public:
	fuelPump();
	~fuelPump();
	float getPressure();
	bool fuelIsPetrol();
	void setPressure(float);
	void setFuelIsPetrol(bool);
};

//Create instances
engine& theEngine();
fuelTank& theFuelTank();
fuelPump& theFuelPump();
//Declare an instance of an engine, fuel tank and fuel pump globally
HANDLE& theOutputMutex();


//Need to do a couple of manager functions as well

unsigned int __stdcall engineManager(void* data); //Makes requests for fuel to the fuelPump when engine is active and based on speed - also check if there is fuel in the first place
unsigned int __stdcall  fuelPumpManager(void* data); //Gets fuel from  the fuel tank, based on pressure update the value of the tank
unsigned int __stdcall  fuelTankManager(void* data); //make calls to car control panel as the fuel level goes down...
