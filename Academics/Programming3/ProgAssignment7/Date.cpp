/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: Date.h

 Required Files: Date.h

***************************************************************************************************************************/

#include "Date.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
Date::Date()
{
	month = 1;
	day = 1;
	year = 1925;
}

/******************************************************************
* Parameter constructor that accepts the month, day , and year as input.
******************************************************************/
Date::Date(int monthIn, int dayIn, int yearIn)
{
	month = monthIn;
	day = dayIn;
	year = yearIn;
}

//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------


/******************************************************************
* This function gets the value stored in the data member: month
******************************************************************/
int Date::GetMonth() const
{
	return month;
}

/******************************************************************
* This function sets the value stored in the data member: month
******************************************************************/
void Date::SetMonth(int monthIn)
{
    month = monthIn;
}

/******************************************************************
* This function gets the value stored in the data member: day
******************************************************************/
int Date::GetDay() const
{
	return day;
}

/******************************************************************
* This function sets the value stored in the data member: day
******************************************************************/
void Date::SetDay(int dayIn)
{
    day = dayIn;
}

/******************************************************************
* This function gets the value stored in the data member: year
******************************************************************/
int Date::GetYear() const
{
	return year;
}

/******************************************************************
* This function sets the value stored in the data member: year
******************************************************************/
void Date::SetYear(int yearIn)
{
    year = yearIn;
}



//----------------------------------------------------------------
// ACTION FUNCTIONS
//----------------------------------------------------------------

/******************************************************************
* This function uses a switch to transform the integer into a month
* name.  Once that is finished, it prints out the formatted date
* with the month name.
******************************************************************/
string Date::PrintDate() const
{
    string monthName;
    string final;

    switch (month)
    {

    case 1:
        monthName = "January";
        break;

    case 2:
        monthName = "February";
        break;

    case 3:
        monthName = "March";
        break;

    case 4:
        monthName = "April";
        break;

    case 5:
        monthName = "May";
        break;

    case 6:
        monthName = "June";
        break;

    case 7:
        monthName = "July";
        break;

    case 8:
        monthName = "August";
        break;

    case 9:
        monthName = "September";
        break;

    case 10:
        monthName = "October";
        break;

    case 11:
        monthName = "November";
        break;

    case 12:
        monthName = "December";
        break;
    }
    
    final = monthName + " " + to_string(day) + ", " + to_string(year);

    return final;
}


//OVERLOADED OPERATORS

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/

ostream& operator << (ostream& outStream, const Date& object)
{
    outStream << object.PrintDate() << endl;
    
    return outStream;
}