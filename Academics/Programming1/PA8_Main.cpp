/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 8
	Created: 3/30/2021
*

-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program will calculate the customer discount for their utility bills from Municipal Power and Light due to an overcharge.  
 The program will collect the customer's name and kW hours used for the month and then apply the following rates and calculations to determine the discount:

kWh used							Cost Scale
--------------------------------	--------------------------------------
less than 1000						$0.052 per kWh used
at least 1000 but less than 1300	$0.052 per kWh for first 1000 kWh used
									$0.041 per kWh over 1000 kWh used
at least 1300 but less than 2000	$0.052 per kWh for first 1000 kWh used
									$0.041 per kWh for the next 300 kWh used
									$0.035 per kWh over 1300 kWh used
at least 2000						$0.052 per kWh for first 1000 kWh used
									$0.041 per kWh for the next 300 kWh used
									$0.035 per kWh for the next 700 kWh used
									$0.03 per kWh over 2000 kWh used

 City (1.5%) and State (3.5%) taxes are calculated from the total base amount of the bill before any discounts (12%).  

*	The final display should be in this format:
*		Customer Name:
*		Base Bill Amount (undiscounted and untaxed):
*		Discount Amount:
*		State Utility Tax Amount:
*		City Utility Tax Amount:
*		Total Amount Due:
		
*
***Pseudocode:

*START
*	Include header files iomanip, cmath, string and iostream
* 
*	use namespace std
*
	Declare variables:
*		string customerName
		int kwhUsed
		double baseRate
		double UseageTier1Rate
		double UseageTier2Rate
		double UseageTier3Rate
		double discountRate
		double stateTax
		double cityTax
		double totalAtBaseRate
		double totalAtTier1Rate
		double totalAtTier2Rate
		double totalAtTier3Rate
		double totalBaseBill
		double totalDiscount
		double totalStateTax
		double totalCityTax
		double totalAmountDue
*
	Initialize variables:
		baseRate = 0.052
		UseageTier1Rate = 0.041
		UseageTier2Rate = 0.035
		UseageTier3Rate = 0.030
		discountRate = 0.12
		stateTax = 0.035
		cityTax = 0.015
*		totalAtBaseRate = 0
		totalAtTier1Rate = 0
		totalAtTier2Rate = 0
		totalAtTier3Rate = 0
		double totalBaseBill = 0
		totalDiscount = 0
		totalStateTax = 0
		totalCityTax = 0
		totalAmountDue = 0

*	Collect Data from user:
*		Display "This program will calculate discounts for Municipal Power and Light customers."
		Display "\newline"
		Display "Enter the customer's name: "
*		Input to customerName
* 
*		Display "\newline"
*		Display "Please enter " << customerName << "'s total kW Hours used for the month (in whole hours): "
*		Input to kwhUsed
*			Valdiate Input => if (kwhUsed < 0), "Inavlid input, cannot be a negative number.  Run again and enter a positive whole number."

*	
	Calculate rates based on KW Hours used by customer
		if (kwhUsed < 1000)
			totalAtBaseRate = baseRate * kwhUsed
		else if (kwhUsed >= 1000 && kwhUsed < 1300)
			totalAtBaseRate = baseRate * 1000
			totalAtTier1Rate = UseageTier1Rate * (kwhUsed - 1000)
		else if (kwhUsed >= 1300 && kwhUsed < 2000)
			totalAtBaseRate = baseRate * 1000
			totalAtTier1Rate = UseageTier1Rate * 300
			totalAtTier2Rate = UseageTier2Rate * (kwhUsed - 1300)
		else if (kwhUsed >= 2000)
			totalAtBaseRate = baseRate * 1000
			totalAtTier1Rate = UseageTier1Rate * 300
			totalAtTier2Rate = UseageTier2Rate * 700
			totalAtTier3Rate = UseageTier2Rate * (kwhUsed - 2000)


	Calculate final total variables:
		totalBaseBill = totalAtBaseRate + totalAtTier1Rate + totalAtTier2Rate + totalAtTier3Rate
		totalDiscount = totalBaseBill * discountRate
*		totalStateTax = totalBaseBill * stateTax
		totalCityTax = totalBaseBill * cityTax
		totalAmountDue = (totalBaseBill - totalDiscount) + totalStateTax + totalCityTax

*	Display setprecision to 2, fixed, showpoint
*	Display "\newline"
	Display "Customer Name:                                " << customerName
•	Display	"Base Bill Amount (undiscounted and untaxed): $" << totalBaseBill
•	Display "Discount Amount:                             $" << totalDiscount
•	Display	"State Utility Tax Amount:                    $" << totalStateTax
•	Display	"City Utility Tax Amount:                     $" << totalCityTax
•	Display	"Total Amount Due:                            $" << totalAmountDue
	Display "\newline"

	Display "Thank you for using the system.  Press any key to close..."
	Input.Ignore() to flush the buffer of new lines
	Input.get() to accept an input to close the program
*END
***************************************************************************************************************************/



//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//The main program function
int main()
{
	//Declare variables:
	string customerName;					//Holds the input for customer name
	int kwhUsed;							//Holds the input for the customer's KW hours used
	const double baseRate = 0.052;					//This is the current rate for base services
	const double UseageTier1Rate = 0.041;			//This is the first tier discount rate for kW hours based on useage
	const double UseageTier2Rate = 0.035;			//This is the third tier discount rate for kW hours  based on useage
	const double UseageTier3Rate = 0.030;			//This is the third tier discount rate for kW hours  based on useage
	const double discountRate = 0.12;				//This is the current discount amount applied to the next bill
	const double stateTax = 0.035;					//This is the current tax rate for the state on utility bills
	const double cityTax = 0.015;					//This is the current tax rate for the state on utility bills
	double totalAtBaseRate = 0;				//Calculated field that holds the base rate totals
	double totalAtTier1Rate = 0;			//Calculated field that holds the tier 1 usage rate totals
	double totalAtTier2Rate = 0;			//Calculated field that holds the tier 2 usage rate totals
	double totalAtTier3Rate = 0;			//Calculated field that holds the tier 3 usage rate totals
	double totalBaseBill = 0;				//Calculated field that holds the unmodified bill totals
	double totalDiscount = 0;				//Calculated field that holds the unmodified bill discount
	double totalStateTax = 0;				//Calculated field that holds the amount due to the state based on the unmodified bill
	double totalCityTax = 0;				//Calculated field that holds the amount due to the city based on the unmodified bill
	double totalAmountDue = 0;				//Calculated field that holds the final amount due to the customer
	
	
	//Collect Data from user
	cout << "This program will calculate discounts for Municipal Power and Light customers.";
	cout << "\n";
	cout << "\n";
	cout << "Enter the customer's name: ";
	getline(cin, customerName);
	
	cout << "\n";
	cout << "Please enter " << customerName << "'s total kW Hours used";
	cout << "\nfor the month (in whole hours): ";
	cin >> kwhUsed;
	
	//Valdiate Input
	if (kwhUsed < 0)
	{
		cout << "\n";
		cout << "Inavlid input, cannot be a negative number.  Run again and enter a positive whole number.";
		cout << "\n";

		//Prompt to close the program
		cout << "\nThank you for using the system.  Press any key to close...";
		cin.ignore();
		cin.get();

		return 0;
	}

	//Calculate rates based on KW Hours used by customer
		if (kwhUsed < 1000)
		{
			totalAtBaseRate = baseRate * kwhUsed;
		}
		else if (kwhUsed >= 1000 && kwhUsed < 1300)
		{
			totalAtBaseRate = baseRate * 1000;
			totalAtTier1Rate = UseageTier1Rate * (kwhUsed - 1000);
		}
		else if (kwhUsed >= 1300 && kwhUsed < 2000)
		{
			totalAtBaseRate = baseRate * 1000;
			totalAtTier1Rate = UseageTier1Rate * 300;
			totalAtTier2Rate = UseageTier2Rate * (kwhUsed - 1300);
		}
		else if (kwhUsed >= 2000)
		{
			totalAtBaseRate = baseRate * 1000;
			totalAtTier1Rate = UseageTier1Rate * 300;
			totalAtTier2Rate = UseageTier2Rate * 700;
			totalAtTier3Rate = UseageTier3Rate * (kwhUsed - 2000);
		}


		//Calculate final total variables
		totalBaseBill = totalAtBaseRate + totalAtTier1Rate + totalAtTier2Rate + totalAtTier3Rate;
		totalDiscount = totalBaseBill * discountRate;
		totalStateTax = totalBaseBill * stateTax;
		totalCityTax = totalBaseBill * cityTax;
		totalAmountDue = (totalBaseBill - totalDiscount) + totalStateTax + totalCityTax;

		//Display Results to User
		cout << setprecision(2) << fixed << showpoint;
		cout << "\n";
		cout << "\nCustomer Name:                               " << customerName;
		cout << "\nBase Bill Amount (undiscounted and untaxed): $" << totalBaseBill;
		cout << "\nDiscount Amount:                             $" << totalDiscount;
		cout << "\nState Utility Tax Amount:                    $" << totalStateTax;
		cout << "\nCity Utility Tax Amount:                     $" << totalCityTax;
		cout << "\nTotal Amount Due:                            $" << totalAmountDue;
		cout << "\n";
		cout << "\n";

		//Prompt to close the program
		cout << "Thank you for using the system.  Press any key to close...";
		cin.ignore();
		cin.get();

	return 0;
}
