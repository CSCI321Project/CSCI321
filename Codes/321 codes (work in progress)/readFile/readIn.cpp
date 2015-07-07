#include <iostream>
#include <fstream>
#include "Car.h"

using namespace std;

int main()
{
    Car car("Car part descriptions.txt"); //change the input file name here
    //car.getCurrentCarParts(2);
    car.zoomOut(5);
    car.textEditorMenu();

    /*
        //5 means have 6 more child nodes, the next 5 lines would be included in the vector of classes
        5,0,0,0,0,4,0,0,0,0
        corner,cornerImage,0 (no description for this part)
        front,frontImage,13
        back,backImage,13
        side,sideImage,10
        top,topImage,3
        interior,interiorImage,12
        interiorSteering,interiorSteerigImage,13
        interiorPedals,interiorPedalImage,11
        interiorSeats,interiorSeatsImage,4
    */

    return 0;
}
