/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 7
 Created: 6/16/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores and calculates the number of days an employee has available for time off based on the hours provided.

 Description File: NumDays.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

class NumDays
{
public:
	
    //Constructors
    NumDays();
	NumDays(double);
	
    //Accessors and Mutators (setters and getters)
    double GetHours() const;
	void SetHours(double);

	double GetDays() const;
    void SetDays(double);

    //Overloaded operators 
    NumDays operator + (const NumDays &);
    NumDays operator - (const NumDays &);

    NumDays operator ++ ();
    NumDays operator ++ (int);

    NumDays operator -- ();
    NumDays operator -- (int);

    NumDays operator = (const NumDays &);
    
    //Overloaded output stream operator designated as a friend
    friend ostream &operator << (ostream &, const NumDays &);


private:
	double hours;
	double days;

};