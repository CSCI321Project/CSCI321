#include "electrical.h"
#include "fuel.h"

using namespace std;

battery::battery()
{
	status = true;
}
void battery::reset()
{
	status = true;
}
battery::~battery()
{

}
void battery::setStatus(bool newStatus)
{
	//Battery is not alright if set to false, useful to simulate battery failure

	if (newStatus == false)
	{
		//Disable all components.
		theHeadlights().setStatus(false);
		theFrontFogLight().setStatus(false);
		theHighBeam().setStatus(false);
		theRearFogLight().setStatus(false);
		theLeftIndicatorLight().setStatus(false);
		theRightIndicatorLight().setStatus(false);
		theHazardLights().setStatus(false);
		theWipers().setWiperSpeed(0);
		theRadio().setVolume(0);
		theRearDefrost().setStatus(false);
	}
	status = newStatus;
}
bool battery::returnStatus()
{
	return status;
}

void lights::setStatus(bool status)
{
	//Only can change status if battery is OK. If battery is not OK should have turned it off anyway.
	if (theBattery().returnStatus() == true)
	{
		active = status;
	}
	
}
bool lights::returnStatus()
{
	return active;
}

lights::lights()
{
	active = false;
	//by default it is off
}

void lights::reset()
{
	active = false;
}
lights::~lights()
{
	//Nothing to do here
}

void wipers::setWiperSpeed(int newSpeed)
{
	//Only can change status if battery is OK. If battery is not OK should have turned it off anyway.
	if (theBattery().returnStatus() == true)
	{
		speed = newSpeed;
	}
}
int wipers::returnWiperSpeed()
{
	return speed;
}
wipers::wipers()
{
	//By default should be 0
	speed = 0;
}
void wipers::reset()
{
	speed = 0; //default speed is 0
}
wipers::~wipers()
{
	//nothing to do here
}

radio::radio()
{
	//By default, set the volume to 0 and channel is channel 1 (can't have channel 0)
	volume = 0;
	channel = 1;
}

void radio::reset()
{
	//By default, set the volume to 0 and channel is channel 1 (can't have channel 0)
	volume = 0;
	channel = 1;
}
radio::~radio()
{
	//Nothing much to do in the destructor
}
void radio::setRadioChannel(int newChannel)
{
	//Only can change status if battery is OK. If battery is not OK the radio is not functioning
	if (theBattery().returnStatus() == true)
	{
		channel = newChannel;
	}
}
int radio::getRadioChannel()
{
	return channel;
}
void radio::setVolume(int newVolume)
{
	//Only can change status if battery is OK. If battery is not OK the radio is not functioning
	if (theBattery().returnStatus() == true)
	{
		volume = newVolume;
	}
}
int radio::getVolume()
{
	return volume;
}

rearDefrost::rearDefrost()
{
	//Set status to false by default
	status = false;
}

void rearDefrost::reset()
{
	//Set status to false by default
	status = false;
}
rearDefrost::~rearDefrost()
{
	//Nothing much to do here...
}
void rearDefrost::setStatus(bool newStatus)
{
	//Only can change status if battery is OK. If battery is not OK should have turned it off anyway.
	if (theBattery().returnStatus() == true)
	{
		status = newStatus;
	}
}
bool rearDefrost::getStatus()
{
	return status;
}

battery& theBattery()
{
	static battery myBattery;
	return myBattery;
}

lights& theHeadlights()
{
	static lights myHeadlight;
	return myHeadlight;
}

lights& theFrontFogLight()
{
	static lights myFrontFogLight;
	return myFrontFogLight;
}

lights& theHighBeam()
{
	static lights myHighBeam;
	return myHighBeam;
}

lights& theRearFogLight()
{
	static lights myRearFogLight;
	return myRearFogLight;
}

lights& theHazardLights()
{
	static lights myHazardLights;
	return myHazardLights;
}

lights& theLeftIndicatorLight()
{
	static lights myLeftIndicator;
	return myLeftIndicator;
}

lights& theRightIndicatorLight()
{
	static lights myRightIndicator;
	return myRightIndicator;

}

wipers& theWipers()
{
	static wipers myWipers;
	return myWipers;
}

radio& theRadio()
{
	static radio myRadio;
	return myRadio;
}

rearDefrost& theRearDefrost()
{
	static rearDefrost myRearDefrost;
	return myRearDefrost;
}
unsigned int __stdcall batteryManager(void* data)
{
	for (;;)
	{
		//Infinite loop this...
		if (theBattery().returnStatus() == false)
		{
			//Battery is not OK
			WaitForSingleObject(theOutputMutex(), INFINITE);
			//cout << endl << "Warning: Battery failure detected!" << endl;
			ReleaseMutex(theOutputMutex());

		}

		//Nothing much else...
	}
}
unsigned int __stdcall headlightManager(void* data)
{
	for (;;)
	{
		//Nothing much here....
		if (theHeadlights().returnStatus() == false)
		{
			cout << endl << "LIGHTS OFF" << endl;
		}
	}
}
unsigned int __stdcall frontFogManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
		if (theHeadlights().returnStatus() == false)
		{
			//front fog light should remain off
			theFrontFogLight().setStatus(false);
		}
	}
}
unsigned int __stdcall highBeamManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
		if (theHeadlights().returnStatus() == false)
		{
			//high beam light should remain off
			theHighBeam().setStatus(false);
		}
	}
}
unsigned int __stdcall rearFogManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
		if (theHeadlights().returnStatus() == false)
		{
			//rear fog light should remain off
			theRearFogLight().setStatus(false);
		}
	}
}
unsigned int __stdcall hazardLightManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
	}
}
unsigned int __stdcall leftIndicatorManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
		if (theHazardLights().returnStatus() == false)
		{
			//indicator light should remain off
			theLeftIndicatorLight().setStatus(false);
		}

		//Only one of the two indicators can be on

		if (theRightIndicatorLight().returnStatus() == true)
		{
			theLeftIndicatorLight().setStatus(false);
		}
	}
}
unsigned int __stdcall rightIndicatorManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
		if (theHazardLights().returnStatus() == false)
		{
			//indicator light should remain off
			theLeftIndicatorLight().setStatus(false);
		}

		//Only one of the two indicators can be on
		if (theLeftIndicatorLight().returnStatus() == true)
		{
			theRightIndicatorLight().setStatus(false);
		}
	}
}
unsigned int __stdcall wiperManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
	}
}
unsigned int __stdcall radioManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
	}
}
unsigned int __stdcall rearDefrostManager(void* data)
{
	for (;;)
	{
		//Nothing much to do here really...
	}
}