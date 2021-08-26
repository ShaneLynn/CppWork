/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class uses the Car class to create an object called parked car that has all of the features of the car class plus it 
 holds the amount of time the car has been parked in minutes.

 Required Files: Car.h, Car.cpp
 Description File: ParkedCar.cpp
 
***************************************************************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

class ParkedCar
{
public:

    //Constructors
    ParkedCar();                                         //Default
    ParkedCar(string, string, string, string, int);      //Parameter
    ParkedCar(const ParkedCar& obj);                     //Copy
   
    //Accessors and Mutators (setters and getters)
    int GetMinutesParked() const;
    void SetMinutesParked(int);


    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const ParkedCar&);

private:
    
    //Declare Data Members
    Car vehicle;
    int parkedMinutes;
};