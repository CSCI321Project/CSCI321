#include "Coolant.h"
#include "fuel.h"
using namespace std;


HANDLE& allowCoolantTankLevelModification()
{
	static HANDLE allowCoolantTankLevelModification;
	return allowCoolantTankLevelModification;
}

HANDLE& allowEngineCoolantLevelModification()
{
	static HANDLE allowEngineCoolantLevelModification;
	return allowEngineCoolantLevelModification;
}
HANDLE& allowRadiatorCoolantLevelModficiation()
{
	static HANDLE allowRadiatorCoolantLevelModficiation;
	return allowRadiatorCoolantLevelModficiation;
}

coolantReservoir::coolantReservoir()
{
	currentTemperature = defaultTemp;
	currentVolume = defaultCurrentVol;
	capacity = defaultCapacity;

}
coolantReservoir::~coolantReservoir()
{
	//Nothing to do in the destructor
}
void coolantReservoir::setCurrentVolume(float newCurrentVolume)
{
	currentVolume = newCurrentVolume;
}
void coolantReservoir::addToReservoir(float amountToAdd) //Used to channel coolant back into the reservoir
{
	currentVolume = currentVolume + amountToAdd;
}
void coolantReservoir::reduceFromReservoir(float amountToReduce) //Used by the coolant pump to get coolant out
{
	currentVolume = currentVolume - amountToReduce;
}
float coolantReservoir::getCurrentVolume()
{
	return currentVolume;
}
void coolantReservoir::setCapacity(float newCapacity)
{
	capacity = newCapacity;
}
float coolantReservoir::getCapacity()
{
	return capacity;
}
void coolantReservoir::setTemperature(float newTemperature) //By the reservoir
{
	currentTemperature = newTemperature;
}
float coolantReservoir::getTemperature()
{
	return currentTemperature;
}

//Function to actually modulate when coolant is being returned...
void coolantReservoir::returnToReservoir(float amountReturned, float temperatureOfReturned)
{
	//The idea would be that we actually would have to calculate the new temperature of the coolant in the reservoir
	//based on the total amount of heat in the reservoir and the amount of heat in the coolant fluid returned

	//Calculate amount of heat in the reservoir - rudimental way to calculate the amount of heat but basically amount * temperature
	float reservoirHeatContent = currentTemperature * currentVolume;

	float returnedFluidHeatContent = amountReturned * temperatureOfReturned;

	//note that all volumes here are in litres

	//From here, calculate the sum of heat...
	float sumOfHeat = reservoirHeatContent + returnedFluidHeatContent;
	float sumOfFluid = amountReturned + currentVolume;

	

	if ((sumOfFluid == 0) && (sumOfHeat == 0))
	{
		//Override a delete by 0

	}
	else
	{
		//Only if not a delete by 0,
		//And now, just find the average heat per litre of fluid - essentially the temperature, heat per unit liquid
		float finalTemperature = sumOfHeat / sumOfFluid;

		//Now, we can just add the fluid back in and set the new temperature

		addToReservoir(amountReturned);
		setTemperature(finalTemperature);
	}
	
}

coolantPump::coolantPump()
{
	//Constructor
	//Initialise the temperature detected by the coolant pump to be whatever from the coolant reservoir
	//pressure should be set to 0
	flowAmount = defaultFlow;
	temperature = theCoolantReservoir().getTemperature();
}
coolantPump::~coolantPump()
{
	//Nothing to do in the destructors
}
void coolantPump::setFlowAmt(float newFlow)
{
	flowAmount = newFlow;
}
float coolantPump::getFlowAmt()
{
	return flowAmount;
}
void coolantPump::setTemperature(float newTemperature)
{
	temperature = newTemperature;
}
float coolantPump::getTemperature()
{
	return temperature;
}


radiator::radiator()
{
	//constructor for the radiator
	coolDown = true; // we want to cool the coolant down
	amountOfCoolant = 0; //radiator is initially empty
	coolantTemperature = 0; // since no coolant so there isnt any temperature anyway...
}
radiator::~radiator()
{
	//Destructor
	//Nothing to do here...
}
void radiator::addCoolant(float amountToAdd, float tempOfCoolantAdded)
{
	//need to do some thermodynamics here...

	//Calculate amount of heat in the th - rudimental way to calculate the amount of heat but basically amount * temperature
	float radiatorHeatContent = amountOfCoolant * coolantTemperature;

	float addedCoolantHeatContent = amountToAdd * tempOfCoolantAdded;

	//note that all volumes here are in litres

	//From here, calculate the sum of heat...
	float sumOfHeat = radiatorHeatContent + addedCoolantHeatContent;
	float sumOfFluid = amountOfCoolant + amountToAdd;

	//And now, just find the average heat per litre of fluid - essentially the temperature, heat per unit liquid
	float finalTemperature = sumOfHeat / sumOfFluid;

	//If a 0/0 happened, we need to override that
	if ((sumOfFluid == 0) && (sumOfHeat == 0))
	{
		//Set everything to 0...
		amountOfCoolant = 0;
		coolantTemperature = 0;
	}
	else
	{
		//Finally, set our new temperatures and new volume of coolant in the there...
		amountOfCoolant = sumOfFluid;
		coolantTemperature = finalTemperature;
	}
}
void radiator::reduceCoolant(float amountToReduce)
{
	amountOfCoolant = amountOfCoolant - amountToReduce;
}
void radiator::setCoolantAmount(float coolantAmount, float tempOfCoolant)
{
	amountOfCoolant = coolantAmount;
	coolantTemperature = tempOfCoolant;

	//This is only used as a way if we want to override the regular add function. Otherwise we should NOT be using this function...
}
float radiator::getCoolantAmount()
{
	return amountOfCoolant;
}
float radiator::getTemperature()
{
	return coolantTemperature;
}
void radiator::setTemperature(float temp)
{
	coolantTemperature = temp;
}

void radiator::setCoolDown(bool status)
{
	coolDown = status;
}
bool radiator::getCoolDown()
{
	return coolDown;
}

coolantPump& theCoolantPump()
{
	static coolantPump myCoolantPump;
	return myCoolantPump;
}
coolantReservoir& theCoolantReservoir()
{
	static coolantReservoir myCoolantReservoir;
	return myCoolantReservoir;
}
radiator& theRadiator()
{
	static radiator myRadiator;
	return myRadiator;
}

unsigned int __stdcall coolantPumpManager(void* data)
{
	//Get coolant from the coolant reservoir and send to the engine
	for (;;)
	{
		//If engine is off, the coolantPump should be off
		if (theEngine().engineStatus() == false)
		{
			//Therefore coolantPump should be off
			theCoolantPump().setFlowAmt(0);
		}
		else
		{
			//Coolant pump should be on
			//Pump will supply at a constant rate...

			theCoolantPump().setFlowAmt(1.5); // remember we are using litres here...

			//Reduce the amount from the coolant tank
			WaitForSingleObject(allowRadiatorCoolantLevelModficiation(), INFINITE);
			theCoolantReservoir().reduceFromReservoir(1.5);

			//Update the temperature of the coolant being detected by the coolant pump
			theCoolantPump().setTemperature(theCoolantReservoir().getTemperature());
			ReleaseMutex(allowRadiatorCoolantLevelModficiation());
			
			

			// Add to the engine...
			//Encase this in a mutex...
			WaitForSingleObject(allowEngineCoolantLevelModification(), INFINITE);
			theEngine().addCoolant(1.5, theCoolantPump().getTemperature());
			ReleaseMutex(allowEngineCoolantLevelModification());

		}

		//Sleep
		Sleep(500); //Don't want to query it always, once every half second should be fine...
	}
}
unsigned int __stdcall coolantReservoirManager(void* data)
{
	//Nothing much really?
	for (;;)
	{
		WaitForSingleObject(theOutputMutex(), INFINITE);

		cout << endl << "Coolant reservoir temp : " << theCoolantReservoir().getTemperature() << endl;

		ReleaseMutex(theOutputMutex());
		Sleep(1000);
	}
	return 0;
}
unsigned int __stdcall radiatorManager(void* data)
{

	//Note we should probably encase this in a mutex to prevent coolant being added while it is being reduced...
	float temperature;
	//Check if the user wants to simulate an overheat
	//if no, then reduce the temperature of the coolant in the radiator, else, do not reduce the temperature (action controlled by bool variable of the radiator)

	for (;;)
	{
		//Infinite loop this...
		//Lock to ensure only one is modifying the radiator's values...
		WaitForSingleObject(allowRadiatorCoolantLevelModficiation(), INFINITE);
		WaitForSingleObject(allowCoolantTankLevelModification(), INFINITE);


		if (theRadiator().getCoolDown() == true)
		{

			WaitForSingleObject(theOutputMutex(), INFINITE);
			cout << endl << "Cool down!!!"  << endl;
			ReleaseMutex(theOutputMutex());

			//We want to cool down the coolant and not simulate an overheat
			//Reduce the temperature of the coolant in the radiator
			if ((theRadiator().getCoolantAmount() != 0) && (theEngine().engineStatus() == true))
			{
				//Only if not empty...

				temperature = theRadiator().getTemperature();

				WaitForSingleObject(theOutputMutex(), INFINITE);
				cout << endl << "Old Radiator Temp" << theRadiator().getTemperature() << endl;
				ReleaseMutex(theOutputMutex());

				//Reduce the temperature
				temperature = temperature - tempReduction;

				//If the temperature goes below 35, then set it to 35, since it should not be able to below ambient temperature

				if (temperature < ambientTemperature)
				{
					//Set temperature to ambient temperature
					temperature = ambientTemperature;
				}
				theRadiator().setTemperature(temperature);

				WaitForSingleObject(theOutputMutex(), INFINITE);
				cout << endl << "New Radiator Temp" << theRadiator().getTemperature() << endl;
				ReleaseMutex(theOutputMutex());

				//Now that we have reduced the temperature, we now have to actually return the coolant back to the reservoir
			}
			

		}

		if (theRadiator().getCoolantAmount() != 0)
		{
			//If not empty
			//return to reservoir
			theCoolantReservoir().returnToReservoir(theRadiator().getCoolantAmount(), theRadiator().getTemperature());

			//Update the amount of coolant in the radiator
			theRadiator().reduceCoolant(theRadiator().getCoolantAmount());
		}

		ReleaseMutex(allowRadiatorCoolantLevelModficiation());
		ReleaseMutex(allowCoolantTankLevelModification());
		//Sleep
		Sleep(500); //Don't want to query it always, once every half second should be fine...

	}

}
	
