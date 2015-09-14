#include <iostream>
#ifndef attachmentStuff
#define attachmentStudd
class trailer
{
private:
	bool attachStatus; //false if not attached, true otherwise

public:
	void setStatus(bool newStatus);
	bool getStatus();
	trailer();
	~trailer();
};

class towbox
{
private:
	bool attachStatus;

public:
	void setStatus(bool newStatus);
	bool getStatus();
	towbox();
	~towbox();
};

class towbar
{
	//this is the mounting point on the car
private:

	bool attachStatus;
	std::string attachment;

public:
	void mount(std::string toMount);
	void unmount();
	bool getStatus();
	std::string getAttachedObject();
	towbar();
	~towbar();

};

trailer& theTrailer();
towbox& theTowbox();
towbar& theTowbar();

unsigned int __stdcall trailerManager(void* data);
unsigned int __stdcall towboxManager(void* data);
unsigned int __stdcall towbarManager(void* data);

#endif