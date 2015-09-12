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
	HANDLE engineHandle, fuelPumpHandle, fuelTankHandle;

	engineHandle = (HANDLE)_beginthreadex(0, 0, &engineManager, 0, 0, 0);
	fuelPumpHandle = (HANDLE)_beginthreadex(0, 0, &fuelPumpManager, 0, 0, 0);
	fuelTankHandle = (HANDLE)_beginthreadex(0, 0, &fuelTankManager, 0, 0, 0);


	//Make the fuel tank to only have 10 liters of fuel
	theFuelTank().setFuel(10.0);

	//For testing, we want to first start the engine
	theEngine().startEngine();

	//Set the engine speed to 60
	theEngine().setSpeed(120);

	//Now need to wait for these objects to finish...

	WaitForSingleObject(engineHandle, INFINITE);
	WaitForSingleObject(fuelPumpHandle, INFINITE);
	WaitForSingleObject(fuelTankHandle, INFINITE);

	//Once we are done, then close the handles
	CloseHandle(engineHandle);
	CloseHandle(fuelPumpHandle);
	CloseHandle(fuelTankHandle);

	//Then close the mutex
	CloseHandle(theOutputMutex());

	return 0;
}