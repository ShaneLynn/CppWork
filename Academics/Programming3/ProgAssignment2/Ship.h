/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 2
 Created: 7/04/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This base class sets up data used by all kinds of ships that will be dreived from it.

 Required Files:
 Description File: Ship.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ship
{
public:
	//Constructors
	Ship();
	Ship(string, int);

	//Accessors and Mutators (setters and getters)
	string GetShipName() const;
	void SetShipName(string);

	int GetYearBuilt() const;
	void SetYearBuilt(int);

	//Print function
	virtual void Print();

private:
	//Declare data members
	string shipName;
	int yearBuilt;
};