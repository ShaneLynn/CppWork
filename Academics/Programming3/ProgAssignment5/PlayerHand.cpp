/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 5
 Created: 7/23/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: PlayerHand.h

 Required Files: PlayerHand.h

***************************************************************************************************************************/

#include "PlayerHand.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/******************************************************************
* Parameter constructor that accepts two card objects and adds to
* the player's hand queue with two starting cards.
******************************************************************/
PlayerHand::PlayerHand(Card card, Card card2)
{
	playerHand.push_back(card);
	playerHand.push_back(card2);
	SetPlayerScore(card);
	SetPlayerScore(card2);
}

//----------------------------------------------------------------
// ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
//----------------------------------------------------------------

/******************************************************************
*  This function gets the value stored in the data member: playerScore
******************************************************************/
int PlayerHand::GetPlayerScore() const
{
	return playerScore;
}

/******************************************************************
* This function sets the player's score by running several checks to
* determine the face type.  It uses a bool to track if an ace is dealt
* in the first two hand cards.  If the ace is dealt, the bool will be
* set to true and its value to 11.  If two aces are dealt and a bust
* would occur, the value is dropped to 10 and the bool is set to false.
* Face cards are set to 10, and the remaining card values are set based
* on their value on the card.
******************************************************************/
void PlayerHand::SetPlayerScore(Card card)
{
	bool highAce = false;
	
	//See if a first dealt card is an ace
	if (card.getFace() == card.ACE)
	{
		highAce = true;
	}

	//Assign the score values for each card type
	if (card.getFace() == card.KING || card.getFace() == card.QUEEN || card.getFace() == card.JACK)
	{
		playerScore += 10;
	}
	else if (card.getFace() == card.ACE && highAce)
	{
		playerScore += 11;
		
		//Check again if two aces are dealt to reduce the score to prevent a bust
		if (CheckBusted())
		{
			highAce = false;
			playerScore -= 10;
		}
	}
	else
	{
		playerScore += card.getFace();
	}
	
	//Send a message to the user they have busted and show them the card that did it
	if (CheckBusted())
	{
		cout << "\n------------------------------------------" << endl;
		cout << "You got [ " << card.getFaceName() << " of " << card.getSuitName() << " ]" << endl;
		cout << "= Card score is now: " << GetPlayerScore() << endl;
		cout << "\nOver 21....You BUSTED!" << endl;
		cout << "------------------------------------------" << endl;
	}
}

//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function accesses the current queue of player cards and runs
* a loop to display each one while playing.
******************************************************************/
void PlayerHand::DisplayHand() const
{
	//Loop through the queue and display the current cards
	for (int index = 0; index < playerHand.size(); index++)
	{
		cout << "[ " << playerHand[index] << " ]" << endl;
	}
}

/******************************************************************
* This function sends different messages to the player when they
* choose the hit option.  If none of the checks are met, the next
* card is sent to the player's hand, the size is updated, and the score
* is updated.  The first check of busting should not need to be used
* but it is created just in case.
******************************************************************/
void PlayerHand::DealerHit(Card card)
{
	if (CheckBusted())
	{
		cout << "\n------------------------------------------" << endl;
		cout << "You Busted!  Game is over and cannot draw any more cards!" << endl;
		cout << "------------------------------------------" << endl;
	}
	else if (handSize >= 5)
	{
		cout << "\n------------------------------------------" << endl;
		cout << "Your Hand is Full: You have to play!" << endl;
		cout << "------------------------------------------" << endl;
	}
	else if (GetPlayerScore() == 21)
	{
		cout << "\n------------------------------------------" << endl;
		cout << "BlackJack! No need to draw any more cards!" << endl;
		cout << "------------------------------------------" << endl;
	}
	else
	{
		playerHand.push_back(card);
		handSize++;
		SetPlayerScore(card);
	}
}

/******************************************************************
* This function checks the player's score to see if it goes over 21
* and if so sets the bool variable to true.
******************************************************************/
bool PlayerHand::CheckBusted()
{
	bool busted = false;

	if (playerScore > 21)
	{
		busted = true;
	}

	return busted;
}