/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 7
 Created: 6/16/2021
  

***************************************************************************************************************************/

#include "NumDays.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
NumDays::NumDays()
{
	hours = 0;
	days = 0;
}

/******************************************************************
* Parameter constructor that accepts hours and calculates the days
******************************************************************/
NumDays::NumDays(double numHours)
{
	hours = numHours;
	days = numHours / 8.0;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the hours data member.
******************************************************************/
double NumDays::GetHours() const
{
    return hours;
}

/******************************************************************
* This function stores the value in the parameter to the hours data member.
******************************************************************/
void NumDays::SetHours(double totalHours)
{
    hours = totalHours;
}

/******************************************************************
* This function gets the value stored in the days data member.
******************************************************************/
double NumDays::GetDays() const
{
    return days;
}

/******************************************************************
* This function stores the value in the parameter to the days data member.
******************************************************************/
void NumDays::SetDays(double totalDays)
{
    days = totalDays;
}


//Overloaded Operators
/******************************************************************
* This function overloads the + (addition) operator to add two 
class objects togther.
******************************************************************/
NumDays NumDays::operator + (const NumDays &right)
{
    NumDays temp;

    temp.hours = hours + right.hours;
    temp.days = days + right.days;
    return temp;
}

/******************************************************************
* This function overloads the - (subtraction) operator to subtract
two class objects togther.
******************************************************************/
NumDays NumDays::operator - (const NumDays &right)
{
    NumDays temp;

    temp.hours = hours - right.hours;
    temp.days = days - right.days;
    return temp;
}

/******************************************************************
* This function overloads the ++ (prefix mode) operator to increase
a class object based on another object's totals.
******************************************************************/
NumDays NumDays::operator ++ ()
{
    NumDays temp(++hours);
    days = temp.days;
    return temp;
}

/******************************************************************
* This function overloads the ++ (postfix mode) operator to increase
a class object based on another object's totals.
******************************************************************/
NumDays NumDays::operator ++ (int)
{
    NumDays temp(this->GetHours());
    hours = temp.hours++;
    days = hours / 8;
    return temp;
}

/******************************************************************
* This function overloads the -- (prefix mode) operator to decrease
a class object based on another object's totals.
******************************************************************/
NumDays NumDays::operator -- ()
{
    NumDays temp(--hours);
    days = temp.days;
    return temp;
}

/******************************************************************
* This function overloads the -- (postfix mode) operator to decrease
a class object based on another object's totals.
******************************************************************/
NumDays NumDays::operator -- (int)
{
    NumDays temp(this->GetHours());
    hours = temp.hours--;
    days = hours / 8;
    return temp;
}

/******************************************************************
* This function overloads the = (assignment) operator to copy the
values from one class object to the other.
******************************************************************/
NumDays NumDays::operator = (const NumDays &right) 
{
    hours = right.hours;
    days = right.days;
    return *this;
}

/******************************************************************
* This function overloads the << (outgoing stream) operator to 
display the values from the hours and days class object's data members.
******************************************************************/
ostream &operator << (ostream &outStream, const NumDays &object)
{
    outStream << "Available Hours: " << object.hours 
              << "\nAvailable Days: " << object.days
              << endl;
    return outStream;
}