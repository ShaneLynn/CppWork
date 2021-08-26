/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: ParkedCar.h

***************************************************************************************************************************/


#include "ParkedCar.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
ParkedCar::ParkedCar()
{
    vehicle.SetMake("");
    vehicle.SetModel("");
    vehicle.SetColor("");
    vehicle.SetLicensePlateNumber("");
    parkedMinutes = 0;

}

/******************************************************************
* Parameter constructor that accepts all Car parameters plus parking minutes
******************************************************************/
ParkedCar::ParkedCar(string carMake, string carModel, string carColor, string plateNum, int minParked)
{
    vehicle.SetMake(carMake);
    vehicle.SetModel(carModel);
    vehicle.SetColor(carColor);
    vehicle.SetLicensePlateNumber(plateNum);
    parkedMinutes = minParked;
}

/******************************************************************
* Copy constructor that handles all Car parameters plus parking minutes
******************************************************************/
ParkedCar::ParkedCar(const ParkedCar& obj)
{
    vehicle = obj.vehicle;
    parkedMinutes = obj.parkedMinutes;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the minutes parked data member.
******************************************************************/
int ParkedCar::GetMinutesParked() const
{
    return parkedMinutes;
}

/******************************************************************
* This function stores the value in the parameter to the minutes parked data member.
******************************************************************/
void ParkedCar::SetMinutesParked(int minParked)
{
    parkedMinutes = minParked;
}


//Overloaded Operators

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& outStream, const ParkedCar& object)
{
    outStream << object.vehicle 
        << "Vehicle Minutes Parked: " << object.parkedMinutes
        << endl;
    return outStream;
}