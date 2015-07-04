#include "CarPart.h"
#include <iostream>
#include <vector>

using namespace std;

//overloaded output operator for viewing/testing
ostream& operator<< (ostream& out, const CarPart& temp)
{
    out << "Part ID: " << temp.partID << endl;
    out << "Part name: " << temp.partName << endl;
    out << "Part image: " << temp.partImage << endl;
    out << "Number of components: " << temp.noComponents << endl;

    //for displaying the components of the car part
    /*
    if (temp.noComponents != 0)
    {
        for(int i = 0; i < temp.noComponents; i++)
        {
            out << "Component number: " << i << endl;
            out << "Component name: " << temp.carComponents[i].componentName << endl;
            out << "Component image: " << temp.carComponents[i].componentImage << endl;
            out << "Component description: " << temp.carComponents[i].componentDescription << endl;
        }

    }
    */

    //for displaying the siblings
    cout << "Siblings: ";
    for(int i = 0; i < temp.siblings.size(); i++)
    {
        if (i == temp.siblings.size() - 1)
        {
            cout << temp.siblings[i] << endl;
        }
        else
        {
            cout << temp.siblings[i] << ",";
        }
    }

    return out;
}


CarPart::CarPart()
{
    partID = 0;
    partName = "";
    noComponents = 0;
    parentID = -1;
    topNode = false;
}

CarPart::~CarPart()
{

}

//set functions
void CarPart::setTopNode()
{
    topNode = true;
}

void CarPart::setPartID(int tempID)
{
    partID = tempID;
}

void CarPart::setPartName(string tempPartName)
{
    partName = tempPartName;
}

void CarPart::setPartImage(string tempPartImage)
{
    partImage = tempPartImage;
}

void CarPart::setNoComponents(int tempNoComp)
{
    noComponents = tempNoComp;
}

void CarPart::addComponent(component tempComp)
{
    carComponents.push_back(tempComp);
}

void CarPart::setParent(int tempID)
{
    parentID = tempID;
}

void CarPart::addSiblings(vector<int> tempSiblings)
{
    siblings = tempSiblings;
}

//get functions
int CarPart::getNoComponents() const
{
    return noComponents;
}

vector<component> CarPart::getComponent() const
{
    return carComponents;
}

vector<int> CarPart::getSiblings() const
{
    return siblings;
}

int CarPart::getParentID() const
{
    return parentID;
}
