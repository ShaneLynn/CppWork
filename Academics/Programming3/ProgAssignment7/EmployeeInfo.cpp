/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This file describes the methods listed in the header file: EmployeeInfo.h

 Required Files: EmployeeInfo.h

***************************************************************************************************************************/

#include "EmployeeInfo.h"

//----------------------------------------------------------------
// CONSTRUCTORS
//----------------------------------------------------------------

/*************************************
* Default constructor
**************************************/
EmployeeInfo::EmployeeInfo()
{
    id = 0;
}

/******************************************************************
* Parameter constructor that accepts the name, address, city,
* state, and phone number of a person
******************************************************************/
EmployeeInfo::EmployeeInfo(string name, string address, string city, string state, string phone, int monthIn, int dayIn, int yearIn, int idIn) : Person(name, address, city, state, phone)
{
    id = idIn;
    hireDate.SetMonth(monthIn);
    hireDate.SetDay(dayIn);
    hireDate.SetYear(yearIn);
}


//----------------------------------------------------------------
// ACCESSORS AND MUTATORS = GETTERS AND SETTERS
//----------------------------------------------------------------

/******************************************************************
* This function gets the value stored in the data member: name
******************************************************************/
int EmployeeInfo::GetId() const
{
    return id;
}

/******************************************************************
* This function sets the value stored in the data member: name
******************************************************************/
void EmployeeInfo::SetId(int idIn)
{
    id = idIn;
}

/******************************************************************
* This function gets the value stored in the data member: hireDate
******************************************************************/
Date EmployeeInfo::GetHireDate() const
{
    return hireDate;
}

/******************************************************************
* This function sets the value stored in the data member: hireDate
******************************************************************/
void EmployeeInfo::SetHireDate(int month, int day, int year)
{
    hireDate.SetMonth(month);
    hireDate.SetDay(day);
    hireDate.SetYear(year);
}


//----------------------------------------------------------------
// OVERLOADED OPERATORS
//----------------------------------------------------------------

/******************************************************************
* This function overloads the < (less than) operator to
compare the values from the class object's data members.
******************************************************************/
bool EmployeeInfo::operator < (EmployeeInfo& right) const
{
    return (id < right.GetId());
}

/******************************************************************
* This function overloads the > (greater than) operator to
compare the values from the class object's data members.
******************************************************************/
bool EmployeeInfo::operator > (EmployeeInfo& right) const
{
    return (id > right.GetId());
}

/******************************************************************
* This function overloads the == (equal to) operator to
compare the values from the class object's data members.
******************************************************************/
bool EmployeeInfo::operator == (EmployeeInfo& right) const
{
    return (id == right.GetId());
}

/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the values from the class object's data members.
******************************************************************/

ostream& operator << (ostream& outStream, const EmployeeInfo& object)
{
    outStream 
        << "\nEMPLOYEE DETAILS"
        << "\n-----------------"
        << "\nName: " << object.GetName()
        << "\nAddress: " << object.GetAddress()
        << "\nCity: " << object.GetCity()
        << "\nState: " << object.GetState()
        << "\nPhone: " << object.GetPhone()
        << "\nID : " << object.GetId()
        << "\nHire Date : " << object.GetHireDate()
        << endl;
    return outStream;
}
