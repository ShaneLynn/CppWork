/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 6
	Created: 3/23/2021
*
*Description:
 This program will calculate the number of slices a pizza can be divided into based on user input.  And, it also
 determines how many pizzas should be ordered for a party using the following criterria.  It will show the user the final
 estimations for the number of slices available per pizza of that size, and how many of those size pizzas will be needed to 
 feed all of the guests at the party. :

*	The calculations in the program are based on the following data:
		-PI is 3.14159
*		-Slice area must be 14.125
		-Each person will eat 3 slices each
		-Guests and pizza size are determined by the user
*		-Area = PI * r2
		-Radius = diameter / 2
*		-Number of slices needed must be rounded to one decimal place
		-Pizzas needed must be rounded up to a whole number
* 
* 
*Pseudocode:

*START
*	Include header files iomanip, cmath, and iostream
*
	Declare variables:
*		constant double PI
		constant double SLICE_AREA
		int partyPeople
		int slicesPerPerson
*		double pizzaDiameter
*		double pizzaArea
*		double pizzaRadius
*		double slicesPerPizza
*		double slicesNeeded
*		double pizzasNeeded
*	
	Initialize variables:
		PI = 3.14159
		SLICE_AREA = 14.125
		slicesPerPerson = 3
*
*	Collect Data from user:
*		Display "Enter the diameter of the pizza you would like: "
*		Input to pizzaDiameter
*
*		Display "How many people will be at the party? "
*		Input to partyPeople
*

*	Calculate variables:
		pizzaRadius = pizzaDiameter / 2
*		pizzaArea = PI * pow(pizzaRadius, 2)
		slicesPerPizza = pizzaArea / SLICE_AREA
*		slicesNeeded = slicesPerPerson * partyPeople
		pizzasNeeded = round(slicesNeeded / slicesPerPizza)
*

*	Display setprecision to 1, fixed, showpoint
*	Display "\newline"
	Display "Here are our calculations for your party: " 
	Display "Requested pizza diamater (inches): " << pizzaDiameter << ", and total expected party attendees: " << partyPeople
*	Display "Estimated slices per person: " << slicesPerPerson
	Display "Total slices available per pizza: " << slicesPerPizza
*	Display "Total pizza's needed for the party: " << pizzasNeeded
*	Display "\newline"

*END
***************************************************************************************************************************/



//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//The main program function
int main()
{
	//Variables
	const double PI = 3.14159;			//Constant variable that holds the value of Pi for caclulations
	const double SLICE_AREA = 14.125;	//Constant variable that holds the standard size of slice area per shop criteria.	
	const int slicesPerPerson = 3;		//Constant variable that holds the estimated slices per person per shop criteria.
	int partyPeople;					//Holds user provided data on total people at the party
	double pizzaDiameter;				//Holds user provided data on the desired pizza diamater size in inches
	double pizzaArea;					//Calculated field that holds the pizza's area based on the diameter provided
	double pizzaRadius;					//Calculated field that holds the pizza's diameter based on the provided diameter
	double slicesPerPizza;				//Calculated field that holds the total slices available based on slice area and pizza area
	double slicesNeeded;				//Calculated field that holds the total slices needed based on the people provided
	double pizzasNeeded;				//Calculated field that holds the total pizzas needed by the customer for the party

	//Collect the input from the user for each field
	cout << "Welcome to the party slice estimator for Tony's Pizza Palace!";
	cout << "\n";

	cout << "\nEnter the diameter (in inches) of the pizza you would like: ";
	cin >> pizzaDiameter;

	cout << "How many people will be at the party? ";
	cin >> partyPeople;


	//Calculate the metrics to determine the pizza slices available/needed based on user input to get the total pizzas needed to purchase
	pizzaRadius = pizzaDiameter / 2;
	pizzaArea = PI * pow(pizzaRadius, 2);
	slicesPerPizza = pizzaArea / SLICE_AREA;
	slicesNeeded = slicesPerPerson * partyPeople;
	pizzasNeeded = ceil(slicesNeeded / slicesPerPizza);

	//Format the variable output for one decimal place rounding
	cout << fixed << showpoint << setprecision(1);

	//Display the results of the calculations for the user
	cout << "\n";
	cout << "Here are our calculations for your party: ";
	cout << "\nRequested pizza diamater (inches): " << pizzaDiameter;
	cout << "\nTotal expected party attendees: " << partyPeople;
	cout << "\nEstimated slices per person: " << slicesPerPerson;
	cout << "\nTotal slices available per pizza: " << slicesPerPizza;
	cout << "\nTotal slices needed for the party: " << slicesNeeded;
	cout << "\nTotal pizza's needed for the party: " << pizzasNeeded;
	cout << "\n";

	return 0;
}
