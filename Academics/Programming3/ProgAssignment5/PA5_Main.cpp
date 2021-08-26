/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 5
 Created: 7/23/2021

 ----------------------------------------------------------------------------------------------------------------------------
 
 Description:
 This program simulates a game of Blackjack.  The main part of the program greets the user and runs a loop to display a menu
 of choices to the user to play or exit the game.  It uses several functions to generate the menu (Menu), setup the game 
 (SetupGame), run the main game loop (GameLoop), and check the win conditions at the end of the game (DetermineWinner).  The
 program is only setup for two players and does not involve competing against the dealer in addition to players.


 Class File used: DeckOfCards.h, PlayerHand.h

***************************************************************************************************************************/

//HEADER FILES FOR THE PROGRAM

#include <iostream>
#include <string>
#include "DeckOfCards.h"
#include "PlayerHand.h"

using namespace std;

//FUNCTION PROTOTYPES
int Menu();
void SetupGame();
void GameLoop(PlayerHand&, Deck&);
void DetermineWinner(PlayerHand, PlayerHand);

//GLOBAL VARIABLES (FOR INPUT AND GAME LOOPS)
int playerChoice = -1;
bool playAgain = true;
bool validate = false;

int main()			
{
	//Prompt the user with a welcome to the program
	cout << "Welcome to the BlackJack Card Simulator!" << endl;
	cout << "--The window may need to be expanded to see all results." << endl;
	cout << "\n";

	//Start a menu loop for continuous play
	do
	{
		cout << "\n|||||||||||||||||||||||||||||||||||||||" << endl;
		cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
		cout << "\nWould you like to play or exit?" << endl;
		Menu();
		
		//Setup a switch statement to determine what the user wants to do.
		switch (playerChoice)
		{
		case 1:
			cout << "\nTime to deal the cards!! " << endl;
			SetupGame();
			break;
		case 2:
			cout << "Leaving the table... " << endl;
			playAgain = false;
			break;
		}
					
	}while(playAgain == true);
	
	cin.get();
	return 0;
}

//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* Displays the game menu and provides an option to the user to see
* if they want to play the game or exit.
******************************************************************/
int Menu()
{
	
	cout << "\n#1: Play a game of BlackJack" << endl;
	cout << "#2: Exit the Game" << endl;
	cout << "->";
	cin >> playerChoice;
	
	//Begin the input validation loop
	while (!validate)
	{
		
		if (playerChoice < 0 || playerChoice > 2 || cin.fail())
		{
		cout << "Not a valid choice!  Please enter 1 or 2." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> playerChoice;
		}
		else
		{
			validate = true;
		}
	}
	
	validate = false;

	return playerChoice;
}


/******************************************************************
* This function calls the other functions to setup the blackjack game
* (establish players, create the deck, etc) and run the game loop. After
* the deck is initialized, two cards are dealt to the player's hand and
* the loop starts with the first player
******************************************************************/
void SetupGame()
{
	Deck deck;
	deck.ShuffleDeck();
	PlayerHand player1(deck.DealCard(), deck.DealCard());
	PlayerHand player2(deck.DealCard(), deck.DealCard());
	
	//Start the first player's turn
	cout << "\n***PLAYER 1's TURN***" << endl;
	GameLoop(player1, deck);

	//Start the next player's turn
	cout << "\n***PLAYER 2's TURN***" << endl;
	GameLoop(player2, deck);

	//Once all turns are finished, find the winner
	DetermineWinner(player1, player2);

	//To show the total cards left in the deck after the game (used mostly for diagnostics)
	//deck.RemainingCards();
}


/******************************************************************
* The following function runs the game loop for each player.  It accepts
* the player and deck objects and runs a loop as long as the player wants
* to keep hitting.  The loop ends when the player stays.
******************************************************************/
void GameLoop(PlayerHand& player, Deck& deck)
{
	//Setup a variable to hold the user's input
	int input;

	//Display a greeting indicating this is a new player.
	cout << "\nNew player at the table!  Let's deal..." << endl;

	//Run the game loop for the player
	do
	{
		cout << "\n====Your Cards====" << endl;
		player.DisplayHand();
		cout << "= Card score is now: " << player.GetPlayerScore() << endl;
		
		//Add a special message for 21 scoring hands
		if (player.GetPlayerScore() == 21)
		{
			cout << "BLACKJACK!" << endl;
		}

		cout << "\nWhat would you like to do?" << endl;
		cout << "--#1: Hit (Get another Card)" << endl;
		cout << "--#2: Stay (Keep what you have)" << endl;
		cout << "->";
		cin >> input;

		//Input validation
		while (!validate)
		{
			if (input < 0 || input > 2 || cin.fail())
			{
				cout << "Not a valid choice!  Please enter 1 or 2." << endl;
				cout << "->";
				cin.clear();
				cin.ignore();
				cin >> input;
			}
			else
			{
				validate = true;
			}
		}
		
		//Reset the validation flag
		validate = false;

		//Perform the dealing and adding a card to the player's hand for choice of 1
		//Do not do a hit if the choice is a 2
		if(input == 1)
		{
			player.DealerHit(deck.DealCard());
		}
		else if (input == 2)
		{
			cout << "\n------------------------------------------" << endl;
			cout << "Staying with the hand you have." << endl;
			cout << "------------------------------------------" << endl;
		}

		//If the player's hit busts, assign 2 to the input value to break out of the loop
		if (player.CheckBusted())
		{
			input = 2;
		}

	} while (input == 1);
}


/******************************************************************
* This function determines the winner of the game based on
* the card scores of the players.  It also calls the CheckBusted
* function to determine the winner if one or both players busted.
* In the case of a draw, it display that message to the players.
******************************************************************/
void DetermineWinner(PlayerHand player1, PlayerHand player2)
{
	if (player1.GetPlayerScore() > player2.GetPlayerScore() && !player1.CheckBusted())
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "Player 1's Score: " << player1.GetPlayerScore() << endl;
		cout << "Player 2's Score: " << player2.GetPlayerScore() << endl;
			
		cout << "\nWinner is: Player 1 !!!" << endl;
	}
	else if (player1.GetPlayerScore() < player2.GetPlayerScore() && !player2.CheckBusted())
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "Player 1's Score: " << player1.GetPlayerScore() << endl;
		cout << "Player 2's Score: " << player2.GetPlayerScore() << endl;

		cout << "\nWinner is: Player 2 !!!" << endl;
	}
	else if (!player1.CheckBusted() && player2.CheckBusted())
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "Player 1's Score: " << player1.GetPlayerScore() << endl;
		cout << "Player 2's Score: " << player2.GetPlayerScore() << endl;

		cout << "\nWinner is: Player 1 !!!" << endl;
	}
	else if (player1.CheckBusted() && !player2.CheckBusted())
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "Player 1's Score: " << player1.GetPlayerScore() << endl;
		cout << "Player 2's Score: " << player2.GetPlayerScore() << endl;

		cout << "\nWinner is: Player 2 !!!" << endl;
	}
	else if (player1.CheckBusted() && player2.CheckBusted())
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "\nBoth Players Busted! The House Wins!" << endl;
	}
	else
	{
		cout << "\n==GAME RESULTS==" << endl;
		cout << "\nThe game is a draw!" << endl;
	}
}