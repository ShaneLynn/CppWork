/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 7
	Created: 3/30/2021
*
* 
---------------------------------------------------------------------------------------------------------------------------
*Description:
 This program is a calculator to determine the area for a circle, rectangle, triangle, trapezoid, and sphere.  The
 program will display a menu to the user with 6 options, validate input, and use that input to branch into the item the user wants to calculate.
 Once in one of the branches, the program will ask the user for input based on the type of shape selected and then calculate the area of that shpare.
 One of the six options will be to exit the program. The program will terminate if any invalid inputs (negative numbers) are made.

*	The calculations in the program are based on the following data:
		-PI is 3.14159
		-User determines the menu choice and formula variables
*		-Circle area = PI * r2
		-Rectangle area = length * width
		-Triangle area = base * height * 0.5
		-Trapezoid area = height/2 * (b1 +b2)
		-Sphere area = 4 * PI *r2
•	
	This program should display the following menu:
		Calculator Options:
		1.	Calculate the area of a circle
		2.	Calculate the area of a rectangle
		3.	Calculate the area of a triangle
		4.	Calculate the area of a trapezoid
		5.	Calculate the area of a sphere
		6.	Exit Enter your choice (1-6)
*
*
**Pseudocode:

*START
*	Include header files iomanip, cmath, and iostream
*
	Declare variables:
*		constant double PI
		int menuChoice

*		double circleArea
*		double rectangleArea
*		double triangleArea
*		double trapezoidArea
*		double sphereArea
* 
*		double circleRadius
*		double rectangleLength
*		double rectangleWidth
*		double triangleBase
*		double triangleHeight
*		double trapHeight
*		double trapBase1
*		double trapBase2
*		double sphereRadius
* 
*
	Initialize variables:
		PI = 3.14159

		
		
*	Collect Data from user:
*		Display "Please choose from the following menu:"

*			"Calculator Options:"
			"1.	Calculate the area of a circle"
			"2.	Calculate the area of a rectangle"
			"3.	Calculate the area of a triangle"
			"4.	Calculate the area of a trapezoid"
			"5.	Calculate the area of a sphere"
			"6.	Exit"
			"Enter your choice (1-6)"

		Input to menuChoice
			if menuChoice is < 1 OR > 6
				Display menuChoice << " is not a valid choice, please enter numbers: 1, 2, 3, 4, 5, or 6."
					
					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit
*
*	 	Calculation formulas for variables (Each one will be in corresponding section of switch statement):
*
*			circleArea = PI * pow(circleRadius, 2)
*			rectangleArea = rectangleLength * rectangleWidth
*			triangleArea = triangleBase * triangleHeight * 0.5
*			trapezoidArea = trapHeight/2 * (trapBase1 + trapBase2)
*			sphereArea = 4 * PI * pow(sphereRadius, 2)
* 
*		Display << fixed << showpoint << setprecision(2);
* 
*		Switch (menuChoice)
*			case 1:
*				Display "You Selected: Calculating the area of a circle"
*				Display "\newline"
*				Display "\newline"
				Display "Enter the radius of the circle: "
				Input to circleRadius
					if circleRadius is < 0
					Display circleRadius << " is not valid for the radius, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit
					
				Calculate variables:
*					circleArea = PI * pow(circleRadius, 2)
* 
				Display "\newline"
				Display "Based on the radius of " << circleRadius
				Display "\newline"
				Display " The circle's area is: " << circleArea
				Display "\newline"
				Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.get() to pause until user enters something
				
				break out

			case 2:
*				Display "You Selected: Calculating the area of a rectangle"
*				Display "\newline"
*				Display "\newline"
				Display "Enter the length of the rectangle: "
				Input to rectangleLength
					if rectangleLength is < 0
					Display rectangleLength << " is not valid for the length, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

*				Display "Enter the width of the rectangle: "
				Input to rectangleWidth
					if rectangleWidth is < 0
					Display rectangleWidth << " is not valid for the width, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

				Calculate variables:
*					rectangleArea = rectangleLength * rectangleWidth
* 
				Display "\newline"
				Display "Based on the length of " << rectangleLength << " and the width of " << rectangleWidth
				Display "\newline"
				Display "The rectangle's area is: " << rectangleArea
				

				break out

			case 3:
*				Display "You Selected: Calculating the area of a triangle"
*				Display "\newline"
*				Display "\newline"
				Display "Enter the base of the rectangle: "
				Input to triangleBase
					if triangleBase is < 0
					Display triangleBase << " is not valid for the base, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit
*				
				Display "Enter the height of the rectangle: "
				Input to triangleHeight
					if triangleHeight is < 0
					Display triangleHeight << " is not valid for the height, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

				Calculate variables:
*					triangleArea = triangleBase * triangleHeight * 0.5
*
				Display "\newline"
				Display "Based on the base of " << triangleBase << " and the height of " << triangleHeight
				Display "\newline"
				Display "The triangle's area is: " << triangleArea
				

				break out

			case 4:
*				Display "You Selected: Calculating the area of a trapezoid"
*				Display "\newline"
*				Display "\newline"
				Display "Enter the height of the trapezoid: "
				Input to trapHeight
					if trapHeight is < 0
					Display trapHeight << " is not valid for the height, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

*				Display "Enter base 1 of the trapezoid: "
				Input to trapBase1
					if trapBase1 is < 0
					Display trapBase1 << " is not valid for base 1, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

				Display "Enter base 2 of the trapezoid: "
				Input to trapBase2
					if trapBase2 is < 0
					Display trapBase2 << " is not valid for base 2, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit


				Calculate variables:
*					trapezoidArea = trapHeight/2 * (trapBase1 + trapBase2)
*
				Display "\newline"
				Display "Based on the height of " << trapHeight << " , base 1 of " << trapBase1 << " , and base 2 of " << trapBase2
				Display "\newline"
				Display "The trapezoid's area is: " << trapezoidArea
				

				break out

			case 5:
*				Display "You Selected: Calculating the area of a sphere"
*				Display "\newline"
*				Display "\newline"
				Display "Enter the radius of the sphere: "
				Input to sphereRadius
					if sphereRadius is < 0
					Display sphereRadius << " is not valid for the radius, please enter 0 or higher."

					Display "Thanks for using the calculator!  Press any key to close the program..."
					Input.Ignore() to flush the buffer
					Input.get() to pause until user enters something
					Program will return 0 to exit

				Calculate variables:
*					sphereArea = 4 * PI * pow(sphereRadius, 2)
* 
				Display "\newline"
				Display "Based on the radius of " << sphereRadius
				Display "\newline"
				Display " The sphere's area is: " << sphereArea
				

				break out

			case 6:
*				Display "You Selected: Exit"
*				Display "\newline"
*				Display "\newline"
				
				break out
	
	Display "\newline"
	Display "Thanks for using the calculator!  Press any key to close the program..."
	Input.Ignore() to flush the buffer
	Input.get() to pause until user enters something

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
	int menuChoice;						//Variable that holds the menu choices
	double circleArea;					//Variable that holds the circle area calculation
	double rectangleArea;				//Variable that holds the rectangle area calculation
	double triangleArea;				//Variable that holds the triangle area calculation
	double trapezoidArea;				//Variable that holds the trapezoid area calculation
	double sphereArea;					//Variable that holds the sphere area calculation
	double circleRadius;				//Variable that holds the user input for circle radius
	double rectangleLength;				//Variable that holds the user input for rectangle length
	double rectangleWidth;				//Variable that holds the user input for rectangle width
	double triangleBase;				//Variable that holds the user input for triangle base
	double triangleHeight;				//Variable that holds the user input for triangle height
	double trapHeight;					//Variable that holds the user input for trapezoid height
	double trapBase1;					//Variable that holds the user input for trapezoid base 1
	double trapBase2;					//Variable that holds the user input for trapezoid base 2
	double sphereRadius;				//Variable that holds the user input for sphere radius	
	

	//Display the menu to the user
	cout << "Please choose from the following menu:";
	cout << "\nCalculator Options:";
	cout << "\n1.	Calculate the area of a circle";
	cout << "\n2.	Calculate the area of a rectangle";
	cout << "\n3.	Calculate the area of a triangle";
	cout << "\n4.	Calculate the area of a trapezoid";
	cout << "\n5.	Calculate the area of a sphere";
	cout << "\n6.	Exit ";
	cout << "\nEnter your choice (1-6): ";
	

	//Collect user choice for the menu, valdidate input and close the program if choices are incorrect.
	cin >> menuChoice;
		if (menuChoice  < 1 || menuChoice > 6)
		{
			cout << "\n";
			cout << "Your choice " << menuChoice << ", is not a valid choice, please enter numbers: 1, 2, 3, 4, 5, or 6.";
			cout << "\n";
			cout << "Thanks for using the calculator!  Press any key to close the program...";
			cin.ignore();
			cin.get();
			return 0;
		}
		//Setup display for areas to two decimal places	
		cout << fixed << showpoint << setprecision(2);
	
	switch (menuChoice)
	{
		//Circle option user input and calculation display
	case 1:
		cout << "\nYou Selected: Calculating the area of a circle";
		cout << "\n";
		cout << "\n";
		cout << "Enter the radius of the circle: ";
		cin >> circleRadius;
			if (circleRadius < 0) //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << circleRadius << ", is not valid for the radius, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		//Calculate the area
		circleArea = PI * pow(circleRadius, 2);

		//Display Results
		cout << "\n";
		cout << "Based on the radius of " << circleRadius;
		cout << "\n";
		cout << "The circle's area is: " << circleArea;

		break;
		
		//Rectangle option user input and calculation display
	case 2:
		cout << "\nYou Selected: Calculating the area of a rectangle";
		cout << "\n";
		cout << "\n";
		cout << "Enter the length of the rectangle: ";
		cin >> rectangleLength;  
			if (rectangleLength < 0) //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << rectangleLength << ", is not valid for the length, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		cout << "Enter the width of the rectangle: ";
		cin >> rectangleWidth;  
			if (rectangleWidth < 0) //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << rectangleWidth << ", is not valid for the width, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		//Calculate area variable
		rectangleArea = rectangleLength * rectangleWidth;
		
		//Display Results
		cout << "\n";
		cout << "Based on the length of " << rectangleLength << " and the width of " << rectangleWidth;
		cout << "\n";
		cout << "The rectangle's area is: " << rectangleArea;

		break;
				
		//Triangle option user input and calculation display
	case 3:
		cout << "\nYou Selected: Calculating the area of a triangle";
		cout << "\n";
		cout << "\n";
		cout << "Enter the base of the triangle: ";
		cin >> triangleBase;
			if (triangleBase < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << triangleBase << ", is not valid for the base, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		cout << "Enter the height of the triangle: ";
		cin >> triangleHeight;
			if (triangleHeight < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << triangleHeight << ", is not valid for the height, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		//Calculate area variable
		triangleArea = triangleBase * triangleHeight * 0.5;
		
		//Display Results
		cout << "\n";
		cout << "Based on the base of " << triangleBase << " and the height of " << triangleHeight;
		cout << "\n";
		cout << "The triangle's area is: " << triangleArea;

		break;

		//Trapezoid option user input and calculation display
	case 4:
		cout << "\nYou Selected: Calculating the area of a trapezoid";
		cout << "\n";
		cout << "\n";
		cout << "Enter the height of the trapezoid: ";
		cin >> trapHeight;
			if (trapHeight < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << trapHeight << ", is not valid for the height, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		cout << "Enter base 1 of the trapezoid: ";
		cin >> trapBase1;
			if (trapBase1 < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << trapBase1 << ", is not valid for base 1, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		cout << "Enter base 2 of the trapezoid: ";
		cin >> trapBase2;
			if (trapBase2 < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << trapBase2 << ", is not valid for base 2, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}

		//Calculate area variable
		trapezoidArea = trapHeight / 2 * (trapBase1 + trapBase2);
		
		//Display Results
		cout << "\n";
		cout << "Based on the height of " << trapHeight << " , base 1 of " << trapBase1 << " , and base 2 of " << trapBase2;
		cout << "\n";
		cout << "The trapezoid's area is: " << trapezoidArea;

		break;

		//Trapezoid option user input and calculation display
	case 5:
		cout << "\nYou Selected: Calculating the area of a sphere";
		cout << "\n";
		cout << "\n";
		cout << "Enter the radius of the sphere: ";
		cin >> sphereRadius;
			if (sphereRadius < 0)  //Input validation to end the progam when entering a negative number
			{
				cout << "\n";
				cout << "Your choice " << sphereRadius << ", is not valid for the radius, please enter 0 or higher.";
				cout << "\n";
				cout << "Thanks for using the calculator!  Press any key to close the program...";
				cin.ignore();
				cin.get();
				return 0;
			}
		//Calculate area variable
		sphereArea = 4 * PI * pow(sphereRadius, 2);

		//Display Results
		cout << "\n";
		cout << "Based on the radius of " << sphereRadius;
		cout << "\n";
		cout << " The sphere's area is: " << sphereArea;

		break;

		//Exit option user input
	case 6:
		cout << "\nYou Selected: Exit";
		cout << "\n";
		cout << "\n";

		break;
	}
	
	cout << "\n";
	cout << "Thanks for using the calculator!  Press any key to close the program...";
	cout << "\n";
	cin.ignore();
	cin.get();
	return 0;
}
