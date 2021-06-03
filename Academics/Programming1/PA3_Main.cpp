/***********************************************************************************************
*Author: Christopher S Lynn
		CISS 241 -  Programming I
*		Programming Assignment 3
		Created: 3/18/2021
*
*Description:

*This program will calculate and display the miles per gallon a car has based on its fuel
*tank capacity and if the vehicle is driving on the highway or in the city.

*Pseudocode:

*START
	Declare variables:
*		double maxGasTank
		double totalTankMilesCity
*		double totalTankMilesHwy
		double cityMPG
*		double hwyMPG

*	Initialize variables:
		maxGasTank = 16
*		totalTankMilesCity = 345.0
		totalTankMilesHwy = 460.0
*		
	cityMPG = totalTankMilesCity / maxGasTank
*	hwyMPG = totalTankMilesHwy  / maxGasTank

*	Display "With a full tank of " maxGasTank " gallons of fuel: "
	Display "The vehicle will get " cityMPG " MPG in the city and " hwyMPG " MPG on the highway."
*END
*************************************************************************************************/


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Variables
	int maxGasTank;					//Holds the maximum gallons of fuel the car can hold
	double totalTankMilesCity;		//Holds the total miles the car can drive on the city with a full tank
	double totalTankMilesHwy;		//Holds the total miles the car can drive on the highway with a full tank
	double cityMPG;					//Holds the MPG calculation for city driving
	double hwyMPG;					//Holds the MPG calculation for highway driving

	//Initialize the variables with driving values
	maxGasTank = 16;
	totalTankMilesCity = 345.0;
	totalTankMilesHwy = 460.0;


	//Calculate the miles per gallon(MPG) for each driving type
	cityMPG = totalTankMilesCity / maxGasTank;
	hwyMPG = totalTankMilesHwy / maxGasTank;

	//Format the variable output to display rounded decimal places for the calculations
	cout << fixed << showpoint << setprecision(3);

	//Display the results of the calculations for each driving type
	cout << "With a full tank of " << maxGasTank << " gallons of fuel:\n";
	cout << "The vehicle will get " << cityMPG << " MPG in the city and " << hwyMPG << " MPG on the highway.\n";

	return 0;
}
