#pragma once

#include <iostream>
#define tankCapacity = 50 // macro definition of the capacity of the fuel tank, we use a macro definition here to ensure that we can easily modify this value

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

	public:
		void setFuel(float);
		float getCapacity();
		int getCurrentFuelLevel();
		void addFuel(float);

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