//Template file provided for the assignment

#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <ostream>
using namespace std;

class Card;
ostream& operator<<(ostream& strm, const Card& obj);

class Card
{

private:
	const static int NUM_FACES = 13;
	const static int NUM_SUITS = 4;

	int face, suit;
	string faceName, suitName;

public:
	const static int ACE = 1;
	const static int TWO = 2;
	const static int THREE = 3;
	const static int FOUR = 4;
	const static int FIVE = 5;
	const static int SIX = 6;
	const static int SEVEN = 7;
	const static int EIGHT = 8;
	const static int NINE = 9;
	const static int TEN = 10;
	const static int JACK = 11;
	const static int QUEEN = 12;
	const static int KING = 13;

	const static int CLUBS = 1;
	const static int DIAMONDS = 2;
	const static int HEARTS = 3;
	const static int SPADES = 4;
	Card();
	Card(int faceValue, int suitValue);
	void setFaceName();
	void setSuitName();
	bool isHigherThan(Card card2, bool aceHigh);
	bool isHigherThan(Card card2);
	int getFace();
	int getSuit();
	string getFaceName() const;
	string getSuitName() const;
	friend ostream& operator<<(ostream& strm, const Card& obj);
};

