/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 13
	Created: 4/20/2021
*

-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program tracks rainfall over a 12 month period in a year.  It does so by using two arrays (setup in parallel) of 12 elements, with one holding double
 data types for the rainfall and the other holding strings for the month names.

 The array with the month strings is initialized with all of the month values in place when it is created, and the rainfall array will collect user data using
 a function.  The user input function accesses both arrays (one to display the month of collection to the user, while storing the data input to the rainfall array).

*
* The program uses the following functions to interact with main() and handle the data collection and calculations:
•	void CollectRainData(double [ ], string [ ], int);
	o	Collects user input of the rain totals for each month
	o	Parameter 1, directs to the array for rainfail totals
	o	Parameter 2, directs to the string array of month names
	o	Parameter 3, collects the size of the arrays from the total months in the year
•	double CalculateTotalRainfall(double [ ], int);
	o	Calculates the total rainfall from the array parameter.
	o	Return the value
•	double CalculateAverage(double, int);
	o	Calculate the Average rainfall
	o	Parameter 1, is for the total rainfall
	o	Parameter 2, is for the number of months
	o	Return the value
•	double FindLowest(double [ ], int, int&);
	o	Finds the month with the lowest amount of rainfall
	o	Parameter 3, is for the index of the lowest month
	o	Return the value
•	double FindHighest(double [ ], int, int&);
	o	Finds the month with the highest amount of rainfall
	o	Parameter 3, is for the index of the lowest month
	o	Return the value
•	void DisplayResults(double, double, double, string, double, string);
	o	Displays the results to the user (format shown below)
	o	Parameter 1, is for the total rainfall
	o	Parameter 2, is for the average rainfall
	o	Parameter 3, is the total for the month with the highest rainfall
	o	Parameter 4, is for the month name with the highest rainfall
	o	Parameter 3, is the total for the month with the lowest rainfall
	o	Parameter 6, is for the month name with the lowest rainfall

•	string DisplayHighest(int, int);
	o	Compares the parameter input (highest month index) to the array for a match
	o	Parameter 2 uses the global months to determine array size
	o	Displays the month name from the month array
	o	Return the value
•	string DisplayLowest(int, int);
	o	Compares the parameter input (lowest month index) to the array for a match
	o	Parameter 2 uses the global months to determine array size
	o	Displays the month name from the month array
	o	Return the value

  Once all of the calculations are finished, the program used the DisplayResults function to generate the report for the user in the following format:
	**All output is rounded for viewing using two decimal places.
	Total rainfall for the year:
	Average monthly rainfall:
	Highest month of rainfall:
	Lowest month of rainfall:
*
***Pseudocode:

*START
	Include header files iostream, iomanip, cmath, cstdlib, string

	use namespace std

	//Declare function prototypes
	void CollectRainData(double [ ], string [ ], int)
	double CalculateTotalRainfall(double [ ], int)
	double CalculateAverage(double, int)
	double FindLowest(double [ ], int, int&)
	double FindHighest(double [ ], int, int&)
	void DisplayResults(double, double, double, string, double, string)
	string DisplayHighest(int, int)
	string DisplayLowest(int, int)

	//Declare global variables:
	const int months = 12
	
	

  MAIN()
	//Declare variables:
		double totalRainfall
		double avgRainfall
		double highestRainfall
		double lowestRainfall
		string monthHighest
		string monthLowest
		int indexHighMonth
		int indexLowMonth

		//Declare arrays:
		double rainfall[months]
		string monthNames[months] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}
		
		Display "This program collects the rainfall by month for the previous year."
		Display "\newline"

		CollectRainData(rainfall[], monthNames[], months)

		totalRainfall = CalculateTotalRainfall(rainfall[], months)

		avgRainfall = CalculateAverage(totalRainfall, months)

		highestRainfall = FindHighest(rainfall[], months, indexHighMonth)
		lowestRainfall = FindLowest(rainfall[], months, indexLowMonth)

		monthHighest = DisplayHighest(indexHighMonth, months)
		monthLowest = DisplayLowest(indexLowMonth, months)

		DisplayResults(totalRainfall, avgRainfall, highestRainfall, monthHighest, lowestRainfall, monthLowest);


		Display "Thank you for using the system.  Press any key to close..."
		Input.ignore() to flush the buffer of new lines
		Input.get() to accept an input to close the program

  END MAIN()

  void CollectRainData(double rainfall[], string monthNames[], int months);
	for(counter = 0; counter < months; counter++)
		Display "Please enter total rainfall for the month of " << monthNames[counter]
		Input >> rainfall[counter]
			while (rainfall[counter] < 0)
				Display "Invalid Input.  Rainfall cannot be below 0."
				Display "Please enter total rainfall for the month of " << monthNames[counter]
				Input >> rainfall[counter]
		Display "\newline"
	Display "All values entered, now generating the report..."
	Display "\newline"


  double CalculateTotalRainfall(double rainfall[], int months);
	double yearlyRainfall
	for(counter = 0; counter < months; counter++)
		yearlyRainfall += rainfall[counter]
	return yearlyRainfall


  double CalculateAverage(double yearlyRainfall, int months);
	double totalRainfall
	totalRainfall = yearlyrainfall / months
	return totalRainfall
 

  double FindHighest(double rainfall[], int months, int &indexHigh);
	double  highRainfall = rainfall[0]
	for(int counter = 0; counter < months; counter++)
		if (rainfall[counter] > highRainfall)
		 highRainfall = rainfall[counter]
		 indexHigh = counter
	return highRainfall


  double FindLowest(double rainfall[], int months, int &indexLow);
	double  lowRainfall = rainfall[0]
	for(int counter = 0; counter < months; counter++)
		if (rainfall[counter] < lowRainfall)
		 lowRainfall = rainfall[counter]
		 indexLow = counter
	return lowRainfall


  string DisplayHighest(int indexHigh);
	string highMonth
	highMonth = monthNames[indexHigh]
	return highMonth


  string DisplayLowest(int indexLow);
	string lowMonth
	highMonth = monthNames[indexLow]
	return lowMonth


  void DisplayResults(double rainTotal, double rainAVG, double monthRainHigh, string monthHigh, double monthRainLow, string monthLow);
	Display << "Rainfall Metrics for the Prior Year Report"
	Display << "\newline"
	Display << "------------------------------------------"
	Display << "Total rainfall for the year: " << rainTotal << endline
	Display << "Average monthly rainfall: " << rainAVG << endline
	Display << "Highest month of rainfall: " << monthRainHigh << " occurred in " << monthHigh << endline
	Display << "Lowest month of rainfall: " <<  monthRainLow << " occurred in " << monthLow << endline
	Display << "\newline"
	

*END
***************************************************************************************************************************/



//Header files needed for the program to function correctly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

//Declare function prototypes
void CollectRainData(double[], string[], int);
double CalculateTotalRainfall(double[], int);
double CalculateAverage(double, int);
double FindLowest(double[], int, int&);
double FindHighest(double[], int, int&);
void DisplayResults(double, double, double, string, double, string);
string DisplayHighest(int, string[]);
string DisplayLowest(int, string[]);

//Declare global variables:
const int months = 12;

//The main program function
int main()
{

	//Declare variables:
	double totalRainfall;				//Holds the total rainfall for the year calculation
	double avgRainfall;					//Holds the average monthly rainfall calculation
	double highestRainfall;				//Holds the value of the highest rainfall month of the year
	double lowestRainfall;				//Holds the value of the lowest rainfall month of the year
	int indexHighMonth = 0;				//Holds the element index value of the highest month.  Initialize to 0 to match the first array element
	string monthHighest;				//Holds the name of the highest rainfall month from the monthNames array
	int indexLowMonth = 0;				//Holds the element index value of the lowest month.  Initialize to 0 to match the first array element
	string monthLowest;					//Holds the name of the lowest rainfall month from the monthNames array
	
	//Declare arrays:
	//double rainfall[months] = { 1.92, 2.25, 2.91, 4.49, 4.98, 4.47, 4.37, 4.36, 3.87, 3.31, 3.25, 2.44 };  //This is used to test functions without data entry.
	double rainfall[months];
	string monthNames[months] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	//Initial program load display to the user
	cout << "This program collects the rainfall by month for the previous year.";
	cout << "\n";
	
	//Run this function to collect user input to populate the rainfall array
	CollectRainData(rainfall, monthNames, months);
	
	//Run this function to calculate the rainfall array after the user input
	totalRainfall = CalculateTotalRainfall(rainfall, months);

	//Run this function to calculate the average rainfall per month
	avgRainfall = CalculateAverage(totalRainfall, months);
	
	//Run this function to determine which array element (month) has the highest entry
	highestRainfall = FindHighest(rainfall, months, indexHighMonth);
	
	//Run this function to determine which array element (month) has the lowest entry
	lowestRainfall = FindLowest(rainfall, months, indexLowMonth);

	//Run this function to collect the corresponding month name
	monthHighest = DisplayHighest(indexHighMonth, monthNames);
	
	//Run this function to collect the corresponding month name
	monthLowest = DisplayLowest(indexLowMonth, monthNames);

	//Run this function to generate the final report display for the user
	DisplayResults(totalRainfall, avgRainfall, highestRainfall, monthHighest, lowestRainfall, monthLowest);


//Prompt to close the program
	cout << "\n";
	cout << "\n";
	cout << "Thank you for using the system.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}

//This function prompts the user to enter rainfall for the corresponding month.  Uses both arrays in parallel
//to prompt the user with the month name, collect the user input, and store that input into the rainfall array.
//The parameters are both arrays and the variable for total months in the year.
void CollectRainData(double rainfall[], string monthNames[], int months)
{
	cout << "\n";
	for (int counter = 0; counter < months; counter++)  //Loop through both arrays to get the month name and store the total
	{
		cout << "Please enter total rainfall for the month of " << monthNames[counter] << ": ";
		cin >> rainfall[counter];
		while (rainfall[counter] < 0) //Input validation.  Does not allow negative numbers.
		{
			cout << "Invalid Input.  Rainfall cannot be below 0." << endl;
			cout << "Please enter total rainfall for the month of " << monthNames[counter] << ": ";
			cin >> rainfall[counter];
		}
	}
	cout << "\n";
	cout << "All values entered, now generating the report..."; //Prompt for the user to know that all input is completed
	cout << "\n";
}
//This function steps through the rainfall array, adds up each element entry to get a total for the year, and returns it to the program.
//The parameters are the rainfall array and the variable for total months in the year.
double CalculateTotalRainfall(double rainfall[], int months)
{
	double yearlyRainfall = 0; //Setup the accumulator variable

	for (int counter = 0; counter < months; counter++)  //Loop through rainfall array to add each element's contents to the accumulator
	{
		yearlyRainfall += rainfall[counter];
	}
	return yearlyRainfall;
}
//This function calculates the average rainfall per month for the year and returns it to the program.
//The parameters are the yearly rainfall total generated by the CalculateTotalRainfall function and the variable for total months in the year.
double CalculateAverage(double yearlyRainfall, int months)
{
	double totalRainfall;
	totalRainfall = yearlyRainfall / months;  //Calculation to get the average per month
	return totalRainfall;
}
//This function steps through the rainfall array elements and determines which one has the highest rainfall amount.
//That amount is then returned to the program, and the element index of what month that is gets updated in the program.
//The parameters are the rainfall array, the variable for total months in the year, and a reference to the highest month index number.
double FindHighest(double rainfall[], int months, int& indexHigh)
{
	double  highRainfall = rainfall[0];					 //Initialize the variable with the first element in the array
	for (int counter = 0; counter < months; counter++)	 //Loop through the rainfall array elements
	{
		if (rainfall[counter] > highRainfall)			 //Setup an if check to determine the highest array total
		{
			highRainfall = rainfall[counter];
			indexHigh = counter;						 //Set the index reference variable to the element position found
		}
	}
	return highRainfall;
}
//This function steps through the rainfall array elements and determines which one has the lowest rainfall amount.
//That amount is then returned to the program, and the element index of what month that is gets updated in the program.
//The parameters are the rainfall array, the variable for total months in the year, and a reference to the highest month index number.
double FindLowest(double rainfall[], int months, int& indexLow)
{
	double  lowRainfall = rainfall[0];						//Initialize the variable with the first element in the array
	
	for (int counter = 0; counter < months; counter++)		//Loop through the rainfall array elements
	{
		if (rainfall[counter] < lowRainfall)				//Setup an if check to determine the lowest array total
		{
			lowRainfall = rainfall[counter];
			indexLow = counter;								//Set the index reference variable to the element position found
		}
		return lowRainfall;
	}
}
//This function uses the index number set from FindHighest to send the month name from the monthNames array to the program
//The parameters are the index numer from the highest month and the monthNames array
string DisplayHighest(int indexHigh, string monthNames[])
{
	string highMonth;

	highMonth = monthNames[indexHigh];  //Use the index number to retreive the month name string from the array
	
	return highMonth;
}
//This function uses the index number set from FindLowest to send the month name from the monthNames array to the program
//The parameters are the index numer from the lowest month and the monthNames array
string DisplayLowest(int indexLow, string monthNames[])
{
	string lowMonth;

	lowMonth = monthNames[indexLow];  //Use the index number to retreive the month name string from the array

	return lowMonth;
}
//This function displays all of the program's data to the user in a final report.  The display is formatted to round and show two decimal places.
//The parameters are based on the return data from the other functions collected in main variables.
//Parameters 1 and 2 are for the year total and average rainfall
//Parameters 3 and 4 are a pair with the double collecting the highest month's value and the string is the corresponding month's name
//Parameters 5 and 6 are a pair with the double collecting the lowest month's value and the string is the corresponding month's name
void DisplayResults(double rainTotal, double rainAVG, double monthRainHigh, string monthHigh, double monthRainLow, string monthLow)
{
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n";
	cout << "Rainfall Metrics for the Prior Year Report";
	cout << "\n";
	cout << "------------------------------------------" << endl;
	cout << "Total rainfall for the year: " << rainTotal << endl;
	cout << "Average monthly rainfall: " << rainAVG << endl;
	cout << "Highest month of rainfall: " << monthRainHigh << " occurred in " << monthHigh << endl;
	cout << "Lowest month of rainfall: " << monthRainLow << " occurred in " << monthLow << endl;
	cout << "\n";
}
