/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 11
	Created: 4/05/2021
*
* ASSIGNMENT
* In this assignment, you will be writing a program to help a teacher calculate the final grade for all the exams a student has taken. The student’s lowest grade must be dropped from the average.
The program is required to have the following functions:
*	void GetScore(double & score)
	o	This function should prompt the user for a test score, the test scored entered should be stored in the reference parameter.
	o	The function should validate the user input before ending the function. The grade entered must be greater than or equal to 0 and less than or equal to 100.
	o	The program will get 6 grades from the user, so this method must be called 6 times.
*	void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
	o	This function will calculate the average of the five highest test scores.
	o	The function will be called by main only one time, the six test scores must be passed all at once via the parameters.
	o	Average must be displayed with a precision of 2 decimal places.
	o	This function will use the FindLowest function to know which test score to drop.
*	double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
	o	This function will find and return the lowest score of the scores passed to it.
	o	This method must be called by CalcAverage, which uses the function to determine which of the six scores to drop.

Pseudocode must be provided in the comment block at the top of the file.



**See book examples programming challenge 11

* 
-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program is used to calculate final grades for students based on all of their test scores.  The program will calculate all of the student's scores and then drop the
 lowest score before determining the average.  The program uses three functions (GetScore, CalcAverage, and FindLowest) to complete the calculations based on 6 grades provided
 by the user.

 The program will validate all user input and not allow negative numbers or numbers larger than 100 for the test scores.  Each of the functions perform a different task in the program.

 *	void GetScore(double & score)
	o	This function prompts users for a test score, and the input gets stored in a variable used as a reference parameter.
	o	User input is validated, and grade scores cannot be less than 0 and more than 100.
	o	The method should be called the same amount of times as each score is needed.  In this case it should be called 6 times.
*	void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
	o	This function calculates the average of the five highest test scores, and does not use the lowest score.
	o	It will accept six test scores all at once via the parameters.
	o	The average returned is displayed using only 2 decimal places.
	o	Another function called FindLowest is called to determine which of the entered scores is the lowest.
*	double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
	o	This function determines which of the provided scores is the lowest.
	



*	The final calculations should display in this format:
*		Student Scores Used:
*		Lowest Score Dropped:
*		Final Student Grade:
*		
*		
*

*
***Pseudocode:

*START
	Include header files iostream, iomanip, cmath

	use namespace std

  Main()
	//Declare variables:
		
		double score1						//Variable to hold student scores entered by the GetScore function
		double score2						//Variable to hold student scores entered by the GetScore function
		double score3						//Variable to hold student scores entered by the GetScore function
		double score4						//Variable to hold student scores entered by the GetScore function
		double score5						//Variable to hold student scores entered by the GetScore function
		double score6						//Variable to hold student scores entered by the GetScore function

	Initialize variables:
		score1 = 0
		score2 = 0
		score3 = 0
		score4 = 0
		score5 = 0
		score6 = 0
	
	//Declare Function Prototypes:
	void GetScore(double &)
	void CalcAverage(double, double, double, double, double, double)
	double FindLowest(double, double, double, double, double, double)

	//Initial Display to the user
	Display "This program will calculate the final grade average from all test scores a student has taken"
	Display "while keeping the scoring consistent by dropping the lowest score for all students."
	
	//Call functions to get and calculate the scores
	Call GetScore(score1)
	Call GetScore(score2)
	Call GetScore(score3)
	Call GetScore(score4)
	Call GetScore(score5)
	Call GetScore(score6)


	//Final Display to user
	Display "\newline"

	//Function has its own display, call here to display final grade
	CalcAverage(score1, score2, score3, score4, score5, score6)   
	Display "\newline"

	//Prompt the user to close the program
	Display "Thank you for using the system.  Press any key to close..."
	Input.ignore() to flush the buffer of new lines
	Input.get() to accept an input to close the program
  End Main

  void GetScore(double &score)
		score = 0
		Display "Enter a student's test score: "
			Input >> score
			while (score < 0 || score > 100)
				Display "Inavlid entry.  Please enter a test value in the range of 0 to 100."
					Input >> score


  void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
 
		double FindLowest(double, double, double, double, double, double)	
		double dropScore
		double finalAverage
		
		dropScore = FindLowest(score1, score2, score3, score4, score5, score6)
		
		finalAverage = (((score1 + score2 + score3 + score4 + score5 + score6) - dropScore) / 5)

	
		Display setprecision to 2, fixed, showpoint
		Display "\newline"

		Display setprecision(2) << fixed << showpoint;
		Display "\newline"

		Display "Student Scores Used:         " << score1 << " | " << score2 << " | " << score3 << " | ";
		Display score4 << " | " << score5 << " | " << score6 << endl;
		Display "\newline"
		Display "Lowest Score Dropped:        " << dropScore << endl;
		Display "\newline"
		Display	"Final Student Grade:	      " << finalAverage
	
	
  double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
		static double lowestScore = score1
 
		if (lowestScore < score2)
			lowestScore = score2
		else if (lowestScore < score3)
			lowestScore = score3
		else if (lowestScore < score4)
			lowestScore = score4
		else if (lowestScore < score5)
			lowestScore = score5
		else if (lowestScore < score6)
			lowestScore = score6
 
		return lowestScore
 
*			
			
*END
***************************************************************************************************************************/



//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Declare Function Prototypes:
void GetScore(double&);
void CalcAverage(double, double, double, double, double, double);
double FindLowest(double, double, double, double, double, double);

//The main program function
int main()
{
	//Declare variables:
	double tScore1 = 0;						//Variable to hold student scores entered by the GetScore function
	double tScore2 = 0;						//Variable to hold student scores entered by the GetScore function
	double tScore3 = 0;						//Variable to hold student scores entered by the GetScore function
	double tScore4 = 0;						//Variable to hold student scores entered by the GetScore function
	double tScore5 = 0;						//Variable to hold student scores entered by the GetScore function
	double tScore6 = 0;						//Variable to hold student scores entered by the GetScore function


	//Initial Display to the user
	cout << "This program will calculate the final grade average from " << endl;
	cout << "all test scores a student has taken while keeping the " << endl;
	cout << "scoring consistent by dropping the lowest score for all students." << endl;

	//Call this function to get and set the test scores
	GetScore(tScore1);
	GetScore(tScore2);
	GetScore(tScore3);
	GetScore(tScore4);
	GetScore(tScore5);
	GetScore(tScore6);

	//This function has its own display, call here to input the test scores and display final grade stats
	cout << "\n";
	CalcAverage(tScore1, tScore2, tScore3, tScore4, tScore5, tScore6);   
	cout << "\n";

	//Prompt to close the program
	cout << "\n";
	cout << "Thank you for using the system.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}

//This function collects test scores from the user and stores them in the main function variables
void GetScore(double &score)
{
	score = 0;
	cout << "\n";
	cout << "Enter a student's test score: ";
	cin >> score;
		while (score < 0 || score > 100) //INput validation.  Don't let the user enter negative or greater than 100 values
		{
			cout << "Inavlid entry.  Please enter a test value in the range of 0 to 100: ";
			cout << "\n";
			cin >> score;
		}
}
//This function calculates and displays the final grade results for the student's test scores.
void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6)
{
	//Declare variables
	double dropScore = 0;
	double finalAverage = 0;

	//Call FindLowest function to get the lowest score
	dropScore = FindLowest(score1, score2, score3, score4, score5, score6);

	//Calculate the final score by summing, dropping the lowest score, and averaging the remaining scores
	finalAverage = (((score1 + score2 + score3 + score4 + score5 + score6) - dropScore) / 5);

	//Final Display from the Function to the user
	cout << setprecision(2) << fixed << showpoint;
	cout << "\n";
	cout << "Here is the final grade summary:" << endl;
	cout << "Student Scores Used:        " << score1 << " | " << score2 << " | " << score3 << " | ";
	cout << score4 << " | " << score5 << " | " << score6 << endl;
	cout << "Lowest Score Dropped:       " << dropScore << endl;
	cout << "Final Student Grade:        " << finalAverage << endl;
}

//This function evaluates all of the test scores entered and determines which one is the lowest score
double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6)
{
	double lowestScore = score1;

	if (score2 < lowestScore)
		lowestScore = score2;
	if (score3 < lowestScore)
		lowestScore = score3;
	if (score4 < lowestScore)
		lowestScore = score4;
	if (score5 < lowestScore)
		lowestScore = score5;
	if (score6 < lowestScore)
		lowestScore = score6;

	return lowestScore;
}



