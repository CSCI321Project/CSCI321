#include <iostream>
#include <process.h>
#include "evHydro.h"
using namespace std;

int main()
{
	/*HANDLE evMotorHandle, evBatteryHandle;

	evMotorHandle = (HANDLE)_beginthreadex(0, 0, &evMotorManager, 0, 0, 0);
	evBatteryHandle = (HANDLE)_beginthreadex(0, 0, &evBatteryManager, 0, 0, 0);
	theEvBattery().setCurrentLevel(55);
	theEvMotor().startMotor();
	theEvMotor().setSpeed(50);
	theEvMotor().setIncline(0);

	Sleep(5000);
	theEvMotor().setIncline(0.8);

	Sleep(5000);
	theEvMotor().setSpeed(100);

	Sleep(5000);
	theEvMotor().setSpeed(50);


	WaitForSingleObject(evMotorHandle, INFINITE);
	WaitForSingleObject(evBatteryHandle, INFINITE);*/


	HANDLE hydrogenMotorHandle, hydrogenTankHandle, hydrogenStackHandle;

	hydrogenMotorHandle = (HANDLE)_beginthreadex(0, 0, &hydrogenMotorManager, 0, 0, 0);
	hydrogenStackHandle = (HANDLE)_beginthreadex(0, 0, &hydrogenStackManager, 0, 0, 0);
	hydrogenTankHandle = (HANDLE)_beginthreadex(0, 0, &hydrogenTankManager, 0, 0, 0);

	theHydrogenTank().setCurrentLevel(55);
	theHydrogenMotor().startMotor();
	theHydrogenMotor().setSpeed(50);
	theHydrogenMotor().setIncline(0);

	Sleep(5000);
	theHydrogenMotor().setIncline(0.8);

	Sleep(5000);
	theHydrogenMotor().setSpeed(100);

	Sleep(5000);
	theHydrogenMotor().setSpeed(50);


	WaitForSingleObject(hydrogenStackHandle, INFINITE);
	WaitForSingleObject(hydrogenTankHandle, INFINITE);
	WaitForSingleObject(hydrogenMotorHandle, INFINITE);

}


