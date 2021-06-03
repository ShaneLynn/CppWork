/***********************************************************************************************
*Author: Christopher S Lynn
		CISS 241 -  Programming I
*		Programming Assignment 4
		Created: 3/18/2021
*
*Description:

*This program will calculate and display some stock market calculations.  It will perform the
*following:

*	The amount paid for the stock alone (without commission)
	The amount of the comission
*	The total amount paid (for the stock plus commission)

*	These calculations are to be based on Cathy's 600 shares of stock, $33.77 per share, 
	and 2% comission per transaction.
*
*Pseudocode:

*START
	Declare variables:
*		int sharesPurchased
		double orignialStockPrice
*		double brokerCommission
		double totalStockPrice
*		double totalCommission
		double totalStockCommPrice
*
	Initialize variables:
*		sharesPurchased = 600
		orignialStockPrice = 33.77
*		double brokerCommission = .02
		
*
	totalStockPrice = orignialStockPrice * sharesPurchased
*	totalCommission = (totalStockPrice * brokerCommission)
	totalStockCommPrice = totalStockPrice + totalCommission
*
	Display "Cathy purchased " sharesPurchased " shares of stock for $" orignialStockPrice
*	Display "The amount of commission is " (brokerCommission * 100) "%, for a total of $" << totalCommission
	Display "The price Cathy paid for the stock without the commission is $" totalStockPrice
*	Display "The price Cathy paid for the stock with the commission is $" totalStockCommPrice
*END
**************************************************************************************************/

//Header files needed to display the data properly
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	//Variables
	int sharesPurchased = 600;				//Holds how many shares were purchased
	double orignialStockPrice = 33.77;		//Holds the original selling price
	double brokerCommission = 0.02;			//Holds the commission percentage for the broker
	double totalStockPrice;					//Holds the caclulated total for stock purchase price
	double totalCommission;					//Holds the calculated total for the commission
	double totalStockCommPrice;				//Holds the calculated total for the total cost of the sale

	//Calculate the final prices for the stock sale
	totalStockPrice = orignialStockPrice * sharesPurchased;
	totalCommission = (totalStockPrice * brokerCommission);
	totalStockCommPrice = totalStockPrice + totalCommission;

	//Format the variable output to reflect currency
	cout << fixed << showpoint << setprecision(2);

	//Display the results of the calculations for the customer
	cout << "Cathy purchased " << sharesPurchased << " shares of stock for $" << orignialStockPrice;
	cout << "\nThe amount of commission is " << (brokerCommission * 100) << "%, for a total of $" << totalCommission;
	cout << "\nThe price Cathy paid for the stock without the commission is $" << totalStockPrice;
	cout << "\nThe price Cathy paid for the stock with the commission is $" << totalStockCommPrice;
	cout << "\n";

	return 0;
}
