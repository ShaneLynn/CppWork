/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 7
 Created: 6/16/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores and calculates the total time an employee has available to use for different types of time off:
 vacation, sick, and unpaid.

 Description File: TimeOff.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "NumDays.h"

using namespace std;

class TimeOff
{

public:

    //Constructors
    TimeOff();
    TimeOff(string, int, NumDays, NumDays, NumDays, NumDays, NumDays, NumDays);

    //Accessors and Mutators (setters and getters)
    string GetName() const;
    void SetName(string);

    int GetEmpNum() const;
    void SetEmpNum(int);

    NumDays GetMaxSickDays() const;
    void SetMaxSickDays(NumDays);

    NumDays GetSickTaken() const;
    void SetSickTaken(NumDays);

    NumDays GetMaxVacation() const;
    void SetMaxVacation(NumDays);

    NumDays GetVacTaken() const;
    void SetVacTaken(NumDays);

    NumDays GetMaxUnpaid() const;
    void SetMaxUnpaid(NumDays);

    NumDays GetUnpaidTaken() const;
    void SetUnpaidTaken(NumDays);


    //Overloaded operators  
    TimeOff operator = (const TimeOff&);


    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const TimeOff&);


private:
    //Declare data members
    string name;
    int empNum;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
};