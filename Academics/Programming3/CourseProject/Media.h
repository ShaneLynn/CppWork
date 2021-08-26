/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class is a base class that holds common data between items like DVD or CD objects called Media.

 Required Files: 
 Description File: Media.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

class Media
{
public:

	//CONSTRUCTORS
	Media();						//Default
	Media(string, int);				//Parameter

	//ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
	string GetMediaTitle() const;
	void SetMediaTitle(string);
	int GetMediaLength() const;
	void SetMediaLength(int);

protected:

	//DATA MEMBERS
	   //Setup the data members used by the functions
	string mediaTitle;				//Holds the name or title of a cd or dvd
	int mediaLength;				//Holds the length in minutes of the movie or cd

};