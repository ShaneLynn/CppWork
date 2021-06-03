/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 4
 Created: 5/25/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program tracks statistics for soccer games for kids.  It uses structures to store data for the player's name, jersey number
 and points scored.  Each player structure is then stored in an array of players determined by a constant for the team size, and the
 program will ask the user to enter data on each player in the array.  The final display of player data is in a table format, followed
 by statistics after the table that shows the total points scored and which player scored the most points on the team.  
 The program also validates user inputs to prevent negative values for the player's number and score.
 
 The following is an example of the table display format:

 Player Name	Jersey Number	Points Scored
 Joe			25				5
 etc.

     Team Points Scored:	11
 Highest Scoring Player:	Joe	(5 points)

* This program uses the following functions:

•	void GetPlayerInfo(Player &);
	o	Accepts the player structure as a reference to update the values directly
	o	Prompts the user to enter data for each component of the structure (player name, number, and score)
	o	Validates the user input for the number and score to prevent negative values

•	void ShowPlayerInfo(const Player);
	o	Accepts the player structure as a constant value to avoid changing any data
	o	Formats the output to a table and left aligns the name field
	o	Displays an output for each of the Player structure components

•	int GetTotalPoints(const Player[ ], int);
	o	Accepts the array of player structures and the global array size
	o	Uses a for loop with accumulator to step through each array element grabbing the playerScore values
	o	Returns the final team score to the program

•	void ShowHighest(Player [ ], int);
	o	Accepts the array of player structures and the global array size
	o	Uses a for loop to step through the array to check each strucure stored
	o	Uses an if check to determine if the current playerScore value is higher than the previous value
	o	Displays the final results

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

//Delare Structures
struct Player
{
	string playerName;
	int playerNumber;
	int playerScore;
};


//Declare the function prototypes:
void GetPlayerInfo(Player&);
void ShowPlayerInfo(const Player);
int GetTotalPoints(const Player[], int);
void ShowHighest(Player[], int);


//Delcare the global size for the team array
const int teamSize = 3; //12 is final count



//The main program function
int main()
{
	//Delare Variables:
	int teamScore = 0;										//Holds the total team's score value returned from the function
	
	//Declare the structure array for the team of players:
	Player mainTeam[teamSize];

	//Initial prompt startup display for the user
	cout << "Welcome to the Little Monsters Soccer Team Tracking Tool!" << endl;
	cout << "\n";

	//Get the player data from the user by moving through the array and calling the function
	for (int index = 0; index < teamSize; index++)
	{
		cout << "\nEnter the data for team member " << index+1 << ": " << endl;		//Prompt for the team member in question
		GetPlayerInfo(mainTeam[index]);
		cin.ignore();
	}
	
	//Setup the display and loop to retreive and display the player data for all team members
	cout << "\n";
	cout << "----------------" << endl;
	cout << "| TEAM RESULTS |" << endl;
	cout << "----------------" << endl;
	cout << setw(25) << left << "Player Name" << setw(15) << left << "Jersey Number" << setw(15) << left << "Points Scored" << endl;
	cout << setw(25) << left << "-----------" << setw(15) << left << "-------------" << setw(15) << left << "-------------" << endl;

	for (int index = 0; index < teamSize; index++)
	{
		ShowPlayerInfo(mainTeam[index]);
	}

	//Calculate the total points scored by the team
	teamScore = GetTotalPoints(mainTeam, teamSize);

	//Display the total points scored by the team
	cout << "\n";
	cout << "    Team Points Scored:\t " << teamScore << endl;

	//Find and display the highest scoring player on the team
	ShowHighest(mainTeam, teamSize);


	//Prompt to close the program
	cout << "\nThank you for using the system.  Press any key to close...";
	cin.get();

	return 0;
}


/****************************************************************************************
This function prompts the user and collects info on each player from the user and stores 
it into the Player structure.  It accepts the Player structure as a reference to change values
directly in the program. Validation is used on the playerNumber and playerScore structure
variables to prevent negative values.  Only stores data, does not return anything.
****************************************************************************************/
void GetPlayerInfo(Player &player)
{
		
	//Collect the player's name and store in the structure's section
	cout << "What is the player's name? ";
	getline(cin, player.playerName);
	

	//Collect the jersey number and store in the structure's section
	cout << "What is their jersey number? ";
	cin >> player.playerNumber;
	while (player.playerNumber < 0)				//Valiadate user entry to avoid negative numbers
	{
		cout << "Invalid entry.  Jersey numbers must be 0 or higher." << endl;
		cout << "What is their jersey number? ";
		cin >> player.playerNumber;
	}
	
	//Collect the points and store in the structure's section
	cout << "What is their total points scored? ";
	cin >> player.playerScore;
	while (player.playerScore < 0)				//Valiadate user entry to avoid negative numbers
	{
		cout << "Invalid entry.  Points scored must be 0 or higher." << endl;
		cout << "What is their total points scored? ";
		cin >> player.playerScore;
	}

}

/****************************************************************************************
This function displays the final team information for the player structure passed into the
function.  It accesses the structure as a constant to avoid changing any values, and it
creates an output display using the same table format setup in main for the final results
output.  Only one display line is needed, as this function can be called from a loop
or directly.
****************************************************************************************/
void ShowPlayerInfo(const Player player)
{
			
	cout << setw(25) << left << player.playerName << setw(15) << player.playerNumber << setw(15) << player.playerScore << endl;
}

/****************************************************************************************
This function searches the player array of structures and calculates the total points 
scored by the team.  It collects both the array and global array size variable, and sets
up an accumulator to be used with a for loop to step through each array element for
playerScore.  Once the accumulator is completed, the function returns the final 
calculation to the program.
****************************************************************************************/
int GetTotalPoints(const Player players[], int teamSize)
{
	int finalScore = 0;				//Accumulator to hold the team's final score

	for (int index = 0; index < teamSize; index++)
	{
		finalScore += players[index].playerScore;
	}

	return finalScore;
}

/****************************************************************************************
This function searches the player array of structures to find the player that scored the
highest amount of points.  It collects both the array and global array size variable, and
sets up two variales to hold the current highest values.  It then uses a for loop to step
through each array element for playerScore and follows with an if check to determine if
the current value is larger than the current highest value in the function variable.  If
the value is higher, the function will record the values for playerName and playerScore from
the current element before continuing.  Once the loop is finished, the function will display
the statistic for the highest scoring player on the team.
****************************************************************************************/
void ShowHighest(Player players[], int teamSize)
{
	int playerScore = 0;				//Holds the highest valueteam's final score
	string playerName;					//Holds the name of the player with the highest score

	for (int index = 0; index < teamSize; index++)
	{
		if(players[index].playerScore > playerScore)
		{
			playerScore = players[index].playerScore;
			playerName = players[index].playerName;
		}
	}

	//Display the player with the highest score
	cout << "Highest Scoring Player: " << playerName << " (" << playerScore << " points)" << endl;
}