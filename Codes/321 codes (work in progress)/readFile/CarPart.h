#include <iostream>
#include <vector>

#ifndef _CARPART_
#define _CARPART_

struct component
{
    std::string componentName;
    std::string componentImage; //the image of the component to be changed to when clicked
    std::string componentDescription;
};

class CarPart
{
    friend std::ostream& operator<< (std::ostream&, const CarPart&);
    private:
        bool topNode;

        int partID; //used to compare against the hierarchy number
        std::string partName;
        std::string partImage;
        int noComponents; //number of componenets for this part of the car
        std::vector<component> carComponents; //stores the different componenets of the car and their description and also their images when clicked
        int parentID; //id of the parent
        std::vector<int> siblings; //the id of their siblings
        //vector<int> child;
    public:
        CarPart();
        ~CarPart();

        //set functions
        void setTopNode();

        void setPartID(int);
        void setPartName(std::string);
        void setPartImage(std::string);
        void setNoComponents(int); //sets the number of component
        void addComponent(component); //actually adds a component in
        void setParent(int);
        void addSiblings(std::vector<int>);

        void addNoComponents(); //adds (BY 1) the value of the number of components
        void reduceNoComponents(); //reduce by 1 the no of components
        void clearComponentVector(); //used in the delete function

        //used for editing a specific component
        void editComponentName(int, std::string);
        void editComponentImage(int, std::string);
        void editComponentDescription(int, std::string);

        //get functions
        std::vector<component> getComponent() const;
        int getNoComponents() const;
        std::vector<int> getSiblings() const;
        int getParentID() const;
        std::string getPartName() const;
};
#endif // _CARPART_
