#pragma once

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <Synchapi.h>

#define tankCapacity 50 // macro definition of the capacity of the fuel tank, we use a macro definition here to ensure that we can easily modify this value
#define idlePressure 0.3  //Minimum fuel pressure
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
	float currentVolume;
	float capacity = tankCapacity;
	bool isPetrol; //true if is petrol, false if it is diesel

public:
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
	float pressure;
	bool isPetrol;

public:
	fuelPump();
	~fuelPump();
	float getPressure();
	bool fuelIsPetrol();
	void setPressure(float);
	void setFuelIsPetrol(bool);
};

//Declare an instance of an engine, fuel tank and fuel pump globally
engine myEngine;
fuelTank myTank;
fuelPump myFuelPump;

//Need to do a couple of manager functions as well

void engineManager(); //Makes requests for fuel to the fuelPump when engine is active and based on speed - also check if there is fuel in the first place
void fuelPumpManager(); //Gets fuel from  the fuel tank, based on pressure update the value of the tank
void fuelTankManager(); //make calls to car control panel as the fuel level goes down...