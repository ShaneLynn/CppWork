/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: Car.h

***************************************************************************************************************************/

#include "Car.h"

using namespace std;


//Consructors
/*************************************
* Default constructor
**************************************/
Car::Car()
{
    make = " ";
    model = " ";
    color = " ";
    liPlateNum = " ";
}

/******************************************************************
* Parameter constructor that accepts hours and calculates the days
******************************************************************/
Car::Car(string carMake, string carModel, string carColor, string plateNum)
{
    make = carMake;
    model = carModel;
    color = carColor;
    liPlateNum = plateNum;
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the value stored in the make data member.
******************************************************************/
string Car::GetMake() const
{
    return make;
}

/******************************************************************
* This function stores the value in the parameter to the make data member.
******************************************************************/
void Car::SetMake(string carMake)
{
    make = carMake;
}

/******************************************************************
* This function gets the value stored in the model data member.
******************************************************************/
string Car::GetModel() const
{
    return model;
}

/******************************************************************
* This function stores the value in the parameter to the model data member.
******************************************************************/
void Car::SetModel(string carModel)
{
    model = carModel;
}

/******************************************************************
* This function gets the value stored in the model color member.
******************************************************************/
string Car::GetColor() const
{
    return color;
}

/******************************************************************
* This function stores the value in the parameter to the color data member.
******************************************************************/
void Car::SetColor(string carColor)
{
    color = carColor;
}

/******************************************************************
* This function gets the value stored in the license plate data member.
******************************************************************/
string Car::GetLicensePlateNumber() const
{
    return liPlateNum;
}

/******************************************************************
* This function stores the value in the parameter to the license plate data member.
******************************************************************/
void Car::SetLicensePlateNumber(string carPlate)
{
    liPlateNum = carPlate;
}


//Overloaded Operators

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/
ostream& operator << (ostream& outStream, const Car& object)
{
    outStream << "Vehicle Make: " << object.make
        << "\nVehicle Model: " << object.model
        << "\nVehicle Color: " << object.color
        << "\nVehicle Plate Number: " << object.liPlateNum
        << endl;
    return outStream;
}