/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 5
 Created: 7/23/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class sets up and stores information about a deck of cards player's hand.  It uses the files provided to create a singular
 card and creates several action functions and data member containers to collect those cards.  A special action method is provided
 to track the remaining cards in the deck that can be called (usually after the game is over) to inspect the stack and see how
 many cards are remaining.

 Required Files: Card.h
 Description File: DeckOfCards.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <random>
#include <algorithm>
#include "Card.h"

using namespace std;

const int DECKSIZE = 52;

class Deck
{
public:
	//CONSTRUCTORS
	Deck();

	//ACTION FUNCTIONS
	Card DealCard();
	void ShuffleDeck();
	void RemainingCards();

private:
	//DATA MEMBERS
	//Setup the data member containers: Array, vector, and a stack to create the final dealer's deck
	Card unshuffledDeck[DECKSIZE];
	vector<Card> shuffledDeck;
	stack <Card, vector<Card>> finalDeck;
};
