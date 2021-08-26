/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 4
 Created: 7/19/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class sets up and stores information about a baseball player.  It stores basic data througout the season like the
 player's name, hits, home runs, walks, and strike outs.  It also calculates the total score to rank the player against
 other players and overloads the operators <, >, and << to compare and display the information about the player.

 Required Files: 
 Description File: BaseballPlayer.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

class BaseballPlayer
{

public:

    //Constructors
    BaseballPlayer();
    BaseballPlayer(string name, int hits, int homeRuns, int walks, int strikeOuts);

    //Accessors and Mutators - Getters and Setters
    string GetName() const;
    void SetName(string);

    int GetHits() const;
    void SetHits(int);

    int GetHomeRuns() const;
    void SetHomeRuns(int);

    int GetWalks() const;
    void SetWalks(int);

    int GetStrikeOuts() const;
    void SetStrikeOuts(int);

    int GetPlayerScore() const;
    void SetPlayerScore(int);

    //Calculation functions
    void CalculatePlayerScore();

    //Operator overloads
    bool operator < (const BaseballPlayer&) const;
    bool operator > (const BaseballPlayer&) const;
    friend ostream& operator << (ostream& out, const BaseballPlayer& player);


private:
    //Setup the data members
    string name;
    int hits;
    int homeRuns;
    int walks;
    int strikeOuts;
    int totalScore;

};