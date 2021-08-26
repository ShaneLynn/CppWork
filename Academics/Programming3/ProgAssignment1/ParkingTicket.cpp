/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: ParkingTicket.h

***************************************************************************************************************************/



#include "ParkingTicket.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
ParkingTicket::ParkingTicket()
{
    parkingFine = 0.0;
    illegalMinutes = 0;
}

/******************************************************************
* Parameter constructor that accepts a parked vehicle object and
how many minutes that car has been parked illegally 
******************************************************************/
ParkingTicket::ParkingTicket(ParkedCar parkVehicle, int minIllegal)
{
    vehicle = parkVehicle;
    illegalMinutes = minIllegal;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the parked car data member.
******************************************************************/
ParkedCar ParkingTicket::GetParkedCar() const
{
    return vehicle;
}

/******************************************************************
* This function stores the value in the parameter for the parked car
data member.
******************************************************************/
void ParkingTicket::SetParkedCar(ParkedCar carParked)
{
    vehicle = carParked;
}

/******************************************************************
* This function gets the value stored in the illegal minutes data member.
******************************************************************/
int ParkingTicket::GetIllegalMinutes() const
{
    return illegalMinutes;
}

/******************************************************************
* This function stores the value in the parameter to the illegal minutes data member.
******************************************************************/
void ParkingTicket::SetIllegalMinutes(int minIllegal)
{
    illegalMinutes = minIllegal;
}

/******************************************************************
* This function gets the value stored in the parking fine data member.
******************************************************************/
double ParkingTicket::GetParkingFine() const
{
    return parkingFine;
}

/******************************************************************
* This function stores the value in the parameter to the parking fine data member.
* It uses the private member fine calculation to set the parking fine amount.
******************************************************************/
void ParkingTicket::SetParkingFine(int minIllegal)
{
    parkingFine = CalculateParkingFine(minIllegal);
}


//Calculation Functions
/******************************************************************
* This function calculates the total fine earned by the parked car
object based on the amount of minutes it has been parked illegally.
It uses an if check to set the first hour amount and then a while
loop to determine the rest of the hourly charges.
******************************************************************/
double ParkingTicket::CalculateParkingFine(int minIllegal)
{
    double totalFine = 0;       //Initialize the temp holder for the total fine amount
    
    int illegalTime = minIllegal;       //Working variable for the illegal time

    if (illegalTime > 0)
    {
        totalFine += 25;            //Automatically charge $25 for the first hour block of time illegally parked
        illegalTime -= 60;              //And remove that 1st hour time from the illegal minutes parked total
    }

    while (illegalTime > 0)         //Setup a loop to charge $10 for each additional hour block of illegal time
    {
        if (illegalTime > 60)
        {
            totalFine += 10;            
            illegalTime -= 60;
        }
        else
        {
            totalFine += 10;                    //Charge the final $10 for the remaining time less than an hour and clear the time.
            illegalTime -= illegalTime;             
        }

    }

    return totalFine;
}


//Overloaded Operators

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& outStream, const ParkingTicket& object)
{
    outStream << "\n++Parking Ticket Details:"
        <<"\n----Offending Vehicle Info: \n" 
                << object.vehicle
        << "\n----Illegal Parked Minutes: " << object.illegalMinutes
        << "\n----Parking Fine Total: $" << object.GetParkingFine()
        << endl;
    return outStream;
}

