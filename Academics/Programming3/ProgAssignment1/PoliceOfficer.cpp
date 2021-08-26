/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: PoliceOfficer.h

***************************************************************************************************************************/


#include "PoliceOfficer.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
PoliceOfficer::PoliceOfficer()
{
    officerName = " ";
    badgeNumber = " ";
    
}

/******************************************************************
* Parameter constructor that accepts two strings for the officer's
* name and their badge number.
******************************************************************/
PoliceOfficer::PoliceOfficer(string oName, string bNumber)
{
    officerName = oName;
    badgeNumber = bNumber;
}

//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the officer name data member.
******************************************************************/
string PoliceOfficer::GetOfficerName() const
{
    return officerName;
}

/******************************************************************
* This function stores the value in the parameter for the officer
name data member.
******************************************************************/
void PoliceOfficer::SetOfficerName(string oName)
{
    officerName = oName;
}

/******************************************************************
* This function gets the value stored in the badge number data member.
******************************************************************/
string PoliceOfficer::GetBadgeNumber() const
{
    return badgeNumber;
}

/******************************************************************
* This function stores the value in the parameter to the badge number
data member.
******************************************************************/
void PoliceOfficer::SetBadgeNumber(string bNumber)
{
    badgeNumber = bNumber;
}


//Calculation Functions
/******************************************************************
* This function simulates the officer on patrol for parking violations.
It collects the objects for the parked car and the parking meter and
compares the values of the purchased meter minutes and the total minutes
the car has been parked.  This is a pointer based function, so it returns
a pointer to the parking ticket object.
******************************************************************/
ParkingTicket *PoliceOfficer::Patrol(ParkedCar pCar, ParkingMeter pMeter)
{
    //Setup temp objects to hold the input
    ParkedCar vehicle = pCar;
    ParkingMeter meter = pMeter;       

    int parkedMinutes = vehicle.GetMinutesParked();         //Get the minutes the car has been parked
    int meterMinutes = meter.GetMinutesPurchased();         //Get the minutes purchased on the meter
    int illMinutes = 0;                                     //Initialize the illegal minutes parked

    //Compare the minutes purchased to the minutes parked to get the total illegal minutes parked
    if (parkedMinutes > meterMinutes)
    {
        illMinutes = parkedMinutes - meterMinutes;            
    }
    
    //Setup the temp ticket objects and feed it the current parameters to calculate the parking fine
    ParkingTicket ticket(vehicle, illMinutes);
    ticket.SetParkingFine(ticket.GetIllegalMinutes());

   //Populate the pointer with the ticket information
    officerTicketPTR->SetParkedCar(vehicle);
    officerTicketPTR->SetIllegalMinutes(illMinutes);
    officerTicketPTR->SetParkingFine(illMinutes);
        
    //Return the pointer with updated data
    return officerTicketPTR;
}


//Overloaded Operators

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& outStream, const PoliceOfficer& object)
{
    outStream << "\n++Officer Details: "
            << "\n----Officer's Name: " << object.GetOfficerName()
            << "\n----Officer's Badge Number: " << object.GetBadgeNumber()
        << endl;
    return outStream;
}