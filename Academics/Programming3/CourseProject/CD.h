/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class creates an object called CD and has data members that store details on the cd such as songs.  It inherits from
 the Media class to get the title and length.  And, it has a specific data member for the artist of the CD.

 Required Files: Media.h, LinkedList.h
 Description File: CD.cpp

***************************************************************************************************************************/

#pragma once
#include "Media.h"
#include "LinkedList.h"
#include <iomanip>
#include <iostream>
#include <string>

struct Song
{
	string songTitle;
	int songLength = 0;
};


class CD : public Media
{

public:

	//CONSTRUCTORS
	CD();								//Default
	CD(string, int, string);			//Parameter
	
	//ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
	string GetArtistName() const;
	void SetArtistName(string);
	string GetCurrSongTitle() const;
	int GetCurrSongLen() const;
	void SetCurrSong(string, int);
	
	//ACTION FUNCTIONS
	void AddNewSong();
	void RemoveSong();
	void UpdateSong();
	void DisplayCDSongs();

	//OVERLOADED OPERATORS
	friend ostream& operator << (ostream&, const Song&);
	friend ostream& operator << (ostream&, const CD&);
	bool operator == (CD&) const;
	bool operator != (CD&) const;


private:
	
	//DATA MEMBERS
		 //Setup the data members used by the functions
	string artistName;
	Song song;
	LinkedList<Song>* songs = new LinkedList<Song>();
	
};
