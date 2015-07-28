#include "Car.h"
#include "CarPart.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

Car::Car()
{

}

Car::~Car()
{

}

void Car::resetFunc()
{
	vector<int> tempSiblings = carParts[0].getSiblings();
	currentParts.clear();
	if (tempSiblings.empty())
	{
		currentParts.push_back(carParts[0]);
	}
	else
	{
		for (int i = 0; i < tempSiblings.size(); i++)
		{
			currentParts.push_back(carParts[tempSiblings[i]]);
		}
	}
}

void Car::loadFile(string fileName)
{
    ifstream infile;
    infile.open(fileName.c_str());

    if(!infile.good())
    {
        cout << "File not found" << endl;
    }
    else
    {
        string tempString = "";
        int tempNoComp = 0;
        int totalPartNumber = 0;

        getline(infile, tempString, '\n');
        totalPartNumber = atoi(tempString.c_str());

        for(int i = 0; i < totalPartNumber; i++)
        {
            //if we dont do this checking, it will mess up the upcoming ones
            if(i == totalPartNumber - 1)
            {
                getline(infile, tempString, '\n');
            }
            else
            {
                getline(infile, tempString, ',');
            }
            //push the first hierarchy number in
            hierarchyNumber.push_back(atoi(tempString.c_str()));
        }

        //we read in from the file all the different parts for the system
        for(int i = 0; i < totalPartNumber; i++)
        {
            CarPart tempCarPart;
            tempCarPart.setPartID(i); //set the id for the part

            if(i == 0)
            {
                tempCarPart.setTopNode();
            }

            //get the name for the part
            getline(infile, tempString, ',');
            tempCarPart.setPartName(tempString);
            //get the image for the part when nothing is clicked
            getline(infile, tempString, ',');
            tempCarPart.setPartImage(tempString);
            //get the number of components and their description available for the part
            getline(infile, tempString, '\n');
            tempNoComp = atoi(tempString.c_str()); //no of components
            tempCarPart.setNoComponents(tempNoComp);

            if(tempNoComp != 0) //we only read in if there are any components
            {
                for(int j = 0; j < tempNoComp; j++)
                {
                    component tempComp;

                    //get the component name
                    getline(infile, tempString, ',');
                    tempComp.componentName = tempString;
                    //get the component image
                    getline(infile, tempString, ',');
                    tempComp.componentImage = tempString;
                    //get the component video
                    getline(infile,tempString,',');
                    tempComp.componentVideo = tempString;

                    /*
                        Things to take note at this point is that, we must take in the video first (before this i did not
                        take into consideration for videos), the reason is because there are commas in the description.
                        It will f*ck up everything badly imo lol
                    */

                    //get the component description
                    getline(infile, tempString, '\n');
                    tempComp.componentDescription = tempString;

                    tempCarPart.addComponent(tempComp);
                }
            }
            carParts.push_back(tempCarPart);
            //cout << tempCarPart.display() << endl;
        }

        //we assign the family members here
        /*
            values -    5,0,0,0,0,3,2,0,0,0,0
            position -  0 1 2 3 4 5 6 7 8 9 10
            the first value is 5, which means that the next 5 values would be considered to be child of the first node
            if we encounter any values as we are traversing, we need to skip the values, for example, if we reach the node of value 3,
                the child of the node 3 (at position 5) is 6, 9, and 10. We skipped 2 values in between as they are the child of node at position 6.
                (probably needs to be phrased better)
            if we reach the final child value of the particular node, and it has a value in it, we dont have to add on the count and just take in the value.

        */
        for(int i = 0; i < totalPartNumber; i++)
        {
            if(hierarchyNumber[i] > 0)
            {
                vector<int> siblingIDs;
                int count = i + 1; //this count is to keep track of how many we have gone through
                for(int j = 0; j < hierarchyNumber[i]; j++)
                {
                    //cout << carParts[count].display() << endl;

                    if (hierarchyNumber[count] > 0 && j == hierarchyNumber[i] - 1)
                    {
                        siblingIDs.push_back(count);
                    }
                    else if (hierarchyNumber[count] > 0)
                    {
                        siblingIDs.push_back(count);
                        count = count + hierarchyNumber[count] + 1;
                    }
                    else
                    {
                        siblingIDs.push_back(count);
                        count++;
                    }
                }
                //we add all the siblings together to individual sibling
                //so we can access from any point to change the "current" level
                for(int k = 0; k < siblingIDs.size(); k++)
                {
                    carParts[siblingIDs[k]].setParent(i);
                    carParts[siblingIDs[k]].addSiblings(siblingIDs);
                    //cout << carParts[siblingIDs[k]].display() << endl;
                }
            }
        }

        //we should set the current to the first element in the tree
        //only 1 node at the top, the user must zoom in to view more components
        currentParts.push_back(carParts[0]);
    }
    //at this point we have read in all the part and their components OR the thing failed to open
    infile.close();
}

int Car::getHierarchyNumber(int position) const
{
    return hierarchyNumber[position];
}

vector<CarPart> Car::getCurrentCarParts() const
{
    return currentParts;
}

void Car::setCurrentCarParts(vector<int> tempSiblings)
{
    //clear the vector first
    currentParts.clear();

    //cout << tempSiblings.size() << endl;
    for(int i = 0; i < tempSiblings.size(); i++)
    {
        currentParts.push_back(carParts[tempSiblings[i]]);
        //cout << carParts[tempSiblings[i]] << endl;
    }
}


void Car::zoomIn(int currPosition)
{
    //assuming that we already checked that theres nothing to zoom in to
    if(hierarchyNumber[currPosition] == 0)
    {
        cout << "There is nothing to zoom in to" << endl;
    }
    else
    {
        //if there is a value in hierarchyNumber, we know for sure that the next x values is the child
        //for the current position

        /*
            we know for sure that 1 value after hierarchyNumber is definitely going to be a child of he hierarchyNumber
            the value of the child might have more child, for example
            value -     3,2,0,0,0,0
            position -  0 1 2 3 4 5
            we know that the first value has 3 child, we know for sure that the first value after position 0 is
            definitely a child of position 0. The child has its own child, we dont have to do the calculations
            again to skip the value. We use the sibling values of the position 1 to know who are its siblings.
            In this case, we would know that the sibling values would be 1,4,5 (This is done at the constructor)
        */
        vector<int> tempSiblings;
        //we would then know what are the siblings, the current layer to be displayed to the user
        tempSiblings = carParts[currPosition + 1].getSiblings();

        setCurrentCarParts(tempSiblings);
    }
}

void Car::zoomOut(int currPosition)
{
    int parentID = carParts[currPosition].getParentID();
    if(parentID == -1)
    {
        cout << "There is nothing to zoom out to" << endl;
    }
    else
    {
        //cout << carParts[parentID] << endl;
        vector<int> tempSiblings = carParts[parentID].getSiblings();

        if(tempSiblings.size() == 0)
        {
            tempSiblings.push_back(parentID);
        }
        setCurrentCarParts(tempSiblings);
    }
	/*
    for(int i = 0; i < currentParts.size(); i++)
    {
        cout << currentParts[i] << endl;
    }
	*/
}

void Car::textEditorMenu()
{
    int choice = 0;
    bool check = false;
    while (check == false)
    {
        cout << ">> Text Editor <<" << endl << endl;
        cout << "How do you wish to edit today?" << endl;
        cout << "1. Edit by batch" << endl;
        cout << "2. Edit individually" << endl;
        cout << "3. Exit" << endl;
        cout << "Input: ";
        cin >>  choice;

        switch(choice)
        {
            case 1:
            {
                cout << ">> Editing by batch <<" << endl << endl;
                editByBatch();
            }
            break;
            case 2:
            {
                cout << ">> Editing individually <<" << endl << endl;
                editIndividually();
            }
            break;
            case 3:
            {
                cout << ">> Exiting << " << endl;
                check = true;
            }
            break;
            default:
            {
                cout << ">> Invalid input <<" << endl;
                cout << "Please try again" << endl;
                check = false;
            }
        }
    }
}

void Car::editByBatch()
{
    int choice = -1;
    cout << ">> If there is no option that you seek, use \"Edit Individually\" instead. <<" << endl;
    cout << ">> Make a choice and get a description on what it is suppose to do and the format of the text file that is expected <<" << endl;
    cout << endl;

    cout << "How do you wish to update by batch today?" << endl;
    cout << "1. Update by batch for ALL images AND videos for parts and ALL COMPONENTS" << endl;
    cout << "2. Update by batch for ALL images for ALL PARTS and ALL COMPONENTS" << endl;
    cout << "3. Update by batch for images for  THE CHOSEN PART and ITS COMPONENTS" << endl;
    cout << "4. Update by batch for images for COMPONENTS only" << endl;
    cout << "5. Update by batch for videos for COMPONENTS only " << endl;
    cout << "6. Update by batch for components name for COMPONENTS only" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "You are trying to do the following: " << endl;
            cout << "1. Updating all part images" << endl;
            cout << "2. Updating all component images" << endl;
            cout << "3. Updating all component videos" << endl;

            cout << endl;
            cout << "The expected format for the file is detailed below: " << endl;
        }
        break;
        case 2:
        {
            cout << "You are trying to do the following:" << endl;
            cout << "1. Updating all part images" << endl;
            cout << "2. Updating all component images" << endl;
        }
        break;
        case 3:
        {
            cout << "You are trying to do the following: " << endl;
            cout << "1. Updating the chosen part's image" << endl;
            cout << "2. Updating the images for all components for a chosen part " << endl;
        }
        break;
        case 4:
        {
            cout << "You are trying to do the following: " << endl;
            cout << "1. Updating the images for all components for a chosen part" << endl;
        }
        break;
        case 5:
        {
            cout << "You are trying to do the following: " << endl;
            cout << "1. Updating the videos for all components for a chosen part" << endl;
        }
        break;
        case 6:
        {
            cout << "You are trying to do the following: " << endl;
            cout << "1. Updating the name for all components for a chosen part" << endl;
        }
        break;
        case 0:
        {

        }
        break;
        default:
        {
            cout << ">> Invalid input <<" << endl;
            cout << "Please try again" << endl;
        }
    }


    bool check = false;
    int numParts = carParts.size();
    //int choice = -1;

    while (check == false)
    {
        cout << "Which car part do you wish to edit?" << endl;
        for(int i = 0; i < numParts; i++)
        {
            cout << i + 1 << ". \t";
            cout << carParts[i].getPartName() << endl;
        }
        //can't use swtich since we dont know how many component we might have
        cout << "0. \tExit" << endl;
        cout << "Input: ";
        cin >> choice;

        if (choice > 0 && choice < numParts + 1)
        {
            //if valid choice
            choice -= 1;
            //editBatchPart(choice);
        }
        else if (choice ==  0)
        {
            check = true;
        }
        else
        {
            cout << "Invalid choice" << endl;
            cout << "Please try again" << endl;
            check = false;
        }
    }

}

/*
void Car::editBatchPart(int selectedPart)
{
    int modifyChoice = -1;
    bool check = false; //used to make sure that user has keyed in correct choice and if he wishes to cont or not
    while (check == false)
    {
        cout << endl;
        cout << "What do you wish to modify by BATCH?" << endl;
        cout << "Current part being modified: " << carParts[selectedPart].getPartName() << endl;
        cout << "1. Part name" << endl;
        cout << "2. Part image" << endl;
        cout << "3. Add a component" << endl;
        cout << "4. Delete a component" << endl;
        cout << "5. Modify a component" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> modifyChoice;


        vector<component> tempComps = carParts[selectedPart].getComponent();
        int choice = -1;
        bool check = false;

        while (check == false)
        {
            if(tempComps.size() == 0)
            {
                cout << ">> There are no components to be updated by batch << " << endl;
                check = true; //we change it to true as there is nothing to be deleted
            }
            else
            {

            }
        }
    }
}
*/

void Car::outputFile(string fileName)
{
    ifstream infile;
    infile.open(fileName.c_str());

    if(infile.good())
    {
        while(!infile.eof())
        {
            string line;
            getline(infile, line, '\n');

            cout << line << endl;
        }
    }

    infile.close();
}

void Car::editIndividually()
{
    int numParts = carParts.size();
    int choice = -1;
    bool check = false;

    while (check == false)
    {
        cout << "Which car part do you wish to edit?" << endl;
        for(int i = 0; i < numParts; i++)
        {
            cout << i + 1 << ". \t";
            cout << carParts[i].getPartName() << endl;
        }
        //can't use swtich since we dont know how many component we might have
        cout << "0. \tExit" << endl;
        cout << "Input: ";
        cin >> choice;

        if (choice > 0 && choice < numParts + 1)
        {
            //if valid choice
            choice -= 1;
            editSelectedPart(choice);
        }
        else if (choice ==  0)
        {
            check = true;
        }
        else
        {
            cout << "Invalid choice" << endl;
            cout << "Please try again" << endl;
            check = false;
        }
    }
}

void Car::editSelectedPart(int selectedPart)
{
    int modifyChoice = -1;
    bool check = false; //used to make sure that user has keyed in correct choice and if he wishes to cont or not
    while (check == false)
    {
        cout << endl;
        cout << "What do you wish to modify?" << endl;
        cout << "Current part being modified: " << carParts[selectedPart].getPartName() << endl;
        cout << "1. Part name" << endl;
        cout << "2. Part image" << endl;
        cout << "3. Add a component" << endl;
        cout << "4. Delete a component" << endl;
        cout << "5. Modify a component" << endl;
        cout << "0. Quit" << endl;
        cout << "Choice: ";
        cin >> modifyChoice;

        switch(modifyChoice)
        {
            case 1:
            {
                cout << ">> Modifying part name <<" << endl;

                string temp;
                cout << "What is the new part name? " << endl;
                cout << "Part name: ";
                cin >> temp;

                carParts[selectedPart].setPartName(temp);
            }
            break;
            case 2:
            {
                cout << ">> Modifying part image <<" << endl;

                string temp;
                cout << "What is the new image file?" << endl;
                cout << "File name: ";
                cin >> temp;

                carParts[selectedPart].setPartImage(temp);
            }
            break;
            case 3:
            {
                cout << ">> Adding a component <<" << endl;

                string temp;
                component tempComp;

                cout << "What is the name of the new component? " << endl;
                cout << "New component name: ";
                cin >> temp;
                tempComp.componentName = temp;

                cout << "What is the image file for this component?" << endl;
                cout << "Image file: ";
                cin >> temp;
                tempComp.componentImage = temp;

                cout << "What is the video file for this component?" << endl;
                cout << "Video file: ";
                cin >> temp;
                tempComp.componentVideo = temp;

                cout << "What is the component description?" << endl;
                cout << "Component description: ";
                cin >> temp;
                tempComp.componentDescription = temp;

                //add 1 value for the component
                carParts[selectedPart].addNoComponents();
                carParts[selectedPart].addComponent(tempComp);
            }
            break;
            case 4:
            {
                cout << ">> Deleting a component <<" << endl;

                vector<component> tempComps = carParts[selectedPart].getComponent();
                int choice = -1;
                bool check = false;

                while (check == false)
                {
                    if(tempComps.size() == 0)
                    {
                        cout << ">> There are no components to be deleted << " << endl;
                        check = true; //we change it to true as there is nothing to be deleted
                    }
                    else
                    {
                        int noComponent = tempComps.size();
                        //list the components for the part of the car
                        cout << "Which component do you want to delete? " << endl;
                        for(int i = 0; i < noComponent; i++)
                        {
                            cout << i + 1 << ". \t";
                            cout << tempComps[i].componentName << endl;
                        }
                        cout << "0. \tExit" << endl;
                        cout << "Choice: ";
                        cin >> choice;

                        if (choice > 0 && choice < noComponent + 1)
                        {
                            //valid choice
                            choice -= 1;

                            int userChoice = -1;
                            cout << "We are attempting to delete " << tempComps[choice].componentName << endl;
                            cout << "Are you sure? " << endl;
                            cout << "1. Yes" << endl;
                            cout << "2. No" << endl;
                            cout << "Choice: ";
                            cin >> userChoice;

                            //only check if user wants to delete or not, if yes then delete
                            if (userChoice == 1)
                            {
                                carParts[selectedPart].clearComponentVector();

                                for(int i = 0; i < noComponent; i++)
                                {
                                    //if it is the one the user has deleted, we dont write it in
                                    if (i != choice)
                                    {
                                        carParts[selectedPart].addComponent(tempComps[i]);
                                    }
                                }
                                //refresh the vector with the updated one
                                tempComps.clear();
                                tempComps = carParts[selectedPart].getComponent();
                            }
                        }
                        else if (choice == 0)
                        {
                            check = true;
                        }
                        else
                        {
                            cout << ">> Invalid input. <<" << endl;
                            cout << "Please try again " << endl;
                            check = false;
                        }

                    }

                }
                //DEleting function ends here
            }
            break;
            case 5:
            {
                cout << ">> Modifying a component <<" << endl;

                vector<component> tempComps = carParts[selectedPart].getComponent();
                int choice = -1;
                bool check = false;

                while (check == false)
                {
                    if(tempComps.size() == 0)
                    {
                        cout << ">> There are no components to be modified << " << endl;
                        check = true; //we change it to true as there is nothing to be modified
                    }
                    else
                    {
                        int noComponent = tempComps.size();
                        //list the components in the part of the car
                        cout << "Which component do you want to modify? " << endl;
                        for(int i = 0; i < noComponent; i++)
                        {
                            cout << i + 1 << ". \t";
                            cout << tempComps[i].componentName << endl;
                        }
                        cout << "0. \tExit" << endl;
                        cout << "Choice: ";
                        cin >> choice;

                        if (choice > 0 && choice < noComponent + 1)
                        {
                            //valid choice
                            choice -= 1;
                            int userChoice = -1;
                            //changesMade variable used for reloading the latest vector when a change has been madeeeeeee
                            bool changesMade = false;

                            cout << "What do you wish to modify for " << tempComps[choice].componentName << "?" << endl;
                            cout << "1. Component name" << endl;
                            cout << "2. Component image file" << endl;
                            cout << "3. Component video file" << endl;
                            cout << "4. Component description" << endl;
                            cout << "0. Exit" << endl;
                            cout << "Choice: ";
                            cin >> userChoice;

                            switch(userChoice)
                            {
                                case 1:
                                {
                                    string temp;
                                    cout << "What is the modified component name?" << endl;
                                    cout << "Component name: ";
                                    cin >> temp;

                                    carParts[selectedPart].editComponentName(choice, temp);
                                    changesMade = true;
                                }
                                break;
                                case 2:
                                {
                                    string temp;
                                    cout << "What is the modified image file?" << endl;
                                    cout << "Image file: ";
                                    cin >> temp;

                                    carParts[selectedPart].editComponentImage(choice, temp);
                                    changesMade = true;
                                }
                                break;
                                case 3:
                                {
                                    string temp;
                                    cout << "What is the modified video file?" << endl;
                                    cout << "Video file: ";
                                    cin >> temp;

                                    carParts[selectedPart].editComponentVideo(choice, temp);
                                    changesMade = true;
                                }
                                break;
                                case 4:
                                {
                                    string temp;
                                    cout << "What is the modified component description?" << endl;
                                    cout << "Component description: ";
                                    cin >> temp;

                                    carParts[selectedPart].editComponentDescription(choice, temp);
                                    changesMade = true;
                                }
                                break;
                                case 0:
                                {
                                    changesMade = false;
                                }
                                break;
                                default:
                                {
                                    cout << ">> Invalid input << " << endl;
                                    cout << "Please try again" << endl;
                                }
                            }

                            //refresh the vector with the updated one if changes were made
                            if(changesMade)
                            {
                                tempComps.clear();
                                tempComps = carParts[selectedPart].getComponent();
                            }
                        }
                        else if (choice == 0)
                        {
                            check = true;
                        }
                        else
                        {
                            cout << ">> Invalid input. <<" << endl;
                            cout << "Please try again " << endl;
                            check = false;
                        }
                    }
                }
                //MODIFying function ends here
            }
            break;
            case 0:
            {
                cout << ">> Exiting <<" << endl;
                check = true;
            }
            break;
            default:
            {
                cout << ">> Invalid choice <<" << endl;
                cout << "Please try again" << endl;
            }
        }
    }
    //end of first while loop
}

void Car::writeToFile()
{
    cout << ">> Writing to file << " << endl;

    ofstream outfile;
    outfile.open("test.txt");

    outfile << hierarchyNumber.size() << endl;
    for(int i = 0; i < hierarchyNumber.size(); i++)
    {
        if(i == hierarchyNumber.size() - 1)
        {
            outfile << hierarchyNumber[i] << endl;
        }
        else
        {
            outfile << hierarchyNumber[i] << ",";
        }
    }

    for(int i = 0; i < carParts.size(); i++)
    {
        if(i == carParts.size() - 1)
        {
            outfile << carParts[i];
        }
        else
        {
            outfile << carParts[i] << endl;
        }
    }

    outfile.close();
}
