#include "CarPart.h"
#include <iostream>
#include <vector>

using namespace std;

//overloaded output operator for writing to file
ostream& operator<< (ostream& out, const CarPart& temp)
{
    out << temp.partName << ",";
    out << temp.partImage << ",";
    if(temp.noComponents == 0)
    {
        out << temp.noComponents;
    }
    else
    {
        out << temp.noComponents << endl;
    }

    if(temp.noComponents != 0)
    {
        for(int i = 0; i < temp.noComponents; i++)
        {
            out << temp.carComponents[i].componentName << ",";
            out << temp.carComponents[i].componentImage << ",";
            out << temp.carComponents[i].componentVideo << ",";
            if(i == temp.noComponents - 1)
            {
                out << temp.carComponents[i].componentDescription;
            }
            else
            {
                out << temp.carComponents[i].componentDescription << endl;
            }
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

void CarPart::addNoComponents()
{
    noComponents++;
}

void CarPart::clearComponentVector()
{
    carComponents.clear();

    cout << carComponents.size() << endl;
}

//used for editing a specific component
void CarPart::editComponentName(int position, string componentName)
{
    carComponents[position].componentName = componentName;
}

void CarPart::editComponentImage(int position, string componentImage)
{
    carComponents[position].componentImage = componentImage;
}

void CarPart::editComponentDescription(int position, string componentDescription)
{
    carComponents[position].componentDescription = componentDescription;
}

void CarPart::editComponentVideo(int position, string componentVideo)
{
    carComponents[position].componentVideo = componentVideo;
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

string CarPart::getPartName() const
{
    return partName;
}

void CarPart::display()
{
    cout << "Part ID: " << partID << endl;
    cout << "Part name: " << partName << endl;
    cout << "Part image: " << partImage << endl;
    cout << "Number of components: " << noComponents << endl;

    //for displaying the components of the car part

    if (noComponents != 0)
    {
        for(int i = 0; i < noComponents; i++)
        {
            cout << "Component number: " << i << endl;
            cout << "Component name: " << carComponents[i].componentName << endl;
            cout << "Component image: " << carComponents[i].componentImage << endl;
            cout << "Component video: " << carComponents[i].componentVideo << endl;
            cout << "Component description: " << carComponents[i].componentDescription << endl;
        }

    }

    /*
    //for displaying the siblings
    cout << "Siblings: ";
    for(int i = 0; i < siblings.size(); i++)
    {
        if (i == siblings.size() - 1)
        {
            cout << siblings[i] << endl;
        }
        else
        {
            cout << siblings[i] << ",";
        }
    }
    */
}
