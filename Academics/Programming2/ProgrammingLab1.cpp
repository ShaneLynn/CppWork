/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 1
 Created: 5/06/2021
*

-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program determines if the number entered is a winning ticket number.  The winning ticket array houses 10 numbers, and prompts the user to enter their 5 digit
 ticket number.  A linear search function collects the user input and then determines if the ticket is a winner and then informs the user if their ticket has won based
 on the returned value from the function.


* The program uses these functions to interact with main() and generate the calculations for the program:
•	bool searchList(const long[], int, long);
	o	The first argument accepts the winning ticket number array, the second accepts the array size, and the third accepts the user entered value
	o	A for loop is used to step through the array and check the values
	o	Returns a boolean value of true if the number is found.

***************************************************************************************************************************/


//Source Lab 1 File provided code

#include <iostream>
using namespace std;

// Function prototype
bool searchList(const long[], int, long);

// Constant for array size
const int SIZE = 10;

int main()
{
	// Array of numbers that are always played
	long ticket[SIZE] = { 13579,  26791,
						  26792,  33445,
					      55555,  62483,
					      77777,  79422,
						  85647,  93121 };

	// This variable will hold the winning number.
	long winningNum;

	// Get this week's winning number.
	cout << "\nPlease enter this week's 5-digit "
		<< "winning lottery number: ";
	cin >> winningNum;

	// Search for the winning number.
	if (searchList(ticket, SIZE, winningNum))
	{
		// If searchList returned true, then
		// the player has a winning ticket.
		cout << "You have a winning ticket.\n";
	}
	else
	{
		cout << "You did not win this week." << endl;
	}

	//Used to pause the program for viewing
	cout << "Press a key to end...";
	cin.ignore();
	cin.get();
	return 0;
}

/********************************************************
 The searchList function accepts as arguments, an array
 of numbers, the size of the array, and the number to
 search for. It determines if the number to search for
 is in the set of stored numbers using a linear search.
 It returns true if the number is found, otherwise it
 returns false.

 Pseudo Code
 Declare found as boolean default to false - return value

 For count = 0 to size of array and not found increment by 1
	If element at count equals search value
		Set found to true
	End If
 End For

 Return found
********************************************************/
bool searchList(const long list[], int numElems, long value)
{
	bool found = false;				//Declare the T/F variable to return to the program if the number is found

	for (int count = 0; count < numElems; count++)		//Use a for loop to check each index of the winning number array
	{
		if (list[count] == value)
		{
			found = true;			//Set the variable to true if the provided number is equal to a list number
		}
	}
	
	return found;		
}