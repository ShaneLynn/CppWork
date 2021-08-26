/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 5
 Created: 7/23/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class sets up and stores information about a card player's hand.  It tracks the score of each card that goes into the 
 hand using the data members, and it has several functions that get, set, and perform actions.  The action functions determine
 what happens when the player asks for a new card from the dealer, and a method to check to see if the player busts.  The score
 can be set based on actions while playing.

 Required Files: DeckOfCards.h
 Description File: PlayerHand.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <deque>
#include "DeckOfCards.h"

using namespace std;

class PlayerHand
{
public:
	//CONSTRUCTORS
	PlayerHand(Card, Card);
	
	//ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
	int GetPlayerScore() const;
	void SetPlayerScore(Card);
	
	//ACTION FUNCTIONS
	void DisplayHand() const;
	void DealerHit(Card);
	bool CheckBusted();


private:
	//DATA MEMBERS
	//Setup the data members to track the player's score and size of the current cards
	int handSize = 2;
	int playerScore = 0;
	
	//Setup the queue to hold the player's current cards
	deque<Card> playerHand;
};
