/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------
 Description:
 This program uses inheritance to create a class hierarcy from three classes: Ship, CruiseShip, and CargoShip.  It sets up an array that holds
 six pointer elements of the Ship class which are dynamically allocated to objects from those classes.

 The program uses the methods DisplayShipInfo and FindOldest which then operate on the objects.  The first method cycles through the array and calls the print method
 found in each class.  The second method loops through the array twice compares the year built field of each object to determine which one is older and which one is
 the newest.  It then displays both results to the user.


 Class File used: Ship.h, Ship.cpp, CruiseShip.h, CruiseShip.cpp, CargoShip.h, CargoShip.cpp

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"

using namespace std;

//Prototypes for functions used in main
void DisplayShipInfo(Ship *[]);
void FindOldest(Ship *[]);

//Declare array size to hold the total number of ships in the fleet
const int totalShips = 6;

//The main program function
int main()
{

    //Prompt the user with a welcome
    cout << "Welcome to the Eastcoast Shipping Fleet Information system." << endl;
    cout << "--The window may need to be expanded to see all results." << endl;
    cout << "\n";


    //Setup the pointer array using the fleet size from the totalShips global.
    //Each ship is initialized when setting up the array since the fleet is small
    Ship* shipArray[totalShips] = { new Ship("Tiny Tug", 11), new Ship("Speed King", 7) 
                                    , new CruiseShip("Sunset Ocean", 17, 1125), new CruiseShip("Starlight Passages", 19, 1350)
                                    , new CargoShip("Ocean Trucker", 6, 10250), new CargoShip("Neptune's Hauler", 21, 8475)
                                  };
    

    //Call the DisplayShipInfo method to cycle through all of the ships and print their specific data
    cout << "---Fleet Report--- " << endl;
    DisplayShipInfo(shipArray);


    //Call the FindOldest method to check all of the ships and display a message of the one with the highest and lowest age
    cout << "\n---Maintenance Report --- " << endl;
    FindOldest(shipArray);
    

    //Prompt to close the program window
    cout << "\nThank you for using the system.  Press the enter key to close...";

    cin.get();

    return 0;
}

/*****************************************************************************
This function cycles through the pointers array of ship objects and calls the
print method to display the ship information.
******************************************************************************/
void DisplayShipInfo(Ship *ships[])
{
    //Setup a loop to step through the array and call the print function of each object
    for (int index = 0; index < totalShips; index++)
    {
        ships[index]->Print();
    }
}

/*****************************************************************************
This function cycles through the pointers in the array of ship objects and compares
the year built of each one.  Once the oldest is found, it displays a message
stating the oldest with the ship name and year built.  It repeats the process for
the newest ship in the fleet.
******************************************************************************/
void FindOldest(Ship *ships[])
{
    int elementIDOld = 0;           //Holds the element ID of the ship with the highest year built
    int elementIDNew = 0;           //Holds the element ID of the ship with the lowest year built

    //Set the yearBuilt field to the first element 
    int yearBuilt = ships[0]->GetYearBuilt();

    //Setup the loop to find the oldest ship in the fleet
    for (int index = 0; index < totalShips; index++)
    {

        if (ships[index]->GetYearBuilt() > yearBuilt)
        {
            yearBuilt = ships[index]->GetYearBuilt();
            elementIDOld = index;
        }
    }

    //Setup the loop to find the newest ship in the fleet
    for (int index = 0; index < totalShips; index++)
    {

        if (ships[index]->GetYearBuilt() < yearBuilt)
        {
            yearBuilt = ships[index]->GetYearBuilt();
            elementIDNew = index;
        }
    }

    //Display the results to the user
    cout << "\nThe oldest ship in the fleet is: " << ships[elementIDOld]->GetShipName() << " built " << ships[elementIDOld]->GetYearBuilt() << " years ago!" << endl;
    cout << "The newest ship in the fleet is: " << ships[elementIDNew]->GetShipName() << " built " << ships[elementIDNew]->GetYearBuilt() << " years ago!" << endl;
}