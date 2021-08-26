/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class simulates a parking meter object.  It holds the amount of parking time purchased by users of the parked car class.

 Required Files: 
 Description File: ParkingMeter.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class ParkingMeter
{
public:

    //Constructors
    ParkingMeter();         //Default
    ParkingMeter(int);      //Parameter

    //Accessors and Mutators (setters and getters)
    int GetMinutesPurchased() const;
    void SetMinutesPurchased(int);


    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const ParkingMeter&);

private:

    //Declare Data Members
    int purchasedMinutes;
};