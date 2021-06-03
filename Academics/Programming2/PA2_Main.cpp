/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 2
 Created: 5/11/2021
*
* 
-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program collects student names and scores to generate a report with the scores sorted in ascending order.  The program has
 two arrays that use dynamic memory allocation with their size determined by asking the user how many student scores
 they have to enter.  Once the user enters the total students to report, the program will then loop through the total students and
 ask the user to enter a name and score for each entry.  Once the input is finished, the program will call functions to sort the results,
 calculate the class average, and then display the sorted results and average to the user based on the format below.

 Validation is done on the user input fields to determine the array size (students) and the student's score to not accept negative values.

 The final report output should appear in this format:
 Student				  Score
 ------------------------------
 Richard				  67.40

 Mark					  67.83

 Jane					  72.65

 Sandy				      95.32

 Class average is:  75.80


* This program uses the following functions:

•	void GetGrades(double* scores, string* students, int size)
	o	Accepts the parameters for studentNames and studentScores pointers, and the array size variable
	o	Uses a loop to prompt the user to input values for the names and scores for each student

•	void DisplayGrades(double* scores, string* students, int size, double avg)
	o	Accepts the parameters for both studentNames and studentScores pointers, the array size variable, and scoreAVG variable
	o	Uses a loop to display results from both arrays

•	void Sort(double* scores, string* students, int size)
	o	Accepts the parameters for both studentNames and studentScores pointers as well as the array size variable
	o	Uses a select sort algorithim with two loops and variables to compare the values in studentScores and determine
		which one is the least in that iteration.
	o	Calls the SortSwap function to switch the values

•	void SortSwap(double& first, double& second) ; void SortSwap(string& first, string& second)
	o	Overloaded function: accepts paramaters from the two arrays which are the scores (double) and students(string)
	o	Accepts subscript parameters from the studentSores array during the sort function
	o	Swaps the values of first and second to change positions of the values in the array

•	double Average(double* scores, int size)
	o	Accepts the parameter for the studentScores array pointer and the array size variable
	o	Uses a loop to step through the array and tally the values in an accumulator
	o	Returns the accumulator value

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

//Declare the function prototypes:
void GetGrades(double*, string*, int);
void DisplayGrades(double*, string*, int, double);
void Sort(double*, string*, int);
void SortSwap(double&, double&);
void SortSwap(string&, string&);
double Average(double*, int);


//The main program function
int main()
{
	//Delare Variables:
	int totalStudents = 0;										//Holds the value for the array size to be filled in by the user
	double scoreAVG = 0;										//Holds the average calculation returned from the function
	
	//Initial prompt startup display for the user
	cout << "Welcome to the Student Grading reporting system!" << endl;
	cout << "\n";
	cout << "Enter the total number of students with scores: ";
	cin >> totalStudents;
	while (totalStudents < 0)
	{
		cout << "Total students cannot be negative.  Enter 0 or higher: ";
		cin >> totalStudents;
	}

	//Declare the arrays using dynamic memory allocation:
	string* studentNames = new string[totalStudents];				//Setup the array to hold student names
	double* studentScores = new double[totalStudents];				//Setup the array to hold student scores

	//Call the method to collect user input for the student's names and scores
	GetGrades(studentScores, studentNames, totalStudents);

	//Call the methods to sort the results and calculate the average for the student scores
	Sort(studentScores, studentNames, totalStudents);
	scoreAVG = Average(studentScores, totalStudents);

	//Call the method to display the final report to the user
	cout << "\nThe final results for all entered students are:" << endl;
	cout << "\n";
	DisplayGrades(studentScores, studentNames, totalStudents, scoreAVG);

	//Remove the memory allocation for the arrays
	delete[] studentNames;
	delete[] studentScores;

	//Prompt to close the program
	cout << "\n";
	cout << "Thank you for using the system.  Press any key to close...";
	cin.ignore();
	cin.get();

	return 0;
}


/****************************************************************************************
This function prompts the user for the student's name and test score.  It uses a for loop 
to step though both arrays to collect user input and store it before moving to the next
element.  Pointers are used to direct data to the correct memory location and store the 
value using the indirection operator.
****************************************************************************************/
void GetGrades(double* scores, string* students, int size)
{
	string studentName;						//Stores the student's name input from the user
	double studentScore = 0;				//Stores the student's score input from the user

	//Loop through the studentScores array to collect input based on the size argument supplied for the array size
	for(int index = 0; index < size; index++)
	{
		cout << "\n";
		cout << "Enter the name for student " << index + 1 << ": ";
		cin.ignore();								//Flush the buffer to avoid auto entries
		getline(cin, studentName);					//Use getline incase student's full names are used
		
		cout << "Enter the score for student " << index + 1 << ": ";
		cin >> studentScore;
		while (studentScore < 0)		//Validate the input to prevent negative numbers
		{
			cout << "Student's score cannot be negative.  Enter 0 or higher: ";
			cin >> studentScore;
		}

		*(students + index) = studentName;			//Update the pointer with the value for the current array element 
		*(scores + index) = studentScore;			//Update the pointer with the value for the current array element
	}
}


/****************************************************************************************
This function displays the final report list of sorted student scores to the user.  It
uses a for loop to step through both arrays and uses the pointer to call the values.  The
display is set to be left aligned for the student's and the standard right alignment for
the student's scores.  The student name field may not be big enough if first and last names
are used, so the columns may become unaligned with larger names entered.  The average variable
is called at the end to display the class average.
****************************************************************************************/
void DisplayGrades(double* scores, string* students, int size, double avg)
{
	cout << left << setw(25) << "Student" << setw(25) << "Score" << endl;
	cout << "------------------------------" << endl;
	cout << setprecision(2) << showpoint << fixed;

	for (int index = 0; index < size; index++)
	{
		cout << left << setw(25) << *(students + index) << setw(25) << *(scores + index) << endl;
		cout << "\n";
	}

	cout << "Class average is:  " << avg << endl;
}


/****************************************************************************************
This function uses the selection sort algorithm on the pointers for the studentScores
array to arrange them into ascending order.  It also sorts the names attached to those 
scores in the studentNames array at the same time to avoid detaching the name from the 
score.  The program uses two for loops based on the studentScores array since those are the
numeric values to be sorted.  The first loop is the main loop that is moving along each 
element while the second loop is scanning the array and using an if check to compare the
values found.  If the new value is lower, it stores the value and index position in the
holding variables.  It drops back to the main for loop and calls the SortSwap function
twice to switch the values in both arrays before ending and moving to the next element.
****************************************************************************************/
void Sort(double* scores, string* students, int size)
{
	int minIndex;							//Holds the lowest index position found
	double minScrValue;						//Holds the value of the lowest poistion found
	
	for (int start = 0; start < (size - 1); start++)		//Loop through the array, uses size-1 because final position will be set before last position
	{
		minIndex = start;									//Set the minIndex value to the start counter of the main loop
		minScrValue = *(scores + start);					//Set the student's score value based on the pointer's position according to the start counter value

		for (int index = start + 1; index < size; index++)	//Loop to step through the array to sort in ascending order
		{
			if (*(scores + index) < minScrValue)			//If check to determine if the pointer's value is less than the previous value
			{
				minScrValue = *(scores + index);			//Update the new position 
				minIndex = index;
			}
		}
		SortSwap(*(scores + minIndex), *(scores + start));			//Call the swap functions for both arrays to change value positions
		SortSwap(*(students + minIndex), *(students + start));
	}
}


/****************************************************************************************
This function is overloaded and is a companion to the Sort() function.  The first version
accepts values from the studentScores array pointer and the second from the studentNames
pointer.  Both operate the same by storing the first value in the temp position and the
second argument under the first variable.  The second variable is then updated with the 
temp value, and the positions of the variables are switched.  Reference parameters are
used to update the pointer array directly.
****************************************************************************************/
void SortSwap(double& first, double& second)
{
	double temp = first;
	first = second;
	second = temp;
}
void SortSwap(string& first, string& second)
{
	string temp = first;
	first = second;
	second = temp;
}


/****************************************************************************************
This function calculates the average based on the values in the studentScores array.  It 
uses a for loop to step through each element and then the pointer's position value is then
added to the score accumulator.  Once the loop finishes the score variable is divided by
the size variable from the totalStudents variable that determines the array size.  The
calculated average value is then returned to the program.
****************************************************************************************/
double Average(double* scores, int size)
{
	double average;						//Stores the average calculation
	double score = 0;					//Accumulator variable set to 0

	for (int index = 0; index < size; index++)
	{
		score += *(scores + index);
	}

	average = score / size;				//Calculates the average

	return average;
}
