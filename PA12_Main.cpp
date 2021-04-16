/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 12
	Created: 4/15/2021
*

-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program is a variation of the game called Rock Paper Scissors.  Two extra choices are added called Lizard and Spock which gives the game added
 win conditions.  The game is played against the computer (which selects a random number), and continues until a winner is determined (ties force continued play).
 Once either the player or the computer wins, the program will end.

 The following options are presented to the player in a menu:
 1.	Rock
 2.	Paper
 3.	Scissors
 4.	Lizard
 5.	Spock

 The computer’s choice is selected from the same options, but the game will display both the user’s and computer's choices using the text terms "Rock".  This should
 generate the display of "The player's choice is Rock", and "The Computer's choice is Sissors."


 *Once the choices are selected the program determines if there is a winner or a tie. Ties continue another game while winning conditions will generate a display
 to the user "The Player/Computer won!", and display the winning condition rule (listed below).

 A winner is determined using the following rules:
	Scissors -= CUT           =- Paper
	Paper    -= COVERS        =- Rock
	Rock     -= CRUSHES       =- Lizard
	Lizard   -= POISONS       =- Spock
	Spock    -= SMASHES/MELTS =- Scissors
	Scissors -= DECAPITATE    =- Lizard
	Lizard   -= EATS          =- Paper
	Paper    -= DISPROVES     =- Spock
	Spock    -= VAPORIZES     =- Rock
	Rock     -= BREAKS        =- Scissors
*
* 
* The program uses the following functions to interact with main() and process choice and game activity:
•	int getUserChoice()
	o	Displays a menu of choices
	o	Prompts the user for their choice from the menu
	o	Returns the users choice as an integer to main
•	int getComputerChoice()
	o	Uses a random number generator to create the computer's choice 
	o	Returns the computer's choice as an integer to main
•	bool determineWinner(int userChoice, int compChoice)
	o	Accepts the two parameters returned from the get functions
	o	Compares those values to the rule list to determine a winner
	o	Returns true if a winner happens, and false if a tie happens
	o	If a winner occurs, sends a message indicating who won
•	void displayChoice(int choice)
	o	Collects the user choice.
	o	Collects the computer choice.
	o   Uses a switch statement to display the choice as text not numeric (Such as “Rock” for choice of 1).
	o	Function then displays the choice as the single word.
•	string winningRule(int userChoice, int compChoice)
	o	Collects the user and computer choices
	o	Compares those values, and then returns a string output based on the rules section chart


*
***Pseudocode:

*START
	Include header files iostream, iomanip, cmath, ctime, cstdlib, string

	use namespace std

	//Declare function prototypes
	int getUserChoice()
	int getComputerChoice()
	bool determineWinner(int, int)
	void displayChoice(int)
	string winningRule(int, int)

  MAIN()
	Declare variables:
		int userChoice
		int compChoice
		bool gameWon is false
		string winRule

		do
		{
			userChoice = getUserChoice()
			compChoice = getComputerChoice()

			Display "The player's choice is " << displayChoice(userChoice)
			Display "The computer's choice is " << displayChoice(compChoice)
			Display "Was their a winner? " 
			gameWon = determineWinner(userChoice, compChoice)
			Display "Winning Rule: " << winningRule(userChoice, compChoice)
	
		}while (gameWon == false)

		Display "Thank you for using the system.  Press any key to close..."
		Input.ignore() to flush the buffer of new lines
		Input.get() to accept an input to close the program

  END MAIN()

 int getUserChoice()

		int userChoice
		Display "Pick a choice from the following options: "
		Display "1.	Rock
				 2.	Paper
				 3.	Scissors
				 4.	Lizard
				 5.	Spock "
			Input >> userChoice
		return userChoice

 int getComputerChoice()
	  
	  int compChoice
	  const int MIN_VALUE	//Initalize values to maximum of 5
	  const int MAX_VALUE

	  //Get the system time for the random number
      unsigned randomVar = time(0);

      //Seed the random number generator.
      srand(randomVar);

	  //Generate the computer's choice
      compChoice = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

	  return compChoice
	
 
 bool determineWinner(int userChoice, int compChoice)
	bool gameWon
	string winner
	
	//Section for the player's win
	if (userChoice == 1 && compChoice == 4)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 1 && compChoice == 3)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 2 && compChoice == 1)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 2 && compChoice == 5)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 3 && compChoice == 4)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 3 && compChoice == 2)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 4 && compChoice == 2)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 4 && compChoice == 5)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 5 && compChoice == 3)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (userChoice == 5 && compChoice == 1)
		gameWon = true
		winner = "Player"
		Display << "The " << winner << " won!"
	else if (compChoice == 1 && userChoice == 4)		//Section for the computer's win
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 1 && userChoice == 3)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 2 && userChoice == 1)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 2 && userChoice == 5)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 3 && userChoice == 4)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 3 && userChoice == 2)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 4 && userChoice == 2)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 4 && userChoice == 5)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 5 && userChoice == 3)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else if (compChoice == 5 && userChoice == 1)
		gameWon = true
		winner = "Computer"
		Display << "The " << winner << " won!"
	else											//Section for ties
		gameWon = false
		winner = "None.  Tied game."
		Display << winner
	
	return gameWon
 
 void displayChoice(int choice)

	switch (choice)
		case 1: Display << "Rock"
		case 2: Display << "Paper"
		case 3: Display << "Scissors"
		case 4: Display << "Lizard"
		case 5: Display << "Spock"

string winningRule(int userChoice, int compChoice)
	string winRule
	if (userChoice == 1 && compChoice == 4)					//User section
		winRule = "Rock     -= CRUSHES       =- Lizard"
	else if (userChoice == 1 && compChoice == 3)
		winRule = "Rock     -= BREAKS        =- Scissors"
	else if (userChoice == 2 && compChoice == 1)
		winRule = "Paper    -= COVERS        =- Rock"
	else if (userChoice == 2 && compChoice == 5)
		winRule = "Paper    -= DISPROVES     =- Spock"
	else if (userChoice == 3 && compChoice == 4)
		winRule = "Scissors -= DECAPITATE    =- Lizard"
	else if (userChoice == 3 && compChoice == 2)
		winRule = "Scissors -= CUT           =- Paper"
	else if (userChoice == 4 && compChoice == 2)
		winRule = "Lizard   -= EATS          =- Paper"
	else if (userChoice == 4 && compChoice == 5)
		winRule = "Lizard   -= POISONS       =- Spock"
	else if (userChoice == 5 && compChoice == 3)
		winRule = "Spock    -= SMASHES/MELTS =- Scissors"
	else if (userChoice == 5 && compChoice == 1)
		winRule = "Spock    -= VAPORIZES     =- Rock"
	else if (compChoice == 1 && userChoice == 4)			//Computer section
		winRule = "Rock     -= CRUSHES       =- Lizard"
	else if (compChoice == 1 && userChoice == 3)
		winRule = "Rock     -= BREAKS        =- Scissors"
	else if (compChoice == 2 && userChoice == 1)
		winRule = "Paper    -= COVERS        =- Rock"
	else if (compChoice == 2 && userChoice == 5)
		winRule = "Paper    -= DISPROVES     =- Spock"
	else if (compChoice == 3 && userChoice == 4)
		winRule = "Scissors -= DECAPITATE    =- Lizard"
	else if (compChoice == 3 && userChoice == 2)
		winRule = "Scissors -= CUT           =- Paper"
	else if (compChoice == 4 && userChoice == 2)
		winRule = "Lizard   -= EATS          =- Paper"
	else if (compChoice == 4 && userChoice == 5)
		winRule = "Lizard   -= POISONS       =- Spock"
	else if (compChoice == 5 && userChoice == 3)
		winRule = "Spock    -= SMASHES/MELTS =- Scissors"
	else if (compChoice == 5 && userChoice == 1)
		winRule = "Spock    -= VAPORIZES     =- Rock"
	else													//Section for ties
		winRule = "The game is a tie, playing again!"


	return winRule





*END
***************************************************************************************************************************/



//Header files needed for the program to function correctly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

//Declare function prototypes:
int getUserChoice();
int getComputerChoice();
bool determineWinner(int, int);
void displayChoice(int);
string winningRule(int, int);


//The main program function
int main()
{
		
	//Declare variables:
	int userChoice;					//This stores the integer value for the human player
	int compChoice;					//This stores the integer value for the computer player
	bool gameWon = false;			//This controls the game loop which repeats for ties.  Set to false to repate unless a game is won.
	string winRule;					//This stores the value displayed for how each choice beats the other

		//Setup a loop to check for ties and repeat the game if it happens
		do
		{
			//Call the functions to collect the input for both players
			userChoice = getUserChoice();
			compChoice = getComputerChoice();
			
			//Display the game results to the user
			cout << "\n";
			cout << "The player's choice is: ";
			displayChoice(userChoice);						//Call the function to return the text value of the game choice for the user.
			cout << "\nThe computer's choice is: ";
			displayChoice(compChoice);						//Call the function to return the text value of the game choice for the computer.
			cout << "\nWas their a winner? ";
			gameWon = determineWinner(userChoice, compChoice);	//Call the function to set the game state based on player choices and display who won.
			cout << "\nWinning Rule: " << winningRule(userChoice, compChoice);		//Call this function to display the game rule to determine the winner.

		} while (gameWon == false);					//Loop only repeats if the game state is still false.


	//Prompt to close the program
	cout << "\n";
	cout << "\n";
	cout << "Thank you for playing.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}

//This function displays the menu options to the user, collects input, and returns their choice out of the function.
int getUserChoice()
{
		int userChoice;
		cout << "\n";
		cout << "\n";
		cout << "Pick a choice from the following options: " << endl;
		cout << "1.	Rock" << endl;
		cout << "2.	Paper" << endl;
		cout << "3.	Scissors" << endl;
		cout << "4.	Lizard" << endl;
		cout << "5.	Spock " << endl;
		cout << "===============" << endl;
		cout << "\n";

		cin >> userChoice;
			while (userChoice < 1 || userChoice >5) //Input validation limits choices to menu options.
			{
			cout << "Invalid choice.  Please select 1-5: ";
				cin >> userChoice;
			}
		return userChoice;
}

//This function randomly generates a menu choice number for the computer player
int getComputerChoice()
{
	int compChoice;				//Holds the computer's random choice
	const int MIN_VALUE = 1;	//Initalize random choice range values to maximum of 5 for this game
	const int MAX_VALUE = 5;

	//Get the system time for the random number
	unsigned randomVar = time(0);

	//Seed the random number generator.
	srand(randomVar);

	//Generate the computer's choice
	compChoice = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
	
	//Uncomment this section and comment out the random generator to test computer choices
	//compChoice = 1;
	return compChoice;
}

//This function takes input from both players and determines the winner, game state, and displays those options
bool determineWinner(int userChoice, int compChoice)
{
	bool gameWon;			//Holds the T/F value for the tie
	string winner;			//Holds the winner's name

//This section begins the player's win options
if (userChoice == 1 && compChoice == 4)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 1 && compChoice == 3)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 2 && compChoice == 1)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 2 && compChoice == 5)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 3 && compChoice == 4)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 3 && compChoice == 2)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 4 && compChoice == 2)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 4 && compChoice == 5)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 5 && compChoice == 3)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (userChoice == 5 && compChoice == 1)
{
	gameWon = true;
	winner = "Player";
	cout << "The " << winner << " won!";
}
else if (compChoice == 1 && userChoice == 4)  //Section begins the computer's win options
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 1 && userChoice == 3)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 2 && userChoice == 1)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 2 && userChoice == 5)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 3 && userChoice == 4)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 3 && userChoice == 2)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 4 && userChoice == 2)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 4 && userChoice == 5)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 5 && userChoice == 3)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else if (compChoice == 5 && userChoice == 1)
{
	gameWon = true;
	winner = "Computer";
	cout << "The " << winner << " won!";
}
else
{												//This portion activates if the options are ties.
	gameWon = false;
	winner = "None.  Tied game.";
	cout << winner;
 }

 return gameWon;
}

//This function displays the text value based on the numeric choice of each player
void displayChoice(int choice)
{

	switch (choice)
	{
	case 1:
		cout << "Rock";
		break;

	case 2:
		cout << "Paper";
		break;

	case 3:
		cout << "Scissors";
		break;

	case 4:
		cout << "Lizard";
		break;

	case 5:
		cout << "Spock";
		break;
	}
}

//This function compares the input choices and returns the winning rule as a string.
string winningRule(int userChoice, int compChoice)
{
	//This variable holds the text string of the win rule
	string winRule;

		//This section is for the player win options
		if (userChoice == 1 && compChoice == 4)
			winRule = "Rock  -= CRUSHES =-  Lizard";
		else if (userChoice == 1 && compChoice == 3)
			winRule = "Rock  -= BREAKS =-  Scissors";
		else if (userChoice == 2 && compChoice == 1)
			winRule = "Paper -= COVERS =-  Rock";
		else if (userChoice == 2 && compChoice == 5)
			winRule = "Paper -= DISPROVES =-  Spock";
		else if (userChoice == 3 && compChoice == 4)
			winRule = "Scissors  -= DECAPITATE =-  Lizard";
		else if (userChoice == 3 && compChoice == 2)
			winRule = "Scissors  -= CUT =-  Paper";
		else if (userChoice == 4 && compChoice == 2)
			winRule = "Lizard  -= EATS =-  Paper";
		else if (userChoice == 4 && compChoice == 5)
			winRule = "Lizard  -= POISONS =-  Spock";
		else if (userChoice == 5 && compChoice == 3)
			winRule = "Spock  -= SMASHES/MELTS =-  Scissors";
		else if (userChoice == 5 && compChoice == 1)
			winRule = "Spock  -= VAPORIZES =-  Rock";
		else if (compChoice == 1 && userChoice == 4)			//This section beings the computer win options
			winRule = "Rock  -= CRUSHES =-  Lizard";
		else if (compChoice == 1 && userChoice == 3)
			winRule = "Rock  -= BREAKS =-  Scissors";
		else if (compChoice == 2 && userChoice == 1)
			winRule = "Paper  -= COVERS =-  Rock";
		else if (compChoice == 2 && userChoice == 5)
			winRule = "Paper  -= DISPROVES =-  Spock";
		else if (compChoice == 3 && userChoice == 4)
			winRule = "Scissors  -= DECAPITATE =-  Lizard";
		else if (compChoice == 3 && userChoice == 2)
			winRule = "Scissors  -= CUT =-  Paper";
		else if (compChoice == 4 && userChoice == 2)
			winRule = "Lizard  -= EATS =-  Paper";
		else if (compChoice == 4 && userChoice == 5)
			winRule = "Lizard  -= POISONS =-  Spock";
		else if (compChoice == 5 && userChoice == 3)
			winRule = "Spock  -= SMASHES/MELTS =- Scissors";
		else if (compChoice == 5 && userChoice == 1)
			winRule = "Spock  -= VAPORIZES =-  Rock";
		else
			winRule = "The game is a tie, playing again!";		//This portion is to display when a tie happens

	return winRule;
}