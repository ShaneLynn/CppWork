/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: Person.h

 Required Files: Person.h

***************************************************************************************************************************/

#include "Person.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
Person::Person()
{
    name = "";
    address = "";
    city = "";
    state = "";
    phone = "";
}

/******************************************************************
* Parameter constructor that accepts the name, address, city, 
* state, and phone number of a person
******************************************************************/
Person::Person(string nameIn, string addressIn, string cityIn, string stateIn, string phoneIn)
{
    name = nameIn;
    address = addressIn;
    city = cityIn;
    state = stateIn;
    phone = phoneIn;
}


//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------

/******************************************************************
* This function gets the value stored in the data member: name
******************************************************************/
string Person::GetName() const
{
    return name;
}

/******************************************************************
* This function sets the value stored in the data member: name
******************************************************************/
void Person::SetName(string nameIn)
{
    name = nameIn;
}

/******************************************************************
* This function gets the value stored in the data member: address
******************************************************************/
string Person::GetAddress() const
{
    return address;
}

/******************************************************************
* This function sets the value stored in the data member: address
******************************************************************/
void Person::SetAddress(string addressIn)
{
    address = addressIn;
}

/******************************************************************
* This function gets the value stored in the data member: city
******************************************************************/
string Person::GetCity() const
{
    return city;
}

/******************************************************************
* This function sets the value stored in the data member: city
******************************************************************/
void Person::SetCity(string cityIn)
{
    city = cityIn;
}

/******************************************************************
* This function gets the value stored in the data member: state
******************************************************************/
string Person::GetState() const
{
    return state;
}

/******************************************************************
* This function sets the value stored in the data member: state
******************************************************************/
void Person::SetState(string stateIn)
{
    state = stateIn;
}

/******************************************************************
* This function gets the value stored in the data member: phone
******************************************************************/
string Person::GetPhone() const
{
    return phone;
}

/******************************************************************
* This function sets the value stored in the data member: phone
******************************************************************/
void Person::SetPhone(string phoneIn)
{
    phone = phoneIn;
}