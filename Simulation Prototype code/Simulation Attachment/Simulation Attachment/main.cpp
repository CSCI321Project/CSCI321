#include <iostream>
#include <process.h>
#include "fuel.h"

using namespace std;

int main()
{
	//Run!
	//For testing, set the pressure to a certain value
	/*theFuelPump().setPressure(2.2);
	cout << endl << theFuelPump().getPressure() << endl;
	while (theFuelTank().getCurrentFuelLevel() != 0)
	{
	//Run the fuel pump
	cout << endl << "Running fuel pump" << endl;
	fuelPumpManager();
	}
	cout << "Goodbye";

	int appl;
	cin >> appl;*/


	//Multithreaded code...

	//Build the mutex
	theOutputMutex() = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);

	//Prepare handles
	HANDLE engineHandle, fuelPumpHandle, fuelTankHandle, towbarHandle, towboxHandle, trailerHandle;

	engineHandle = (HANDLE)_beginthreadex(0, 0, &engineManager, 0, 0, 0);
	fuelPumpHandle = (HANDLE)_beginthreadex(0, 0, &fuelPumpManager, 0, 0, 0);
	fuelTankHandle = (HANDLE)_beginthreadex(0, 0, &fuelTankManager, 0, 0, 0);

	towbarHandle = (HANDLE)_beginthreadex(0, 0, &towbarManager, 0, 0, 0); 
	towboxHandle = (HANDLE)_beginthreadex(0, 0, &towboxManager, 0, 0, 0);
	trailerHandle = (HANDLE)_beginthreadex(0, 0, &trailerManager, 0, 0, 0);

	//Make the fuel tank to only have 10 liters of fuel
	theFuelTank().setFuel(10.0);

	//For testing, we want to first start the engine
	theEngine().startEngine();

	//Set the engine speed to 60
	theEngine().setSpeed(60);


	//Want to attach some stuff now
	theTowbox().setStatus(true);
	theTrailer().setStatus(true);

	if (theTrailer().getStatus() == false)
	{
		cout << endl << "Failed to add trailer";
	}

	theTowbox().setStatus(false);
	theTrailer().setStatus(true);

	theTowbox().setStatus(true);
	if (theTowbox().getStatus() == false)
	{
		cout << endl << "Failed to add towbox";
	}
	//Now need to wait for these objects to finish...

	WaitForSingleObject(engineHandle, INFINITE);
	WaitForSingleObject(fuelPumpHandle, INFINITE);
	WaitForSingleObject(fuelTankHandle, INFINITE);

	WaitForSingleObject(towbarHandle, INFINITE);
	WaitForSingleObject(towboxHandle, INFINITE);
	WaitForSingleObject(trailerHandle, INFINITE);
	
	//Once we are done, then close the handles
	CloseHandle(engineHandle);
	CloseHandle(fuelPumpHandle);
	CloseHandle(fuelTankHandle);

	CloseHandle(towbarHandle);
	CloseHandle(towboxHandle);
	CloseHandle(trailerHandle);


	//Then close the mutex
	CloseHandle(theOutputMutex());

	return 0;
}