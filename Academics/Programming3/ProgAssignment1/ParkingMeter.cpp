/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: ParkingMeter.h

***************************************************************************************************************************/



#include "ParkingMeter.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
ParkingMeter::ParkingMeter()
{
    purchasedMinutes = 0;
}

/******************************************************************
* Parameter constructor that accepts parking minutes purchased by 
parked car drivers
******************************************************************/
ParkingMeter::ParkingMeter(int minPurchased)
{
    purchasedMinutes = minPurchased;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the purchased minutes data member.
******************************************************************/
int ParkingMeter::GetMinutesPurchased() const
{
    return purchasedMinutes;
}

/******************************************************************
* This function stores the value in the parameter to the purchased minutes data member.
******************************************************************/
void ParkingMeter::SetMinutesPurchased(int minPurchased)
{
    purchasedMinutes = minPurchased;
}


//Overloaded Operators

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& outStream, const ParkingMeter& object)
{
    outStream << "\n++Parking Meter Details:"
        << "\n----Parking Meter Minutes Purchased: " << object.purchasedMinutes
        << endl;
    return outStream;
}