/***************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 15 - Course Project
	Created: 4/26/2021
* 
-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program is for making and updating airline reservations for Stormy Skies Airlines. It initially provides a menu to the user that allows them
 to perform the following options: view the current seating chart, reserve a seat(s), display the total number of seats sold, view the total number
 empty seats per row, view the total number of seats empty in the plane, and view the total amount of sales (in dollars) for the current flight.  
 All seats and calculations are based on type (first class or coach) and overall total.  And, input validation is designed to prevent selecting invalid
 seat and row combinations as well as already reserved seats.
 
 While viewing the seating chart for the airplane, an (*) indicates a seat currently taken while (#) indicates an available seat.  There are two types
 of seats per flight on the airplane: first class and coach.  Each seat type will have a different cost which is read from the file called "SeatPrices.txt", and 
 stored in the array called "seatPrices" and the price breakdown is as follows: all first class seats are the same price (tier 1), rows 1-5 of coach seating are 
 more expensive (tier 2), rows 6-10 of the remaining coach seats have standard pricing (tier 3).

 The airplane holds 5 rows in first class with 4 seats in each row and 10 rows in the coach section with 6 in each row.
 
 The following is a display template for the seating chart of each aircraft:

          12 34
 Row  1:  ## ##
 Row  2:  ## ##
 Row  3:  ## ##
 Row  4:  ## ##
 Row  5:  ## ##

 	     123 456
 Row  1: ### ###
 Row  2: ### ###
 Row  3: ### ###
 Row  4: ### ###
 Row  5: ### ###
 Row  6: ### ###
 Row  7: ### ###
 Row  8: ### ###
 Row  9: ### ###
 Row 10: ### ###

  
* The program uses these functions to interact with main() and generate the calculations for the program:
•	int RetreiveSeatPrices(double seatPrices[]);
	o	Pulls seat prices from the SeatPrices.txt file and stores them into the seatPrices array
	o	Returns 0 for the main function to end the program if the file is not found on loading

•	void DisplayAvailableSeats(char[][firstClassColumns], char[][coachClassColumns], int, int, int, int, int, int);
	o 	Pulls in the seat arrays and the variables to adjust the available seats
	o	Calculates filled and remaining seats for the user
	
•	void FlightSoldSeats(int, int, int);
	o	Calculates and displays the current seats sold/reserved in the system total and by class

•	void FlightEmptySeats(int, int, int);
	o	The reverse of the seats sold function, this one shows all of the currently available seats on the flight by class

•	void EmptySeatsByRow(char[][firstClassColumns], char[][coachClassColumns]);
	o	Calculates and displays to the user how many seats are empty by class and row on the flight

•	void FlightSales(double, double, double);
	o	Calculates the dollar amount of all of the seats sold and by class on the flight
	o	Displays the results to the user using 2 decimal places for currency.

•	void ReserveSeats(char[][firstClassColumns], char[][coachClassColumns], double[], int&, int&, int&, int&, int&, int&, double&, double&, double&);
	o	Pulls in all variables and arrays as reference
	o	Asks for user input to make seat selections
	o	Calls the DisplayAvailableSeats function to make it easy for the user to select the row and column IDs for their choice
	o	Validation does not allow choices outside of valid rows/columns or reserving already purchased seats

•	void ResetReservations(char[][firstClassColumns], char[][coachClassColumns], int&, int&, int&, int&, int&, int&, double&, double&, double&);
	o	Pulls in the variables and arrays to reset all of the reservation changes back to a no sales state

*
***Pseudocode:

*START
	Include header files: iostream, iomanip, cmath, cstdlib, fstream, string

	use namespace std

	//Declare global variables for the array sizes
	const int firstClassRows = 5
	const int firstClassColumns = 4
	const int coachClassRows = 10
	const int coachClassColumns = 6

	//Function Prototypes:
	int RetreiveSeatPrices(double[]);
	void DisplayAvailableSeats(char[][firstClassColumns], char[][coachClassColumns], int, int, int, int, int, int)
	void FlightSoldSeats(int, int, int)
	void FlightEmptySeats(int, int, int)
	void EmptySeatsByRow(char[][firstClassColumns], char[][coachClassColumns])
	void FlightSales(double, double, double)
	void ReserveSeats(char[][firstClassColumns], char[][coachClassColumns], double[], int&, int&, int&, int&, int&, int&, double&, double&, double&)
	void ResetReservations(char[][firstClassColumns], char[][coachClassColumns], int&, int&, int&, int&, int&, int&, double&, double&, double&)

	MAIN()
			
	//Delare and Initialize Variables:
	int seatsAvailableFirstClass = 20							
	int seatsAvailablePremiumCoach = 30							
	int seatsAvailableStandardCoach = 30							
	int seatsFilledFirstClass = 0								
	int seatsFilledPremiumCoach = 0								
	int seatsFilledStandardCoach = 0								
	double seatsPurchasedFirstClass = 0							
	double seatsPurchasedPremCoachClass = 0						
	double seatsPurchasedCoachClass = 0							
	int menuChoice												

	//Delcare Arrays for the seating chart
	char firstClass[firstClassRows][firstClassColumns] = { {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'} }


	char coachClass[coachClassRows][coachClassColumns] = { {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'} }

	//Declare Array for seat prices:
	double seatPrices[3]										

	//Load the seat prices from the file
	RetreiveSeatPrices(seatPrices)

	//Initial prompt display and menu choices for the user
	DISPLAY << "Welcome to the Stormy Skies Airlines reservation system!" << endline
	DISPLAY << "\new line"


	//Start the menu loop to allow the user to use the reservation system
	do
	{
		DISPLAY << "\new line"
		DISPLAY << "1. Display Seat Layout and Availability" << endl
		DISPLAY << "2. Reserve a seat(s)" << endl
		DISPLAY << "3. View current seats sold" << endl
		DISPLAY << "4. View current empty seats per row" << endl
		DISPLAY << "5. View current empty seats on the flight" << endl
		DISPLAY << "6. View current flight seats sales" << endl
		DISPLAY << "7. Reset & refund all reservations on the flight" << endl
		DISPLAY << "8. Exit the system" << endl
		DISPLAY << "Please make a selection from the menu: "

		INPUT >> menuChoice

		if (menuChoice < 1 || menuChoice > 8)		//Input validation for the menu choices
		{
			DISPLAY << "\nInvalid Input.  Please select options 1-8: " << endl
		}
		else
		{
			//Setup a switch to handle the menu option selections
			switch (menuChoice)
			{
				case 1:
				{
					DISPLAY << "\n===1. Display Seat Layout and Availability" << endl
					DISPLAY << "\new line"
					DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach)
					break
				}
				case 2:
				{
					DISPLAY << "\n===2. Reserve a seat(s)" << endl
					ReserveSeats(firstClass, coachClass, seatPrices, seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach, seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach, seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass)
					break
				}
				case 3:
				{
					DISPLAY << "\n===3. View current seats sold" << endl
					FlightSoldSeats(seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach)
					break
				}
				case 4:
				{
					DISPLAY << "\n===4. View current empty seats per row" << endl
					DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach)
					EmptySeatsByRow(firstClass, coachClass)
					break
				}
				case 5:
				{
					DISPLAY << "\n===5. View current empty seats on the flight" << endl
					FlightEmptySeats(seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach)
					break
				}
				case 6:
				{
					DISPLAY << "\n===6. View current flight seat sales" << endl
					FlightSales(seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass)
					break
				}
				case 7:
				{
					DISPLAY << "\n===7. Reset & refund all reservations on the flight" << endl
					ResetReservations(firstClass, coachClass, seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach, seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach, seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass)
					DISPLAY << "\new line";
					break;
				}
				case 8:
				{
					DISPLAY << "\n===Exiting the reservation system..." << endl
					break
				}
			}
		}
	} while (menuChoice != 8)			


	//Prompt to close the program
	DISPLAY << "\newline"
	DISPLAY << "Thank you for flying with Stormy Skies Airlines.  Press any key to close..."
	INPUT.ignore()
	INPUT.get()

	return 0

	END MAIN


	//This function loads the seat prices into the array from a file to be used by the program.
	//It is setup to return an integer so it can close the program if the file fails to load
int RetreiveSeatPrices(double seatPrices[])
{
	ifstream inputFile					
	double fileData					

	//Use the file stream object to open the file
	inputFile.open("SeatPrices.txt")

	//Validate the text file can be openedand, and process if it does
	if (inputFile.fail())
	{
		DISPLAY << "\nFile Not Found!!" << endl
		DISPLAY << "Make sure the file is located in the same directory and try again." << endl
		DISPLAY << "Press any key to close..."  << endl
		INPUT.ignore()
		INPUT.get()
		exit(0)
	}
	else
	{
		//Loop to read the data from the file
		for (int counter = 0; counter < 3; counter++)
		{
			inputFile >> fileData
			seatPrices[counter] = fileData
		}

		//Close the connection to the file
		inputFile.close()

		//Status update to the user
		DISPLAY << "Price file loaded and array update successful." << endl
		DISPLAY << "\newline"
	}
}

	//This function displays the currently available seats and the seating chart layout for the airplane using the first class and coach seat arrays.
void DisplayAvailableSeats(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], int seatsAvailableFirstClass, int seatsFilledFirstClass, int seatsAvailablePremiumCoach, int seatsFilledPremiumCoach, int seatsAvailableStandardCoach, int seatsFilledStandardCoach)
{

	//Display first class seats
	DISPLAY << "\newline"
	DISPLAY << "FIRST CLASS SECTION" << endl
	DISPLAY << "           12  34" << endl
	DISPLAY << "Row   1:   " << firstClass[0][0] << firstClass[0][1] << "  " << firstClass[0][2] << firstClass[0][3] << endl
	DISPLAY << "Row   2:   " << firstClass[1][0] << firstClass[1][1] << "  " << firstClass[1][2] << firstClass[1][3] << endl
	DISPLAY << "Row   3:   " << firstClass[2][0] << firstClass[2][1] << "  " << firstClass[2][2] << firstClass[2][3] << endl
	DISPLAY << "Row   4:   " << firstClass[3][0] << firstClass[3][1] << "  " << firstClass[3][2] << firstClass[3][3] << endl
	DISPLAY << "Row   5:   " << firstClass[4][0] << firstClass[4][1] << "  " << firstClass[4][2] << firstClass[4][3] << endl

	//Display coach class seats
	DISPLAY << "\newline"
	DISPLAY << "COACH SECTION" << endl
	DISPLAY << "          123  456" << endl
	DISPLAY << "Row   1:  " << coachClass[0][0] << coachClass[0][1] << coachClass[0][2] << "  " << coachClass[0][3] << coachClass[0][4] << coachClass[0][5] << endl
	DISPLAY << "Row   2:  " << coachClass[1][0] << coachClass[1][1] << coachClass[1][2] << "  " << coachClass[1][3] << coachClass[1][4] << coachClass[1][5] << endl
	DISPLAY << "Row   3:  " << coachClass[2][0] << coachClass[2][1] << coachClass[2][2] << "  " << coachClass[2][3] << coachClass[2][4] << coachClass[2][5] << endl
	DISPLAY << "Row   4:  " << coachClass[3][0] << coachClass[3][1] << coachClass[3][2] << "  " << coachClass[3][3] << coachClass[3][4] << coachClass[3][5] << endl
	DISPLAY << "Row   5:  " << coachClass[4][0] << coachClass[4][1] << coachClass[4][2] << "  " << coachClass[4][3] << coachClass[4][4] << coachClass[4][5] << endl
	DISPLAY << "Row   6:  " << coachClass[5][0] << coachClass[5][1] << coachClass[5][2] << "  " << coachClass[5][3] << coachClass[5][4] << coachClass[5][5] << endl
	DISPLAY << "Row   7:  " << coachClass[6][0] << coachClass[6][1] << coachClass[6][2] << "  " << coachClass[6][3] << coachClass[6][4] << coachClass[6][5] << endl
	DISPLAY << "Row   8:  " << coachClass[7][0] << coachClass[7][1] << coachClass[7][2] << "  " << coachClass[7][3] << coachClass[7][4] << coachClass[7][5] << endl
	DISPLAY << "Row   9:  " << coachClass[8][0] << coachClass[8][1] << coachClass[8][2] << "  " << coachClass[8][3] << coachClass[8][4] << coachClass[8][5] << endl
	DISPLAY << "Row  10:  " << coachClass[9][0] << coachClass[9][1] << coachClass[9][2] << "  " << coachClass[9][3] << coachClass[9][4] << coachClass[9][5] << endl

	//Display seat counts
	DISPLAY << "\newline"
	DISPLAY << "First Class seats currently available: " << seatsAvailableFirstClass << endl
	DISPLAY << "First Class seats currently occupied: " << seatsFilledFirstClass << endl
	DISPLAY << "\newline"
	DISPLAY << "Coach Class seats currently available: " << seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl
	DISPLAY << "Coach Class seats currently occupied: " << seatsFilledPremiumCoach + seatsFilledStandardCoach << endl
	DISPLAY << "\newline"

}

	//This function calculates and displays the currently available seats on the flight.
void FlightSoldSeats(int seatsFilledFirstClass, int seatsFilledPremiumCoach, int seatsFilledStandardCoach)
{
	DISPLAY << "\newline"
	DISPLAY << "Total seats sold on the flight: " << seatsFilledFirstClass + seatsFilledPremiumCoach + seatsFilledStandardCoach << endl
	DISPLAY << "--First Class seats sold on the flight: " << seatsFilledFirstClass << endl
	DISPLAY << "--Coach Class seats sold on the flight: " << seatsFilledPremiumCoach + seatsFilledStandardCoach << endl
	DISPLAY << "----Premium Coach seats sold on the flight: " << seatsFilledPremiumCoach << endl
	DISPLAY << "----Standard Coach seats sold on the flight: " <<  seatsFilledStandardCoach << endl
	DISPLAY << "\newline"
}

	//This function uses loops to show the current empty seats available for each row by class
void EmptySeatsByRow(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns])
{
	int emptySeat = 0

		//Setup to loop through the firstClass array to find emtpy seats by row.
	DISPLAY << "\newline"
	DISPLAY << "FIRST CLASS " << endl

	for (int row = 0; row < firstClassRows; row++)
	{
		for (int col = 0; col < firstClassColumns; col++)
		{
			if (firstClass[row][col] == '#')
			{
				emptySeat += 1
			}

		}
		DISPLAY << "Row " << row + 1 << " seats available: " << emptySeat << endl
		emptySeat = 0
	}

	//Setup to loop through the coachClass array to find emtpy seats by row.
	DISPLAY << "\newline"
	DISPLAY << "COACH CLASS " << endl
	emptySeat = 0

	for (int row = 0; row < coachClassRows; row++)
	{
		for (int col = 0; col < coachClassColumns; col++)
		{
			if (coachClass[row][col] == '#')
			{
				emptySeat += 1
			}

		}
		DISPLAY << "Row " << row + 1 << " seats available: " << emptySeat << endl
		emptySeat = 0
	}
}

	//This function function retreives the currently empty seats on the flight, and it breaks coach down further into the tier 1 and 2 price structure.
void FlightEmptySeats(int seatsAvailableFirstClass, int seatsAvailablePremiumCoach, int seatsAvailableStandardCoach)
{
	DISPLAY << "\newline"
	DISPLAY << "Total seats currently available: " << seatsAvailableFirstClass + seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl
	DISPLAY << "--First Class seats currently available: " << seatsAvailableFirstClass << endl
	DISPLAY << "--Coach Class total seats currently available: " << seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl
	DISPLAY << "----Coach Class premium seats currently available: " << seatsAvailablePremiumCoach << endl
	DISPLAY << "----Coach Class standard seats currently available: " << seatsAvailableStandardCoach << endl
	DISPLAY << "\newline"
}

	//This function retreives the sales amounts of every seat sold on the flight broken out by type.
void FlightSales(double seatsPurchasedFirstClass, double seatsPurchasedPremCoachClass, double seatsPurchasedCoachClass)
{
	DISPLAY << "\newline"
	DISPLAY << setprecision(2) << fixed << showpoint
	DISPLAY << "Total Sales for the flight: $" << seatsPurchasedFirstClass + seatsPurchasedPremCoachClass + seatsPurchasedCoachClass << endl
	DISPLAY << "--First Class sales for the flight: $" << seatsPurchasedFirstClass << endl
	DISPLAY << "--Coach Class sales for the flight: $" << seatsPurchasedPremCoachClass + seatsPurchasedCoachClass << endl
	DISPLAY << "----Premium Coach sales for the flight: $" << seatsPurchasedPremCoachClass << endl
	DISPLAY << "----Standard Coach sales for the flight: $" << seatsPurchasedCoachClass << endl
	DISPLAY << "\newline"
}

	//This function allows the user to reset the reservation system to return everything to the starting values.  It uses the same parameter list as the ReserveSeat
	//function to adjust all of the same variable parameters to the initial values.
void ResetReservations(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], int& seatsAvailableFirstClass, int& seatsAvailablePremiumCoach, int& seatsAvailableStandardCoach, int& seatsFilledFirstClass, int& seatsFilledPremiumCoach, int& seatsFilledStandardCoach, double& seatsPurchasedFirstClass, double& seatsPurchasedPremCoachClass, double& seatsPurchasedCoachClass)
{
	//Reset everything
	seatsAvailableFirstClass = 20
	seatsAvailablePremiumCoach = 30
	seatsAvailableStandardCoach = 30
	seatsFilledFirstClass = 0
	seatsFilledPremiumCoach = 0
	seatsFilledStandardCoach = 0
	seatsPurchasedFirstClass = 0
	seatsPurchasedPremCoachClass = 0
	seatsPurchasedCoachClass = 0


	//Reset the first class array
	for (int row = 0; row < firstClassRows; row++)
	{
		for (int col = 0; col < firstClassColumns; col++)
		{
			firstClass[row][col] = '#'
			
		}
	}

	//Reset the coach array
	for (int row = 0; row < coachClassRows; row++)
	{
		for (int col = 0; col < coachClassColumns; col++)
		{
			coachClass[row][col] = '#'

		}
	}
	DISPLAY << "\newline"
	DISPLAY << "All reservations have been sucessfully cleared from the current flight." << endl
}

	//This function allows the user to book first class and coach seats on the flight.  For coach, it also selects the premium and standard prices
	//based on the row selection the user inputs.  The function uses lots of parameters to access the arrays and make adjustments for updating the
	//seat and price information.
void ReserveSeats(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], double seatPrices[], int &seatsAvailableFirstClass, int &seatsAvailablePremiumCoach, int &seatsAvailableStandardCoach, int &seatsFilledFirstClass, int &seatsFilledPremiumCoach, int &seatsFilledStandardCoach, double &seatsPurchasedFirstClass, double &seatsPurchasedPremCoachClass, double &seatsPurchasedCoachClass)
{

	int desiredSeats = 0
	int desiredClass
	int rowChoice
	int aisleChoice

	//Display the current seating information
	DISPLAY << "\newline"
	DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach);		//Display the currently available seats menu

	DISPLAY << "\newline"
	DISPLAY << "Would you like First Class or Coach tickets?" << endl
	DISPLAY << "Enter 1 for First Class and 2 for Coach: "
		INPUT >> desiredClass
		while (desiredClass != 1 && desiredClass != 2)		//Input validation step to prevent choices outside of the menu range
		{
			DISPLAY << "\nInvalid input.  You must enter 1 or 2: "
			INPUT >> desiredClass
		}

	DISPLAY << "\nHow many seats would you like to purchase? "
		INPUT >> desiredSeats
		while (desiredSeats < 0)			//Input validation step to prevent negative selections
		{
			DISPLAY << "\nInvalid input.  You must enter 0 or higher: "
				INPUT >> desiredSeats
		}
	if (desiredSeats == 0)		//Allows the user to avoid entering seats and return to the menu.
	{
		DISPLAY << "Returning the the main menu." << endl
		return;
	}

	if (desiredClass == 1)		//This section adds the reservations for the first class  section
	{
		//Loop to cycle through the first class seat selections
		DISPLAY << "\newline"
		for (int counter = 0; counter < desiredSeats; counter++)
		{
			DISPLAY << "\nFor seat " << counter+1 << " enter the First Class Row ID: "
			INPUT >> rowChoice;
				while (rowChoice < 1 || rowChoice > 5)		//Input validation for the flight row and column
				{
					DISPLAY << "Invalid Input. Enter a valid row range: "
					INPUT >> rowChoice
				}
			rowChoice -= 1			//Adjust the user input to fit into the arrry storage structure

			DISPLAY << "For seat " << counter+1 << " enter the First Class Aisle ID: "
			INPUT >> aisleChoice
				while (aisleChoice < 1 || aisleChoice > 4)		//Input validation for the flight row and column
				{
					DISPLAY << "Invalid Input. Enter a valid aisle range: "
					INPUT >> aisleChoice
				}
			aisleChoice -= 1		//Adjust the user input to fit into the arrry storage structure
			DISPLAY << "\newline"

			while (firstClass[rowChoice][aisleChoice] == '*')
			{
				DISPLAY << "That seat has already been reserved.  Please select another seat: "
				DISPLAY << "\nEnter the First Class Row ID: "
				INPUT >> rowChoice
					while (rowChoice < 1 || rowChoice > 5)		//Input validation for the flight row and column
					{
						DISPLAY << "Invalid Input. Enter a valid row range: "
						INPUT >> rowChoice
					}
				rowChoice -= 1			//Adjust the user input to fit into the arrry storage structure

				DISPLAY << "\nEnter the First Class Aisle ID: " << endl
				INPUT >> aisleChoice
					while (aisleChoice < 1 || aisleChoice > 4)		//Input validation for the flight row and column
					{
						DISPLAY << "Invalid Input. Enter a valid aisle range: "
						INPUT >> aisleChoice
					}
				aisleChoice -= 1		//Adjust the user input to fit into the arrry storage structure
				DISPLAY << "\newline"
			}

			firstClass[rowChoice][aisleChoice] = '*'
			seatsAvailableFirstClass--
			seatsFilledFirstClass++
			seatsPurchasedFirstClass += seatPrices[0]		//Adds the first class ticket price
			DISPLAY << "The seat has been booked successfully." << endl

		}
	}
	else if (desiredClass == 2)			//This section adds the reservations for the two different tiers for the coach section
	{

		//Loop to cycle through the coach seat selections
		DISPLAY << "\newline"
		for (int counter = 0; counter < desiredSeats; counter++)
		{
			DISPLAY << "\nFor seat " << counter+1 << " enter the Coach Class Row ID: "
			INPUT >> rowChoice
				while (rowChoice < 1 || rowChoice > 10)			//Input validation for the flight row and column
				{
					DISPLAY << "Invalid Input. Enter a valid row range: "
					INPUt >> rowChoice;
				}
			rowChoice -= 1			//Adjust the user input to fit into the arrry storage structure

			DISPLAY << "For seat " << counter + 1 << " enter the Coach Class Aisle ID: "
			INPUT >> aisleChoice
				while (aisleChoice < 1 || aisleChoice > 6)			//Input validation for the flight row and column
				{
					DISPLAY << "Invalid Input. Enter a valid aisle range: "
					INPUT >> aisleChoice;
				}
			aisleChoice -= 1			//Adjust the user input to fit into the arrry storage structure
			cout << "\newline"

			while (coachClass[rowChoice][aisleChoice] == '*')		//Input validation to determine if the seat has already been reserved
			{
				DISPLAY << "That seat has already been reserved.  Please select another seat: " << endl
				DISPLAY << "Enter the Coach Class Row ID: "
				INPUT >> rowChoice
					while (rowChoice < 1 || rowChoice > 10)			//Input validation for the flight row and column
					{
						DISPLAY << "Invalid Input. Enter a valid row range: "
						INPUT >> rowChoice
					}
				rowChoice -= 1			//Adjust the user input to fit into the arrry storage structure


				DISPLAY << "Enter the Coach Class Aisle ID: "
				INPUT >> aisleChoice
					while (aisleChoice < 1 || aisleChoice > 6)			//Input validation for the flight row and column
					{
						DISPLAY << "Invalid Input. Enter a valid aisle range: "
						INPUT >> aisleChoice
					}
				aisleChoice -= 1			//Adjust the user input to fit into the arrry storage structure
				DISPLAY << "\newline"
			}

			//Update the array to show the seat is reserved.
			coachClass[rowChoice][aisleChoice] = '*'

			if((rowChoice+1) <= 5)
			{
				//Adjusts the available seat and price variables for the premium priced coach seats
				seatsAvailablePremiumCoach--
				seatsFilledPremiumCoach++
				seatsPurchasedPremCoachClass += seatPrices[1]		//Adds the premium coach ticket price
				DISPLAY << "The seat has been booked successfully." << endl
			}
			else if ((rowChoice+1) >= 6)
			{
				//Adjusts the available seat and price variables for the standard priced coach seats
				seatsAvailableStandardCoach--
				seatsFilledStandardCoach++
				seatsPurchasedCoachClass += seatPrices[2];		//Adds the standard coach ticket price
				DISPLAY << "The seat has been booked successfully." << endl
			}
		}
	}
}
		

*END
***************************************************************************************************************************/



//Header files needed for the program to function correctly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

//Declare global variables for the array sizes
const int firstClassRows = 5;
const int firstClassColumns = 4;
const int coachClassRows = 10;
const int coachClassColumns = 6;

//Declare function prototypes
int RetreiveSeatPrices(double[]);
void DisplayAvailableSeats(char[][firstClassColumns], char[][coachClassColumns], int, int, int, int, int, int);
void FlightSoldSeats(int, int, int);
void FlightEmptySeats(int, int, int);
void EmptySeatsByRow(char[][firstClassColumns], char[][coachClassColumns]);
void FlightSales(double, double, double);
void ReserveSeats(char[][firstClassColumns], char[][coachClassColumns], double[], int&, int&, int&, int&, int&, int&, double&, double&, double&);
void ResetReservations(char[][firstClassColumns], char[][coachClassColumns], int&, int&, int&, int&, int&, int&, double&, double&, double&);

//The main program function
int main()
{
	//Delare Variables:
	int seatsAvailableFirstClass = 20;								//Holds the value of the current available seats for first class
	int seatsAvailablePremiumCoach = 30;							//Holds the value of the current available seats for premium coach
	int seatsAvailableStandardCoach = 30;							//Holds the value of the current available seats for standard coach
	int seatsFilledFirstClass = 0;									//Holds the value of the current filled seats for first class
	int seatsFilledPremiumCoach = 0;								//Holds the value of the current filled seats for premium coach
	int seatsFilledStandardCoach = 0;								//Holds the value of the current filled seats for standard coach
	double seatsPurchasedFirstClass = 0;							//Holds the sales amount of sales from first class seats
	double seatsPurchasedPremCoachClass = 0;						//Holds the sales amount of sales from premium coach seats
	double seatsPurchasedCoachClass = 0;							//Holds the sales amount of sales from standard coach seats
	int menuChoice;													//Holds the input value from the user for the main menu

	//Delcare Arrays for the seating chart data and initialize to the unoccupied character:
	char firstClass[firstClassRows][firstClassColumns] = { {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'},
														   {'#', '#', '#', '#'} };


	char coachClass[coachClassRows][coachClassColumns] = { {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'},
														  {'#', '#', '#', '#', '#', '#'} };

	//Declare Array for seat prices:
	double seatPrices[3];											//Setup the array to hold the seat prices from the file input

	//Load the seat prices from the external file and display the status to the user.
	RetreiveSeatPrices(seatPrices);

	//Initial prompt display and menu choices for the user
	cout << "Welcome to the Stormy Skies Airlines reservation system!" << endl;
	cout << "\n";
	
		
	//Start the menu loop to allow the user to use the reservation system
	do
	{
		cout << "\n";
		cout << "1. Display Seat Layout and Availability" << endl;
		cout << "2. Reserve a seat(s)" << endl;
		cout << "3. View current seats sold" << endl;
		cout << "4. View current empty seats per row" << endl;
		cout << "5. View current empty seats on the flight" << endl;
		cout << "6. View current flight seats sales" << endl;
		cout << "7. Reset & refund all reservations on the flight" << endl;
		cout << "8. Exit the system" << endl;
		cout << "Please make a selection from the menu: ";
		
		cin >> menuChoice;

		if (menuChoice < 1 || menuChoice > 8)		//Input validation for the menu choices
		{
			cout << "\nInvalid Input.  Please select options 1-8: " << endl;
		}
		else
		{
			//Setup a switch to handle the menu option selections
			switch (menuChoice)
			{
				case 1:
				{
					cout << "\n===1. Display Seat Layout and Availability" << endl;
					cout << "\n";
					DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach);
					break;
				}
				case 2:
				{
					cout << "\n===2. Reserve a seat(s)" << endl;
					ReserveSeats(firstClass, coachClass, seatPrices, seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach, seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach, seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass);
					break;
				}
				case 3:
				{
					cout << "\n===3. View current seats sold" << endl;
					FlightSoldSeats(seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach);
					
					break;
				}
				case 4:
				{
					cout << "\n===4. View current empty seats per row" << endl;
					DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach);
					EmptySeatsByRow(firstClass, coachClass);
					break;
				}
				case 5:
				{
					cout << "\n===5. View current empty seats on the flight" << endl;
					FlightEmptySeats(seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach);
					break;
				}
				case 6:
				{
					cout << "\n===6. View current flight seat sales" << endl;
					FlightSales(seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass);
					break;
				}
				case 7:
				{
					cout << "\n===7. Reset & refund all reservations on the flight" << endl;		
					ResetReservations(firstClass, coachClass, seatsAvailableFirstClass, seatsAvailablePremiumCoach, seatsAvailableStandardCoach, seatsFilledFirstClass, seatsFilledPremiumCoach, seatsFilledStandardCoach, seatsPurchasedFirstClass, seatsPurchasedPremCoachClass, seatsPurchasedCoachClass);
					cout << "\n";
					break;
				}
				case 8:
				{
					cout << "\n===Exiting the reservation system..." << endl;
					break;
				}
			}
		}
	} while (menuChoice != 8);			//Exit the loop with the exit choice from the menu.
	
	
	//Prompt to close the program
	cout << "\n";
	cout << "Thank you for flying with Stormy Skies Airlines.  Press any key to close...";
	cin.ignore();
	cin.get();

	return 0;
}

//This function loads the seat prices into the array from a file to be used by the program.
//It is setup to return an integer so it can close the program if the file fails to load.
int RetreiveSeatPrices(double seatPrices[])
{
	ifstream inputFile;					//Create the object to read data from the seat prices file
	double fileData;					//Created to hold the input from the file read.

	//Use the file stream object to open the file
	inputFile.open("SeatPrices.txt");

	//Validate the text file can be openedand, and process if it does
	if (inputFile.fail())
	{
		cout << "\nFile Not Found!!" << endl;
		cout << "Make sure the file is located in the same directory and try again." << endl;
		cout << "Press any key to close..."  << endl;
		cin.ignore();
		cin.get();
		exit(0);
	}
	else
	{
		//Use a loop to read the data from the file which ends when no more entries are present
		for (int counter = 0; counter < 3; counter++)
		{
			inputFile >> fileData;
			seatPrices[counter] = fileData;
		}

		//Close the connection to the file
		inputFile.close();
	
		//Status update to the user
		cout << "Price file loaded and array update successful." << endl;
		cout << "\n";
	}
}
																																																																		
//This function displays the currently available seats and the seating chart layout for the airplane using the first class and coach seat arrays.													
void DisplayAvailableSeats(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], int seatsAvailableFirstClass, int seatsFilledFirstClass, int seatsAvailablePremiumCoach, int seatsFilledPremiumCoach, int seatsAvailableStandardCoach, int seatsFilledStandardCoach)
{
	
	//Display for first class seats
	cout << "\n";
	cout << "FIRST CLASS SECTION" << endl;
	cout << "           12  34" << endl;
	cout << "Row   1:   " << firstClass[0][0] << firstClass[0][1] << "  " << firstClass[0][2] << firstClass[0][3] << endl;
	cout << "Row   2:   " << firstClass[1][0] << firstClass[1][1] << "  " << firstClass[1][2] << firstClass[1][3] << endl;
	cout << "Row   3:   " << firstClass[2][0] << firstClass[2][1] << "  " << firstClass[2][2] << firstClass[2][3] << endl;
	cout << "Row   4:   " << firstClass[3][0] << firstClass[3][1] << "  " << firstClass[3][2] << firstClass[3][3] << endl;
	cout << "Row   5:   " << firstClass[4][0] << firstClass[4][1] << "  " << firstClass[4][2] << firstClass[4][3] << endl;

	//Display for coach class seats
	cout << "\n";
	cout << "COACH SECTION" << endl;
	cout << "          123  456" << endl;
	cout << "Row   1:  " << coachClass[0][0] << coachClass[0][1] << coachClass[0][2] << "  " << coachClass[0][3] << coachClass[0][4] << coachClass[0][5] << endl;
	cout << "Row   2:  " << coachClass[1][0] << coachClass[1][1] << coachClass[1][2] << "  " << coachClass[1][3] << coachClass[1][4] << coachClass[1][5] << endl;
	cout << "Row   3:  " << coachClass[2][0] << coachClass[2][1] << coachClass[2][2] << "  " << coachClass[2][3] << coachClass[2][4] << coachClass[2][5] << endl;
	cout << "Row   4:  " << coachClass[3][0] << coachClass[3][1] << coachClass[3][2] << "  " << coachClass[3][3] << coachClass[3][4] << coachClass[3][5] << endl;
	cout << "Row   5:  " << coachClass[4][0] << coachClass[4][1] << coachClass[4][2] << "  " << coachClass[4][3] << coachClass[4][4] << coachClass[4][5] << endl;
	cout << "Row   6:  " << coachClass[5][0] << coachClass[5][1] << coachClass[5][2] << "  " << coachClass[5][3] << coachClass[5][4] << coachClass[5][5] << endl;
	cout << "Row   7:  " << coachClass[6][0] << coachClass[6][1] << coachClass[6][2] << "  " << coachClass[6][3] << coachClass[6][4] << coachClass[6][5] << endl;
	cout << "Row   8:  " << coachClass[7][0] << coachClass[7][1] << coachClass[7][2] << "  " << coachClass[7][3] << coachClass[7][4] << coachClass[7][5] << endl;
	cout << "Row   9:  " << coachClass[8][0] << coachClass[8][1] << coachClass[8][2] << "  " << coachClass[8][3] << coachClass[8][4] << coachClass[8][5] << endl;
	cout << "Row  10:  " << coachClass[9][0] << coachClass[9][1] << coachClass[9][2] << "  " << coachClass[9][3] << coachClass[9][4] << coachClass[9][5] << endl;

	//Display the current seat counts
	cout << "\n";
	cout << "First Class seats currently available: " << seatsAvailableFirstClass << endl;
	cout << "First Class seats currently occupied: " << seatsFilledFirstClass << endl;
	cout << "\n";
	cout << "Coach Class seats currently available: " << seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl;
	cout << "Coach Class seats currently occupied: " << seatsFilledPremiumCoach + seatsFilledStandardCoach << endl;
	cout << "\n";

}

//This function calculates and displays the currently available seats on the flight.
void FlightSoldSeats(int seatsFilledFirstClass, int seatsFilledPremiumCoach, int seatsFilledStandardCoach)
{
cout << "\n";
cout << "Total seats sold on the flight: " << seatsFilledFirstClass + seatsFilledPremiumCoach + seatsFilledStandardCoach << endl;
cout << "--First Class seats sold on the flight: " << seatsFilledFirstClass << endl;
cout << "--Coach Class seats sold on the flight: " << seatsFilledPremiumCoach + seatsFilledStandardCoach << endl;
cout << "----Premium Coach seats sold on the flight: " << seatsFilledPremiumCoach << endl;
cout << "----Standard Coach seats sold on the flight: " <<  seatsFilledStandardCoach << endl;
cout << "\n";
}

//This function uses loops to show the current empty seats available for each row by class						
void EmptySeatsByRow(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns])
{
	int emptySeat = 0;

		//Setup to loop through the firstClass array to find emtpy seats by row.
	cout << "\n";
	cout << "FIRST CLASS " << endl;
	
	for (int row = 0; row < firstClassRows; row++)
	{
		for (int col = 0; col < firstClassColumns; col++)
		{
			if (firstClass[row][col] == '#')
			{
				emptySeat += 1;
			}
			
		}
		cout << "Row " << row + 1 << " seats available: " << emptySeat << endl;
		emptySeat = 0;
	}
	
	//Setup to loop through the coachClass array to find emtpy seats by row.
	cout << "\n";
	cout << "COACH CLASS " << endl;
	emptySeat = 0;
		
	for (int row = 0; row < coachClassRows; row++)
	{
		for (int col = 0; col < coachClassColumns; col++)
		{
			if (coachClass[row][col] == '#')
			{
				emptySeat += 1;
			}

		}
		cout << "Row " << row + 1 << " seats available: " << emptySeat << endl;
		emptySeat = 0;
	}
}

//This function function retreives the currently empty seats on the flight, and it breaks coach down further into the tier 1 and 2 price structure.
void FlightEmptySeats(int seatsAvailableFirstClass, int seatsAvailablePremiumCoach, int seatsAvailableStandardCoach)
{
cout << "\n";
cout << "Total seats currently available: " << seatsAvailableFirstClass + seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl;
cout << "--First Class seats currently available: " << seatsAvailableFirstClass << endl;
cout << "--Coach Class total seats currently available: " << seatsAvailablePremiumCoach + seatsAvailableStandardCoach << endl;
cout << "----Coach Class premium seats currently available: " << seatsAvailablePremiumCoach << endl;
cout << "----Coach Class standard seats currently available: " << seatsAvailableStandardCoach << endl;
cout << "\n";
}

//This function retreives the sales amounts of every seat sold on the flight broken out by type.
void FlightSales(double seatsPurchasedFirstClass, double seatsPurchasedPremCoachClass, double seatsPurchasedCoachClass)
{
	cout << "\n";
	cout << setprecision(2) << fixed << showpoint;
	cout << "Total Sales for the flight: $" << seatsPurchasedFirstClass + seatsPurchasedPremCoachClass + seatsPurchasedCoachClass << endl;
	cout << "--First Class sales for the flight: $" << seatsPurchasedFirstClass << endl;
	cout << "--Coach Class sales for the flight: $" << seatsPurchasedPremCoachClass + seatsPurchasedCoachClass << endl;
	cout << "----Premium Coach sales for the flight: $" << seatsPurchasedPremCoachClass << endl;
	cout << "----Standard Coach sales for the flight: $" << seatsPurchasedCoachClass << endl;
	cout << "\n";
}

//This function allows the user to reset the reservation system to return everything to the starting values.  It uses the same parameter list as the ReserveSeat
//function to adjust all of the same variable parameters to the initial values.
void ResetReservations(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], int& seatsAvailableFirstClass, int& seatsAvailablePremiumCoach, int& seatsAvailableStandardCoach, int& seatsFilledFirstClass, int& seatsFilledPremiumCoach, int& seatsFilledStandardCoach, double& seatsPurchasedFirstClass, double& seatsPurchasedPremCoachClass, double& seatsPurchasedCoachClass)
{
	//Reset all of the variables
	seatsAvailableFirstClass = 20;
	seatsAvailablePremiumCoach = 30;
	seatsAvailableStandardCoach = 30;
	seatsFilledFirstClass = 0;
	seatsFilledPremiumCoach = 0;
	seatsFilledStandardCoach = 0;
	seatsPurchasedFirstClass = 0;
	seatsPurchasedPremCoachClass = 0;
	seatsPurchasedCoachClass = 0;


	//Reset the first class array
	for (int row = 0; row < firstClassRows; row++)
	{
		for (int col = 0; col < firstClassColumns; col++)
		{
			firstClass[row][col] = '#';
		}
	}

	//Reset the coach array
	for (int row = 0; row < coachClassRows; row++)
	{
		for (int col = 0; col < coachClassColumns; col++)
		{
			coachClass[row][col] = '#';
		}
	}
	cout << "\n";
	cout << "All reservations have been sucessfully cleared from the current flight." << endl;
}

//This function allows the user to book first class and coach seats on the flight.  For coach, it also selects the premium and standard prices
//based on the row selection the user inputs.  The function uses lots of parameters to access the arrays and make adjustments for updating the
//seat and price information.
void ReserveSeats(char firstClass[][firstClassColumns], char coachClass[][coachClassColumns], double seatPrices[], int &seatsAvailableFirstClass, int &seatsAvailablePremiumCoach, int &seatsAvailableStandardCoach, int &seatsFilledFirstClass, int &seatsFilledPremiumCoach, int &seatsFilledStandardCoach, double &seatsPurchasedFirstClass, double &seatsPurchasedPremCoachClass, double &seatsPurchasedCoachClass)
{
		
	int desiredSeats = 0;						//Holds the amount of seats the customer wants to purchase
	int desiredClass;							//Holds first class or coach ticket choice
	int rowChoice;								//Holds input for the seat selection menus
	int aisleChoice;							//Holds input for the seat selection menus
	
	//Display the current seating information
	cout << "\n";
	DisplayAvailableSeats(firstClass, coachClass, seatsAvailableFirstClass, seatsFilledFirstClass, seatsAvailablePremiumCoach, seatsFilledPremiumCoach, seatsAvailableStandardCoach, seatsFilledStandardCoach);		//Display the currently available seats menu

	cout << "\n";
	cout << "Would you like First Class or Coach tickets?" << endl;
	cout << "Enter 1 for First Class and 2 for Coach: ";
		cin >> desiredClass;
		while (desiredClass != 1 && desiredClass != 2)		//Input validation step to prevent choices outside of the menu range
		{
			cout << "\nInvalid input.  You must enter 1 or 2: ";
			cin >> desiredClass;
		}
	 
	cout << "\nHow many seats would you like to purchase? ";
		cin >> desiredSeats;
		while (desiredSeats < 0)			//Input validation step to prevent negative selections
		{
			cout << "\nInvalid input.  You must enter 0 or higher: ";
				cin >> desiredSeats;
		}
	if (desiredSeats == 0)		//Allows the user to avoid entering seats and return to the menu.
	{
		cout << "Returning the the main menu." << endl;
		return;
	}

	if (desiredClass == 1)		//This section adds the reservations for the first class  section
	{
		//Loop to cycle through the first class seat selections
		cout << "\n";
		for (int counter = 0; counter < desiredSeats; counter++)
		{
			cout << "\nFor seat " << counter+1 << " enter the First Class Row ID: ";
			cin >> rowChoice;
				while (rowChoice < 1 || rowChoice > 5)		//Input validation for the flight row and column
				{
					cout << "Invalid Input. Enter a valid row range: ";
					cin >> rowChoice;
				}
			rowChoice -= 1;				//Adjust the user input to fit into the arrry storage structure

			cout << "For seat " << counter+1 << " enter the First Class Aisle ID: ";
			cin >> aisleChoice;
				while (aisleChoice < 1 || aisleChoice > 4)		//Input validation for the flight row and column
				{
					cout << "Invalid Input. Enter a valid aisle range: ";
					cin >> aisleChoice;
				}
			aisleChoice -= 1;			//Adjust the user input to fit into the arrry storage structure
			cout << "\n";

			while (firstClass[rowChoice][aisleChoice] == '*')
			{
				cout << "That seat has already been reserved.  Please select another seat: ";
				cout << "\nEnter the First Class Row ID: ";
				cin >> rowChoice;
					while (rowChoice < 1 || rowChoice > 5)		//Input validation for the flight row and column
					{
						cout << "Invalid Input. Enter a valid row range: ";
						cin >> rowChoice;
					}
				rowChoice -= 1;			//Adjust the user input to fit into the arrry storage structure

				cout << "\nEnter the First Class Aisle ID: " << endl;
				cin >> aisleChoice;
					while (aisleChoice < 1 || aisleChoice > 4)		//Input validation for the flight row and column
					{
						cout << "Invalid Input. Enter a valid aisle range: ";
						cin >> aisleChoice;
					}
				aisleChoice -= 1;		//Adjust the user input to fit into the arrry storage structure
				cout << "\n";
			}
		
			firstClass[rowChoice][aisleChoice] = '*';
			seatsAvailableFirstClass--;
			seatsFilledFirstClass++;
			seatsPurchasedFirstClass += seatPrices[0];		//Adds the first class ticket price
			cout << "The seat has been booked successfully." << endl;
			
		}
	}
	else if (desiredClass == 2)			//This section adds the reservations for the two different tiers for the coach section
	{
		
		//Loop to cycle through the coach seat selections
		cout << "\n";
		for (int counter = 0; counter < desiredSeats; counter++)
		{
			cout << "\nFor seat " << counter+1 << " enter the Coach Class Row ID: ";
			cin >> rowChoice;
				while (rowChoice < 1 || rowChoice > 10)			//Input validation for the flight row and column
				{
					cout << "Invalid Input. Enter a valid row range: ";
					cin >> rowChoice;
				}
			rowChoice -= 1;				//Adjust the user input to fit into the arrry storage structure
			
			cout << "For seat " << counter + 1 << " enter the Coach Class Aisle ID: ";
			cin >> aisleChoice;
				while (aisleChoice < 1 || aisleChoice > 6)			//Input validation for the flight row and column
				{
					cout << "Invalid Input. Enter a valid aisle range: ";
					cin >> aisleChoice;
				}
			aisleChoice -= 1;			//Adjust the user input to fit into the arrry storage structure
			cout << "\n";

			while (coachClass[rowChoice][aisleChoice] == '*')		//Input validation to determine if the seat has already been reserved
			{
				cout << "That seat has already been reserved.  Please select another seat: " << endl;
				cout << "Enter the Coach Class Row ID: ";
				cin >> rowChoice;
					while (rowChoice < 1 || rowChoice > 10)			//Input validation for the flight row and column
					{
						cout << "Invalid Input. Enter a valid row range: ";
						cin >> rowChoice;
					}
				rowChoice -= 1;			//Adjust the user input to fit into the arrry storage structure
				

				cout << "Enter the Coach Class Aisle ID: ";
				cin >> aisleChoice;
					while (aisleChoice < 1 || aisleChoice > 6)			//Input validation for the flight row and column
					{
						cout << "Invalid Input. Enter a valid aisle range: ";
						cin >> aisleChoice;
					}
				aisleChoice -= 1;			//Adjust the user input to fit into the arrry storage structure
				cout << "\n";
			}

			//Update the array to show the seat is reserved.
			coachClass[rowChoice][aisleChoice] = '*';
			
			if((rowChoice+1) <= 5)
			{
				//Adjusts the available seat and price variables for the premium priced coach seats
				seatsAvailablePremiumCoach--;
				seatsFilledPremiumCoach++;
				seatsPurchasedPremCoachClass += seatPrices[1];		//Adds the premium coach ticket price
				cout << "The seat has been booked successfully." << endl;
			}
			else if ((rowChoice+1) >= 6)
			{
				//Adjusts the available seat and price variables for the standard priced coach seats
				seatsAvailableStandardCoach--;
				seatsFilledStandardCoach++;
				seatsPurchasedCoachClass += seatPrices[2];		//Adds the standard coach ticket price
				cout << "The seat has been booked successfully." << endl;
			}
		}
	}
}

