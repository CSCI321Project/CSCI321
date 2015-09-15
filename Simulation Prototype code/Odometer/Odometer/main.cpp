#include <iostream>
#include <Windows.h>

//Windows.h for Sleep
using namespace std;

int main()
{
	//Declare a couple of variables
	float speed = 0;
	float time = 0.000277778;
	float distancePerSecond = 0;
	float totalDistance = 0;

	//Calculate the distance travelled per second
	for (;;)
	{
		speed = 100;  //Replace this value (100) in speed with theEngine().getSpeed()
		//Speed = distance/time
		//Therefore distance = speed * time

		distancePerSecond = speed * time;

		//Add on to total distance
		totalDistance = totalDistance + distancePerSecond;

		cout << "Distance travelled totally: " << totalDistance << endl;

		Sleep(1000); //Sleep for a second

	}
}