#include "Coolant.h"

using namespace std;

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

	//And now, just find the average heat per litre of fluid - essentially the temperature, heat per unit liquid
	float finalTemperature = sumOfHeat / sumOfFluid;

	//Now, we can just add the fluid back in and set the new temperature
	addToReservoir(amountReturned);
	setTemperature(finalTemperature);
}

coolantPump::coolantPump()
{
	//Constructor
	//Initialise the temperature detected by the coolant pump to be whatever from the coolant reservoir
	//pressure should be set to 0
	pressure = defaultPressure;
	temperature = CoolantReservoir().getTemperature();
}
coolantPump::~coolantPump()
{
	//Nothing to do in the destructors
}
void coolantPump::setPressure(float newPressure)
{
	pressure = newPressure;
}
float coolantPump::getPressure()
{
	return pressure;
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
	coolantTemperature = 0 // since no coolant so there isnt any temperature anyway...
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

	//Finally, set our new temperatures and new volume of coolant in the there...
	amountOfCoolant = sumOfFluid;
	coolantTemperature = finalTemperature;
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
coolantPump& CoolantPump()
{
	static coolantPump myCoolantPump;
	return myCoolantPump;
}
coolantReservoir& CoolantReservoir()
{
	static coolantReservoir myCoolantReservoir;
	return myCoolantReservoir;
}
radiator& Radiator()
{
	static radiator myRadiator;
	return myRadiator;
}