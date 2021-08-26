/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 5
 Created: 7/23/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: DeckOfCards.h

 Required Files: DeckOfCards.h

***************************************************************************************************************************/

#include "DeckOfCards.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/******************************************************************
* The default constructor is used to generate a deck of cards by using
* an accumulator and nested for loop.  The loop cycles through the 
* four suits and 13 faces of cards and generates a temporary card
* object for each pass.  That temporary object is stored in the array
* until all cards have been added.
******************************************************************/
Deck::Deck()
{
	//Setup accumulator to track how many cards are created (should be 52 = 13 face * 4 suit) 
	int cardCount = 0;

	//Create an outer and inner for loop to generate one type of each card in the deck
	for (int suit = 0; suit < 4; suit++)
	{
		for (int face = 0; face < 13; face++)
		{
			//Create a temporary card object to pass the values to the Card constructor to generate the card
			Card temp(face + 1, suit + 1);
			
			//Add the new card to the array
			unshuffledDeck[cardCount] = temp;
			
			//Increase the accumulator count
			cardCount++;
		}
	}
}

//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function creates a temporary card object and transfers the
* top card of the dealer's stack to it.  It then removes the top
* card from the stack to prevent reuse and returns that card to be
* used in the player's hand.
******************************************************************/
Card Deck::DealCard()
{
	Card temp;
	temp = finalDeck.top();
	finalDeck.pop();
	return temp;
}

/******************************************************************
* This function copies the array created in the constructor into a
* vector using a loop.  Once copied into the vector, the vector calls
* an algorithm function from the STL to randomize "shuffle" the elements
* around.  Next, the randomzied vector is pushed onto the stack for the
* dealer's deck.
******************************************************************/
void Deck::ShuffleDeck()
{
	//Transfer the ordered cards created in the constructor
	// populated unshuffled deck to the vector shuffled deck
	for (int index = 0; index < DECKSIZE; index++)
	{
		shuffledDeck.push_back(unshuffledDeck[index]);
	}
	
	//Shuffle the cards around in the vector for play
	random_shuffle(shuffledDeck.begin(), shuffledDeck.end());

	//Transfer the cards from the vector into the dealer's stack of cards
	for (int index = 0; index < DECKSIZE; index++)
	{
		finalDeck.push(shuffledDeck[index]);
	}

}

/******************************************************************
* This function checks the cards remaining in the deck of cards
* object.  It is mostly used for diagnostics and should be called
* at the end of the game loop when the game is over.  It makes
* a copy of the final deck object and empties the temporary stack
* to avoid impacting the real deck object should it be needed for
* another use.
******************************************************************/
void Deck::RemainingCards()
{
	cout << "\nRemaining cards in the deck: " << finalDeck.size() << endl;
	cout << "List of remaining cards: " << endl;
	stack<Card, vector<Card>> deckCopy(finalDeck);
	
	for (int index = 0; index < finalDeck.size(); index++)
	{
		cout << "--" << deckCopy.top() << endl;
		deckCopy.pop();
	}
}