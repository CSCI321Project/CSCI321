#include "Car.h"
#include "CarPart.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

Car::Car(string fileName)
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
                    //get the component description
                    getline(infile, tempString, '\n');
                    tempComp.componentDescription = tempString;

                    tempCarPart.addComponent(tempComp);
                }
            }
            carParts.push_back(tempCarPart);
            //cout << tempCarPart << endl;
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
                    //cout << carParts[count] << endl;

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
                    //cout << carParts[siblingIDs[k]] << endl;
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

Car::~Car()
{

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

    for(int i = 0; i < currentParts.size(); i++)
    {
        cout << currentParts[i] << endl;
    }
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

                component tempComp;
                string temp;
                cout << "What is the name of the new component? " << endl;
                cout << "NEw component name: ";
                cin >> temp;
                tempComp.componentName = temp;

                cout << "What is the image file for this component?" << endl;
                cout << "Image file: ";
                cin >> temp;
                tempComp.componentImage = temp;

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

                for(int i = 0; i < tempComps.size(); i++)
                {
                    cout << tempComps[i].componentName << endl;
                }
            }
            break;
            case 5:
            {
                cout << ">> Modifying a component <<" << endl;
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
