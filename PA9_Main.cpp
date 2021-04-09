/**************************************************************************************************************************
*Author: Christopher S Lynn
	CISS 241 -  Programming I
*	Programming Assignment 9
	Created: 4/05/2021
*
-------------------------------------------------------------------------------------------------------------------------
*
*Description:
 This program replicates the guessing game.  It generates a random number from 1 to 100, and will prompt the player for input on their guess for the number.
 The program will compare the user's guess to the selected random number, and count how many guesses the user made.  And, the program will loop and only
 allow the user to have 10 guesses.  The program will catch any incorrect input outside of 1-100, ask for a correct value, and not count it against the player.

 The program will display the following messages during the game:
 * If the user’s guess is higher than the random number, display: “Too high, try again.”
 * If the user’s guess is lower than the random number, display: “Too low, try again.”
 * If the user’s guess is equal to the random number, display: “Yes!  You chose the correct number.”
 * If guess 10 is not correct, display:	"Sorry - You have taken too many guesses."

 When the game ends, it will then display one of the following system messages to the user:

 Number of Guesses by the User			Message
 -------------------------------		--------------------------------------
 Less than 5 guesses					"Either you know the secret or you got lucky!"
 5-7 guesses							"You're pretty good at this!"
 8-10 guesses							"You'll do better next time."

*	The final status display should be in this format and wait for user confirmation before closing:
*		Player Name:
*		The Secret Number Was:
*		Secret Number Found?:
*		Total Guesses Made:
*		System Message:
*		

*						
***Pseudocode:

*START
	Include header files iomanip, cmath, cstdlib, ctime, string and iostream

	use namespace std

	Declare variables:
		string playerName						//Holds the player's name
		string successfulMatch					//Holds a Yes or No field to indicate if the game was won
		int totalGuesses						//Accumulator, keeps track of the total guess made
		int playersGuess						//Holds the guess input from the player for the current round
		int secretNumber						//Holds the random number generated for the guessing game
		const int MIN_VALUE						//The minimum value the random number can be
		const int MAX_VALUE						//The maximum value the random number can be
		unsigned rvalue							//Holds a value for the system clock
		string systemMessage					//Holds the final message to the player based on guesses

	Initialize variables:
		totalGuesses = 0
		MIN_VALUE = 1
		MAX_VALUE = 100
		successfulMatch = "No"
		rvalue = time(0)						//Get a value from the clock for the random number
		srand(rvalue)							//Randomize the result from the system clock
		secretNumber = (rand() % (MAX_VALUE − MIN_VALUE + 1)) + MIN_VALUE;		//Generate a random number for the secret number

	Calculate final total variables:
		No Calculations

	 Initial Display and Data input from the player:
		Display "Let's play guess the Secret Number!"
		Display "\newline"
		Display "\newline"
		Display "Enter the player's name: "
			Input to playerName

		Display "\newline"
		Display "Welcome " << playerName << "!  The object of the game is to guess what the secret number is from 1 to 100."
		Display "\newline"
		Display "You only get 10 guesses, so make them count!"
		Display "\newline"
		

	//Setup the main loop for the player to guess the secret number
	do
		
		Display "What is your guess for the secret number?"
			Input to playersGuess
				Display "\newline"
				Valdiate Input => while (playersGuess < 1 || playersGuess > 100), "Inavlid input.  Please enter a number from 1 to 100."
				Display "\newline"
		
		if (playersGuess > secretNumber)
			Display "\newline"
			Display: “Too high, try again.”
			Display "\newline"
			totalGuesses++
		else if (playersGuess > secretNumber)
			Display "\newline"
			Display: “Too low, try again.”
			Display "\newline"
			totalGuesses++
		else if (playersGuess == secretNumber)
			Display "\newline"
			Display: “Yes!  You chose the correct number.”
			Display "\newline"
			successfulMatch = "Yes"
		else
			Display "Invalid Input"

		if (totalGuesses >= 10)
			Display "\newline"
			Display: “Sorry - You have taken too many guesses.”
			Display "\newline"
			break out
 
	while (playersGuess != secretNumber)
	
		
	//Setup a switch to select the system message for the player based on guessing proficiency
	switch (playerGuesses)
		case 4
		case 3
		case 2
		case 1		systemMessage = "Either you know the secret or you got lucky!"
		break out
		case 7
		case 6
		case 5		systemMessage = "You're pretty good at this!"
		break out
		case 10
		case 9
		case 8		systemMessage = "You'll do better next time."
		break out
		

	//Show some play statistics to the player
	Display "\newline"
	Display "Player Name:             " << playerName
	Display	"The Secret Number was:	  " << secretNumber
	Display "Secret Number Found?:    " << successfulMatch
	Display "Total Guesses Made:      " << totalGuesses
	Display "System Message:          " << systemMessage
	Display "\newline"

	Display "Thank you for playing!	Press any key to close..."
	Input.ignore() to flush the buffer of new lines
	Input.get() to accept an input to close the program
*END
***************************************************************************************************************************/



//Header files needed to display the data properly
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//The main program function
int main()
{
	
	//Declare variables
	string playerName;						//Holds the player's name
	string successfulMatch = "No";			//Holds a Yes or No field to indicate if the game was won
	int totalGuesses = 0;					//Accumulator, keeps track of the total guess made
	int playersGuess;						//Holds the guess input from the player for the current round
	int secretNumber;						//Holds the random number generated for the guessing game
	const int MIN_VALUE = 1;				//The minimum value the random number can be
	const int MAX_VALUE = 100;				//The maximum value the random number can be
	unsigned rvalue;						//Holds a value for the system clock
	string systemMessage;					//Holds the final message to the player based on guesses

	//Setup and generate the random secret number
	rvalue = time(0);														//Get a value from the clock for the random number
	srand(rvalue);															//Randomize the result from the system clock
	secretNumber = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;		//Generate a random number for the secret number


	//Initial Game Display and Data input from the player
	cout << "Let's play guess the Secret Number!";
	cout << "\n";
	cout << "\n";
	cout << "Enter the player's name: ";
	getline(cin, playerName);

	cout << "\n";
	cout << "\nWelcome " << playerName << "!";
	cout << "\nThe object of the game is to guess the secret number from 1 to 100.";
	cout << "\n";
	cout << "\nYou only get 10 guesses, so make them count!";
	cout << "\n";
	cout << "\n";


	//Setup the main loop for the player to guess the secret number
		do
		{
			//Initial play prompt
			cout << "\nWhat is your guess for the secret number?: ";
			cin >> playersGuess;
			cout << "\n";
				
				//Valdiate Player Input to prevent negative numbers
				while (playersGuess < 1 || playersGuess > 100)
				{
				cout << "Inavlid input.  Please enter a number from 1 to 100.";
				cout << "\n";
				cout << "\nWhat is your guess for the secret number?: ";
				cin >> playersGuess;
				}
			
			//Check the player's guess against the secret number, give a hint for the next guess, and increase the players guessing count
			if (playersGuess > secretNumber)
			{
				cout << "Too high, try again.";
				cout << "\n";
				cout << "\n";
				totalGuesses++;
			}
			else if (playersGuess < secretNumber)
			{
				cout << "Too low, try again.";
				cout << "\n";
				cout << "\n";
				totalGuesses++;
			}
			else if (playersGuess == secretNumber)
			{
				cout << "Yes! You chose the correct number.";
				cout << "\n";
				cout << "\n";
				successfulMatch = "Yes";
				totalGuesses++;
			}
			else
				cout << "\nInvalid Input.  Try entering again."; //This section is to catch errors that may show up.
			
			if (totalGuesses >= 10)			//Ends the player's game if they choose wrong on the 10th guess
			{
				cout << "Sorry - You have taken too many guesses.";
				cout << "\n";
				cout << "\n";
				break;
			}

		} while (playersGuess != secretNumber);


		//Setup a switch to select the system message for the player based on guessing proficiency.  Uses fall through to guessing value range.
		switch (totalGuesses)
		{
		case 4:
		case 3:
		case 2:
		case 1:
		{
			systemMessage = "Either you know the secret or you got lucky!";
			break;
		}
		case 7:
		case 6:
		case 5:
		{
			systemMessage = "You're pretty good at this!";
			break;
		}
		case 10:
		case 9:
		case 8:
		{
			systemMessage = "You'll do better next time.";
			break;
		}
		
		}

	//Display some play statistics to the player
	cout << "\n";
	cout << "\nPlayer Name:             " << playerName;
	cout << "\nThe Secret Number Was:   " << secretNumber;
	cout << "\nSecret Number Found?:    " << successfulMatch;
	cout << "\nTotal Guesses Made:      " << totalGuesses;
	cout << "\nSystem Message:          " << systemMessage;
	cout << "\n";

	//Prompt to close the program
	cout << "\nThank you for playing.  Press any key to close...";
	cin.ignore();
	cin.get();

	//End the program
	return 0;
}