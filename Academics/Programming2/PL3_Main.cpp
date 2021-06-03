/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 3
 Created: 5/18/2021
*
-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program lab displays a list of password requirements to the user and then asks them to enter a password.  The program
 then checks the entered password array and each character to see if it meets the list of requirements.  Based on the
 results of the validation, the program will inform the user if the password is fine or what part they need to correct for
 the next time.


* The program uses two functions:
•	void displayRequirements();
	o	Takes no arguments
	o	Displays a list of password requirements to the user.
•	void displayResults(char array[]);
	o	The only argument is the array of characters for the password string
	o	Runs through an variety of validation checks
	o	Displays the validation results to the user

***************************************************************************************************************************/

//Provided code from Source 3 file

#include <iostream>
#include <cctype>	//Added header file to use c-string tests

using namespace std;

// Global constants
const int SIZE = 80; // The maximum size of the array
const int MIN = 6;   // The minimum number characters

// Function prototypes
void displayRequirements();
void displayResult(char[]);


int main()
{
	char cstring[SIZE];


	displayRequirements();

	cout << "Enter a password: ";
	cin.getline(cstring, SIZE);

	displayResult(cstring);

	return 0;
}

void displayRequirements()
{
	// Display the password requirements.
	cout << "\nPassword Requirments:\n"
		<< "  - The password should be at least "
		<< MIN << " characters long.\n"
		<< "  - The password should contain at least one uppercase\n"
		<< "    and at least one lowercase letter.\n"
		<< "  - The password should have at least one digit.\n\n";
}

void displayResult(char str[])
{
	//Provided code variables
	bool length, upper, lower, digit;
	length = upper = lower = digit = false;
	int lengthCount = 0;

	//Create a pointer to the array
	char* valPTR = str;

	//Check the length of the array and store the value
	lengthCount = strlen(valPTR);

	//Validate the length of the password with the first check and then
	//loop through the array to validate each character of the password
	//and set the corresponding variable as true.

	if (lengthCount >= MIN)
	{
		length = true;
	}

	for (int index = 0; index < lengthCount; index++)
	{
		if (isupper(valPTR[index]))
		{
			upper = true;
		}

		if (islower(valPTR[index]))
		{
			lower = true;
		}

		if (isdigit(valPTR[index]))
		{
			digit = true;
		}
	}

	
	//Display results of the password to the user.  Based on the validation of
	//the password part in the previous section, a custom message will be
	//shown to the user to let them know which part of the password did not meet
	//the criteria.  If everything is correct, the user will be shown the password
	//is fine.
	if (length == true && upper == true && lower == true && digit == true)
	{
		cout << "\nYour password meets all requirements!";
	}
	else if (length == false)
	{
		cout << "\nYour pasword is less than " << MIN << " characters." << endl;
		displayRequirements();
	}
	else if (upper == false)
	{
		cout << "\nThe password does not have a character in upper case." << endl;
		displayRequirements();
	}
	else if (lower == false)
	{
		cout << "\nThe password does not have a character in lower case." << endl;
		displayRequirements();
	}
	else if (digit == false)
	{
		cout << "\nThe password does not have a number." << endl;
		displayRequirements();
	}
}