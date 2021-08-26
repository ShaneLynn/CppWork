/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 4
 Created: 7/19/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: BaseballPlayer.h

 Required Files: BaseballPlayer.h

***************************************************************************************************************************/

#include "BaseballPlayer.h"

using namespace std;


//Constructors
/*************************************
* Default constructor
**************************************/
BaseballPlayer::BaseballPlayer()
{
    name = "";
    hits = 0;
    homeRuns = 0;
    walks = 0;
    strikeOuts = 0;
    totalScore = 0;
}

/******************************************************************
* Parameter constructor that accepts the name, hits, homeRuns, walks, and
strikeOuts as input.
******************************************************************/
BaseballPlayer::BaseballPlayer(string name, int hits, int homeRuns, int walks, int strikeOuts)
{
    this->name = name;
    this->hits = hits;
    this->homeRuns = homeRuns;
    this->walks = walks;
    this->strikeOuts = strikeOuts;
    CalculatePlayerScore();
}

//Accessors and Mutators - Getters and Setters

/******************************************************************
* This function gets the value stored in the data member: name
******************************************************************/
string BaseballPlayer::GetName() const
{
    return name;
}

/******************************************************************
* This function sets the value stored in the data member: name
******************************************************************/
void BaseballPlayer::SetName(string name)
{
    this->name = name;
    CalculatePlayerScore();
}

/******************************************************************
* This function gets the value stored in the data member: hits
******************************************************************/
int BaseballPlayer::GetHits() const
{
    return hits;
}

/******************************************************************
* This function sets the value stored in the data member: hits
******************************************************************/
void BaseballPlayer::SetHits(int hits)
{
    this->hits = hits;
    CalculatePlayerScore();
}

/******************************************************************
* This function gets the value stored in the data member: homeRuns
******************************************************************/
int BaseballPlayer::GetHomeRuns() const
{
    return homeRuns;
}

/******************************************************************
* This function sets the value stored in the data member: homeRuns
******************************************************************/
void BaseballPlayer::SetHomeRuns(int homeRuns)
{
    this->homeRuns = homeRuns;
    CalculatePlayerScore();
}

/******************************************************************
* This function gets the value stored in the data member: walks
******************************************************************/
int BaseballPlayer::GetWalks() const
{
    return walks;
}

/******************************************************************
* This function sets the value stored in the data member: walks
******************************************************************/
void BaseballPlayer::SetWalks(int walks)
{
    this->walks = walks;
    CalculatePlayerScore();
}


/******************************************************************
* This function gets the value stored in the data member: strikeOuts
******************************************************************/
int BaseballPlayer::GetStrikeOuts() const
{
    return strikeOuts;
}

/******************************************************************
* This function sets the value stored in the data member: strikeOuts
******************************************************************/
void BaseballPlayer::SetStrikeOuts(int strikeOuts)
{
    this->strikeOuts = strikeOuts;
    CalculatePlayerScore();
}

/******************************************************************
* This function gets the value stored in the data member: totalScore
******************************************************************/
int BaseballPlayer::GetPlayerScore() const
{
    return totalScore;
}

/******************************************************************
* This function sets the value stored in the data member: totalScore
******************************************************************/
void BaseballPlayer::SetPlayerScore(int totalScore)
{
    this->totalScore = totalScore;
}


//Calculation functions

/******************************************************************
* This function calculates the points earned for the player's activity
of hits, home runs, walks and strike outs.
******************************************************************/
void BaseballPlayer::CalculatePlayerScore()
{
    //Create and initialize the accumulator to 0
    int currPoints = 0;

    //Check if hits are entered, and add to the accumulator
    if (hits > 0)
    {
        currPoints += hits;
    }

    //Check if homeRuns are entered, and add to the accumulator *4
    if (homeRuns > 0)
    {
        currPoints += (homeRuns * 4);
    }

    //Check if hits are entered, and add to the accumulator
    if (walks > 0)
    {
        currPoints += walks;
    }

    //Check if strikeOuts are entered, and subtract from the accumulator
    if (strikeOuts > 0)
    {
        currPoints -= strikeOuts;
    }

    //Update the total score data member with the accumulator's value
    totalScore = currPoints;
}


//Operator overloads
/******************************************************************
* This function overloads the < operator to be able to compare the
points earned for the player's activity of hits, home runs, walks and strike outs.
******************************************************************/
bool BaseballPlayer::operator < (const BaseballPlayer& right) const
{
    //Setup the variable for the left player and retreive the player's score
    int leftPoints = GetPlayerScore();

    //Setup the variable for the right player and retreive the player's score
    int rightPoints = right.GetPlayerScore();

    //Use a check to compare which player has the lesser score and return true if the
    //left player has a lower score than the right player.
    if (leftPoints < rightPoints)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/******************************************************************
* This function overloads the > operator to be able to compare the
points earned for the player's activity of hits, home runs, walks and strike outs.
******************************************************************/
bool BaseballPlayer::operator > (const BaseballPlayer& right) const
{
    //Setup the variable for the left player and retreive the player's score
    int leftPoints = GetPlayerScore();

    //Setup the variable for the right player and retreive the player's score
    int rightPoints = right.GetPlayerScore();

    //Use a check to compare which player has the higher score and return true if the
    //left player has a higher score than the right player.
    if (leftPoints > rightPoints)
    {
        return true;
    }
    else
    {
        return false;
    }

}

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& out, const BaseballPlayer& player)
{
    out << "\nPlayer Name: " << player.name
        << "\n  Hits: " << player.hits
        << "\n  Home Runs: " << player.homeRuns
        << "\n  Walks: " << player.walks
        << "\n  Strike Outs: " << player.strikeOuts
        << "\n  Total Score: " << player.GetPlayerScore() << endl;

    return out;
}
