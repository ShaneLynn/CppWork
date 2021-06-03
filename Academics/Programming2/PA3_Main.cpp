/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 3
 Created: 5/18/2021

----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program is a directory search based on the data provided by the user.  The user is prompted to enter a name, partial name, phone
 number or partial phone number of someone they are trying to contact.  The program will then call a search function to take the user
 input and compare each string stored in the array to see if it has a match.  If a match exists, it will return all resulting matches that it
 finds.  If no matches are found, the function will display a message to the user with their search criteria and that no matches were
 found.  The search is case sensitive, so a warning message is displayed to the user to enter capital letters for first and last names.
 
 The following is the test data used to populate the string array directory:
 “Renee Javens, 678-1223”,
 “Joe Looney, 586-0097”,
 “Geri Palmer, 223-8787”,
 “Lynn Presnell, 887-1212”,
 “Bill Wolfe, 223-8878”,
 “Sam Wiggins, 486-0998”,
 “Bob Kain, 586-8712”,
 “Tim Haynes, 586-7676”,
 “John Johnson, 223-9037”,
 “Jean James, 678-4939”,
 “Ron Palmer, 486-2783”


* This program uses the following function:

•	void SearchDirectory(string members[], string userInput, int size)
	o	Accepts the parameters for the string array members, userInput, and the array size variable
	o	Uses a loop to take the user's input and search each string of the arary elements
	o	When each one is found, those results are displayed in the loop
	o	An accumulator keeps track of each search found to display results, and to let the user know how many were found
	o	If nothing is found, a message is displayed to the user letting them know their search found nothing


***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//Declare the function prototype:
void SearchDirectory(string[], string, int);

//Delcare global for array size
const int dataSize = 11;

//The main program function
int main()
{
	//Delare Variables:
	string nameSearch;										//Holds the input value from the user for the search

	//Declare and initialize the array with the test data:
	string members[dataSize] = { "Renee Javens, 678 - 1223"
								,"Joe Looney, 586 - 0097"
								,"Geri Palmer, 223 - 8787"
								,"Lynn Presnell, 887 - 1212"
								,"Bill Wolfe, 223 - 8878"
								,"Sam Wiggins, 486 - 0998"
								,"Bob Kain, 586 - 8712"
								,"Tim Haynes, 586 - 7676"
								,"John Johnson, 223 - 9037"
								,"Jean James, 678 - 4939"
								,"Ron Palmer, 486 - 2783" };


	//Initial prompt startup display for the user
	cout << "Welcome to the Member Directory Search Tool!" << endl;
	cout << "\n";
	cout << "**Please remember to capitalize all first and last name searches" << endl;			//Warning for case, might impact results
	cout << "\nEnter the full name, phone number or partials to search for: ";
	
	//Get the search data from the user
	getline(cin, nameSearch);
	
	//Call the search method to check user input and display the results
	SearchDirectory(members, nameSearch, dataSize);
	

	//Prompt to close the program
	cout << "\nThank you for using the system.  Press any key to close...";
	cin.get();

	return 0;
}


/****************************************************************************************
This function searches the string array of names and numbers based on the the user's input
when prompted.  It then uses a for loop to step through each element of the array and uses
the .find() feature of the string object to search the contents of each element.  If it finds
a match, the IF check is executed.  The IF check is setup to evaluate if a match is found
based on the string::npos return value when a match is not found.  The program uses an accumulator
to determine how many matches were found, and uses that value to display the results.  If
matches are not found, a message is returned to the user indicating nothing is found and shows
them the search criteria they used.  Matching by user input is case sensitive.
****************************************************************************************/
void SearchDirectory(string members[], string userInput, int size)
{
	int matches = 0;						//Accumulator to store how many matches are returned
	
	//Loop through the members array to search for the input match and display if found
	for (int index = 0; index < size; index++)
	{
		if (members[index].find(userInput) != string::npos)
		{
			matches++;						//Increase accumulator when found
			cout << "Result " << matches << ": " << members[index] << endl;
		}
	}
	
	//Display messages based on matches found/not found and show the user input search criteria
	if(matches > 0)
	{
		cout << "\nYour search for " << "\"" << userInput << "\"" << " returned " << matches << " result(s)." << endl;
	}
	else
	{
		cout << "\nNo matches were found for the search using: " << "\"" << userInput << "\"" << endl;
	}
}
