/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 7
 Created: 6/16/2021


***************************************************************************************************************************/

#include "TimeOff.h"

using namespace std;

//Consructors
/*************************************
* Default constructor
**************************************/
TimeOff::TimeOff() 
{
    name = "";
    empNum = 0;
    maxSickDays.SetHours(0);
    maxSickDays.SetDays(0);
    sickTaken.SetHours(0);
    sickTaken.SetDays(0);
    maxVacation.SetHours(0);
    maxVacation.SetDays(0);
    vacTaken.SetHours(0);
    vacTaken.SetDays(0);
    maxUnpaid.SetHours(0);
    maxUnpaid.SetDays(0);
    unpaidTaken.SetHours(0);
    unpaidTaken.SetDays(0);
}

/******************************************************************
* Parameter constructor that accepts the parameters from the data
members employee name, employee number, maxSickDays, sickTaken,
maxVacation, vacTaken, maxUnpaid, and unpaidTaken
******************************************************************/
TimeOff::TimeOff(string empName, int empID, NumDays maxSick, NumDays sickTaken, NumDays maxVac, NumDays vacTaken, NumDays maxUnpd, NumDays unpaidTaken)
{
    name = empName;
    empNum = empID;
    maxSickDays.SetHours(maxSick.GetHours());
    maxSickDays.SetDays(maxSick.GetDays());
    SetSickTaken(sickTaken);
    SetMaxVacation(maxVac);
    SetVacTaken(vacTaken);
    maxUnpaid.SetHours(maxUnpd.GetHours());
    maxUnpaid.SetDays(maxUnpd.GetDays());
    SetUnpaidTaken(unpaidTaken);
}


//Set and Get functions for the data members.
/******************************************************************
* This function gets the employee's name value stored in the name 
data member.
******************************************************************/
string TimeOff::GetName() const
{
    return name;
}

/******************************************************************
* This function sets the employee's name using the input parameter.
******************************************************************/
void TimeOff::SetName(string name)
{
    name = name;
}

/******************************************************************
* This function gets the employee's number value stored in the name
data member.
******************************************************************/
int TimeOff::GetEmpNum() const
{
    return empNum;
}

/******************************************************************
* This function sets the employee's number using the input parameter.
******************************************************************/
void TimeOff::SetEmpNum(int ID)
{
    empNum = ID;
}

/******************************************************************
* This function gets the employee's maximum sick time value stored
in the name data member.
******************************************************************/
NumDays TimeOff::GetMaxSickDays() const
{
    return maxSickDays;
}

/******************************************************************
* This function sets the employee's maximum sick time value using
the input parameter.
******************************************************************/
void TimeOff::SetMaxSickDays(NumDays employee)
{
    maxSickDays.SetHours(employee.GetHours());
    maxSickDays.SetDays(employee.GetDays());
}

/******************************************************************
* This function gets the employee's sick time taken value stored
in the name data member.
******************************************************************/
NumDays TimeOff::GetSickTaken() const
{
    return sickTaken;
}

/******************************************************************
* This function sets the employee's sick time taken value using
the input parameter.  It also validates if the employee has the
available hours to take the requested time, and if not it sets
the time available to be taken at the current max hours available.
******************************************************************/
void TimeOff::SetSickTaken(NumDays employee)
{
    if (employee.GetHours() <= maxSickDays.GetHours())
    {
        sickTaken.SetHours(employee.GetHours());
        sickTaken.SetDays(employee.GetDays());
    }
    else
    {
        //Notify the employee, and set the time requested to the time available in the bank.
        cout << "\nYou do not have enough time for the request, changing to the maximum available time." << endl;
        sickTaken.SetHours(maxSickDays.GetHours());
        sickTaken.SetDays(maxSickDays.GetDays());
    }
}

/******************************************************************
* This function gets the employee's maximum vacation time available
value stored in the name data member.
******************************************************************/
NumDays TimeOff::GetMaxVacation() const
{
    return maxVacation;
}

/******************************************************************
* This function sets the employee's maximum vacation time value using
the input parameter.  It also validates if the employee has met the
limit to store the requested time, and if not it sets the time 
to the allowable amount to be stored at current max hours available.
******************************************************************/
void TimeOff::SetMaxVacation(NumDays employee)
{
    if (employee.GetHours() <= 240)
    {
        maxVacation.SetHours(employee.GetHours());
        maxVacation.SetDays(employee.GetDays());
    }
    else
    {
        //Informs the user that the total bankable vacation time has been met
        cout << "\nThe maximum bankable vacation time is 240 hours (30 days)." << endl;
        maxVacation.SetHours(240);
        maxVacation.SetDays(240 / 8.0);
    }
}

/******************************************************************
* This function gets the employee's vacation time taken value stored
in the name data member.
******************************************************************/
NumDays TimeOff::GetVacTaken() const
{
    return vacTaken;
}

/******************************************************************
* This function sets the employee's vacation time taken value using
the input parameter.  It also validates if the employee has the
available hours to take the requested time, and if not it sets
the time available to be taken to the current max hours available.
******************************************************************/
void TimeOff::SetVacTaken(NumDays employee)
{
    if (employee.GetHours() <= maxVacation.GetHours())
    {
        vacTaken.SetHours(employee.GetHours());
        vacTaken.SetDays(employee.GetDays());
    }
    else
    {
        //Notify the employee, and set the time requested to the time available in the bank.
        cout << "\nYou do not have enough time for the request, changing to the maximum available time." << endl;
        vacTaken.SetHours(maxVacation.GetHours());
        vacTaken.SetDays(maxVacation.GetDays());
    }
}

/******************************************************************
* This function gets the employee's maximum unpaid time available
value stored in the name data member.
******************************************************************/
NumDays TimeOff::GetMaxUnpaid() const
{
    return maxUnpaid;
}

/******************************************************************
* This function sets the employee's maximum unpaid time value using
the input parameter.  
******************************************************************/
void TimeOff::SetMaxUnpaid(NumDays employee)
{
    maxUnpaid.SetHours(employee.GetHours());
    maxUnpaid.SetDays(employee.GetDays());
}

/******************************************************************
* This function gets the employee's unpaid time taken value stored
in the name data member.
******************************************************************/
NumDays TimeOff::GetUnpaidTaken() const
{
    return unpaidTaken;
}

/******************************************************************
* This function sets the employee's unpaid time taken value using
the input parameter.  It also validates if the employee has the
available hours to take the requested time, and if not it sets
the time available to be taken to the current max hours available.
******************************************************************/
void TimeOff::SetUnpaidTaken(NumDays employee)
{
    if (employee.GetHours() <= maxUnpaid.GetHours())
    {
        unpaidTaken.SetHours(employee.GetHours());
        unpaidTaken.SetDays(employee.GetDays());
    }
    else
    {
        //Notify the employee, and set the time requested to the time available in the bank.
        cout << "\nYou do not have enough time for the request, changing to the maximum available time." << endl;
        unpaidTaken.SetHours(maxUnpaid.GetHours());
        unpaidTaken.SetDays(maxUnpaid.GetDays());
    }
}


//Overloaded Operators
/******************************************************************
* This function overloads the = (assignment) operator to copy the
values from one class object to the other.
******************************************************************/
TimeOff TimeOff::operator = (const TimeOff &right)
{
    name = right.name;
    empNum = right.empNum;
    maxSickDays = right.maxSickDays;
    sickTaken = right.sickTaken;
    maxVacation = right.maxVacation;
    vacTaken = right.vacTaken;
    maxUnpaid = right.maxUnpaid;
    unpaidTaken = right.unpaidTaken;
    return *this;
}


/******************************************************************
* This function overloads the << (outgoing stream) operator to
display the final time off report for the class object formatted
so it shows all of the values stored in the class object's data members.
******************************************************************/
ostream &operator << (ostream &outStream, const TimeOff &object)
{
    outStream << "\n" 
              << setw(25) << left << "Time Off Report: " << object.GetName() << " (" << object.GetEmpNum() << ")"
              << "\n\n"
              << setw(20) << right << "    Sick Time Taken: " << object.GetSickTaken().GetDays() << " day(s) (" << object.GetSickTaken().GetHours() << ".hours) | Maximum Sick Time: " << object.GetMaxSickDays().GetDays() << " day(s) (" << object.GetMaxSickDays().GetHours() << ".hours)"
              << setw(20) << right << "\nVacation Time Taken: " << object.GetVacTaken().GetDays() << " day(s) (" << object.GetVacTaken().GetHours() << ".hours) | Maximum Vacation Time: " << object.GetMaxVacation().GetDays() << " day(s) (" << object.GetMaxVacation().GetHours() << ".hours)"
              << setw(20) << right << "\n  Unpaid Time Taken: " << object.GetUnpaidTaken().GetDays() << " day(s) (" << object.GetUnpaidTaken().GetHours() << ".hours) | Maximum Unpaid Time: " << object.GetMaxUnpaid().GetDays() << " day(s) (" << object.GetMaxUnpaid().GetHours() << ".hours)"
              << endl;
    
    return outStream;
}