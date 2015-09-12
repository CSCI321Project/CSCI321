#include <iostream>
#include "electrical.h"
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
	HANDLE engineHandle, fuelPumpHandle, fuelTankHandle, batteryHandle, headlightHandle, frontFogHandle, highBeamHandle, rearFogHandle, hazardLightHandle, leftIndicatorHandle, rightIndicatorHandle, wiperHandle, radioHandle, rearDefrostHandle;

	engineHandle = (HANDLE)_beginthreadex(0, 0, &engineManager, 0, 0, 0);
	fuelPumpHandle = (HANDLE)_beginthreadex(0, 0, &fuelPumpManager, 0, 0, 0);
	fuelTankHandle = (HANDLE)_beginthreadex(0, 0, &fuelTankManager, 0, 0, 0);


	batteryHandle = (HANDLE)_beginthreadex(0, 0, &batteryManager, 0, 0, 0);
	headlightHandle = (HANDLE)_beginthreadex(0, 0, &headlightManager, 0, 0, 0);
	frontFogHandle = (HANDLE)_beginthreadex(0, 0, &frontFogManager, 0, 0, 0);
	highBeamHandle = (HANDLE)_beginthreadex(0, 0, &highBeamManager, 0, 0, 0);
	rearFogHandle = (HANDLE)_beginthreadex(0, 0, &rearFogManager, 0, 0, 0);
	hazardLightHandle = (HANDLE)_beginthreadex(0, 0, &hazardLightManager, 0, 0, 0);
	leftIndicatorHandle = (HANDLE)_beginthreadex(0, 0, &leftIndicatorManager, 0, 0, 0);
	rightIndicatorHandle = (HANDLE)_beginthreadex(0, 0, &rightIndicatorManager, 0, 0, 0);
	wiperHandle = (HANDLE)_beginthreadex(0, 0, &wiperManager, 0, 0, 0);
	radioHandle = (HANDLE)_beginthreadex(0, 0, &radioManager, 0, 0, 0);
	rearDefrostHandle = (HANDLE)_beginthreadex(0, 0, &rearDefrostManager, 0, 0, 0);


	//Make the fuel tank to only have 10 liters of fuel
	theFuelTank().setFuel(10.0);

	//For testing, we want to first start the engine
	theEngine().startEngine();

	//Set the engine speed to 60
	theEngine().setSpeed(60);

	//Couple of things we want to do with the electrical system

	theHeadlights().setStatus(true);
	if (theHeadlights().returnStatus() == true)
	{
		cout << endl << "lights on";
	}
	theHighBeam().setStatus(true);
	if (theHighBeam().returnStatus() == true)
	{
		cout << endl << "Highbeam ok";
	}
	theFrontFogLight().setStatus(true);
	if (theFrontFogLight().returnStatus() == true)
	{
		cout << endl << "front fog ok";
	}
	theRearFogLight().setStatus(true);
	if (theRearFogLight().returnStatus() == true)
	{
		cout << endl << "rear fog ok";
	}

	theLeftIndicatorLight().setStatus(true);
	if ((theLeftIndicatorLight().returnStatus() == true) && (theRightIndicatorLight().returnStatus() == false))
	{
		cout << endl << "left signal ok";
	}
	theRightIndicatorLight().setStatus(true);
	if ((theRightIndicatorLight().returnStatus() == true) && (theLeftIndicatorLight().returnStatus() == false))
	{
		cout << endl << "right signal ok";
	}

	theLeftIndicatorLight().setStatus(true);
	if ((theLeftIndicatorLight().returnStatus() == true) && (theRightIndicatorLight().returnStatus() == false))
	{
		cout << endl << "left signal ok";
	}

	theHazardLights().setStatus(true);
	if ((theLeftIndicatorLight().returnStatus() == false) && (theRightIndicatorLight().returnStatus() == false) && (theHazardLights().returnStatus()== true))
	{
		cout << endl << "hazard signal ok";
	}

	theWipers().setWiperSpeed(3);

	if (theWipers().returnWiperSpeed() == 3)
	{
		cout << endl << "wiper at speed 3";
	}

	theRadio().setRadioChannel(2);
	if (theRadio().getRadioChannel() == 2)
	{
		cout << endl << "radio channel 2";
	}
	theRadio().setVolume(3);
	if (theRadio().getVolume() == 3)
	{
		cout << endl << "radio volume 3";
	}
	theRearDefrost().setStatus(true);
	if (theRearDefrost().getStatus() == true)
	{
		cout << endl << " rear defrost ok";
	}

	theBattery().setStatus(false);
	if (theHeadlights().returnStatus() == false)
	{
		cout << endl << "lights off";
	}
	else
	{
		cout << endl << "lights OK!" << endl;
	}
	if (theHighBeam().returnStatus() == false)
	{
		cout << endl << "Highbeam fail";
	}
	if (theFrontFogLight().returnStatus() == false)
	{
		cout << endl << "front fog fail";
	}
	if (theRearFogLight().returnStatus() == false)
	{
		cout << endl << "rear fog fail";
	}
	if ((theLeftIndicatorLight().returnStatus() == false))
	{
		cout << endl << "left signal off";
	}
	if ((theRightIndicatorLight().returnStatus() == false))
	{
		cout << endl << "right signal off";
	}
	if ((theHazardLights().returnStatus() == false))
	{
		cout << endl << "hazards off";
	}
	if (theWipers().returnWiperSpeed() == 3)
	{
		cout << endl << "wiper at speed 3";
	}
	if (theRadio().getRadioChannel() == 2)
	{
		cout << endl << "radio channel 2";
	}
	if (theRadio().getVolume() == 0)
	{
		cout << endl << "radio volume 0";
	}
	if (theRearDefrost().getStatus() == false)
	{
		cout << endl << " rear defrost fail";
	}
	theHeadlights().setStatus(true);
	if (theHeadlights().returnStatus() == false)
	{
		cout << endl << "lights off";
	}
	else
	{
		cout << endl << "lights OK!" << endl;
	}
	/*if (theHighBeam().returnStatus() == false)
	{
		WaitForSingleObject(theOutputMutex(), INFINITE);
		cout << endl << "highbeam activation failed" << endl;
		ReleaseMutex(theOutputMutex());
	}
	else
	{
		WaitForSingleObject(theOutputMutex(), INFINITE);
		cout << endl << "Highbeam active" << endl;
		ReleaseMutex(theOutputMutex());

	}*/

	//Now need to wait for these objects to finish...

	WaitForSingleObject(engineHandle, INFINITE);
	WaitForSingleObject(fuelPumpHandle, INFINITE);
	WaitForSingleObject(fuelTankHandle, INFINITE);

	WaitForSingleObject(batteryHandle, INFINITE); 
	WaitForSingleObject(headlightHandle, INFINITE);
	WaitForSingleObject(frontFogHandle, INFINITE);
	WaitForSingleObject(highBeamHandle, INFINITE);
	WaitForSingleObject(rearFogHandle, INFINITE);
	WaitForSingleObject(leftIndicatorHandle, INFINITE);
	WaitForSingleObject(rightIndicatorHandle, INFINITE);
	WaitForSingleObject(hazardLightHandle, INFINITE);
	WaitForSingleObject(wiperHandle, INFINITE);
	WaitForSingleObject(radioHandle, INFINITE);
	WaitForSingleObject(rearDefrostHandle, INFINITE);


	//Once we are done, then close the handles
	CloseHandle(engineHandle);
	CloseHandle(fuelPumpHandle);
	CloseHandle(fuelTankHandle);

	CloseHandle(batteryHandle);
	CloseHandle(headlightHandle);
	CloseHandle(frontFogHandle);
	CloseHandle(highBeamHandle);
	CloseHandle(rearFogHandle);
	CloseHandle(leftIndicatorHandle);
	CloseHandle(rightIndicatorHandle);
	CloseHandle(hazardLightHandle);
	CloseHandle(wiperHandle);
	CloseHandle(radioHandle);
	CloseHandle(rearDefrostHandle);


	//Then close the mutex
	CloseHandle(theOutputMutex());

	return 0;
}