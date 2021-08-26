/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores cargo capcacity information about a cargo ship based on the ship class.  It adds data and methods for the maximum
 cargo this type of ship can hold.

 Required Files: Ship.h, Ship.cpp
 Description File: CargoShip.cpp

***************************************************************************************************************************/


#pragma once
#include "Ship.h"

class CargoShip : public Ship
{
public:
	//Constructors
	CargoShip();
	CargoShip(string, int, int);

	//Accessor and Mutator
	int GetMaxCargoCapacity() const;
	void SetMaxCargoCapacity(int);

	//Print function
	void Print() override;

private:
	//Declare data members
	int cargoTonCapacity;

};
