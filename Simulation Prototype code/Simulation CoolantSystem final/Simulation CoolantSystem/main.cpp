#include <iostream>
#include <process.h>
#include "fuel.h"
#include "Coolant.h"
#include "attachment.h"
using namespace std;

int main()
{
	//Multithreaded code...


	//Build the mutex
	theOutputMutex() = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);

	allowCoolantTankLevelModification() = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);
	 allowEngineCoolantLevelModification() = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);
	 allowRadiatorCoolantLevelModficiation() = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);

	 
	 //If we want to simulate an overheat, we set cooldown to false
	
	theRadiator().setCoolDown(true);


	//Prepare handles
	HANDLE engineHandle, fuelPumpHandle, fuelTankHandle, coolantReservoirHandle, radiatorHandle, coolantPumpHandle;

	engineHandle = (HANDLE)_beginthreadex(0, 0, &engineManager, 0, 0, 0);
	fuelPumpHandle = (HANDLE)_beginthreadex(0, 0, &fuelPumpManager, 0, 0, 0);
	fuelTankHandle = (HANDLE)_beginthreadex(0, 0, &fuelTankManager, 0, 0, 0);
	

	cout << endl << "Handles prepared" << endl;
	//Make the fuel tank to only have 10 liters of fuel
	theFuelTank().setFuel(15.0);

	//For testing, we want to first start the engine
	theEngine().startEngine();

	//Set the engine speed to 60
	theEngine().setSpeed(0);

	Sleep(5000);
	cout << endl << "ADDING SPEED & Attachment >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	theEngine().setSpeed(70);
	theTrailer().setStatus(true);
	theEngine().setIncline(10);
	theEngine().setAltitudeKilometres(1.5);

	Sleep(6000);
	theEngine().setCool(true);
	coolantReservoirHandle = (HANDLE)_beginthreadex(0, 0, &coolantReservoirManager, 0, 0, 0);
	radiatorHandle = (HANDLE)_beginthreadex(0, 0, &radiatorManager, 0, 0, 0);
	coolantPumpHandle = (HANDLE)_beginthreadex(0, 0, &coolantPumpManager, 0, 0, 0);
	cout << endl << "COOLING SYSTEM BEGINS" << endl;
	//Note that only around 110/120 kmh we actually hit maximum temperature of the coolant when the cooldown is false

	//Now need to wait for these objects to finish...

	WaitForSingleObject(engineHandle, INFINITE);
	WaitForSingleObject(fuelPumpHandle, INFINITE);
	WaitForSingleObject(fuelTankHandle, INFINITE);
	WaitForSingleObject(coolantReservoirHandle, INFINITE);
	WaitForSingleObject(radiatorHandle, INFINITE);
	WaitForSingleObject(coolantPumpHandle, INFINITE);

	//Also consider to add in mutexes for updating the coolant reservoir level, updating the engine coolant level and the radiator coolant level

	//Once we are done, then close the handles
	CloseHandle(engineHandle);
	CloseHandle(fuelPumpHandle);
	CloseHandle(fuelTankHandle);
	CloseHandle(coolantPumpHandle);
	CloseHandle(coolantReservoirHandle);
	CloseHandle(radiatorHandle);

	//Then close the mutex
	CloseHandle(theOutputMutex());

	return 0;
}