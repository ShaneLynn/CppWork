/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class creates an object called DVD and has data members that store details on the dvd such as actors/actresses.  It inherits from
 the Media class to get the title and length.  And, it has a specific data member for the release year of the DVD.

 Required Files: Media.h, LinkedList.h
 Description File: DVD.cpp

***************************************************************************************************************************/

#pragma once
#include "Media.h"
#include "LinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>

struct Cast
{
	string actorName;
	string characterName;
};


class DVD : public Media
{
public:

	//CONSTRUCTORS
	DVD();								//Default
	DVD(string, int, int);				//Parameter

	//ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
	int GetReleaseYear() const;
	void SetReleaseYear(int);
	string GetCurrActorName() const;
	string GetCurrActorChars() const;
	void SetCurrActor(string, string);

	//ACTION FUNCTIONS
	void AddNewActor();
	void RemoveActor();
	void UpdateActor();
	void DisplayDVDActors();

	//OVERLOADED OPERATORS
	friend ostream& operator << (ostream&, const Cast&);
	friend ostream& operator << (ostream&, const DVD&);
	bool operator == (DVD&) const;
	bool operator != (DVD&) const;


private:

	//DATA MEMBERS
		 //Setup the data members used by the functions
	int releaseYear;
	Cast actor;
	LinkedList<Cast>* actors = new LinkedList<Cast>();

};
