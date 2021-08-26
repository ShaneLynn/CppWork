/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 8 - Course Project
 Created: 8/12/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: Media.h

***************************************************************************************************************************/

#include "Media.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
Media::Media()
{
	mediaTitle = "";
	mediaLength = 0;
}

/******************************************************************
* Parameter constructor that accepts the month, day , and year as input.
******************************************************************/
Media::Media(string title, int length)
{
	mediaTitle = title;
	mediaLength = length;
}


//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------

/******************************************************************
* This function gets the value stored in the data member: MediaTitle
******************************************************************/
string Media::GetMediaTitle() const
{
	return mediaTitle;
}

/******************************************************************
* This function sets the value stored in the data member: MediaTitle
******************************************************************/
void Media::SetMediaTitle(string title)
{
	mediaTitle = title;
}

/******************************************************************
* This function sets the value stored in the data member: MediaTitle
******************************************************************/
int Media::GetMediaLength() const
{
	return mediaLength;
}

/******************************************************************
* This function sets the value stored in the data member: MediaTitle
******************************************************************/
void Media::SetMediaLength(int length)
{
	mediaLength = length;
}