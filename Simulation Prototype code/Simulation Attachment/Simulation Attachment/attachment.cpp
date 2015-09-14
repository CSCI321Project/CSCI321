#include "attachment.h"

using namespace std;

void trailer::setStatus(bool newStatus)
{
	if ((theTowbar().getAttachedObject() == "towbox") && (theTowbar().getStatus() == true))
	{
		//Cannot  do anything, towbox is attached
	}
	else
	{
		if (newStatus == true)
		{
			//We want to mount the trailer
			attachStatus = true;
			theTowbar().mount("trailer");
		}
		else
		{
			//we want to unmount
			//Make sure that we are currently mounted in the first place
			if (attachStatus == true)
			{
				//only if we are already attached, then only unmount ourself
				theTowbar().unmount();
				attachStatus = false;
			}
		}
	}
		

}
bool trailer::getStatus()
{
	return attachStatus;
}
trailer::trailer()
{
	//By default, not attached
	attachStatus = false;
}
trailer::~trailer()
{
	//Nothing to do here really
}

void towbox::setStatus(bool newStatus)
{
	if ((theTowbar().getAttachedObject() == "trailer") && (theTowbar().getStatus() == true))
	{
		//Cannot  do anything, trailer is attached
	}
	else
	{
		if (newStatus == true)
		{
			//We want to mount the towbox
			attachStatus = true;
			theTowbar().mount("towbox");
		}
		else
		{
			//we want to unmount
			//Make sure that we are currently mounted in the first place
			if (attachStatus == true)
			{
				//only if we are already attached, then only unmount ourself
				theTowbar().unmount();
				attachStatus = false;
			}
		}
	}
}
bool towbox::getStatus()
{
	return attachStatus;
}
towbox::towbox()
{
	//by default, not attched
	attachStatus = false;
}
towbox::~towbox()
{
	//Nothing much to do here
}

trailer& theTrailer()
{
	static trailer myTrailer;
	return myTrailer;
}
towbox& theTowbox()
{
	static towbox myTowbox;
	return myTowbox;
}

towbar& theTowbar()
{
	static towbar myTowbar;
	return myTowbar;
}
void towbar::mount(std::string toMount)
{
	if (attachStatus == true)
	{
		//something is attached already. Do not proceed unless we unmount
	}
	else
	{
		attachStatus = true;

		attachment = toMount;
	}
}
void towbar::unmount()
{
	attachStatus = false;
	attachment.clear();

	//Unmount whatever object that is there..
}
bool towbar::getStatus()
{
	return attachStatus;
}
std::string towbar::getAttachedObject()
{
	return attachment;
}
towbar::towbar()
{
	//By default nothing attached
	attachStatus = false;
	attachment = "";
}
towbar::~towbar()
{
	//nothing to do in the destructor
}

unsigned int __stdcall trailerManager(void* data)
{
	for (;;)
	{
		//Infinitely look for changes..

		if (theTrailer().getStatus() == true)
		{
			//Trailer is attached
		}
		else
		{
			//trailer isnt attached
		}
	}
}
unsigned int __stdcall towboxManager(void* data)
{
	for (;;)
	{
		//Infinitely look for changes..

		if (theTowbox().getStatus() == true)
		{
			//towbox is attached
		}
		else
		{
			//towbox isnt attached
		}
	}
}
unsigned int __stdcall towbarManager(void* data)
{
	for (;;)
	{
		//Infinitely look for changes..

		if (theTowbar().getStatus() == true)
		{
			//towbar is attached
		}
		else
		{
			//towbar isnt attached
		}
	}
}