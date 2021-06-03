/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 14
	Created: 4/22/2021
*
-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program is for the IT department of Acme Electronics that generates a report on the previous year's sales for leadership to use.
 To accomplish this, the program uses a 2-Dimensional array which holds the sales totals for the 4 divisions (North, South, East, West) and
 the 4 quarters (QTR1, QTR2, QTR3, QTR4).  The array also has space for an extra row and column (for divisions and quarters) totals, and the structure
 of the array has the quarters as the columns and the divisions as the rows. The last column holds the totals for the rows (division totals)
 and the last row holds the totals for the columns (quarter totals). The last element is not used at this time.

 The second array stores the division names (North, South, East, and West) and the third array stores the quarter information (Quarter 1 to 4)
 both of which are called in parrallel to aid in input from the user, and when when generating the final report.  

 The program uses functions to create the report.  One is setup to collect sales data as input from the user, and the other functions run
 calculations before generating the report.  
 
 And, the program also uses the global constants (ROWS and COLS) to control the array sizes for the table structure.
 
* The program uses these functions to interact with main() and generate the data for the report:
•	double CalculateTotal(double [][COLS]);
	o	Calculate the total of the complete array
	o	Does not calculate the totals in the last column and last row.
	o	Return the array total.
•	double CalculateAverage(double [][COLS]);
	o	Calculate the average of all the values in the array
	o	Does not calculate the totals in the last column and last row (4*4 elements, not 5*5).
	o	Return the average.
•	double CalculateRowTotal(double [][COLS], int);
	o	Calculate the total for a specific row using the second parameter.
	o	Returns the total for the specified row.
•	double CalculateColumnTotal(double [][COLS], int);
	o	Calculates the total for a specific column using the second parameter.
	o	Return the total for the specified column.
•	double FindHighest(double [][COLS], int&, int&);
	o	Finds the highest sales in the array.
	o	Finds the index values (row, column) of the highest QTR, and changes the variables in main
	o	Return the highest sales amount.
•	double FindLowest(double [][COLS], int&, int&);
	o	Finds the lowest sales in the array.
	o	Finds the index values (row, column) of the lowest QTR, and changes the variables in main.
	o	Return the lowest sales amount.
•	void CollectSalesData(double [], string [], string []);
	o	Collects input from the user and stores it in the sales[][] array by division and qtr
	o	Uses collected parameters to generate

	
	o Final report display template (will need to resize the console window when it opens to view correctly):

	Sales by division and quarter for the previous year: 
					Quarter 1	|	Quarter 2	|	Quarter 3	|	Quarter 4	||	Division Total
					------------------------------------------------------------------------------
	North		  |	$			|	$			|	$			|	$			||	$			 |
	______________|_____________|_______________|_______________|_______________||_______________|
	South		  |	$			|	$			|	$			|	$			||	$			 |
	______________|_____________|_______________|_______________|_______________||_______________|
	East		  |	$			|	$			|	$			|	$			||	$			 |
	______________|_____________|_______________|_______________|_______________||_______________|
	West		  |	$			|	$			|	$			|	$			||	$			 |
	==============|=============|===============|===============|===============||================
	|											Totals											 |
	----------------------------------------------------------------------------------------------
	Quarter		  |	$			|	$			|	$			|	$			||	$			 |
	----------------------------------------------------------------------------------------------
	Highest Sales (by division and quarter):	(division) had $x,xxx sales in (Quarter)
	Lowest Sales  (by division and quarter):	(division) had $x,xxx sales in (Quarter)
	Total Sales  (all divisions and quarters):	Acme had $x,xxx in sales this year
	Average Sales (by quarter):					Acme averaged $x,xxx sales per quarter


*
***Pseudocode:

*START
	Include header files iostream, iomanip, cmath, cstdlib, string

	use namespace std

	//Declare global variables
	const int ROWS = 5				//Holds row size for arrays.  Initializing at 5 to include extra division totals row
	const int COLS = 5				//Holds column size for arrays.  Initializing at 5 to include extra quarter totals column

	//Declare function prototypes
	double CalculateTotal(double [][COLS])
	double CalculateAverage(double [][COLS])
	double CalculateRowTotal(double [][COLS], int)
	double CalculateColumnTotal(double [][COLS], int)
	double FindHighest(double [][COLS], int&, int&)
	double FindLowest(double [][COLS], int&, int&)
	void CollectSalesData(double [][COLS], string [], string [])
	
  MAIN()
	Declare Variables:
		int highestRowQTR = 0
		int highestColQTR = 0
		
		int lowestRowQTR = 0
		int lowestColQTR = 0
	
		double totalSales
		double totalSalesAVG
		double highestSales
		double lowestSales

		
	Declare Arrays:
		string divisions[4] = { "North", "South", "East", "West" }
		string quarters[4] =  { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4" }
		double sales [ROWS] [COLS] 
		//Test data before input into actual array
		double sales [ROWS] [COLS] = {	{1312.17, 4464.62, 6811.12, 7842.89, 0},			
										{1551.46, 717.31, 4198.73, 5197.66, 0},
										{3928.88, 2681.55, 11612.59, 9759.24, 0},
										{2684.97, 2493.74, 8864.69, 9680.13, 0},
										{0, 0, 0, 0, 0}}

		
		Display << "Welcome to Acme Electronics annual sales report." << endl
		Display << "Please enter the total sales amounts for each division and quarter" << endl
		CollectSalesData(sales[][COLS], divisions, quarters)
		

		totalSales = CalculateTotal(sales)
		totalSalesAVG = CalculateAverage(sales)
		highestSales = FindHighest(sales, highestRowQTR, highestColQTR)
		lowestSales = FindLowest(sales, lowestRowQTR, lowestColQTR)


		
		//Generate the totals for the array
		sales[0][4] = CalculateRowTotal(sales, 0)
		sales[1][4] = CalculateRowTotal(sales, 1)
		sales[2][4] = CalculateRowTotal(sales, 2)
		sales[3][4] = CalculateRowTotal(sales, 3)

		sales[4][0] = CalculateColumnTotal(sales, 0)
		sales[4][1] = CalculateColumnTotal(sales, 1)
		sales[4][2] = CalculateColumnTotal(sales, 2)
		sales[4][3] = CalculateColumnTotal(sales, 3)


		//Test section.  Checks to see if the array calculates correctly before the final report display is used
		Display << "The total sales are: $" << totalSales << endl
		Display << "The average sales per QTR are: $" << totalSalesAVG << endl
		Display << "The highest sales this year was $" << highestSales << " from " << divisions[highestRowQTR] << " division in QTR " << quarters[highestColQTR] << endl
		Display << "The lowest sales this year was $" << lowestSales << " from " << divisions[lowestRowQTR] << " division in QTR " << quarters[lowestColQTR] << endl
		Display << "The Division totals are:" << endl
			for (int row = 0; row < ROWS-1; row++)
			{
			 for (int col = 0; col < COLS-1; col++)
				{
				Display << divisions[row] << " division sales in " << quarters[col] << " = $" << sales[row][col]
							
				}
			 Display << " || divisions[row] << " total sales for the year are $" << sales[row][4] << endl
			}
			for (int row = 4; row < ROWS; rows++)
			{
				for(int col = 0; col < COLS-1; col++)
				{
				Display << "Total for " << quarters[col] << " is $" << sales[row][col] << endl
			}

	
	Display << "Generating the final report..." << endl
	Display << "\n"
	Display << "Sales by division and quarter for the previous year:" << endl
	Display << setprecision(2) << fixed << showpoint
	Display << "\t   " << quarters[0] << " | " << quarters[1] << "  | " << quarters[2] << "  | " << quarters[3] << "  || Division Total" << endl
	Display << "\t---------------------------------------------------------------------" << endl
	Display << setw(7) << divisions[0] << " | $" << setw(9) << sales[0][0] << " | $" << setw(9) << sales[0][1] << " | $" << setw(9) << sales[0][2] << " | $" << setw(9) << sales[0][3] << " || $" << setw(11) << sales[0][4] << " |" << endl
	Display << "________|____________|____________|____________|____________||______________|" << endl
	Display << setw(7) << divisions[1] << " | $" << setw(9) << sales[1][0] << " | $" << setw(9) << sales[1][1] << " | $" << setw(9) << sales[1][2] << " | $" << setw(9) << sales[1][3] << " || $" << setw(11) << sales[1][4] << " |" << endl
	Display << "________|____________|____________|____________|____________||______________|" << endl
	Display << setw(7) << divisions[2] << " | $" << setw(9) << sales[2][0] << " | $" << setw(9) << sales[2][1] << " | $" << setw(9) << sales[2][2] << " | $" << setw(9) << sales[2][3] << " || $" << setw(11) << sales[2][4] << " |" << endl
	Display << "________|____________|____________|____________|____________||______________|" << endl
	Display << setw(7) << divisions[3] << " | $" << setw(9) << sales[3][0] << " | $" << setw(9) << sales[3][1] << " | $" << setw(9) << sales[3][2] << " | $" << setw(9) << sales[3][3] << " || $" << setw(11) << sales[3][4] << " |" << endl
	Display << "========|============|============|============|============||===============" << endl
	Display << "|                               Totals                                      |" << endl
	Display << "-----------------------------------------------------------------------------" << endl
	Display << "Quarter | $" << setw(9) << sales[4][0] << " | $" << setw(9) << sales[4][1] << " | $" << setw(9) << sales[4][2] << " | $" << setw(9) << sales[4][3] << " || $" << setw(11) << totalSales << " |" << endl
	Display << "-----------------------------------------------------------------------------" << endl
	Display << "Highest Sales (by division and quarter):\t " << divisions[highestRowQTR] << " had $" << setw(6) << highestSales << " sales in " << quarters[highestColQTR] << endl
	Display << "Lowest Sales  (by division and quarter):\t " << divisions[lowestRowQTR] << " had $" << setw(6) << lowestSales << " sales in " << quarters[lowestColQTR]  << endl
	Display << "Total Sales  (all divisions and quarters):\t Acme had $" << setw(6) << totalSales << " in sales this year" << endl
	Display << "Average Sales (by quarter):\t\t\t Acme averaged $" << setw(6) << totalSalesAVG << " sales per quarter" << endl




		Display "Thank you for using the system.  Press any key to close..."
		Input.ignore() to flush the buffer of new lines
		Input.get() to accept an input to close the program


  END MAIN()

  double CalculateTotal(double sales[][COLS]);
		
		double totalSales
		
		for (int row = 0; row < ROWS-1; row++)
		{
			 for (int col = 0; col < COLS-1; col++)
				totalSales += sales[row][col];

		}
		Return totalSales
	
 
 double CalculateAverage(double sales[][COLS]);
		double average
		double total
		int totalCounted = 0
		for (int row = 0; row < ROWS-1; row++)
		{
			 for (int col = 0; col < COLS-1; col++)
				total += sales[row][col];
				totalCounted += 1

		}
		average = total / totalCounted
		Return average
  
  double CalculateRowTotal(double sales[][COLS], int rowSelected);
		double rowTotal = 0
		for (int column = 0; column < COLS-1; column++)
		{
			
				rowTotal += sales[rowSelected][column]

		}
		return rowTotal
			
  double CalculateColumnTotal(double sales[][COLS], int columnSelected);
		double colTotal = 0
		for (int row = 0; row < ROWS-1; row++)
		{
			
				colTotal += sales[row][columnSelected]

		}
		return colTotal

	
  double FindHighest(double sales[][COLS], int &highestRowQTR, int &highestColQTR);
		double highest = sales[0][0]

		for (int row = 0; row < ROWS-1; row++)
		{
			 for (int col = 0; col < COLS-1; col++)
				if(sales[row][col] > highest)
					highest = sales[row][col]
					highestRowQTR = row
					highestColQTR = col
		}
		
		Return highest

  double FindLowest(double sales[][COLS], int &lowestRowQTR, int &lowestColQTR);
		double lowest = sales[0][0]

		for (int row = 0; row < ROWS-1; row++)
		{
			 for (int col = 0; col < COLS-1; col++)
				if(sales[row][col] < lowest)
					lowest = sales[row][col]
					lowestRowQTR = row
					lowestColQTR = col
		}

		Return lowest

		
  void CollectSalesData(double sales[][COLS], string divisions[], string quarters[] ); 
		for (int row = 0; row < ROWS-1; row++)
		{
			 for (int col = 0; col < COLS-1; col++)
				Display << "Please enter the total sales for " << divisions[row] << " in " << quarters[col] << ": "
				Input >> sales[row][col]
					while (sales[row][col] < 0)
						Display << "Invalid Entry.  Sales cannot be negative, so enter a dollar amount 0 or larger."
						Display << "Please enter the total sales for " << divisions[row] << " in " << quarters[col] << ": "
						Input >> sales[row][col]

		}

*END
***************************************************************************************************************************/



//Header files needed for the program to function correctly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

//Declare global variables
const int ROWS = 5;			//Holds row size for arrays.  Initializing at 5 to include extra division totals row
const int COLS = 5;			//Holds column size for arrays.  Initializing at 5 to include extra quarter totals column

//Declare function prototypes
double CalculateTotal(double[][COLS]);
double CalculateAverage(double[][COLS]);
double CalculateRowTotal(double[][COLS], int);
double CalculateColumnTotal(double[][COLS], int);
double FindHighest(double[][COLS], int&, int&);
double FindLowest(double[][COLS], int&, int&);
void CollectSalesData(double[][COLS], string[], string[]);

//The main program function
int main()
{

	//Declare variables:
	int highestRowQTR = 0;				//Holds the row index id for the highest sales division
	int highestColQTR = 0;				//Holds the row index id for the highest sales quarter

	int lowestRowQTR = 0;				//Holds the row index id for the lowest sales division
	int lowestColQTR = 0;				//Holds the row index id for the lowest sales quarter

	double totalSales;				//Holds the calculated output for total yearly sales
	double totalSalesAVG;			//Holds the calculated output for the average quarterly sales
	double highestSales;			//Holds the amount from the highest sales quarter
	double lowestSales;				//Holds the amount from the lowest sales quarter


	//Declare Arrays:
	string divisions[4] = { "North", "South", "East", "West" };
	string quarters[4] = { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4" };
	double sales[ROWS][COLS];

	//Test data for the array
	/*double sales[ROWS][COLS] = { {1312.17, 4464.62, 6811.12, 7842.89, 0},			
								{1551.46, 717.31, 4198.73, 5197.66, 0},
								{3928.88, 2681.55, 11612.59, 9759.24, 0},
								{2684.97, 2493.74, 8864.69, 9680.13, 0},
								{0, 0, 0, 0, 0} }; */
	
	//Collect the sales data from the user
	cout << "Welcome to Acme Electronics annual sales report." << endl;
	cout << "\n";
	cout << "Please enter the total sales amounts for each division and quarter." << endl;
	CollectSalesData(sales, divisions, quarters);

	//Generate the calculations for the final report
	totalSales = CalculateTotal(sales);
	totalSalesAVG = CalculateAverage(sales);
	highestSales = FindHighest(sales, highestRowQTR, highestColQTR);
	lowestSales = FindLowest(sales, lowestRowQTR, lowestColQTR);

	//Generate the division totals for the final report
	sales[0][4] = CalculateRowTotal(sales, 0);
	sales[1][4] = CalculateRowTotal(sales, 1);
	sales[2][4] = CalculateRowTotal(sales, 2);
	sales[3][4] = CalculateRowTotal(sales, 3);

	//Generate the quarter totals for the final report
	sales[4][0] = CalculateColumnTotal(sales, 0);
	sales[4][1] = CalculateColumnTotal(sales, 1);
	sales[4][2] = CalculateColumnTotal(sales, 2);
	sales[4][3] = CalculateColumnTotal(sales, 3);


	//TESTING SECTION========================
	//Tests to see if the array calculates correctly before the report display
	/*cout << setprecision(2) << fixed << showpoint;
	cout << "The total sales are: $" << totalSales << endl;
	cout << "The average sales per QTR are: $" << totalSalesAVG << endl;
	cout << "The highest sales this year was $" << highestSales << " from " << divisions[highestRowQTR] << " division in " << quarters[highestColQTR] << endl;
	cout << "The lowest sales this year was $" << lowestSales << " from " << divisions[lowestRowQTR] << " division in " << quarters[lowestColQTR] << endl;
	cout << "The Division totals are:" << endl;
	
	//Test loop to print the array data for the final report
	for (int row = 0; row < ROWS - 1; row++)
	{
		for (int col = 0; col < COLS - 1; col++)
		{
			cout << divisions[row] << " division sales in " << quarters[col] << " = $" << sales[row][col] << endl;

		}
		cout << "|| " << divisions[row] << " total sales for the year are $" << sales[row][4] << endl;
	}
	for (int row = 4; row < ROWS; row++)
	{
		for (int col = 0; col < COLS - 1; col++)
		{
			cout << "Total sales for " << quarters[col] << " is $" << sales[row][col] << endl;
		}
	}*/
	//END TESTING SECTION======================
	
	//Display the final report to the user.  Change the output console window size to at least 90 wide and 25 high for optimal report viewing.
	cout << "Generating the final report..." << endl;
	cout << "\n";
	cout << "Sales by division and quarter for the previous year:" << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "\t   " << quarters[0] << " | " << quarters[1] << "  | " << quarters[2] << "  | " << quarters[3] << "  || Division Total" << endl;
	cout << "\t---------------------------------------------------------------------" << endl;
	cout << setw(7) << divisions[0] << " | $" << setw(9) << sales[0][0] << " | $" << setw(9) << sales[0][1] << " | $" << setw(9) << sales[0][2] << " | $" << setw(9) << sales[0][3] << " || $" << setw(11) << sales[0][4] << " |" << endl;
	cout << "________|____________|____________|____________|____________||______________|" << endl;
	cout << setw(7) << divisions[1] << " | $" << setw(9) << sales[1][0] << " | $" << setw(9) << sales[1][1] << " | $" << setw(9) << sales[1][2] << " | $" << setw(9) << sales[1][3] << " || $" << setw(11) << sales[1][4] << " |" << endl;
	cout << "________|____________|____________|____________|____________||______________|" << endl;
	cout << setw(7) << divisions[2] << " | $" << setw(9) << sales[2][0] << " | $" << setw(9) << sales[2][1] << " | $" << setw(9) << sales[2][2] << " | $" << setw(9) << sales[2][3] << " || $" << setw(11) << sales[2][4] << " |" << endl;
	cout << "________|____________|____________|____________|____________||______________|" << endl;
	cout << setw(7) << divisions[3] << " | $" << setw(9) << sales[3][0] << " | $" << setw(9) << sales[3][1] << " | $" << setw(9) << sales[3][2] << " | $" << setw(9) << sales[3][3] << " || $" << setw(11) << sales[3][4] << " |" << endl;
	cout << "========|============|============|============|============||===============" << endl;
	cout << "|                               Totals                                      |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Quarter | $" << setw(9) << sales[4][0] << " | $" << setw(9) << sales[4][1] << " | $" << setw(9) << sales[4][2] << " | $" << setw(9) << sales[4][3] << " || $" << setw(11) << totalSales << " |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	cout << "Highest Sales (by division and quarter):\t " << divisions[highestRowQTR] << " had $" << setw(6) << highestSales << " sales in " << quarters[highestColQTR] << endl;
	cout << "Lowest Sales  (by division and quarter):\t " << divisions[lowestRowQTR] << " had $" << setw(6) << lowestSales << " sales in " << quarters[lowestColQTR]  << endl;
	cout << "Total Sales  (all divisions and quarters):\t Acme had $" << setw(6) << totalSales << " in sales this year" << endl;
	cout << "Average Sales (by quarter):\t\t\t Acme averaged $" << setw(6) << totalSalesAVG << " sales per quarter" << endl;
	

//Prompt to close the program
	cout << "\n";
	cout << "\n";
	cout << "Thank you for using the program.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}

//This function calculates the total sales from all divisions and quarters in the sales array except for the total row and column.
double CalculateTotal(double sales[][COLS])
{

	double totalSales = 0;

		for (int row = 0; row < ROWS - 1; row++)
		{
			for (int col = 0; col < COLS - 1; col++)
				totalSales += sales[row][col];

		}
		return totalSales;
}
//This function calculates and returns the yearly average of every entry in the array except the total row and column.
double CalculateAverage(double sales[][COLS])
{
	double average;
	double total = 0;			//This accumulator holds the sum of all array elements.
	int totalCounted = 0;		//This accumulator counts the elements added to the total.
		for (int row = 0; row < ROWS - 1; row++)
		{
			for (int col = 0; col < COLS - 1; col++)
			{
				total += sales[row][col];
				totalCounted += 1;
			}

		}
	average = total / totalCounted;		//Calculation to get the average quarterly sales from all quarters
	return average;
}

//This function calculates each row (division) in the sales array based on the input.  It
//is designed to return one row at a time, so should be called multiple times using the
//rowSelected input to determine which division in the array to retreive.
double CalculateRowTotal(double sales[][COLS], int rowSelected)
{
	double rowTotal = 0;
		for (int column = 0; column < COLS - 1; column++)
		{

			rowTotal += sales[rowSelected][column];

		}
		return rowTotal;
}

//This function calculates each column (quarter) in the sales array based on the input.  It
//is designed to return one column at a time, so should be called multiple times using the
//columnSelected input to determine which quarter in the array to retreive.
double CalculateColumnTotal(double sales[][COLS], int columnSelected)
{
	double colTotal = 0;
		for (int row = 0; row < ROWS - 1; row++)
		{

			colTotal += sales[row][columnSelected];

		}
	return colTotal;
}

//This function moves through the sales array and locates the division and quarter that has
//the highest sales amounts.  When found, it returns the value and adjusts the two input
//variables to the current position in the sales array for use in the final report.
double FindHighest(double sales[][COLS], int& highestRowQTR, int& highestColQTR)
{
	double highest = sales[0][0];		//Set the current value to the first array position

	for (int row = 0; row < ROWS - 1; row++)
	{
		for (int col = 0; col < COLS - 1; col++)
		{
			if (sales[row][col] > highest)		//Check to find the highest amount
			{
				highest = sales[row][col];
				highestRowQTR = row;
				highestColQTR = col;
			}
		}
	}

	return highest;
}

//This function moves through the sales array and locates the division and quarter that has
//the lowest sales amounts.  When found, it returns the value and adjusts the two input
//variables to the current position in the sales array for use in the final report.
double FindLowest(double sales[][COLS], int& lowestRowQTR, int& lowestColQTR)
{
	double lowest = sales[0][0];		//Set the current value to the first array position

		for (int row = 0; row < ROWS - 1; row++)
		{
			for (int col = 0; col < COLS - 1; col++)
			{
				if (sales[row][col] < lowest)		//Check to find the lowest amount
				{
					lowest = sales[row][col];
					lowestRowQTR = row;
					lowestColQTR = col;
				}
			}
		}

	return lowest;
}

//This function collects input from the user to store into the sales array.  It also uses divisions and quarters arrays
//to generate the prompt to let the user know what the array is ready to collect.
void CollectSalesData(double sales[][COLS], string divisions[], string quarters[])
{
	for (int row = 0; row < ROWS - 1; row++)  //Nested loop to walk through the 2D array
	{
		for (int col = 0; col < COLS - 1; col++)
		{
			cout << "Please enter the total sales for " << divisions[row] << " in " << quarters[col] << ": $";
				cin >> sales[row][col];
				while (sales[row][col] < 0) //Input validation.  Does not accept negative numbers.
				{
					cout << "Invalid Entry.  Sales cannot be negative, so enter a dollar amount 0 or larger." << endl;
					cout << "Please enter the total sales for " << divisions[row] << " in " << quarters[col] << ": $";
						cin >> sales[row][col];
				}
		}
	}

}
