/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: Ship.h

***************************************************************************************************************************/


#include "Ship.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
Ship::Ship()
{
    shipName = "";
    yearBuilt = 0;
}

/******************************************************************
* Parameter constructor that accepts the ship name and year built
******************************************************************/
Ship::Ship(string sName, int yBuilt)
{
    shipName = sName;
    yearBuilt = yBuilt;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the shipName data member.
******************************************************************/
string Ship::GetShipName() const
{
    return shipName;
}

/******************************************************************
* This function stores the value in the parameter to the shipName data member.
******************************************************************/
void Ship::SetShipName(string sName)
{
    shipName = sName;
}

/******************************************************************
* This function gets the value stored in the yearBuilt data member.
******************************************************************/
int Ship::GetYearBuilt() const
{
    return yearBuilt;
}

/******************************************************************
* This function stores the value in the parameter to the yearBuilt data member.
******************************************************************/
void Ship::SetYearBuilt(int yBuilt)
{
    yearBuilt = yBuilt;
}


//Print function
/******************************************************************
* This function prints the current information stored in shipName and yearBuilt
data members.
******************************************************************/
void Ship::Print()
{
    cout << "\nShip Name: " << GetShipName() << endl;
    cout << "Year Built: " << GetYearBuilt() << endl;
}

