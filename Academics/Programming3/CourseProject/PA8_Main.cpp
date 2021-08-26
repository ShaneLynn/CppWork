/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program uses the CD, DVD, LinkedList classes to create and maintain a CD/DVD collection inventory.  The program creates
 a two LinkedList objects to hold and maintain the collection of CD/DVD objects. It provides a menu for the user to navigate
 to each section of the collection and allows them to perform various tasks.  
 
 The program and classes provide the following functionality to the user: 
 *  Choose between the CD or DVD collection databases
 *  Each side's sub menu provides the ability to
 *	Display as list of all current items 
 *	Add, Update, Remove a cd/dvd to the collection LinkedList
 *  Add, Update, Remove songs and actors from a cd/dvd to the collection LinkedList
 *  Display the details of each CD/DVD stored in the collection.  This function formats the data in a "card" format with the
 *   general info at the top, total songs/actors in the media, and a list of songs/actors per cd/dvd.  A warning is given
 *   in the menu that this list will require scrolling if lots of cd/dvd items are present.
 *	Exit the program


 Required Files: LinkedList.h, CD.h, DVD.h

***************************************************************************************************************************/

//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "LinkedList.h"
#include "CD.h"
#include "DVD.h"

using namespace std;

//FUNCTION PROTOTYPES
//-----CD FUNCTIONS
void AddCD();
void RemoveCD();
void UpdateCD();
void DisplayCDCollection();
void AddSongsToCDs();
void UpdateSongsOnCDs();
void RemoveSongsOnCDs();
void DisplayAllCDsSongs();

//-----DVD FUNCTIONS
void AddDVD();
void RemoveDVD();
void UpdateDVD();
void DisplayDVDCollection();
void AddActorsToDVDs();
void UpdateActorsOnDVDs();
void RemoveActorsOnDVDs();
void DisplayAllDVDsActors();


//Setup the linked lists to store the CD and DVD collections
LinkedList<CD>* cdCollection = new LinkedList<CD>();
LinkedList<DVD>* dvdCollection = new LinkedList<DVD>();


//The main program function
int main()
{
	//Prompt the user with a welcome
	cout << "Welcome to the CD and DVD Collection Management System." << endl;
	cout << "--The window may need to be expanded to see all results." << endl;
	cout << "\n";

	//Setup variables to collect user input for the menus
	int mainMenuChoice;
	int secondMenuChoice;
	bool menuValidate = false;
	bool secondMenuValidate = false;

	//Start the main menu loop to allow the user to use the collection system
	do
	{
		cout << "\n";
		cout << "**********************************" << endl;
		cout << "MAIN MENU" << endl;
		cout << "1. Enter the current CD Collection" << endl;
		cout << "2. Enter the current DVD Collection" << endl;
		cout << "3. Exit the system" << endl;
		cout << "Please make a selection from the menu: ";
		cin >> mainMenuChoice;

		//Reset the validation flag
		menuValidate = false;
		
		//User Input validation
		while(!menuValidate)
		{
			if (mainMenuChoice == 1 || mainMenuChoice == 2 || mainMenuChoice == 3 && !cin.fail())
			{
				menuValidate = true;
			}
			else
			{
				cout << "\nInvalid Input.  Please select options 1-3: " << endl;
				cout << "->";
				cin.clear();
				cin.ignore();
				cin >> mainMenuChoice;
			}
		}
		
		//Setup a switch to handle the main menu option selections
		switch (mainMenuChoice)
		{
			case 1:
			{
				cout << "\n===1. Enter the current CD Collection" << endl;
				cout << "\n";

				cout << "\n";
				cout << "--Now displaying the CD collection options..." << endl;
				
				////Start the inner menu loop to allow the user to navigate CD options
				do
				{
					cout << "\n";
					cout << "**********************************" << endl;
					cout << "MENU - CD OPTIONS" << endl;
					cout << "1. Display the current CD Collection" << endl;
					cout << "2. Add a CD" << endl;
					cout << "3. Update a CD" << endl;
					cout << "4. Remove a CD" << endl;
					cout << "5. Add Songs to a CD" << endl;
					cout << "6. Update Songs on a CD" << endl;
					cout << "7. Remove Songs from a CD" << endl;
					cout << "8. Display All CDs and Songs (Warning-Large)" << endl;
					cout << "9. Return to the main menu" << endl;
					cout << "Please make a selection from the menu: ";
					cin >> secondMenuChoice;

					//Reset the validation flag
					secondMenuValidate = false;

					//User Input validation
					while (!secondMenuValidate)
					{
						if (secondMenuValidate >= 1 || secondMenuValidate <= 9 && !cin.fail())
						{
							secondMenuValidate = true;
						}
						else
						{
							cout << "\nInvalid Input.  Please select options 1-9: " << endl;
							cout << "->";
							cin.clear();
							cin.ignore();
							cin >> secondMenuChoice;
						}
					}
						

					//Setup the switch to handle the menu option selections
					switch (secondMenuChoice)
					{
						case 1:
						{
							cout << "\n===1. Display the current CD Collection" << endl;
							cout << "\n";

							cout << "\n";
							cout << "--Now displaying the CD collection..." << endl;
							DisplayCDCollection();
							break;
						}
						case 2:
						{
							cout << "\n===2. Add a CD" << endl;
							AddCD();
							break;
						}
						case 3:
						{
							cout << "\n===3. Update a CD" << endl;
							UpdateCD();
							break;
						}
						case 4:
						{
							cout << "\n===4. Remove a CD" << endl;
							RemoveCD();
							break;
						}
						case 5:
						{
							cout << "\n===5. Add Songs to a CD" << endl;
							AddSongsToCDs();
							break;
						}
						case 6:
						{
							cout << "\n===6. Update Songs on a CD" << endl;
							UpdateSongsOnCDs();
							break;
						}
						case 7:
						{
							cout << "\n===7. Remove Songs from a CD" << endl;
							RemoveSongsOnCDs();
							break;
						}
						case 8:
						{
							cout << "\n===8. Display All CDs and Songs" << endl;
							DisplayAllCDsSongs();
							break;
						}
						case 9:
						{
							cout << "\n===9. Return to the main menu" << endl;
							break;
						}
					}
				} while (secondMenuChoice != 9);			//Exit the inner switch loop and return to the menu.
				break;
			}
			case 2:
			{
				cout << "\n===2. Enter the current DVD Collection" << endl;
				cout << "\n";

				cout << "\n";
				cout << "--Now displaying the DVD collection options..." << endl;

				////Start the inner menu loop to allow the user to navigate CD options
				do
				{
					cout << "\n";
					cout << "**********************************" << endl;
					cout << "MENU - DVD OPTIONS" << endl;
					cout << "1. Display the current DVD Collection" << endl;
					cout << "2. Add a DVD" << endl;
					cout << "3. Update a DVD" << endl;
					cout << "4. Remove a DVD" << endl;
					cout << "5. Add Actors/Actresses to a DVD" << endl;
					cout << "6. Update Actors/Actresses on a DVD" << endl;
					cout << "7. Remove Actors/Actresses from a DVD" << endl;
					cout << "8. Display All DVDs and Actors/Actresses" << endl;
					cout << "9. Return to the main menu" << endl;
					cout << "Please make a selection from the menu: ";
					cin >> secondMenuChoice;

					//Reset the validation flag
					secondMenuValidate = false;

					//User Input validation
					while (!secondMenuValidate)
					{
						if (secondMenuValidate >= 1 || secondMenuValidate <= 9 && !cin.fail())
						{
							secondMenuValidate = true;
						}
						else
						{
							cout << "\nInvalid Input.  Please select options 1-9: " << endl;
							cout << "->";
							cin.clear();
							cin.ignore();
							cin >> secondMenuChoice;
						}
					}

					//Setup the switch to handle the menu option selections
					switch (secondMenuChoice)
					{
						case 1:
						{
							cout << "\n===1. Display the current DVD Collection" << endl;
							cout << "\n";

							cout << "\n";
							cout << "--Now displaying the DVD collection..." << endl;
							DisplayDVDCollection();
							break;
						}
						case 2:
						{
							cout << "\n===2. Add a DVD" << endl;
							AddDVD();
							break;
						}
						case 3:
						{
							cout << "\n===3. Update a DVD" << endl;
							UpdateDVD();
							break;
						}
						case 4:
						{
							cout << "\n===4. Remove a DVD" << endl;
							RemoveDVD();
							break;
						}
						case 5:
						{
							cout << "\n===5. Add Actors/Actresses to a DVD" << endl;
							AddActorsToDVDs();
							break;
						}
						case 6:
						{
							cout << "\n===6. Update Actors/Actresses on a DVD" << endl;
							UpdateActorsOnDVDs();
							break;
						}
						case 7:
						{
							cout << "\n===7. Remove Actors/Actresses from a DVD" << endl;
							RemoveActorsOnDVDs();
							break;
						}
						case 8:
						{
							cout << "\n===8. Display All DVDs and Actors/Actresses" << endl;
							DisplayAllDVDsActors();
							break;
						}
						case 9:
						{
							cout << "\n===9. Return to the main menu" << endl;
							break;
						}
					} 
				} while (secondMenuChoice != 9);			//Exit the inner switch loop and return to the menu.
				break;
			}
			case 3:
			{
				cout << "\n===Exiting both Collections..." << endl;
				break;
			}
		}
	} while (mainMenuChoice != 3);			//Exit the loop with the exit choice from the menu.

	

	//Prompt to close the program
	cout << "\nThank you for using the system.  Press the enter key to close...";
	cin.clear();
	cin.get();

	return 0;
}

//================================================================
//FUNCTION DEFINITIONS
//================================================================


//----------------------------------------------------------------
// ACTION FUNCTIONS - CDs
//----------------------------------------------------------------

/******************************************************************
* This function adds a new cd to the current linkedList: cdCollection
* It prompts the user to enter the title, length, and artist before
* appending it to the linked list.  
******************************************************************/
void AddCD()
{
	//Setup variables to use with adding the cd
	CD temp;
	string userInputTitle;
	int userInputNum;
	string userInputArtist;

	//Prompt the user for the title, length, and artist of the new CD
	cout << "\nWhat is the title of the CD to Add?" << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, userInputTitle);

	cout << "What is the length in minutes of the CD?" << endl;
	cout << "-> ";
	cin >> userInputNum;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || userInputNum < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> userInputNum;
		//cin.ignore();
	}

	cout << "Who is the artist of the CD?" << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, userInputArtist);
	
	//Update the object variables
	temp.SetMediaTitle(userInputTitle);
	temp.SetMediaLength(userInputNum);
	temp.SetArtistName(userInputArtist);

	//Add the new cd to the list
	cdCollection->AppendNode(temp);
	cout << "New CD added!" << endl;
}

/******************************************************************
* This function removes a current from the current linkedList: cdCollection
* It prompts the user to enter the title, length, and artist before
* searching the linked list for a match.  If match is found it is removed.
******************************************************************/
void RemoveCD()
{
	//Setup a check to cancel the action if no cds exist
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CD's in the collection to remove." << endl;
		return;
	}
	
	//Setup variables to use with removing the cd
	CD oldCD;
	string cdTitleInput;
	int cdLenInput;
	string cdArtistInput;

	//Prompt the user for the title, length, and artist of the old cd
	cout << "\nWhat is the title of the CD to remove? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, cdTitleInput);

	cout << "What is its length in minutes to remove?" << endl;
	cout << "-> ";
	cin >> cdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || cdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> cdLenInput;
		//cin.ignore();
	}

	cout << "Who is the artist to remove? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, cdArtistInput);

	//Update the object variables
	oldCD.SetMediaTitle(cdTitleInput);
	oldCD.SetMediaLength(cdLenInput);
	oldCD.SetArtistName(cdArtistInput);
	
	//Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
	//------------------------------------------------------------------------------------------------------
	//Setup validation variables
	string currTitle;
	int currLength;
	string currArtist;
	bool exactMatch = false;

	//Use a loop to step through the collection to find a match for the user input
	for (auto index = 0; index < cdCollection->CountNodes(); index++)
	{
		currTitle = (*cdCollection)[index].GetMediaTitle();
		currLength = (*cdCollection)[index].GetMediaLength();
		currArtist = (*cdCollection)[index].GetArtistName();

		if (oldCD.GetMediaTitle() == currTitle && oldCD.GetMediaLength() == currLength && oldCD.GetArtistName() == currArtist)
		{
			exactMatch = true;
			break;
		}
	}

	//If a match is found, process the node deletion, otherwise inform the user the input is not correct
	if (exactMatch == true)
	{
		cdCollection->DeleteNode(oldCD);
		cout << "Old CD removed!" << endl;
	}
	else
	{
		cout << "==>Unable to remove CD.  Make sure all fields match exactly!" << endl;
		return;
	}
	//------------------------------------------------------------------------------------------------------
}

/******************************************************************
* This function combines the functionality to update a cd in the
* current linkedList: cdCollection
* It prompts the user to enter the title, length, and artist before
* searching the linked list for a match.  If match is found it is removed.
* Next, it prompts the user to update the cd's fields which is essentially
* adding a new node to the list which is invisible to the user.
******************************************************************/
void UpdateCD()
{
	//Setup a check to cancel the action if no cds exist
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CD's in the collection to update." << endl;
		return;
	}

	//Setup variables to use with removing the cd
	CD update;
	string cdTitleInput;
	int cdLenInput;
	string cdArtistInput;
	
	//Prompt the user for the title, length, and artist of the cd to update
	cout << "\nWhat is the CD's title to update? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, cdTitleInput);

	cout << "What is the CD's length in minutes?" << endl;
	cout << "-> ";
	cin >> cdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || cdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> cdLenInput;
		//cin.ignore();
	}

	cout << "Who is the CD's artist to update? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, cdArtistInput);

	//Update the object variables
	update.SetMediaTitle(cdTitleInput);
	update.SetMediaLength(cdLenInput);
	update.SetArtistName(cdArtistInput);

	//Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
	//------------------------------------------------------------------------------------------------------
	//Setup validation variables
	string currTitle;
	int currLength;
	string currArtist;
	bool exactMatch = false;

	//Use a loop to step through the collection to find a match for the user input
	for (auto index = 0; index < cdCollection->CountNodes(); index++)
	{
		currTitle = (*cdCollection)[index].GetMediaTitle();
		currLength = (*cdCollection)[index].GetMediaLength();
		currArtist = (*cdCollection)[index].GetArtistName();

		if (update.GetMediaTitle() == currTitle && update.GetMediaLength() == currLength && update.GetArtistName() == currArtist)
		{
			exactMatch = true;
			break;
		}
	}

	//If a match is found, process the node deletion, otherwise inform the user the input is not correct
	if (exactMatch == true)
	{
		cdCollection->DeleteNode(update);
	}
	else
	{
		cout << "==>Unable to update CD.  Make sure all fields match exactly!" << endl;
		return;
	}
	//------------------------------------------------------------------------------------------------------


	//============Add the new node==================================
	// 
	//Collect the new title, length, and artist for the update
	cout << "\nWhat is the CD's new title? " << endl;
	cout << "-> ";
	getline(cin, cdTitleInput);

	cout << "What is the CD's new length in minutes?" << endl;
	cout << "-> ";
	cin >> cdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || cdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> cdLenInput;
		//cin.ignore();
	}

	cout << "Who is the CD's new artist? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, cdArtistInput);

	//Update the object variables
	update.SetMediaTitle(cdTitleInput);
	update.SetMediaLength(cdLenInput);
	update.SetArtistName(cdArtistInput);

	//Add the updated cd to the linked list
	cdCollection->AppendNode(update);
	cout << "CD updated!" << endl;

}

/******************************************************************
* This function displays all CDs in the current linkedList: cdCollection
* It is formatted to display in a table structure, and the rest of the
* formats can be found in CD.cpp under the operator overloads for <<.
******************************************************************/
void DisplayCDCollection()
{
	cout << "\nCD Collection ===============================================" << endl;
	cout << "Total CDs in collection: " << cdCollection->CountNodes() << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Title             || Length (minutes) || Artist:             " << endl;
	cout << "-------------------------------------------------------------" << endl;
	cdCollection->DisplayList();
}

/******************************************************************
* This function accesses all CDs in the current linkedList: cdCollection
* It accesses the AddNewSong function of each CD object stored in the list
* and allows the user to add songs on each CD if desired.
******************************************************************/
void AddSongsToCDs()
{
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CDs in the collection to add songs to." << endl;
	}
	else
	{
		//Setup a for loop to step through each CD and add songs for each one in the list
		for (int index = 0; index < cdCollection->CountNodes(); index++)
		{
			(*cdCollection)[index].AddNewSong();
		}
	}
}

/******************************************************************
* This function accesses all CDs in the current linkedList: cdCollection
* It accesses the UpdateSong function of each CD object stored in the list
* and allows the user to update the songs on each CD if desired.
******************************************************************/
void UpdateSongsOnCDs()
{
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CDs in the collection to update songs." << endl;
	}
	else
	{
		//Setup a for loop to step through each CD and update songs for each one in the list
		for (int index = 0; index < cdCollection->CountNodes(); index++)
		{
			(*cdCollection)[index].UpdateSong();
		}
	}
}

/******************************************************************
* This function accesses all CDs in the current linkedList: cdCollection
* It accesses the RemoveSong function of each CD object stored in the list
* and allows the user to remove the songs on each CD if desired.
******************************************************************/
void RemoveSongsOnCDs()
{
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CDs in the collection to remove songs." << endl;
	}
	else
	{
		//Setup a for loop to step through each CD and update songs for each one in the list
		for (int index = 0; index < cdCollection->CountNodes(); index++)
		{
			(*cdCollection)[index].RemoveSong();
		}
	}
}

/******************************************************************
* This function accesses all CDs in the current linkedList: cdCollection
* It accesses the DisplayCDSongs function of each CD object stored in the list
* and allows the user see a complete list of songs for each title.
******************************************************************/
void DisplayAllCDsSongs()
{
	if (cdCollection->CountNodes() == 0)
	{
		cout << "No CDs in the collection to display." << endl;
	}
	else
	{

		//Setup a for loop to display each song in the list using array behavior
		for (auto index = 0; index < cdCollection->CountNodes(); index++)
		{
			(*cdCollection)[index].DisplayCDSongs();
		}
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
// ACTION FUNCTIONS - DVDs
//------------------------------------------------------------------------------------------------------------------------------------------------------------

/******************************************************************
* This function adds a new dvd to the current linkedList: dvdCollection
* It prompts the user to enter the title, length, and release year before
* appending it to the linked list. 
******************************************************************/
void AddDVD()
{
	//Setup variables to use with adding the dvd
	DVD temp;
	string userInputTitle;
	int userInputNum;
	int userInputYear;

	//Prompt the user for the title, length, and release year of the new DVD
	cout << "\nWhat is the title of the DVD to Add?" << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, userInputTitle);

	cout << "What is the length in minutes of the DVD?" << endl;
	cout << "-> ";
	cin >> userInputNum;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || userInputNum < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> userInputNum;
		//cin.ignore();
	}

	cout << "What is the release year of the DVD?" << endl;
	cout << "-> ";
	cin >> userInputYear;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || userInputYear < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> userInputYear;
		//cin.ignore();
	}

	//Update the object variables
	temp.SetMediaTitle(userInputTitle);
	temp.SetMediaLength(userInputNum);
	temp.SetReleaseYear(userInputYear);

	//Add the new cd to the list
	dvdCollection->AppendNode(temp);
	cout << "New DVD added!" << endl;
}

/******************************************************************
* This function removes a current dvd from the current linkedList: dvdCollection
* It prompts the user to enter the title, length, and release year before
* searching the linked list for a match.  If match is found it is removed.
******************************************************************/
void RemoveDVD()
{
	//Setup a check to cancel the action if no cds exist
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No DVD's in the collection to remove." << endl;
		return;
	}

	//Setup variables to use with removing the cd
	DVD oldDVD;
	string dvdTitleInput;
	int dvdLenInput;
	int dvdYearInput;

	//Prompt the user for the title, length, and release year of the old dvd
	cout << "\nWhat is the title of the DVD to remove? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, dvdTitleInput);

	cout << "What is its length in minutes to remove?" << endl;
	cout << "-> ";
	cin >> dvdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdLenInput;
		//cin.ignore();
	}

	cout << "What is the release year of the DVD to remove?" << endl;
	cout << "-> ";
	cin >> dvdYearInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdYearInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdYearInput;
		//cin.ignore();
	}

	//Update the object variables
	oldDVD.SetMediaTitle(dvdTitleInput);
	oldDVD.SetMediaLength(dvdLenInput);
	oldDVD.SetReleaseYear(dvdYearInput);

	//Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
	//------------------------------------------------------------------------------------------------------
	//Setup validation variables
	string currTitle;
	int currLength;
	int currYear;
	bool exactMatch = false;

	//Use a loop to step through the collection to find a match for the user input
	for (auto index = 0; index < dvdCollection->CountNodes(); index++)
	{
		currTitle = (*dvdCollection)[index].GetMediaTitle();
		currLength = (*dvdCollection)[index].GetMediaLength();
		currYear = (*dvdCollection)[index].GetReleaseYear();

		if (oldDVD.GetMediaTitle() == currTitle && oldDVD.GetMediaLength() == currLength && oldDVD.GetReleaseYear() == currYear)
		{
			exactMatch = true;
			break;
		}
	}

	//If a match is found, process the node deletion, otherwise inform the user the input is not correct
	if (exactMatch == true)
	{
		dvdCollection->DeleteNode(oldDVD);
		cout << "Old DVD removed!" << endl;
	}
	else
	{
		cout << "==>Unable to remove DVD.  Make sure all fields match exactly!" << endl;
		return;
	}
	//------------------------------------------------------------------------------------------------------
}

/******************************************************************
* This function combines the functionality to update a dvd in the
* current linkedList: dvdCollection
* It prompts the user to enter the title, length, and release year before
* searching the linked list for a match.  If match is found it is removed.
* Next, it prompts the user to update the dvd's fields which is essentially
* adding a new node to the list which is invisible to the user.
******************************************************************/
void UpdateDVD()
{
	//Setup a check to cancel the action if no cds exist
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No CD's in the collection to update." << endl;
		return;
	}

	//Setup variables to use with removing the cd
	DVD update;
	string dvdTitleInput;
	int dvdLenInput;
	int dvdYearInput;

	//Prompt the user for the title, length, and artist of the cd to update
	cout << "\nWhat is the DVD's title to update? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, dvdTitleInput);

	cout << "What is the DVD's length in minutes?" << endl;
	cout << "-> ";
	cin >> dvdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdLenInput;
		//cin.ignore();
	}

	cout << "What is the DVD's release year?" << endl;
	cout << "-> ";
	cin >> dvdYearInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdYearInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdYearInput;
		//cin.ignore();
	}

	//Update the object variables
	update.SetMediaTitle(dvdTitleInput);
	update.SetMediaLength(dvdLenInput);
	update.SetReleaseYear(dvdYearInput);

	//Validate the user's input to avoid crashing the program when deleting a node (exact matches required).
	//------------------------------------------------------------------------------------------------------
	//Setup validation variables
	string currTitle;
	int currLength;
	int currYear;
	bool exactMatch = false;

	//Use a loop to step through the collection to find a match for the user input
	for (auto index = 0; index < dvdCollection->CountNodes(); index++)
	{
		currTitle = (*dvdCollection)[index].GetMediaTitle();
		currLength = (*dvdCollection)[index].GetMediaLength();
		currYear = (*dvdCollection)[index].GetReleaseYear();

		if (update.GetMediaTitle() == currTitle && update.GetMediaLength() == currLength && update.GetReleaseYear() == currYear)
		{
			exactMatch = true;
			break;
		}
	}

	//If a match is found, process the node deletion, otherwise inform the user the input is not correct
	if (exactMatch == true)
	{
		dvdCollection->DeleteNode(update);
	}
	else
	{
		cout << "==>Unable to update DVD.  Make sure all fields match exactly!" << endl;
		return;
	}
	//------------------------------------------------------------------------------------------------------


	//============Add the new node==================================
	// 
	//Collect the new title, length, and artist for the update
	cout << "\nWhat is the DVD's new title? " << endl;
	cout << "-> ";
	cin.ignore();
	getline(cin, dvdTitleInput);

	cout << "What is the DVD's new length in minutes?" << endl;
	cout << "-> ";
	cin >> dvdLenInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdLenInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdLenInput;
		//cin.ignore();
	}

	cout << "What is the DVD's new release year?" << endl;
	cout << "-> ";
	cin >> dvdYearInput;
	//cin.ignore();
	//Validate the input
	while (cin.fail() || dvdYearInput < 0)
	{
		cout << "Not a valid choice!  Please enter 0 or higher minutes." << endl;
		cout << "->";
		cin.clear();
		cin.ignore();
		cin >> dvdYearInput;
		//cin.ignore();
	}

	//Update the object variables
	update.SetMediaTitle(dvdTitleInput);
	update.SetMediaLength(dvdLenInput);
	update.SetReleaseYear(dvdYearInput);

	//Add the updated cd to the linked list
	dvdCollection->AppendNode(update);
	cout << "DVD updated!" << endl;

}

/******************************************************************
* This function displays all DVDs in the current linkedList: dvdCollection
* It is formatted to display in a table structure, and the rest of the
* formats can be found in DVD.cpp under the operator overloads for <<.
******************************************************************/
void DisplayDVDCollection()
{
	cout << "\nDVD Collection ===============================================" << endl;
	cout << "Total DVDs in collection: " << dvdCollection->CountNodes() << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Title             || Length (minutes) || Release Year        " << endl;
	cout << "-------------------------------------------------------------" << endl;
	dvdCollection->DisplayList();
}

/******************************************************************
* This function accesses all DVDs in the current linkedList: dvdCollection
* It accesses the AddNewActor function of each DVD object stored in the list
* and allows the user to add actors/actresses on each DVD if desired.
******************************************************************/
void AddActorsToDVDs()
{
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No DVDs in the collection to add actors/actresses to." << endl;
	}
	else
	{
		//Setup a for loop to step through each DVD and add actors/actresses for each one in the list
		for (int index = 0; index < dvdCollection->CountNodes(); index++)
		{
			(*dvdCollection)[index].AddNewActor();
		}
	}
}

/******************************************************************
* This function accesses all DVDs in the current linkedList: dvdCollection
* It accesses the UpdateActor function of each DVD object stored in the list
* and allows the user to update the actors/actresses on each DVD if desired.
******************************************************************/
void UpdateActorsOnDVDs()
{
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No DVDs in the collection to update actors/actresses." << endl;
	}
	else
	{
		//Setup a for loop to step through each DVD and update actors/actresses for each one in the list
		for (int index = 0; index < dvdCollection->CountNodes(); index++)
		{
			(*dvdCollection)[index].UpdateActor();
		}
	}
}

/******************************************************************
* This function accesses all DVDs in the current linkedList: dvdCollection
* It accesses the RemoveActor function of each DVD object stored in the list
* and allows the user to remove the actors/actresses on each DVD if desired.
******************************************************************/
void RemoveActorsOnDVDs()
{
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No DVDs in the collection to remove actors/actresses." << endl;
	}
	else
	{
		//Setup a for loop to step through each DVD and update actors/actresses for each one in the list
		for (int index = 0; index < dvdCollection->CountNodes(); index++)
		{
			(*dvdCollection)[index].RemoveActor();
		}
	}
}

/******************************************************************
* This function accesses all DVDs in the current linkedList: dvdCollection
* It accesses the DisplayDVDActors function of each DVD object stored in the list
* and allows the user see a complete list of actors/actresses for each title.
******************************************************************/
void DisplayAllDVDsActors()
{
	if (dvdCollection->CountNodes() == 0)
	{
		cout << "No DVDs in the collection to display." << endl;
	}
	else
	{

		//Setup a for loop to display each actor in the list using array behavior
		for (auto index = 0; index < dvdCollection->CountNodes(); index++)
		{
			(*dvdCollection)[index].DisplayDVDActors();
		}
	}
}
