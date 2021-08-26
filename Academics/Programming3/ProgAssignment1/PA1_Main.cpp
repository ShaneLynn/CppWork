/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------
 UPDATE
 Description:
 This program simulates a traffic officer patroling and finding parked cars.  The officer then examines the parked cars and
 the parking meter to see if the car is parked there with an expired meter.  If it is illegally parked, the officer will issue a ticket to
 the parked car before moving to check the next car in the line.  It uses multiple classes (ParkedCar <which includes Car>, ParkingMeter,
 ParkingTicket, and PoliceOfficer that interact with each other.

 The program tests the interactions and functions of each class by providing 3 different vehicles with different parking times.  The parking
 time meter is set at 60 minutes for all vehicles.  An array is setup to store the parked cars which simulates sequential parking spaces.  
 The test cases have 1 vehicle that does not get a ticket, another that gets a ticket  for the first hour of expriation, and the 3rd vehicle
 will get a ticket for more than 1 hour of expired time.


 Class File used: ParkedCar.h, ParkedCar.cpp, ParkingMeter.h, ParkingMeter.cpp, ParkingTicket.h, ParkingTicket.cpp, PoliceOfficer.h, PoliceOfficer.cpp

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;


//The main program function
int main()
{

    //Prompt the user with a welcome
    cout << "Welcome to the parking violation & ticket simulation." << endl;
    cout << "--The window may need to be expanded to see all results." << endl;
    cout << "\n";

    //Declare array size and the array to hold the parked cars
    const int parkedCars = 3;
    ParkedCar parkedList[parkedCars];

    //Create instances of the parked cars using parmaters
    ParkedCar parked1("Honda", "Odyssey", "Silver", "123XYZ", 90);
    ParkedCar parked2("Toyota", "Corolla", "Tan", "ZXY321", 185);
    ParkedCar parked3("Ford", "Explorer", "Green", "Roady1", 30);

    //Load the cars into the array (parking spots)
    parkedList[0] = parked1;
    parkedList[1] = parked2;
    parkedList[2] = parked3;

    //Create an instance of the parking meter with 60 minutes purchased for each space
    ParkingMeter spaceMeter(60);

    //Create a police officer object to conduct the patrol and write tickets
    PoliceOfficer officer("Martin Riggs", "D435");

    //Create the pointer to hold the ticket information
    ParkingTicket* ticket1 = nullptr;
    
    //Display to the user that the officer is starting the patrol (begin array access and patrol method)
    cout << "The traffic officer on patrol comes across the parked cars and finds out the following..." << endl;
    
    //Create a for loop to cycle through all 3 test cases (have a car that is not given a ticket <parked3>,
    //have a car receive a ticket within an hour <parked1>, and have a car receive a ticket for more than one hour <parked2>.
    for (int index = 0; index < parkedCars; index++)
    {
        cout << "\nChecking parked car " << index+1 << " and comparing meter time:" << endl;
        ticket1 = officer.Patrol(parkedList[index], spaceMeter);

        if (ticket1->GetIllegalMinutes() > 0)
        {
            cout << "The officer begins writing a ticket..." << endl;
            cout << officer;
            cout << spaceMeter;
            cout << *ticket1;
        }
        else
        {
            cout << "No parking violations for this vehicle." << endl;
        }

    }
    
    //Indicate the end of the array (parking spots)
    cout << "\nThe officer finishes the patrol and heads home." << endl;

    //Maintenance the pointer memory
    delete ticket1;
    ticket1 = nullptr;
    

    //Prompt to close the program window
    cout << "\nThank you for using the system.  Press the enter key to close...";
    
    cin.get();

    return 0;
}