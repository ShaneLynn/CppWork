/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 4
 Created: 7/19/2021

 ----------------------------------------------------------------------------------------------------------------------------
 Description:
 This program uses the Baseball player class and combines it with the derived linked list class to store data about baseball
 players.  It allows creating each baseball player object, and then storing that object in the linked list as a data node.  A
 constant integer is used to count how many players are on the team and provide a value for the array retriveval behavior the linked list
 can provide.  Once the team roster has been displayed, it calls two functions of the derived list to determine which player
 in the list has the highest calculated score based on their statistics.


 Class File used: BaseballPlayer.h, HighLowLL.h

***************************************************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "HighLowLL.h"
#include "BaseballPlayer.h"

using namespace std;

//The main program function
int main()
{

	//Prompt the user with a welcome
	cout << "Welcome to the Baseball Player Team Roster." << endl;
	cout << "--The window may need to be expanded to see all results." << endl;
	cout << "\n";
	
	//Setup the counter for the total players on the team
	const int playerCount = 4 ;
	
	//Setup the baseball players circa 1985
	BaseballPlayer player1("Jack Clark", 124, 22, 83, 88);
	BaseballPlayer player2("Ozzie Smith", 148, 6, 65, 27);
	BaseballPlayer player3("Terry Pendleton", 134, 5, 37, 75);
	BaseballPlayer player4("Willie McGee", 216, 10, 34, 86);
	

	//Setup the derived linked list
	HighLowLL<BaseballPlayer>* playerList = new HighLowLL<BaseballPlayer>();

	//Add the players to the list
	playerList->AppendNode(player1);
	playerList->AppendNode(player2);
	playerList->AppendNode(player3);
	playerList->AppendNode(player4);
	
	//Send a message to the user that the list is going to start
	cout << "The current players on the team and their stats are: " << endl;

	//Setup a for loop to display each player in the list using array behavior
	for (int index = 0; index < playerCount; index++)
	{
		cout << (*playerList)[index];
	}

	cout << "\n\nBest Player: " << playerList->FindHighestValue() << endl;
	cout << "Worst Player: " << playerList->FindLowestValue() << endl;


	//Prompt to close the program window
	cout << "\nThank you for using the system.  Press the enter key to close...";

	cin.get();

	return 0;
}