/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 4
 Created: 5/25/2021
*
-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program lab creates a structure so it can hold sales data for each division of a corporation.  The program uses a function
 to prompt the user to enter sales data for each quarter.  Once each division structure is finished, a display function is called
 for each division that presents those totals to the user.


* The program uses two functions:
•	void GetDivisionSales(Division&);
	o	Takes in the structure as an argument as a refrence to modify it outside of the function
	o	Prompts the user to enter sales data by quarter for each division.
•	void DisplayDivision(Division);
	o	Takes in the structure as an argument
	o	Displays the results of the enter sales data by division structure to the user

***************************************************************************************************************************/

//Provided code from Source 4 file

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Division				//This structure is designed to hold division sales data. 
{
	string name;				//Variable to hold the name of the division
	double quarter1;			//These variables will hold the sales data from each of the division's quarters
	double quarter2;
	double quarter3;
	double quarter4;
};

void GetDivisionSales(Division& div);
void DisplayDivision(Division div);

int main()
{
	Division east, west, north, south;

	east.name = "East";
	west.name = "West";
	north.name = "North";
	south.name = "South";

	GetDivisionSales(east);
	GetDivisionSales(west);
	GetDivisionSales(north);
	GetDivisionSales(south);

	DisplayDivision(east);
	DisplayDivision(west);
	DisplayDivision(north);
	DisplayDivision(south);

	return 0;
}
/*This function accepts a division structure as a reference and then prompts the user to
* enter sales data by quarter.  The function will display the current structure's name first,
* (based on the division passed) and individually ask for each quarter's sales. No data is
* returned and each one is updated directly in main.*/
void GetDivisionSales(Division& div)
{
	cout << "\nPlease enter the sales data for division: " << div.name << endl;
	cout << "--Sales for quarter 1 are: ";
	cin >> div.quarter1;
	cout << "--Sales for quarter 2 are: ";
	cin >> div.quarter2;
	cout << "--Sales for quarter 3 are: ";
	cin >> div.quarter3;
	cout << "--Sales for quarter 4 are: ";
	cin >> div.quarter4;
}

void DisplayDivision(Division div)
{
	cout << "Sales amount for " << div.name << "Division" << endl;
	cout << setw(20) << div.quarter1 << endl;
	cout << setw(20) << div.quarter2 << endl;
	cout << setw(20) << div.quarter3 << endl;
	cout << setw(20) << div.quarter4 << endl;
	cout << "Total Sales " << div.quarter1 + div.quarter2
		+ div.quarter3 + div.quarter4 << endl;
}