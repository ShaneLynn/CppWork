/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 1
 Created: 5/06/2021
*
*
-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program collects product sales data from the user and generates a report of sales activity. It uses three arrays total to hold the data with two generated from
 external files (ProductNames.txt and ProductPrices.txt) which are checked before opening.  And, if the files are not found the function will inform the user and halt
 the program execution.  The final array holds the data input from the user based on the total bottles sold for each product line, and validation is used to prevent 
 the user from entering negative products sold. Also, all of the arrays operate in parallel to avoid incorrect associations.  
 
 The program uses multiple functions to collect, calculate, and display the final report in a table format (see below).  The report itself contains all product names,
 prices, and item sale amounts which are the base for the total calculations of each line item.  It also shows the overall sales total and identifies the highest and 
 lowest selling product and lists its amount.

 Final output format template (all columns evenly spaced, and currency format used):
 
 Product Name		Product Price		Amount Sold		Total Sales
 Item 1				$ Price 1			Sales 1			(Price 1 * Sales 1)
 (repeated for all product lines)

 =============================================================================
                                    Totals                                  
 
      Highest Sales: (product name) is the most popular sauce by selling: (amount sold) bottles
   Highest Grossing: (product name) is the highest earning product priced at $(Product Price) and earning $(total Sales)
       Lowest Sales: (product name) is the least popular sauce by selling: (amount sold) bottles
	Lowest Grossing: (product name) is the lowest earning product priced at $(Product Price) and earning $(total Sales)
 Total Bottles Sold: (sum of amount sold)
      Overall Sales: $(sum of total sales)


* This program uses the following functions:

•	int RetreiveProductNames(string[]);
	o	Accepts the parameter for the productNames array.
	o	Checks to see if the file is present, and then loads the external file of names into the array.
	o	Returns an int of 0 to end the program if the file fails to load.

•	int RetreiveProductPrices(double[]);
	o	Accepts the parameter for the productPrices array.
	o	Checks to see if the file is present, and then loads the external file of prices into the array.
	o	Returns an int of 0 to end the program if the file fails to load	.

•	void CollectSalesData(long[], string[]);
	o	Accepts the parameters for the productsSold array and the productNames array.
	o	Collects user input for the total bottles sold and displays the product name from the corresponding names array.
	o	Validates user input using a loop to prevent negative numbers sold.

•	double CalculateOverallSales(long[], double[], long&);
	o	Accepts the parameters for the productsSold array, productPrices array, and the reference variable to store totalBottlesSold.
	o	Uses a for loop to calculate the dollar sales for all products and the total bottles sold across all products.
	o	Returns the overall dollar sales amount.

•	void FindHighestLowest(double[], long[], int&, int&, int&, int&);
	o	Accepts the parameters for the productsSold array, productPrices array, and the reference variables of highestPrice, highestSold,
		lowestPrice, and lowestSold.
	o	Uses a for loop and multiple checks to determine and set the highest and lowest selling quantity and earning product lines.

•	void DisplayReport(string[], double[], long[], int&, int&, int&, int&, double, long);
	o	Accepts the parameters for the productNames, productPrices, and productsSold arrays.  It also accepts the variables
		highestPrice, highestSold, lowestPrice, lowestSold, overallSales, and totalBottlesSold.
	o	Once collected, it displays a report in table format using those variables.  It also calculates as needed.
	o	A for loop is used to step through each line item to display the final report to the user.

***************************************************************************************************************************/


//Header files used for the program
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

//Declare global variables for the array sizes based on the total products sold by the company
const int products = 6;


//Declare the function prototypes
int RetreiveProductNames(string[]);
int RetreiveProductPrices(double[]);
void CollectSalesData(long[], string[]);
double CalculateOverallSales(long[], double[], long&);
void FindHighestLowest(double[], long[], int&, int&, int&, int&);
void DisplayReport(string[], double[], long[], int&, int&, int&, int&, double, long);

//The main program function
int main()
{
	//Delare Variables:
	double overallSales = 0;								//Holds the calculated total forthe sum of all sales
	int highestPrice = 0;									//Holds the product's index position ID that is the highest grossing
	int highestSold = 0;									//Holds the product's index position ID that is the highest selling
	int lowestPrice = 0;									//Holds the product's index position ID that is the lowest grossing
	int lowestSold = 0;										//Holds the product's index position ID that is the lowest selling
	long totalBottlesSold = 0;								//Holds the calculation for the total bottles sold across all lines
	
	//Declare the arrays for product names, prices, and sales:
	string productNames[products];							//Setup the array to hold product names, initialized from file ProductNames.txt
	double productPrices[products];							//Setup the array to hold product prices, initialized from file ProductPrices.txt
	long productsSold[products];							//Setup the array to hold the bottles sold collected from user input

	//Load the product names and prices from the external files by calling the functions
	RetreiveProductNames(productNames);
	RetreiveProductPrices(productPrices);

	
	//Initial prompt display for the program to the user
	cout << "Welcome to the Superior Sauces reporting system!" << endl;
	cout << "\n";

	//Call the method to collect user input for the products sold
	CollectSalesData(productsSold, productNames);

	//Call the methods to calculate the report data (highest, lowest, total products sold, and overall sales)
	overallSales = CalculateOverallSales(productsSold, productPrices, totalBottlesSold);
	FindHighestLowest(productPrices, productsSold, highestPrice, highestSold, lowestPrice, lowestSold);

	//Call the method to display the final report to the user
	DisplayReport(productNames, productPrices, productsSold, highestPrice, highestSold, lowestPrice, lowestSold, overallSales, totalBottlesSold);


	//Prompt to close the program
	cout << "\n";
	cout << "Thank you for using the system.  Press any key to close...";
	cin.ignore();
	cin.get();

	return 0;
}


/****************************************************************************************
This function loads the product names into the array from a file to be used by the program.
It is setup to return an integer so it can close the program if the file fails to load.
****************************************************************************************/
int RetreiveProductNames(string productNames[])
{
	ifstream inputFile;						//Create the object to read data from the product names file
	string fileData = "";					//Created to hold the input from the file while reading.

	//Use the file stream object to open the file which should be placed in the same location as this file
	inputFile.open("ProductNames.txt");

	//Validate the text file can be opened and end the program if it is missing while processing if it opens
	if (inputFile.fail())
	{
		cout << "\nFile Not Found!! -- ProductNames.txt" << endl;
		cout << "Make sure the file is located in the same directory and try again." << endl;
		cout << "Press any key to close...";
		cin.ignore();
		cin.get();
		exit(0);
	}
	else
	{
		//Use a loop to read the data from the file which ends based on the global products count
		for (int index = 0; index < products; index++)
		{
			getline(inputFile, fileData);
			productNames[index] = fileData;
		}

		//Close the connection to the file
		inputFile.close();

		//Status update to the user
		cout << "--Product name file loaded and the array update was successful." << endl;
	}
}


/****************************************************************************************
This function loads the product prices into the array from a file to be used by the program.
It is setup to return an integer so it can close the program if the file fails to load.
****************************************************************************************/
int RetreiveProductPrices(double productPrices[])
{
	ifstream inputFile;						//Create the object to read data from the product prices file
	double fileData = 0;					//Created to hold the input from the file while reading.

	//Use the file stream object to open the file which should be placed in the same location as this file
	inputFile.open("ProductPrices.txt");

	//Validate the text file can be opened and end the program if it is missing while processing if it opens
	if (inputFile.fail())
	{
		cout << "\nFile Not Found!! -- ProductPrices.txt" << endl;
		cout << "Make sure the file is located in the same directory and try again." << endl;
		cout << "Press any key to close...";
		cin.ignore();
		cin.get();
		exit(0);
	}
	else
	{
		//Use a loop to read the data from the file which ends when no more entries are present
		for (int index = 0; index < products; index++)
		{
			inputFile >> fileData;
			productPrices[index] = fileData;
		}

		//Close the connection to the file
		inputFile.close();

		//Status update to the user
		cout << "--Product price file loaded and the array update was successful." << endl;
		cout << "\n";
	}
}


/****************************************************************************************
This function calculates the overall sales of every product sold by the company.  It works
with the bottles sold and prices arrays in parallel, and stores the calculations for the
gross dollar sales and bottle sales across all product lines. Finally it uses accumulator
variables which store the calculations.  The bottles sold total is stored in the reference
variable while the overall sales dollar amount is returned to the program when finished.
****************************************************************************************/
double CalculateOverallSales(long sales[], double prices[], long &totalSold)
{
	long bottlesSold = 0;					//Start with all at 0 to process calculations
	double salePrice = 0;
	double itemSales = 0;
	double overallSales = 0;

	//Calculate the overall dollar and bottle sales across all lines
	for (int index = 0; index < products; index++)
	{
		bottlesSold = sales[index];
		salePrice = prices[index];
		itemSales = salePrice * bottlesSold;
		overallSales += itemSales;
		totalSold += bottlesSold;
	}

	return overallSales;
}


/****************************************************************************************
This function moves through the products sold array and locates the products that have
the highest and lowest products sold and price sales.  When found, it sets the values of 
the reference parameters located in the main program.
****************************************************************************************/
void FindHighestLowest(double prices[], long sales[], int& highestPrice, int& highestSold, int& lowestPrice, int& lowestSold)
{
	int highestProdSold = sales[0];							//Set and calculate the initial values to the first array position's contents
	double highestProdPrice = sales[0] * prices[0];
	int lowestProdSold = sales[0];
	double lowestProdPrice = sales[0] * prices[0];
	double currentProdSales = 0;

	for (int index = 0; index < products; index++)
	{
		currentProdSales = sales[index] * prices[index];	//Calculate the total sales price per item before checking high/low values

		//Find the highest of the products sold
		if (sales[index] > highestProdSold)			//Check to find the highest sold amount
		{
			highestProdSold = sales[index];
			highestSold = index;					//Update the reference variable with the index position

		}

		//Find the highest of the product's gross sales amount
		if (currentProdSales > highestProdPrice)	//Check against current calculation to find the highest gross price
		{
			highestProdPrice = currentProdSales;
			highestPrice = index;					//Update the reference variable with the index position

		}
	
			
		//Find the lowest of the products sold
		if (sales[index] < lowestProdSold)			//Check to find the lowest sold amount
		{
			lowestProdSold = sales[index];
			lowestSold = index;						//Update the reference variable with the index position

		}

		//Find the lowest of the product's gross sales amount
		if (currentProdSales < lowestProdPrice)		//Check against current calculation to find the lowest gross price
		{
			lowestProdPrice = currentProdSales;
			lowestPrice = index;					//Update the reference variable with the index position

		}
	}
}


/****************************************************************************************
This function collects input from the user to store into the prodcutsSold array.  It runs
the arrays in parallel to display the product name to make it easy for the user to determine
which line is being entered.  The function also uses validation to prevent entering a 
negative quantity sold.
****************************************************************************************/
void CollectSalesData(long sales[], string names[])
{
	for (int index = 0; index < products; index++)  //Uses a for loop to walk through the productsSold array
	{
		cout << "Please enter the total bottles sold for the " << names[index] << " product line: ";
		cin >> sales[index];
		while (sales[index] < 0) //Input validation.  Does not accept negative numbers.
		{
			cout << "Invalid Entry.  Sales cannot be negative, so enter an amount 0 or larger." << endl;
			cout << "Please enter the total bottles sold for the " << names[index] << " product line: ";
			cin >> sales[index];
		}
	}
}


/****************************************************************************************
This function displays the final report to the user.  It accepts the data calculated from the
other functions and needs to be called last.  It uses a loop to step through the arrays to
display each product line item.  Calculations are also performed to generate the Total Sales
summary column.  Currency display is formatted using fixed decimal input with the rest of the
report having a specified with table structure.
****************************************************************************************/
void DisplayReport(string names[], double prices[], long sales[], int& highestPrice, int& highestSold, int& lowestPrice, int& lowestSold, double overallSales, long totalSold)
{
	//Prompt to the user that this function is called and what follows is the report
	cout << "Generating the final report..." << endl;
	cout << "\n";
	cout << "Sales Report for Superior Sauces:" << endl;

	//Create the table columns
	cout << setw(15) << "Product Name" << " | " << setw(15) << "Product Price" << " | " << setw(15) << "Amount Sold" << " | " << setw(15) << "Total Sales" << endl;

	//Display the table row data
	for (int index = 0; index < products; index++)
	{
		cout << setw(15) << names[index] << " | " << setw(11) << "$" << setprecision(2) << fixed << showpoint << prices[index] << " | " << setw(15) << sales[index] << " | " << setw(10) << setprecision(2) << fixed << showpoint << "$" << (sales[index] * prices[index]) << endl;
	}

	//Display the additional totals section with calculations performed for the Highest/Lowest Grossing entries.
	cout << "=============================================================================" << endl;
	cout << setw(40) << "TOTALS" << endl;
	cout << "   Highest Sales: " << names[highestSold] << " is the most popular sauce selling: " << sales[highestSold] << " bottles" << endl;
	cout << "Highest Grossing: " << names[highestPrice] << " is the highest earning product priced " << endl;
	cout << "                     at $" << prices[highestPrice] << " and earning $" << setprecision(2) << fixed << showpoint << (sales[highestPrice] * prices[highestPrice]) << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "    Lowest Sales: " << names[lowestSold] << " is the least popular sauce selling: " << sales[lowestSold] << " bottles" << endl;
	cout << " Lowest Grossing: " << names[lowestPrice] << " is the lowest earning product priced" << endl;
	cout << "                     at $" << prices[lowestPrice] << " and earning $" << setprecision(2) << fixed << showpoint << (sales[lowestPrice] * prices[lowestPrice]) << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Total Bottles Sold: " << totalSold << endl;
	cout << "     Overall Sales: $" << setprecision(2) << fixed << showpoint << overallSales << endl;
}



