#include <iostream>
#include <fstream>
#include <Windows.h>

//Windows.h for Sleep
using namespace std;


//Calculating the altitude is an extension of the calculation of the distance travelled per second.


/*
	USAGE:
	Set the speed variable to the speed from the UI
	Use the incline variable to set the value of the incline in % value. Note that you must also do theEngine().setIncline(incline) to set the incline % for the engine calculation too. Best done at the button
	Use the total distance to find out the odometer value. Note that the odometer value is stored in a text fine as odometer.txt
	Use the trip to find out the trip value. Note that if you restart the program, the trip value isnt saved
	Don't forget to enable theEngine().setAltitude(totalAltitude) , just before the Sleep (1000);

	You would most likely need to move the odometer output code (last 3 lines before the sleep) to the part when you quit the program. If in this case, make the variables here as global if needed to be able to access.
	The best place to put the output code to the place when the engine is stopped, you write to the file

*/

int main()
{
	//Declare a couple of variables
	bool setupOdo = false;
	float speed = 0;
	float trip = 0;
	float time = 0.000277778;
	float distancePerSecond = 0;
	float totalDistance = 0;
	float incline = 5; //the percentage value goes here...<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	float decimalPercentGrade;
	float inclineIncrease;
	float totalAltitude = 0;
	float counter = 0;
	ofstream outfile;
	ifstream infile;
	//Calculate the distance travelled per second
	for (;;)
	{
		if (setupOdo == false)
		{
			infile.open("odometer.txt");

			if (infile.good())
			{
				infile >> totalDistance;
				infile.close();
			}
			else
			{
				//In the event should the file go missing, 
				totalDistance = 0;
			}

			setupOdo = true;
		}
		

		speed = 100;  //Replace this value (100) in speed with theEngine().getSpeed()
		//Speed = distance/time
		//Therefore distance = speed * time

		distancePerSecond = speed * time;

		//Incline calculation here....
		//Calculate the decimal percentGrade

		//If incline is a negative, that is when we begin reducing the altitude
		decimalPercentGrade = incline / 100;

		//Multiply with the amount of distance we have travelled 
		inclineIncrease = decimalPercentGrade * distancePerSecond;

		//update the altitude
		totalAltitude = totalAltitude + inclineIncrease;

		//We need to ensure we dont go below sea level, that is altitude should alwayds be above 0
		if (totalAltitude < 0)
		{
			totalAltitude = 0;
		}
		//Add on to total distance
		totalDistance = totalDistance + distancePerSecond;
		trip = trip + distancePerSecond;
		cout << "Distance travelled totally: " << totalDistance << endl;
		cout << "Altitude: " << totalAltitude << endl;
		
		//Set the incline in the engine >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//theEngine().setAltitudeKilometres(totalAltitude);

		//As this runs infinitely, just to ensure the odometer value is saved...
		outfile.open("odometer.txt");
		outfile << totalDistance;
		outfile.close();

		Sleep(1000); //Sleep for a second

		//For testing 
		/*counter++;
		if (counter == 10)
		{
			//test with a -ve incline
			cout << endl << "QQQ" << endl;
			incline = -5;
		}*/
	}
}