/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 6
 Created: 6/08/2021


 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program uses the Circle class to generate some metrics on a circle.  It also uses input validation when prompting the user
 to enter the radius of the circle to prevent negative values by setting the radius to 0 and informing the user.  Once a radius
 is entered, the program will call the other class methods to display calculated data (using PI as a constant 3.14) about the
 circle based on the radius entered.

 When the radius is input, it will display these metrics:

 Circle Statistics:
 ------------------
		Radius: (as entered)
	  Diameter: radius * 2
		  Area: pi * radius * radius
 Circumference: 2 * pi * radius

 Class File used: Circle.h and Circle.cpp

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Circle.h"

using namespace std;


//The main program function
int main()
{
	//Setup loop variables to collect user input and control the loop repeat
	bool again = false;
	char choice = 'N';
	
	//Prompt the user with a welcome
	cout << "Welcome to the system that will help calculate statistics for a circle." << endl;
	
	//Setup an object from the circle class
	Circle circle;

	//Setup a loop to see if the user wants to repeat the circle calculation
	do
	{
		//Reset the loop flag
		again = false;

		//Call the function from the object to collect the user input and store the radius
		circle.RadiusInput();

		//Call the function to display the calculations
		circle.DisplayCalculations();

		//Prompt the user to see if they want to repeat the program
		cout << "\nWould you like to measure another circle (Y/N)?";
		cin >> choice;
			//Input validation to accept only Y or N inputs
			while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
			{
				cout << "Invalid Input.  Enter Y or N: ";
				cin >> choice;
			}

		//Check the input for both forms of y and switch the flag to true
		if (choice == 'Y' || choice == 'y')
		{
			again = true;
		}

	} while (again == true);

	//Prompt to close the program
	cout << "\nThank you for using the system.  Press the enter key to close...";
	cin.ignore();
	cin.get();

	return 0;
}