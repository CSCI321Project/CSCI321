#pragma once


#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <Synchapi.h>

#define tankCapacity 50 // macro definition of the capacity of the fuel tank, we use a macro definition here to ensure that we can easily modify this value
#define idlePressure 0.3  //Minimum fuel pressure
#define tempFuelStart 40
#define baseEngineTemp 35
#define baseEngineOpsTemp 70
#define engineCoolantMaxTemp 240

class engine
{
private:
	int speed; //vehicle speed
	bool active; //Stores if the engine is on or off, true if engine is on, false if engine is off
	float coolantAmount;
	float engineTemperature;
	float coolantTemp;
	float altitude; //altitude is in kilometers, please convert to meters for ths display
	bool simCool; //false if we dont want to simulate the cooling system, else we would have this as a true

public:
	void setSpeed(int);
	engine();
	~engine();
	int getSpeed();
	bool engineStatus();
	bool startEngine();
	bool stopEngine();
	float getCoolantAmount();
	void setCoolantAmount(float, float);
	void addCoolant(float, float);
	float getCoolantTemp();
	void setCoolantTemp(float);
	float getEngineTemperature();
	void setEngineTemperature(float);
	void setAltitudeKilometres(float); //pass in the values in kilometres
	float getAltitudeKilometres();
	float getAltitudeMetres();
	void setCoolStatus(bool);
	bool returnCoolStatus();
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
