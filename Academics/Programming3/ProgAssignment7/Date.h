/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class sets up three integer variables (month, day, and year) that can be used to store a date.


 Required Files:
 Description File: Date.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date
{

public:

    //CONSTRUCTORS
    Date();
    Date(int, int, int);

    //ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
    int GetMonth() const;
    void SetMonth(int);

    int GetDay() const;
    void SetDay(int);

    int GetYear() const;
    void SetYear(int);

    //ACTION FUNCTIONS
    string PrintDate() const;

    //OVERLOADED OPERATORS
    friend ostream& operator << (ostream&, const Date&);


private:

    //DATA MEMBERS
        //Setup the data members used by the functions
    int month;
    int day;
    int year;
};