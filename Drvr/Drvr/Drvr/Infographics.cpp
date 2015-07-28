#include "Infographics.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <wincon.h>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/*
String^ bitch;
bitch = Convert::ToString(currPos);
descBox->Text = bitch;
*/

namespace Drvr
{
	int currPos = 0;
	vector<CarPart> curr;
	Car carInfo;

	void Infographics::partInfo(int noComponents)
	{
		//pass in the number of components for this part 
		//this will be the list of buttons that we will be working on
		List<Button^> buttons;
		int topRow = 0;		// initiate top and bottom row values to calculate.
		int bottomRow = 0;

		resetButtons();

		//this is the part where it takes in the number of components and divide it accordingly 
		if (noComponents % 2 == 0) // value is even
		{
			if (noComponents < 4)
			{
				topRow = noComponents;
			}
			else if (noComponents >= 4)
			{
				topRow = noComponents / 2;
				bottomRow = noComponents / 2;
			}
		}
		else if (noComponents % 2 != 0)// value is uneven
		{

			if (noComponents < 4)
			{
				topRow = noComponents;
			}
			else if (noComponents >= 5)
			{
				topRow = (noComponents / 2) + 1;
				bottomRow = noComponents / 2;
			}
		}

		//we need to change the values of the boxes that we want it to be visible 
		//********************************* Top Row Button Mapping *********************************
		if (topRow == 2)
		{
			top7Components->Location = Point(114, 30);
			b3Top7->Visible = true;
			b4Top7->Visible = true;

			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
		}
		else if (topRow == 3)
		{
			b3Top7->Visible = true;
			b4Top7->Visible = true;
			b5Top7->Visible = true;

			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
			buttons.Add(b5Top7);
		}
		else if (topRow == 4)
		{
			top7Components->Location = Point(114, 30);
			b2Top7->Visible = true;
			b3Top7->Visible = true;
			b4Top7->Visible = true;
			b5Top7->Visible = true;

			buttons.Add(b2Top7);
			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
			buttons.Add(b5Top7);
		}
		else if (topRow == 5)
		{
			b2Top7->Visible = true;
			b3Top7->Visible = true;
			b4Top7->Visible = true;
			b5Top7->Visible = true;
			b6Top7->Visible = true;

			buttons.Add(b2Top7);
			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
			buttons.Add(b5Top7);
			buttons.Add(b6Top7);
		}
		else if (topRow == 6)
		{
			top7Components->Location = Point(114, 30);
			b1Top7->Visible = true;
			b2Top7->Visible = true;
			b3Top7->Visible = true;
			b4Top7->Visible = true;
			b5Top7->Visible = true;
			b6Top7->Visible = true;

			buttons.Add(b1Top7);
			buttons.Add(b2Top7);
			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
			buttons.Add(b5Top7);
			buttons.Add(b6Top7);
		}
		else if (topRow == 7)
		{
			b1Top7->Visible = true;
			b2Top7->Visible = true;
			b3Top7->Visible = true;
			b4Top7->Visible = true;
			b5Top7->Visible = true;
			b6Top7->Visible = true;
			b7Top7->Visible = true;

			buttons.Add(b1Top7);
			buttons.Add(b2Top7);
			buttons.Add(b3Top7);
			buttons.Add(b4Top7);
			buttons.Add(b5Top7);
			buttons.Add(b6Top7);
			buttons.Add(b7Top7);
		}


		//********************************* Bottom Row Button Mapping *********************************
		if (bottomRow == 1)
		{
			b1Btm7->Visible = true;

			buttons.Add(b1Btm7);
		}
		else if (bottomRow == 2)
		{
			btm7Components->Location = Point(114, 430);
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;

			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
		}
		else if (bottomRow == 3)
		{
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;
			b5Btm7->Visible = true;

			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
			buttons.Add(b5Btm7);

		}
		else if (bottomRow == 4)
		{
			btm7Components->Location = Point(114, 430);
			b2Btm7->Visible = true;
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;
			b5Btm7->Visible = true;

			buttons.Add(b2Btm7);
			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
			buttons.Add(b5Btm7);

		}
		else if (bottomRow == 5)
		{
			b2Btm7->Visible = true;
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;
			b5Btm7->Visible = true;
			b6Btm7->Visible = true;


			buttons.Add(b2Btm7);
			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
			buttons.Add(b5Btm7);
			buttons.Add(b6Btm7);
		}
		else if (bottomRow == 6)
		{
			btm7Components->Location = Point(114, 430);
			b1Btm7->Visible = true;
			b2Btm7->Visible = true;
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;
			b5Btm7->Visible = true;
			b6Btm7->Visible = true;

			buttons.Add(b1Btm7);
			buttons.Add(b2Btm7);
			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
			buttons.Add(b5Btm7);
			buttons.Add(b6Btm7);
		}
		else if (bottomRow == 7)
		{
			b1Btm7->Visible = true;
			b2Btm7->Visible = true;
			b3Btm7->Visible = true;
			b4Btm7->Visible = true;
			b5Btm7->Visible = true;
			b6Btm7->Visible = true;
			b7Btm7->Visible = true;

			buttons.Add(b1Btm7);
			buttons.Add(b2Btm7);
			buttons.Add(b3Btm7);
			buttons.Add(b4Btm7);
			buttons.Add(b5Btm7);
			buttons.Add(b6Btm7);
			buttons.Add(b7Btm7);
		}

		//end getting all the buttons required for this part 

		vector<component> component = curr[currPos].getComponent();
		for (int i = 0; i < noComponents; i++)
		{
			buttons[i]->Text = gcnew String(component[i].componentName.c_str());
		}

	}

	//currently this function is not used, should remove if we are not going to use it !!!!!!
	void Infographics::calculateNeededButtons(int value, List<Button^>^ buttons)
	{
		/*
		//List<Button^> buttons;
		//int value = 8;
		int topRow = 0;		// initiate top and bottom row values to calculate.
		int bottomRow = 0;

		if (value % 2 == 0) // value is even
		{
		if (value < 4)
		{
		topRow = value;
		}
		else if (value >= 4)
		{
		topRow = value / 2;
		bottomRow = value / 2;

		}


		}
		else if (value % 2 != 0)// value is uneven
		{

		if (value < 4)
		{
		topRow = value;
		}
		else if (value >= 5)
		{
		topRow = (value / 2) + 1;
		bottomRow = value / 2;
		}
		}



		//********************************* Top Row Button Mapping *********************************
		if (topRow == 2)
		{
		top7Components->Location = Point(114, 30);
		b3Top7->Visible = true;
		b4Top7->Visible = true;

		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		}
		else if (topRow == 3)
		{
		b3Top7->Visible = true;
		b4Top7->Visible = true;
		b5Top7->Visible = true;

		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		buttons->Add(b5Top7);
		}
		else if (topRow == 4)
		{
		top7Components->Location = Point(114, 30);
		b2Top7->Visible = true;
		b3Top7->Visible = true;
		b4Top7->Visible = true;
		b5Top7->Visible = true;

		buttons->Add(b2Top7);
		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		buttons->Add(b5Top7);
		}
		else if (topRow == 5)
		{
		b2Top7->Visible = true;
		b3Top7->Visible = true;
		b4Top7->Visible = true;
		b5Top7->Visible = true;
		b6Top7->Visible = true;

		buttons->Add(b2Top7);
		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		buttons->Add(b5Top7);
		buttons->Add(b6Top7);
		}
		else if (topRow == 6)
		{
		top7Components->Location = Point(114, 30);
		b1Top7->Visible = true;
		b2Top7->Visible = true;
		b3Top7->Visible = true;
		b4Top7->Visible = true;
		b5Top7->Visible = true;
		b6Top7->Visible = true;

		buttons->Add(b1Top7);
		buttons->Add(b2Top7);
		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		buttons->Add(b5Top7);
		buttons->Add(b6Top7);
		}
		else if (topRow == 7)
		{
		b1Top7->Visible = true;
		b2Top7->Visible = true;
		b3Top7->Visible = true;
		b4Top7->Visible = true;
		b5Top7->Visible = true;
		b6Top7->Visible = true;
		b7Top7->Visible = true;

		buttons->Add(b1Top7);
		buttons->Add(b2Top7);
		buttons->Add(b3Top7);
		buttons->Add(b4Top7);
		buttons->Add(b5Top7);
		buttons->Add(b6Top7);
		buttons->Add(b7Top7);
		}

		//******************************************************************************************
		//********************************* Bottom Row Button Mapping *********************************
		if (bottomRow == 1)
		{
		b1Btm7->Visible = true;

		buttons->Add(b1Btm7);
		}
		else if (bottomRow == 2)
		{
		btm7Components->Location = Point(114, 430);
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;

		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		}
		else if (bottomRow == 3)
		{
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;
		b5Btm7->Visible = true;

		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		buttons->Add(b5Btm7);

		}
		else if (bottomRow == 4)
		{
		btm7Components->Location = Point(114, 430);
		b2Btm7->Visible = true;
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;
		b5Btm7->Visible = true;

		buttons->Add(b2Btm7);
		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		buttons->Add(b5Btm7);

		}
		else if (bottomRow == 5)
		{
		b2Btm7->Visible = true;
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;
		b5Btm7->Visible = true;
		b6Btm7->Visible = true;


		buttons->Add(b2Btm7);
		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		buttons->Add(b5Btm7);
		buttons->Add(b6Btm7);
		}
		else if (bottomRow == 6)
		{
		btm7Components->Location = Point(114, 430);
		b1Btm7->Visible = true;
		b2Btm7->Visible = true;
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;
		b5Btm7->Visible = true;
		b6Btm7->Visible = true;

		buttons->Add(b1Btm7);
		buttons->Add(b2Btm7);
		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		buttons->Add(b5Btm7);
		buttons->Add(b6Btm7);
		}
		else if (bottomRow == 7)
		{
		b1Btm7->Visible = true;
		b2Btm7->Visible = true;
		b3Btm7->Visible = true;
		b4Btm7->Visible = true;
		b5Btm7->Visible = true;
		b6Btm7->Visible = true;
		b7Btm7->Visible = true;

		buttons->Add(b1Btm7);
		buttons->Add(b2Btm7);
		buttons->Add(b3Btm7);
		buttons->Add(b4Btm7);
		buttons->Add(b5Btm7);
		buttons->Add(b6Btm7);
		buttons->Add(b7Btm7);
		}

		*/
	}

	void Infographics::userClickedZoom()
	{
		//currPos is used to keep track of which location we are currently in in the "curr" vector
		//when the user clicks left or right, we add or reduce the number
		//we need to keep track of the number of parts available for the current layer 

		int currPartID = curr[currPos].getPartID();
		//we should check if we are capable of zooming in or not, can check using the hierarchy number

		if (carInfo.getHierarchyNumber(currPartID) != 0) //not 0 means we have something to zoom in to 
		{
			curr.clear();
			currPos = 0; 
			carInfo.zoomIn(currPartID);

			//once the zoom in function is completed, the current layer is updated again, so we must get the latest curr layer 
			curr = carInfo.getCurrentCarParts();

			//we should check if there are any components available in this part 
			//if there is we get the components for this part 
			//this should also be where we will be updating the image for the new layer 
			int noComponents = curr[currPos].getNoComponents();
			if (noComponents != 0)
			{
				partInfo(noComponents);
			}
		}
	}

	void Infographics::ReadIn()
	{
		//this readIn function is called when the infographics is loaded for the first time 
		carInfo.loadFile("Car part descriptions.txt");

		curr = carInfo.getCurrentCarParts();
	}

	void Infographics::nextPart()
	{
		//this function allows us to iterate through each curr layer 
		if (currPos < curr.size() - 1 )
		{
			currPos += 1;
		}
		else
		{
			currPos = 0;
		}
		//get the components setup
		int noComponents = curr[currPos].getNoComponents();
		if (noComponents != 0)
		{
			partInfo(noComponents);
		}
	}

	void Infographics::prevPart()
	{
		//this function allows us to iterate through the curr layer
		if (currPos == 0)
		{
			currPos = curr.size() - 1;
		}
		else
		{
			currPos = currPos - 1;
		}
		//get the components
		int noComponents = curr[currPos].getNoComponents();
		if (noComponents != 0)
		{
			partInfo(noComponents);
		}
	}

	//this function is used when we are navigating through different parts of the car, we need to reset the variables 
	void Infographics::resetButtons()
	{
		//this is the function that resets the buttons 
		top7Components->Location = Point(47, 30);
		btm7Components->Location = Point(47, 431);

		b1Top7->Visible = false;
		b2Top7->Visible = false;
		b3Top7->Visible = false;
		b4Top7->Visible = false;
		b5Top7->Visible = false;
		b6Top7->Visible = false;
		b7Top7->Visible = false;

		b1Btm7->Visible = false;
		b2Btm7->Visible = false;
		b3Btm7->Visible = false;
		b4Btm7->Visible = false;
		b5Btm7->Visible = false;
		b6Btm7->Visible = false;
		b7Btm7->Visible = false;
	}

	void Infographics::resetVariables()
	{
		//we should reset the global variables when the user clicks the exit button
		currPos = 0;
		curr.clear();
		carInfo.resetFunc();
	}

	//end of namespace Drvr
}


