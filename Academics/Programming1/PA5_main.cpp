/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 5
	Created: 3/23/2021
*
*Description:
*This program will calculate the amount of compound interest earned over a year on a static balance.  It will perform the
following:

*	Collect the principal (opening) balance on the account, interest rate, and the total times interest is compounded (12 for the year).
	Calculate the interest earned and new balance amounts using the formula: New Balance = Principal * (1 + rate/T)T
*	Display the interest rate, times compounded, principal, interest dollars earned, and ending amount in savings to the user

*	These calculations are based on the following input data:
	Interest Rate:	4.25%
*	Times Compounded:	12
	Principal:	$1000.00
*
*Pseudocode:

*START
*	Include header files iomanip, cmath, and iostream
* 
	Declare variables:
*		int timesCompounded
		double principalBalance
*		double interestRate
*		double interestPercent
*		double initialInterestGain
		double interestTotal
		double finalBalance
*		
*	Collect Data from user:
*		Display "Enter the starting or principal balance: "
*		Input to principalBalance
* 
*		Display "Enter the annual interest rate: "
*		Input to interestRate
* 
*		Display "Enter the total times interest is compounded: "
*		Input to timesCompounded
*

*	Calculate variables:
	interestRate = interestRate / 100
*	initialInterestGain = principalBalance * pow((1 + (interestRate/timesCompounded)), timesCompounded)
*	interestTotal = initialInterestGain - principalBalance
	interestPercent = interestRate * 100
	finalBalance = principalBalance + interestTotal

*	Display setprecision to 2, fixed, showpoint  
*	Display "\n"
	Display "Interest Rate: " << \t << setw() << interestPercent << "%"
*	Display "Times Compounded: " << \t << setw() << timesCompounded
	Display "Principal: " << \t << "$" << setw() << principalBalance
*	Display "Interest: " <<  \t << "$" << setw() << interestTotal
*	Display "Amount in Savings: "  << \t << "$" << setw() << finalBalance
*END
***************************************************************************************************************************/

//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//The main program function
int main()
{
	//Variables
	int timesCompounded;				//Holds how many times the interest is compounded in a year
	double principalBalance;			//Holds the initial monthly balance of an account
	double interestRate;				//Holds the interest rate gained annually
	double interestPercent;				//Holds the caclulated value to display as a percent.
	double initialInterestGain;			//Holds the total dollar amount gained from interest calculation total
	double interestTotal;				//Holds the calculated dollar amount of balance gain from interest over the year
	double finalBalance;				//Holds the calculated account of the closing balance after adding gained interest


	//Collect the input from the user for each field
	cout << "Enter the starting or principal balance: ";
	cin >> principalBalance;

	cout << "Enter the annual interest rate percent: ";
	cin >> interestRate;

	cout << "Enter the total times interest is compounded: ";
	cin >> timesCompounded;


	//Calculate the interest gained, convert the rate to a percent for program use and display, and ending account balance
	interestRate = interestRate / 100;
	initialInterestGain = principalBalance * pow((1 + (interestRate / timesCompounded)), timesCompounded);
	interestTotal = initialInterestGain - principalBalance;
	interestPercent = interestRate * 100;
	finalBalance = principalBalance + interestTotal;

	//Format the variable output for currency
	cout << fixed << showpoint << setprecision(2);

	//Display the results of the calculations for the user
	cout << "\n";
	cout << "Interest Rate: " << "\t\t" << setw(8) << interestPercent << "%";
	cout << "\nTimes Compounded: " << "\t" << setw(9) << timesCompounded;
	cout << "\nPrincipal: " << "\t\t" << "$" << setw(8) << principalBalance;
	cout << "\nInterest: " << "\t\t" << "$" << setw(8) << interestTotal;
	cout << "\nAmount in Savings: " << "\t" << "$" << setw(8) << finalBalance;
	cout << "\n";

	return 0;
}
