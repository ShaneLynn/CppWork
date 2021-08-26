/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores passenger information about a cruise ship based on the ship class.  It adds data and methods for the maximum
 passengers this type of ship can hold.

 Required Files: Ship.h, Ship.cpp
 Description File: CruiseShip.cpp

***************************************************************************************************************************/


#pragma once
#include "Ship.h"

class CruiseShip : public Ship
{
public:
	//Constructors
	CruiseShip();
	CruiseShip(string, int, int);

	//Accessor and Mutator
	int GetMaxPassengers() const;
	void SetMaxPassengers(int);

	//Print function
	void Print() override;

private:
	//Declare data members
	int passengerMax;

};
