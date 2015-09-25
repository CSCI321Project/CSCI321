#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include <Synchapi.h>

#define defaultCurrentVol 5
#define defaultCapacity 5
#define defaultTemp 30
#define defaultFlow 0
#define tempReduction 30
#define ambientTemperature 35

//Declare our classes
//Need to grab the engine class from engine.h

//Note that we only use litres as the unit for measurement of all our liquids.

//In here, we only need to have a coolant reservoir and a radiator class
class coolantReservoir
{
	//Private members
	private:
		float currentVolume;
		float capacity;
		float currentTemperature;

	public:
		//Public functions
		coolantReservoir();
		~coolantReservoir();
		void setCurrentVolume(float);
		void addToReservoir(float); //Used to channel coolant back into the reservoir
		void reduceFromReservoir(float); // Used by the coolant pump
		float getCurrentVolume();
		void setCapacity(float);
		float getCapacity();
		void setTemperature(float); //By the reservoir
		float getTemperature();
		void returnToReservoir(float, float);
};

class coolantPump
{
	private:
		//Private members
		float flowAmount;
		float temperature;

	public:
		//Public functions
		coolantPump();
		~coolantPump();
		void setFlowAmt(float);
		float getFlowAmt();
		void setTemperature(float);
		float getTemperature();

};

class radiator
{
	private:
		//Private members
		bool coolDown;
		float amountOfCoolant;
		float coolantTemperature;

	public:
		radiator();
		~radiator();
		void addCoolant(float, float); // we need to specify both the amount of coolant entering the radiator, in addition to the temperature of the coolant entering
		void reduceCoolant(float);
		void setCoolantAmount(float, float);
		float getCoolantAmount();
		float getTemperature();
		void setTemperature(float);
		void setCoolDown(bool);
		bool getCoolDown();
		

};
//Declare instances of the objects
coolantPump& theCoolantPump();
coolantReservoir& theCoolantReservoir();
radiator& theRadiator();

//Also need to declare a couple of mutexes
HANDLE& allowCoolantTankLevelModification();
HANDLE& allowEngineCoolantLevelModification();
HANDLE& allowRadiatorCoolantLevelModficiation();

//Actual functions to be multithreaded...
unsigned int __stdcall coolantPumpManager(void* data);
unsigned int __stdcall coolantReservoirManager(void* data);
unsigned int __stdcall radiatorManager(void* data);



