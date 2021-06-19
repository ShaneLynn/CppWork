/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 5
 Created: 6/03/2021

 
 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program searches a file for a string that contains the search paramaters.  It prompts the user for the filename and the
 text to search the file for.  If the search parameters are found in the current line in the file being searched, then the program
 will display that line from the file to the user and continue searching.  If the search is not found, the program will continue 
 reading all lines in the file until it finds the criteria or reaches the end of the file.  If it does not find the user's search
 criteria by the file's end, then it will display a message to the user: "Search criteria not found in this file."

 Once the search is finished, the program will display these metrics from the search:
 o Search Criteria:				(user's search criteria)
 o Total lines read:			(total lines in the file)
 o Total times criteria found:	(count of how many matches to the user's search criteria the program found)

 

* This program uses the following functions:

•	void DisplaySearchInfo(string searchCriteria, int linesCounted, int searchesFound);
	o	Accepts the lines counted, user search criteria, and searches found parameters
	o	Displays the results from those variables to the user using the above template format.

•	void GetSearchInfo(string &fileName, string &searchCriteria)
	o	Accepts the fileName and searchCriteira parameters as reference
	o	Collects input from the user and stores in the corresponding variables

•	void SearchFile(string workingLine, string searchCriteria, int &searchesFound, int lineNumber, int &currentLines, int &matchesFound)
	o	Accepts the current workingLine, user searchCriteria, searchesFound - currentLines - and matchesFound as a reference, and the lineNumber
		accumulator	as parameters.  The reference is used to udate the accumulators declared in the program.
	o	The .find feature of the string object is used to compare the workingLine retreived string to the searchCriteria string
	o	If a match is found, the values in the if check are executed to display the line and update searchesFound

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

//Declare the function prototypes:
void DisplaySearchInfo(string, int, int);
void GetSearchInfo(string&, string&);
void SearchFile(string, string, int&, int, int&, int&);



//The main program function
int main()
{
	//Delare Variables:
	ifstream searchFile;			//Object that holds the input file
	string fileName;				//Holds the file name to be searched
	string searchCriteria;			//Holds the user's search criteria to compare with the file contents
	string workingLine;				//Holds the line to display from the current search
	int currentLines = 0;			//Holds the counter to display only so many line results
	int linesCounted = 0;			//Accumulator that holds how many lines the program processed from the file
	int searchesFound = 0;			//Accumulator for the amount of times the program finds the search criteria in the file
	int lineNumber = 1;			    //Accumulator that holds the line number to display if a match is found
	int matchesFound = 0;			//Accumulator that holds how many matches have been found in the file
	
	//Initial prompt startup display for the user
	cout << "Welcome to the File Search Tool!" << endl;
	cout << "\n";

	
	//Get the file name and search string from the user.
	GetSearchInfo(fileName, searchCriteria);

	//Open the file.
	searchFile.open(fileName);

	// Test for errors.
	if (!searchFile)
	{
		//If the file is not able to open, display the error to the user.
		cout << "Error opening the file: " << fileName << endl;
		cout << "Make sure the file exists and the name is correct to try again." << endl;
	}
	else
	{
		// Read the contents of the file and display
		// each line with a line number.
		while (!searchFile.eof())
		{
			//Set a display limit for reading the file
			if (currentLines > 14)
			{
				cout << "\n--Displaying the first 15 matches. Press the enter key for next matches...";		//Prompt the user
				cin.get();
				currentLines = 0;		//Reset the lines counter to 0 again for the next set of lines
			}

			//Get a line from the file to search
			getline(searchFile, workingLine, '\n');
						
			//Call the search method to check if the current file line has a match for the search criteria.
			SearchFile(workingLine, searchCriteria, searchesFound, lineNumber, currentLines, matchesFound);
			
			//Update the line display counter for the next line.
			lineNumber++;

			//Update the total line counter.
			linesCounted++;
		}

		//Display the metrics to the user from the search
		DisplaySearchInfo(searchCriteria, linesCounted, searchesFound);

		// Close the file.
		searchFile.close();
	}


	//Prompt to close the program
	cout << "\nThank you for using the system.  Press the enter key to close...";
	cin.get();

	return 0;
}


/****************************************************************************************
This function prompts the user and collects info on the filename to open and the search
criteria they would like to search the file for.  It accepts the reference parameters
for the fileName and searchCriteira variables in main for the program to read.
****************************************************************************************/
void GetSearchInfo(string &fileName, string &searchCriteria)
{

	//Collect the user input for the filename
	cout << "What is the file name you would like to open? : ";
	getline(cin, fileName);

	//Collect the player's name and store in the structure's section
	cout << "\nWhat would you like to search for? : ";
	getline(cin, searchCriteria);

}


/****************************************************************************************
This function displays the final search result information to the user.  It accepts the
search criteria from the user, total lines counted by the proram while readin the file
and how many times the program found and displayed a line from the file.
****************************************************************************************/
void DisplaySearchInfo(string searchCriteria, int linesCounted, int searchFound)
{
	cout << "\n\nSEARCH RESULTS" << endl;
	cout << "==============" << endl;
	cout << setw(28) << right << "Search Criteria: " << searchCriteria << endl;
	cout << setw(28) << right << "Total lines read: " << linesCounted << endl;
	cout << setw(28) << right << "Total times criteria found: " << searchFound << endl;
}


/****************************************************************************************
This function searches the currently retreived line from the file based on the the user's
input. It uses the .find() feature of the string object to search the contents of each 
element.  It accepts the parameters for the current file's retreived working line, the 
user's search criteria, the searchesfound, currentLines, and matches found accumulators 
as a reference, and the current line number being searched.  If it finds a match, the IF
check is executed.  The IF check is setup to evaluate if a match is found based on the 
string::npos return value when a match is not found.  The program uses an accumulator to 
update the program when each match is found, and it displays the match notification and
line information to the user for each match.  Matching the user input is case sensitive.
****************************************************************************************/
void SearchFile(string workingLine, string searchCriteria, int &searchesFound, int lineNumber, int &currentLines, int &matchesFound)
{

	//Search for the input match and display it if found
	if (workingLine.find(searchCriteria) != string::npos)
	{
			searchesFound++;						//Increase accumulator when a match is found
			currentLines++;							//Increase accumulator when a match is found for the display limiter
			matchesFound++;							//Increase accumulator when a match is found for the found display

			//Display the line from the file that matches
			cout << "\nMatch " << matchesFound << " Found!" << endl;
			cout << setw(3) << right << lineNumber << ": " << workingLine << endl;
	}
		
}