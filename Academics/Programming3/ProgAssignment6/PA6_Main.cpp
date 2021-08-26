/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 6
 Created: 7/26/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program tests several recursive functions that perform various operations.  The RecursivePower function raises a number
 to a power and returns the result.  The String Reverser function display a test string in reverse, and the sum of numbers
 function returns the sum of a number range up to a provided number.  The functions are stored in a class file and called using
 an object from the class for testing.


 Class File used: ActionFunctions.h

***************************************************************************************************************************/

//HEADER FILES FOR THE PROGRAM

#include <iostream>
#include <cmath>
#include <string>
#include "ActionFunctions.h"

using namespace std;


int main()
{
	//Prompt the user with a welcome to the program
	cout << "Welcome to the Recursion Calculators!" << endl;
	cout << "--The window may need to be expanded to see all results." << endl;
	cout << "\n";

	//Setup the variables to be used for each function test
	int value1 = 0;
	int value2 = 0;
	string stringTest = "";				//Holds the value for the string test

	int powerTotal = 0;					//Holds the total for the RecursivePower function
	int numberSum = 0;					//Holds the sum for the Sum of Numbers function

	//Set the initial testing variables
	value1 = 5;
	value2 = 3;
	stringTest = "Alucard";

	//Create the testing object that holds the three functions
	ActionFunctions functions(value1, value2, stringTest);


	//Display the default values
	cout << "The default testing values are: " << functions.GetNumber() << " and " << functions.GetToPower() << endl;
	cout << "The default testing string value is: " << functions.GetText() << endl;

	//Run the recursive function to raise a value to a power
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the Recursive Power function..." << endl;
	powerTotal = functions.RecursivePower(functions.GetNumber(), functions.GetToPower());
	cout << "--The result of " << functions.GetNumber() << " raised to the power of " << functions.GetToPower() << " is: " << powerTotal << endl;

	//Run the sum of numbers function to total all of the numbers up to the provided value
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the Sum of Numbers function..." << endl;
	numberSum = functions.SumOfNumbers(functions.GetNumber());
	cout << "--The the sum of all of the numbers up to and including " << functions.GetNumber() << " is: " << numberSum << endl;

	//Run the string reverser function to show the original string and then the reversed string
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the String Reverser function..." << endl;
	cout << "--The original string is: " << functions.GetText() << endl;
	cout << "--The original string now reversed is: ";
	functions.StringReverser(functions.GetText());
	cout << "\n\n";


	//Set new testing values into the object for the functions to work with
	functions.SetNumber(12);
	functions.SetToPower(5);
	functions.SetText("Drab as a fool, aloof as a bard");

	//Display the new values
	cout << "The updated testing values are: " << functions.GetNumber() << " and " << functions.GetToPower() << endl;
	cout << "The updated testing string value is: " << functions.GetText() << endl;

	//Run the recursive function to raise a value to a power
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the Recursive Power function..." << endl;
	powerTotal = functions.RecursivePower(functions.GetNumber(), functions.GetToPower());
	cout << "--The result of " << functions.GetNumber() << " raised to the power of " << functions.GetToPower() << " is: " << powerTotal << endl;

	//Run the sum of numbers function to total all of the numbers up to the provided value
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the Sum of Numbers function..." << endl;
	numberSum = functions.SumOfNumbers(functions.GetNumber());
	cout << "--The the sum of all of the numbers up to and including " << functions.GetNumber() << " is: " << numberSum << endl;

	//Run the string reverser function to show the original string and then the reversed string
	cout << "\n\n";
	cout << "------------------------------------------" << endl;
	cout << "Test for the String Reverser function..." << endl;
	cout << "--The original string is: " << functions.GetText() << endl;
	cout << "--The original string now reversed is: ";
	functions.StringReverser(functions.GetText());
	cout << "\n\n";


	//Prompt to close the program window
	cout << "\nThank you for using the system.  Press the enter key to close...";
	cin.get();
	return 0;
}