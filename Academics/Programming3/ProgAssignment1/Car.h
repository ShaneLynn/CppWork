/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 1
 Created: 6/28/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores the details about a car in strings such as the make, model, color, and license plate number.

 Required Files: 
 Description File: Car.cpp

***************************************************************************************************************************/


#pragma once
#include <iostream>
#include <string>

using namespace std;

class Car
{
public:

    //Constructors
    Car();                                      //Default
    Car(string, string, string, string);        //Parameter

    //Accessors and Mutators (setters and getters)
    string GetMake() const;
    void SetMake(string);

    string GetModel() const;
    void SetModel(string);

    string GetColor() const;
    void SetColor(string);

    string GetLicensePlateNumber() const;
    void SetLicensePlateNumber(string);
    

    //Overloaded output stream operator designated as a friend
    friend ostream& operator << (ostream&, const Car&);


private:
    
    //Declare Data Members
    string make;
    string model;
    string color;
    string liPlateNum;

};