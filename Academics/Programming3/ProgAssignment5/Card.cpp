//Template file provided for the assignment

#include "Card.h"


	//-----------------------------------------------------------------
	//  Creates a random card.
	//-----------------------------------------------------------------
	Card::Card()
	{
		srand(time(0));
		face = (int)(rand() % NUM_FACES) + 1;
		setFaceName();

		suit = (int)(rand() * NUM_SUITS) + 1;
		setSuitName();
	}

	//-----------------------------------------------------------------
	//  Creates a card of the specified suit and face value.
	//-----------------------------------------------------------------
	Card::Card(int faceValue, int suitValue)
	{
		face = faceValue;
		setFaceName();

		suit = suitValue;
		setSuitName();
	}

	//-----------------------------------------------------------------
	//  Sets the string representation of the face using its stored
	//  numeric value.
	//-----------------------------------------------------------------
	void  Card::setFaceName()
	{
		switch (face)
		{
		case ACE:
			faceName = "Ace";
			break;
		case TWO:
			faceName = "Two";
			break;
		case THREE:
			faceName = "Three";
			break;
		case FOUR:
			faceName = "Four";
			break;
		case FIVE:
			faceName = "Five";
			break;
		case SIX:
			faceName = "Six";
			break;
		case SEVEN:
			faceName = "Seven";
			break;
		case EIGHT:
			faceName = "Eight";
			break;
		case NINE:
			faceName = "Nine";
			break;
		case TEN:
			faceName = "Ten";
			break;
		case JACK:
			faceName = "Jack";
			break;
		case QUEEN:
			faceName = "Queen";
			break;
		case KING:
			faceName = "King";
			break;
		}
	}

	//-----------------------------------------------------------------
	//  Sets the string representation of the suit using its stored
	//  numeric value.
	//-----------------------------------------------------------------
	void  Card::setSuitName()
	{
		switch (suit)
		{
		case CLUBS:
			suitName = "Clubs";
			break;
		case DIAMONDS:
			suitName = "Diamonds";
			break;
		case HEARTS:
			suitName = "Hearts";
			break;
		case SPADES:
			suitName = "Spades";
			break;
		}
	}

	//-----------------------------------------------------------------
	//  Determines if this card is higher than the passed card. The
	//  second parameter determines if aces should be considered high
	//  (beats a King) or low (lowest of all cards).  Uses the suit
	//  if both cards have the same face.
	//-----------------------------------------------------------------
	bool  Card::isHigherThan(Card card2, bool aceHigh)
	{
		bool result = false;

		if (face == card2.getFace())
		{
			if (suit > card2.getSuit())
				result = true;
		}
		else
		{
			if (aceHigh && face == ACE)
				result = true;
			else
				if (face > card2.getFace())
					result = true;
		}

		return result;
	}

	//-----------------------------------------------------------------
	//  Determines if this card is higher than the passed card,
	//  assuming that aces should be considered high.
	//-----------------------------------------------------------------
	bool Card::isHigherThan(Card card2)
	{
		return isHigherThan(card2, true);
	}

	//-----------------------------------------------------------------
	//  Returns the face (numeric value) of this card.
	//-----------------------------------------------------------------
	int Card::getFace()
	{
		return face;
	}

	//-----------------------------------------------------------------
	//  Returns the suit (numeric value) of this card.
	//-----------------------------------------------------------------
	int Card::getSuit()
	{
		return suit;
	}

	//-----------------------------------------------------------------
	//  Returns the face (string value) of this card.
	//-----------------------------------------------------------------
	string Card::getFaceName() const
	{
		return faceName;
	}

	//-----------------------------------------------------------------
	//  Returns the suit (string value) of this card.
	//-----------------------------------------------------------------
	string Card::getSuitName() const
	{
		return suitName;
	}

	ostream & operator<<(ostream & strm, const Card& obj)
	{
		strm << obj.getFaceName() << " of " << obj.getSuitName();

		return strm;
	}