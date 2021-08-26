/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores ppolice officer data and simulates a traffic patrol to examine a parked car object and the paid meter.


 Required Files: ParkingTicket.h, ParkingTicket.cpp
 Description File: PoliceOfficer.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "ParkingTicket.h"
#include "ParkingMeter.h"

using namespace std;

class PoliceOfficer
{
public:

    //Constructors
    PoliceOfficer();                    //Default
    PoliceOfficer(string, string);      //Parameter

    //Accessors and Mutators (setters and getters)
    string GetOfficerName() const;
    void SetOfficerName(string);

    string GetBadgeNumber() const;
    void SetBadgeNumber(string);

    //Calculation function
    ParkingTicket *Patrol(ParkedCar, ParkingMeter);
    

    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const PoliceOfficer&);

private:

    //Declare Data Members
    ParkingTicket* officerTicketPTR = new ParkingTicket;
    string officerName;
    string badgeNumber;
    

};