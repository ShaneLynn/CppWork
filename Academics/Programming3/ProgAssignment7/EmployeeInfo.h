/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class expands on the Person class to incorporate an id and hire date field to create an employee record.


 Required Files: Date.h, Person.h
 Description File: EmployeeInfo.cpp

***************************************************************************************************************************/

#pragma once
#include "Date.h"
#include "Person.h"

class EmployeeInfo : public Person
{

public:

    //CONSTRUCTORS
    EmployeeInfo();
    EmployeeInfo(string, string, string, string, string, int, int, int, int);

    //ACCESSORS AND MUTATORS (GETTERS AND SETTERS)
    int GetId() const;
    void SetId(int id);

    Date GetHireDate() const;
    void SetHireDate(int, int, int);

    //OVERLOADED OPERATORS
    bool operator < (EmployeeInfo&) const;
    bool operator > (EmployeeInfo&) const;
    bool operator == (EmployeeInfo&) const;
    friend ostream& operator << (ostream&, const EmployeeInfo&);

private:
    //DATA MEMBERS
        //Setup the data members used by the functions
    int id;
    Date hireDate;
};