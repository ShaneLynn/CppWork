/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------
 Description:
 This program uses inheritance and templates to create three derived classes from the base class Shape.  The derived classes
 are: Cube, Rectangular Prism, and Pyramid.  Each shape uses the base options provided by the Shape class and combines them
 with its own data members and functions to generate a report about each shape.  The program will ask for input from the user
 to populate each shape, and it will use exception handling and a loop should the user enter an incorrect value.

 All of the classes are setup as templates so they can be created with multiple data types (like int, float, or double) which
 includes the error handling class.


 Class File used: InputError.h, Shape.h, Cube.h, RecPrism.h, Pyramid.h

***************************************************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "InputError.h"
#include "Shape.h"
#include "Cube.h"
#include "RecPrism.h"
#include "Pyramid.h"

using namespace std;


//The main program function
int main()
{

    //Prompt the user with a welcome
    cout << "Welcome to the Geometric Shape Calculation System." << endl;
    cout << "--The window may need to be expanded to see all results." << endl;
    cout << "\n";

	//Setup the variables for the input and loop control
	bool validate = false;				//Controls the while loop for error handling
	int userINT = -1;					//User input field for the INT shape.  Setting to -1 for input validation.
	float userFLT = -1.0f;				//User input field for the FLT shape.  Setting to -1 for input validation.
	double userDBL = -1.0;				//User input field for the DBL shape.  Setting to -1 for input validation.

	//Create exception objects to handle the errors for each shape type
	InputError<int> errorINT(userINT);
	InputError<float> errorFLT(userFLT);
	InputError<double> errorDBL(userDBL);

	//Create the shapes for each data type
	Cube<int> cube;
	RectPrism<float> prism;
	Pyramid<double> pyramid;

	
	/**********************************************************************************************************/
	//Setup the loop to handle the first shape: Cube
	/**********************************************************************************************************/
	cout << "\n***This step will setup a geometric Cube shape" << endl;
	while (validate != true)
	{
		cout << "\nPlease enter the length of one of the cube's sides: ";
		cin >> userINT;
		errorINT.SetErrorValue(userINT);			//Store the user's input in the exception object
		
		//Setup try/catch loop to handle incorrect user input
		try
		{
			if (userINT < 0 || cin.fail())			//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorINT;
			}
			else
			{
				validate = true;						//Change the flag to end the loop on valid input
				cube.SetLength(userINT);				//Store the user's input into the shape's data member
				cube.SetSideLength(userINT);
			}
		}
		catch (InputError<int> errorINT)			//Display the exception message to the user on incorrect entry
		{
			cout << "\nException Occurred:  The cube's length must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorINT.GetErrorValue() << ") is not valid." << endl;
		}
	}
	
	//Reset the loop flag for the next input cycle
	validate = false;
	
	/**********************************************************************************************************/
	//Setup the loops to handle the second shape: Rectangular Prism
	/**********************************************************************************************************/
	cout << "\n***This step will setup a geometric Rectangular Prism shape" << endl;
	
	//Loop for the length input
	while (validate != true)
	{
		cout << "\nPlease enter the length of the prism's sides: ";
		cin >> userFLT;
		errorFLT.SetErrorValue(userFLT);						//Store the user's input in the exception object
		
		//Setup try/catch loop to handle incorrect user input
		try
		{
			if (userFLT < 0 || cin.fail())						//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorFLT;
			}
			else
			{
				validate = true;								//Change the flag to end the loop on valid input
				prism.SetLength(userFLT);						//Store the user's input into the shape's data member
			}
		}
		catch (InputError<float> errorFLT)						//Display the exception message to the user on incorrect entry
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nException Occurred:  The prism's length must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorFLT.GetErrorValue() << ") is not valid." << endl;
		}
	}
	
	//Reset flag and loop for the width input
	validate = false;
	while (validate != true)
	{
		cout << "\nPlease enter the width of the prism's sides: ";
		cin >> userFLT;
		errorFLT.SetErrorValue(userFLT);						//Store the user's input in the exception object
		try
		{
			if (userFLT < 0 || cin.fail())						//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorFLT;
			}
			else
			{
				validate = true;								//Change the flag to end the loop on valid input
				prism.SetWidth(userFLT);						//Store the user's input into the shape's data member
			}
		}
		catch (InputError<float> errorFLT)						//Display the exception message to the user on incorrect entry
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nException Occurred:  The prism's width must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorFLT.GetErrorValue() << ") is not valid." << endl;
		}
	}
	
	//Reset flag and loop for the height input
	validate = false;
	while (validate != true)
	{

		cout << "\nPlease enter the height of the prism's sides: ";
		cin >> userFLT;
		errorFLT.SetErrorValue(userFLT);						//Store the user's input in the exception object
		try
		{
			if (userFLT < 0 || cin.fail())						//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorFLT;
			}
			else
			{
				validate = true;								//Change the flag to end the loop on valid input
				prism.SetHeight(userFLT);						//Store the user's input into the shape's data member
			}
		}
		catch (InputError<float> errorFLT)						//Display the exception message to the user on incorrect entry
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nException Occurred:  The prism's height must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorFLT.GetErrorValue() << ") is not valid." << endl;
		}
	}

	//Reset the loop flag for the next input cycle
	validate = false;

	/**********************************************************************************************************/
	//Setup the loops to handle the third shape: Pyramid Square
	/**********************************************************************************************************/
	cout << "\n***This step will setup a geometric square Pyramid shape" << endl;

	//Loop for the length input
	while (validate != true)
	{
		cout << "\nPlease enter the length of one of the pyramid's sides: ";
		cin >> userDBL;
		errorDBL.SetErrorValue(userDBL);						//Store the user's input in the exception object

		//Setup try/catch loop to handle incorrect user input
		try
		{
			if (userDBL < 0 || cin.fail())						//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorDBL;
			}
			else
			{
				validate = true;								//Change the flag to end the loop on valid input
				pyramid.SetLength(userDBL);						//Store the user's input into the shape's data member
				pyramid.SetSideLength(userDBL);
			}
		}
		catch (InputError<double> errorDBL)						//Display the exception message to the user on incorrect entry
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nException Occurred:  The pyramid's length must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorDBL.GetErrorValue() << ") is not valid." << endl;
		}
	}

	//Reset flag and loop for the width input
	validate = false;
	while (validate != true)
	{
		cout << "\nPlease enter the height of the pyramid: ";
		cin >> userDBL;
		errorDBL.SetErrorValue(userDBL);						//Store the user's input in the exception object

		//Setup try/catch loop to handle incorrect user input
		try
		{
			if (userDBL < 0 || cin.fail())						//If check to determine negative or character entry
			{
				cin.clear();
				cin.ignore();
				throw errorDBL;
			}
			else
			{
				validate = true;								//Change the flag to end the loop on valid input
				pyramid.SetHeight(userDBL);						//Store the user's input into the shape's data member
			}
		}
		catch (InputError<double> errorDBL)						//Display the exception message to the user on incorrect entry
		{
			cout << setprecision(2) << fixed << showpoint;
			cout << "\nException Occurred:  The pyramid's height must be a number and it cannot be negative." << endl;
			cout << "--The value of (" << errorDBL.GetErrorValue() << ") is not valid." << endl;
		}
	}


	/**********************************************************************************************************/
	//Display the final reports for each shape
	/**********************************************************************************************************/
	cout << "\n\nDisplaying the reports for each geometric shape..." << endl;
	
	//-----------------------------------------------------------------------------------------
	cout << "\nCUBE report (as integer type): " << endl;
	cube.CalculateCubeData();
	cout << "   Length: " << cube.GetLength() << endl;
	cout << "   Side Length: " << cube.GetSideLength() << endl;
	cout << "   Perimeter: " << cube.GetPerimeter() << endl;
	cout << "   Surface Area: " << cube.GetSurfaceArea() << endl;
	cout << "   Volume: " << cube.GetVolume() << endl;

	//-----------------------------------------------------------------------------------------
	cout << setprecision(2) << fixed << showpoint;
	cout << "\nRECTANGULAR PRISM report (as float type): " << endl;
	prism.CalculatePrismData();
	cout << "   Length: " << prism.GetLength() << endl;
	cout << "   Width: " << prism.GetWidth() << endl;
	cout << "   Height: " << prism.GetHeight() << endl;
	cout << "   Perimeter: " << prism.GetPerimeter() << endl;
	cout << "   Surface Area: " << prism.GetSurfaceArea() << endl;
	cout << "   Volume: " << prism.GetVolume() << endl;

	//-----------------------------------------------------------------------------------------
	
	cout << "\nPYRAMID SQUARE report (as double type): " << endl;
	pyramid.CalculatePyramidData();
	cout << "   Length: " << pyramid.GetLength() << endl;
	cout << "   Height: " << pyramid.GetHeight() << endl;
	cout << "   Side Length: " << pyramid.GetSideLength() << endl;
	cout << "   Slant Height: " << pyramid.GetSlantHeight() << endl;
	cout << "   Perimeter: " << pyramid.GetPerimeter() << endl;
	cout << "   Surface Area: " << pyramid.GetSurfaceArea() << endl;
	cout << "   Volume: " << pyramid.GetVolume() << endl;
	


    //Prompt to close the program window
    cout << "\nThank you for using the system.  Press the enter key to close...";

    cin.get();

    return 0;
}