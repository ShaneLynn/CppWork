/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Assignment 7
 Created: 6/16/2021



 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This program uses the TimeOff and NumDays classes to create objects to keep track of employees and their time off totals.  
 The porgram loads preset values and creates some objects to run numerous test cases on the data and object operators.

 Both classes utilize two reports on an overloaded << operator to display formatted employee time and objects:

 Report format from Numdays <<:
 ------------------
		Available Hours: (total hours) 
         Available Days: (total hours / 8)

Report format from TimeOff <<:
 ------------------
        Time Off Report:         Employee Name (Employee Number)

    Sick Time Taken: X.X day(s) (X.hours) | Maximum Sick Time: X.X day(s) (X.hours)
Vacation Time Taken: X.X day(s) (X.hours) | Maximum Vacation Time: X.X day(s) (X.hours)
  Unpaid Time Taken: X.X day(s) (X.hours) | Maximum Unpaid Time: X.X day(s) (X.hours)

 Class File used: TimeOff.h, TimeOff.cpp, NumDays.h, NumDays.cpp

***************************************************************************************************************************/


//Header files for the program
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "TimeOff.h"
#include "NumDays.h"

using namespace std;


//The main program function
int main()
{

	//Prompt the user with a welcome
	cout << "Welcome to the employee absence and time off system." << endl;
    cout << "--The window will need to be expanded to see formatted test results." << endl;
    cout << "\n";

    /********************TEST CLASS CREATION ********************************/
    //Create an instance of the TimeOff class using the default constructor that is empty
    TimeOff defaultEmployee;

    //Create an instance of the TimeOff class using the parameter constructor that sets up an employee
    TimeOff employee("Shane Lynn", 25, NumDays(100), NumDays(25), NumDays(30), NumDays(15), NumDays(50), NumDays(5));
    
    /********************TEST OVERLOADED STREAM OPERATOR ********************************/
    //Use the overloaded stream operator to display the report of each employee
    cout << "---------------------------------------------------------------------" << endl;
    cout << "**Overloaded stream operator test to display the report for the default" << endl;
    cout << "**constructor object and the parameter object with employee data." << endl;
    cout << defaultEmployee;
    cout << employee;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n";

    /********************TEST OVERLOADED PREFIX AND POSTFIX OPERATORS ********************************/
    //Adjust the values of the employee object using the overloaded prefix operator.  Increments by 1 hour or 0.125 days (hours / 8.0)
    employee.SetSickTaken(++employee.GetSickTaken());
    employee.SetVacTaken(++employee.GetVacTaken());
    
    //Adjust the values of the employee object using the overloaded postfix operator.  Increments by 1 hour or 0.125 days (hours / 8.0) occur after display
    employee.SetUnpaidTaken(employee.GetUnpaidTaken()++);

    
    //Display the pre and post fix changes, report needs to be called twice the first will change sick and vacation while unpaid will update for the second report.
    cout << "---------------------------------------------------------------------" << endl;
    cout << "**Prefix and Postfix tests for the increase (++) operator.  These reports will show an incresase" << endl;
    cout << "**to the sick taken and vacation taken times on the first and then to unpaid on the second." << endl;
    cout << employee;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n";

    //Reverse the adjustments made to the employee object using the overloaded prefix operator.  Decrements by 1 hour or 0.125 days (hours / 8.0)
    employee.SetSickTaken(--employee.GetSickTaken());
    employee.SetVacTaken(--employee.GetVacTaken());

    //Reverse the adjustments made to the employee object using the overloaded postfix operator.  Decrements by 1 hour or 0.125 days (hours / 8.0) occur after display
    employee.SetUnpaidTaken(employee.GetUnpaidTaken()--);

    //Display the pre and post fix changes, report needs to be called twice the first will change sick and vacation while unpaid will update for the second report.
    
    cout << "---------------------------------------------------------------------" << endl; 
    cout << "**Prefix and Postfix tests for the decrease (--) operator.  These reports will show a decrease" << endl;
    cout << "**to the sick taken and vacation taken times on the first and then to unpaid on the second." << endl;
    cout << employee;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n";
    

    /********************TEST VALIDATION OF VACATION AND TIME TAKEN ********************************/
    cout << "---------------------------------------------------------------------" << endl;
    cout << "**Test setting max vacation time past 240 maximum and trying to take more time" << endl;
    cout << "**for sick taken, unpaid taken, and vacation taken than current maximum." << endl;

    //Create an instance of the TimeOff class using the parameter constructor that sets up an employee
    TimeOff badEmployee("Bad Employee", 30, NumDays(10), NumDays(5), NumDays(10), NumDays(5), NumDays(10), NumDays(5));

    //Set the max vacation past the allowed 240
    cout << "\nTest validation when setting max vacation past allowed maximum (250):";
    badEmployee.SetMaxVacation(250);

    cout << "\nTest validation when setting sick taken past allowed maximum (15):";
    badEmployee.SetSickTaken(15);

    cout << "\nTest validation when setting vacation taken past allowed maximum (250):";
    badEmployee.SetVacTaken(250);

    cout << "\nTest validation when setting unpaid taken past allowed maximum (15):";
    badEmployee.SetUnpaidTaken(15);

    cout << "\nDisplay the report on the bad employee's time: ";
    cout << badEmployee;

    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n";

    /********************TEST OVERLOADED MATH OPERATORS ********************************/

    //Create two objects from the NumDays class using the default constructor and the
    //parameter constructor populate them with values from the TimeOff object
    NumDays test1;
    NumDays test2(employee.GetVacTaken());
    NumDays test3(employee.GetSickTaken());

    
    /********************TEST OVERLOADED STREAM OPERATOR ********************************/
    //Use the overloaded stream operator to display the report for each object
    cout << "---------------------------------------------------------------------" << endl;
    cout << "**Display the report for NumDays object test1:" << endl;
    cout << test1;
    cout << "\n";
    cout << "**Display the report for NumDays object test2:" << endl;
    cout << test2;
    cout << "\n";
    cout << "**Display the report for NumDays object test3:" << endl;
    cout << test3;
    cout << "\n";

    //Test the math operator + (addition) to assign the values
    test1 = test2 + test3;
    
    //Display the addition result
    cout << "**Display the report for NumDays object test1 = test2 + test3:" << endl;
    cout << test1;
    cout << "\n";

    //Test the math operator - (subtraction) to assign the values
    test1 = test2 - test3;
    
    //Display the subtraction result
    cout << "**Display the report for NumDays object test1 = test2 - test3:" << endl;
    cout << test1;
    cout << "---------------------------------------------------------------------" << endl;

    cout << "\n";

    /********************TEST OVERLOADED = (ASSIGNMENT) OPERATOR ********************************/
    //Create a new empty employee object from TimeOff
    TimeOff employee2;

    //Use the assignment operator to copy all of employee 1 into employee 2
    employee2 = employee;
    
    //Use the overloaded stream operator to display the report that employee 2 is equal to employee 1
    cout << "---------------------------------------------------------------------" << endl;

    cout << "**Assignment (=) test to show new TimeOff object employee 2 is equal to existing employee 1:" << endl;
    cout << employee2;
    cout << employee;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\n";

    cout << "This concludes all of the tests to the employee time off system." << endl;

	//Prompt to close the program
	cout << "\nThank you for using the system.  Press the enter key to close...";
	cin.ignore();
	cin.get();

	return 0;
}