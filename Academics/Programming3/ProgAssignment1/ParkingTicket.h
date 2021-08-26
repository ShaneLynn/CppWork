/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores information needed to simulate a parking ticket and calculates the fine based on illegal minutes parked.

 Required Files: ParkedCar.h, ParkedCar.cpp
 Description File: ParkingTicket.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "ParkedCar.h"

using namespace std;

class ParkingTicket
{
public:

    //Constructors
    ParkingTicket();                    //Default
    ParkingTicket(ParkedCar, int);      //Parameter

    //Accessors and Mutators (setters and getters)
    ParkedCar GetParkedCar() const;
    void SetParkedCar(ParkedCar);

    int GetIllegalMinutes() const;
    void SetIllegalMinutes(int);

    double GetParkingFine() const;
    void SetParkingFine(int);

    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const ParkingTicket&);

private:

    //Declare Data Members
    ParkedCar vehicle;
    double parkingFine;
    int illegalMinutes;

    //Private calculation
    double CalculateParkingFine(int);
    
};