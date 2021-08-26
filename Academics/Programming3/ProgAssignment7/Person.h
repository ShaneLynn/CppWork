/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class stores the details about a person in strings such as their name, address, city, state, and phone number.


 Required Files:
 Description File: Person.cpp

***************************************************************************************************************************/

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Person
{

public:

    //CONSTRUCTORS
    Person();
    Person(string, string, string, string, string);

    //ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
    string GetName() const;
    void SetName(string);

    string GetAddress() const;
    void SetAddress(string);

    string GetCity() const;
    void SetCity(string);

    string GetState() const;
    void SetState(string);

    string GetPhone() const;
    void SetPhone(string);

    
protected:

    //DATA MEMBERS
        //Setup the data members used by the functions
    string name;
    string address;
    string city;
    string state;
    string phone;
  
};