#include <iostream>
#include <list>


/*IMPORTANT NOTE

//Remember, for the highbeam, front fog light, rear foglight to work, front headlights must be on. 
Also, when turning on the left or right indicator, the opposite side one must be offed
. When turning on the hazard, off the indicators both side
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< To be done from the UI side itself

*/
class battery //note that actually we are not using the HV battery that we normally use in an electric car. this is a different battery..
{
private:
	bool status; //To show if the battery is alright
	std::list<std::string> batteryUsers; //A list of the components that are currently using power from the battery

public:
	battery();
	~battery();
	void setStatus(bool newStatus); //Battery is not alright if set to false, useful to simulate battery failure
	bool returnStatus();
	void addUser(std::string newUser);
	void removeUser(std::string userToRemove);
	void clearList();
};

class lights //this is a general lights class we spawn various types of lights as different objects
{
private:
	bool active; //true if light is on, false if off

public:
	void setStatus(bool status);
	bool returnStatus();
	lights();
	~lights();
};

class wipers //technically wiper motors....
{
private:
	int speed; //speed ranges from 0 to 4, with 4 being highest speed

public:
	void setWiperSpeed(int newSpeed);
	int returnWiperSpeed();
	wipers();
	~wipers();
};

class radio{
private:
	int channel;
	int volume; //If volume is 0, it can be assumed as off then

public:
	radio();
	~radio();
	void setRadioChannel(int newChannel);
	int getRadioChannel();
	void setVolume(int newVolume);
	int getVolume();

};

class rearDefrost{
private:
	bool status; //true if on, else false

public:
	rearDefrost();
	~rearDefrost();
	void setStatus(bool newStatus);
	bool getStatus();

};

//Create our class objects
battery& theBattery();
lights& theHeadlights();
lights& theFrontFogLight();
lights& theHighBeam();
lights& theRearFogLight();
lights& theHazardLights();
lights& theLeftIndicatorLight();
lights& theRightIndicatorLight();
wipers& theWipers();
radio& theRadio();
rearDefrost& theRearDefrost();

//Remember, for the highbeam, front fog light, rear foglight to work, front headlights must be on. Also, when turning on the left or right indicator, the opposite side one must be offed. When turning on the hazard, off the indicators both side<<<<<<<< To be done from the UI side itself

//Now need to thread our objects...
//In actual fact, we are only threading these as 
unsigned int __stdcall batteryManager(void* data);
unsigned int __stdcall headlightManager(void* data);
unsigned int __stdcall frontFogManager(void* data);
unsigned int __stdcall highBeamManager(void* data);
unsigned int __stdcall rearFogManager(void* data);
unsigned int __stdcall hazardLightManager(void* data);
unsigned int __stdcall leftIndicatorManager(void* data);
unsigned int __stdcall rightIndicatorManager(void* data);
unsigned int __stdcall wiperManager(void* data);
unsigned int __stdcall radioManager(void* data);
unsigned int __stdcall rearDefrostManager(void* data);