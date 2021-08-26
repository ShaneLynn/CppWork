/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 6
 Created: 7/26/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: ActionFunctions.h

 Required Files: ActionFunctions.h

***************************************************************************************************************************/

#include "ActionFunctions.h"

using namespace std;


//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
ActionFunctions::ActionFunctions()
{
    number = 0;
    toPower = 0;
    text = "";
}

/******************************************************************
* Parameter constructor that accepts the name, hits, homeRuns, walks, and
strikeOuts as input.
******************************************************************/
ActionFunctions::ActionFunctions(int numberIn, int powerNumber, string line)
{
    number = numberIn;
    toPower = powerNumber;
    text = line;
}

//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------


/******************************************************************
* This function gets the value stored in the data member: number
******************************************************************/
int ActionFunctions::GetNumber() const
{
    return number;
}

/******************************************************************
* This function sets the value stored in the data member: number
******************************************************************/
void ActionFunctions::SetNumber(int numberIn)
{
    number = numberIn;
}

/******************************************************************
* This function gets the value stored in the data member: toPower
******************************************************************/
int ActionFunctions::GetToPower() const
{
    return toPower;
}

/******************************************************************
* This function sets the value stored in the data member: toPower
******************************************************************/
void ActionFunctions::SetToPower(int power)
{
    toPower = power;
}

/******************************************************************
* This function gets the value stored in the data member: line
******************************************************************/
string ActionFunctions::GetText() const
{
	return text;
}

/******************************************************************
* This function sets the value stored in the data member: line
******************************************************************/
void ActionFunctions::SetText(string line)
{
	text = line;
}



//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function accepts two arguments with value being the number
* desired and toPower being the exponent that number is raised to.
* Recursion style is used for this function.
******************************************************************/
int ActionFunctions::RecursivePower(int value, int toPower)
{
	//Base case of no exponent left or 0 entered
	if (toPower == 0)
	{
		return 1;		//Should multiply the number by 1 returning the number
	}
	else
	{
		//Call the function repetatedly until the total power is found.  Reduces each case by 1
		return (value * RecursivePower(value, toPower - 1));
	}
}


/******************************************************************
* This function function that accepts a string argument and outputs
* to the user what the string is in reverse order.
******************************************************************/
void ActionFunctions::StringReverser(string line)
{
	//Base case of nothing entered or left in the string
	if (line.size() == 0)
	{
		return;
	}
	else
	{
		//Call the function repetatedly until the final element is reached so the
		//cout statements begin
		StringReverser(line.substr(1));
		cout << line[0];
	}
}


/******************************************************************
* This function accepts one argument and uses that number to calculate
* the sum of all the numbers starting at 1 up to the number passed as
* the argument. For example, if 10 is passed as an argument the function
* will return 55 which is the sum of 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
******************************************************************/
int ActionFunctions::SumOfNumbers(int value)
{
	//Base case of a negative or 0 value entered
	if (value <= 0)
	{
		return 0;
	}
	else
	{
		//Call the function repetatedly until the sum is found by reducing each pass by 1
		return (value + SumOfNumbers(value - 1));
	}
}