/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: CargoShip.h

***************************************************************************************************************************/

#include "CargoShip.h"

using namespace std;



//Consructors
/*************************************
* Default constructor
**************************************/
CargoShip::CargoShip() : Ship()
{
    cargoTonCapacity = 0;
}

/******************************************************************
* Parameter constructor that accepts the ship name and year built and
* the maximum cargo in tons the ship can safely hold
******************************************************************/
CargoShip::CargoShip(string sName, int yBuilt, int maxCargo) : Ship(sName, yBuilt)
{
    cargoTonCapacity = maxCargo;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the cargoTonCapacity data member.
******************************************************************/
int CargoShip::GetMaxCargoCapacity() const
{
    return cargoTonCapacity;
}

/******************************************************************
* This function stores the value in the parameter to the cargoTonCapacity data member.
******************************************************************/
void CargoShip::SetMaxCargoCapacity(int maxCargo)
{
    cargoTonCapacity = maxCargo;
}


//Print function
/******************************************************************
* This function prints the current information stored in cargoTonCapacity
and the ship name from the Ship base class.
******************************************************************/
void CargoShip::Print()
{
    cout << "\nShip Name: " << GetShipName() << endl;
    cout << "Cargo Capacity (tons): " << GetMaxCargoCapacity() << endl;
}