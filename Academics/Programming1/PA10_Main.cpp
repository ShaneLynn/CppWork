/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 10
	Created: 4/05/2021
*
-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program will open an external file called Random.txt that will need to be created before the program is run.  The file contains a list of random
 numbers (chosen by the file creator) and each are on a separate line in the file.  Once the data is read, the program will then run some calculations on
 the data and provide them to the user.
 
 The program also validates the file has been connected and opened before reading from it and displays a user message of "File Not Found" if it is missing
 before ending the program.


*	The final calculations should display in this format:
*		Total Numbers Read from the File:
*		Lowest Value in the File:
*		Highest Value in the File:
*		Average of All numbers in the File:
*		Sum of All Numbers in the File (running total):
*		

*
***Pseudocode:

*START
	Include header files iostream, iomanip, cmath, fstream, string

	use namespace std

	Declare variables:
		string activateChoice					//Initial input to begin processing the file's data
		ifstream inputFile						//Create the object to read data from a file
		int fileData							//Working variable to hold the data read from the file
		int countOfNumbers						//Accumulator that stores how many numbers have been processed
		int lowestNumber						//Field that holds the lowest number found when reading the data
		int highestNumber						//Field that holds the highest number found when reading the data
		double averageOfNumbers					//Calculation field that determines the average of all numbers	
		int sumOfNumbers						//Accumulator field that stores the sum of all numbers
	
	Initialize variables:
		sumOfNumbers = 0
		countOfNumbers = 0
		lowestNumber = NULL
		highestNumber = NULL
	
	Initial Display to the user
	Display "This program reads data from the file Random.txt"
	Display "Would you like to begin processing the file? (Y/N) "
		Input to activateChoice
		while (activateChoice != "Y" && activateChoice != "y" && activateChoice != "N" && activateChoice != "n")
			Display "Invalid Choice.  Please entery Y or N.
			if (activateChoice == "N" || activateChoice == "n")
				Display "Ok.  Maybe another time.  Press any key to close..."
				Input.ignore() to flush the buffer of new lines
				Input.get() to accept an input to close the program
				return 0 to close the program
			else
				Use the file stream object to open the file
					inputFile.open("Random.txt")


				Validate the text file can be opened and then process if it does
					if (inputFile.fail())
						Display "File Not Found, press any key to close..."
						Input.ignore() to flush the buffer of new lines
						Input.get() to accept an input to close the program
						return 0 to close the program
					else
						Read the data from the file that ends when their are no more entries
						while (inputFile >> fileData)
							countOfNumbers++
							sumOfNumbers += fileData
							if (lowestNumber == NULL && highestNumber == NULL)
								lowestNumber = fileData;
								highestNumber = fileData;
							else if (fileData < lowestNumber)
								lowestNumber = fileData
							else if (fileData > hightstNumber)
								highestNumber = fileData
	
			Close the connection to the file
			inputFile.close()

			Calculate final total variables:
			averageOfNumbers = sumOfNumbers / countOfNumbers
		

			Display setprecision to 2, fixed, showpoint
			Display "\newline"
			Display "Total Numbers Read from the File:                  " << countOfNumbers
			Display	"Lowest Value in the File:                          " << lowestNumber
			Display "Highest Value in the File:                         " << hightstNUmber
			Display	"Average of All numbers in the File:                " << averageOfNumbers
			Display	"Sum of All Numbers in the File (running total):    " << sumOfNumbers
			Display "\newline"

			Display "Thank you for using the system.  Press any key to close..."
			Input.ignore() to flush the buffer of new lines
			Input.get() to accept an input to close the program
*END
***************************************************************************************************************************/



//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//The main program function
int main()
{
	//Declare variables:
	string activateChoice;				//Initial input to begin processing the file's data
	ifstream inputFile;					//Create the object to read data from a file
	int fileData;						//Working variable to hold the data read from the file
	int countOfNumbers = 0;				//Accumulator that stores how many numbers have been processed
	int lowestNumber = NULL;			//Field that holds the lowest number found when reading the data
	int highestNumber = NULL;			//Field that holds the highest number found when reading the data
	double averageOfNumbers;			//Calculation field that determines the average of all numbers	
	int sumOfNumbers = 0;				//Accumulator field that stores the sum of all numbers

	
	//Initial Display to the user, and prompt to process the file
	cout << "This program reads data from the file Random.txt" << endl;
	cout << "Would you like to begin processing the file? (Y/N): ";
	cin >> activateChoice;
	cout << "\n";
		//Validate user input to only allow Y and N variations
		while (activateChoice != "Y" && activateChoice != "y" && activateChoice != "N" && activateChoice != "n")
		{
			cout << "Invalid Choice.  Please enter Y or N." << endl;
			cout << "Would you like to begin processing the file? (Y/N): ";
			cin >> activateChoice;
			cout << "\n";
		}
		//Check to end the program if N is selected, otherwise the file will process
		if (activateChoice == "N" || activateChoice == "n")
		{
			cout << "Ok.  Maybe another time.  Press any key to close..." << endl;
			cin.ignore();
			cin.get();
			return 0;
		}
		else
		{
			//Use the file stream object to open the file
			inputFile.open("Random.txt");


			//Validate the text file can be openedand, and process if it does
				if (inputFile.fail())
				{
					cout << "File Not Found, press any key to close..." << endl;
					cin.ignore();
					cin.get();
					return 0;
				}
				else
				{
					//Use a loop to read the data from the file which ends when no more entries are present
					while (inputFile >> fileData)
					{
						countOfNumbers++;				//Count how many items are processed
						sumOfNumbers += fileData;		//Running total adding all numbers together
						
						//Check to find the highest and lowest number values in the file
						if (lowestNumber == NULL && highestNumber == NULL)
						{
							lowestNumber = fileData;
							highestNumber = fileData;
						}
						else if (fileData < lowestNumber)
						{
							lowestNumber = fileData;
						}
						else if (fileData > highestNumber)
						{
							highestNumber = fileData;
						}
						
					}

					//Close the connection to the file
					inputFile.close();
				}
		}
	//Calculate average of all the numbers
	averageOfNumbers = sumOfNumbers / countOfNumbers;


	//Display Results to User
	cout << "\n";
	cout << "Total Numbers Read from the File:                  " << countOfNumbers << endl;
	cout << "Lowest Value in the File:                          " << lowestNumber << endl;
	cout << "Highest Value in the File:                         " << highestNumber << endl;
	cout << "Average of All numbers in the File:                " << averageOfNumbers << endl;
	cout << "Sum of All Numbers in the File (running total):    " << sumOfNumbers << endl;
	cout << "\n";
	cout << "\n";

	//Prompt to close the program
	cout << "Thank you for using the system.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}
