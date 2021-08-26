/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: CruiseShip.h

***************************************************************************************************************************/

#include "CruiseShip.h"

using namespace std;



//Consructors
/*************************************
* Default constructor
**************************************/
CruiseShip::CruiseShip() : Ship()
{
    passengerMax = 0;
}

/******************************************************************
* Parameter constructor that accepts the ship name and year built and
* the max passengers allowed on the ship.
******************************************************************/
CruiseShip::CruiseShip(string sName, int yBuilt, int maxPass) : Ship(sName, yBuilt)
{
    passengerMax = maxPass;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the passengerMax data member.
******************************************************************/
int CruiseShip::GetMaxPassengers() const
{
    return passengerMax;
}

/******************************************************************
* This function stores the value in the parameter to the passengerMax data member.
******************************************************************/
void CruiseShip::SetMaxPassengers(int maxPass)
{
    passengerMax = maxPass;
}


//Print function
/******************************************************************
* This function prints the current information stored in passengerMax
and the ship name from the Ship base class.
******************************************************************/
void CruiseShip::Print()
{
    cout << "\nShip Name: " << GetShipName() << endl;
    cout << "Maximum Number of Passengers: " << GetMaxPassengers() << endl;
}