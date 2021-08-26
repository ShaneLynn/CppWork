/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 7
 Created: 7/30/2021

 ----------------------------------------------------------------------------------------------------------------------------
 Description:
 This program sets up an employee database that is searchable using the Binary Tree template provided by the textbook.  It
 incorporates a class built to hold employee information and stores them in nodes that can be accessed using a menu system.
 The menu provides options to search the database of current employees, and it can display the employee list in 3 different
 ways using the Binary Tree class' methods.  It provides some input validation, and offers the user a choice to keep returning
 to the menu to search multiple times before ending the program.


 Class File used: BinaryTree.h, EmployeeInfo.h

***************************************************************************************************************************/

//HEADER FILES FOR THE PROGRAM

#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "EmployeeInfo.h"

using namespace std;

int main()
{
	//Prompt the user with a welcome to the program
	cout << "Welcome to the Employee Search System!" << endl;
	cout << "--The window may need to be expanded to see all results." << endl;
	cout << "\n";

    //Setup input fields for user input, loop control, and employee searching
    char userInput = 'a';
    int searchId;
    int menuInput = -1;
    bool runAgain = false;
    bool validate = false;
    EmployeeInfo searchEmployee;
    
    //Setup the binary search tree to be used with the EmployeeInfo class objects
    BinaryTree<EmployeeInfo> treeDatabase;

    //Create employees to put into the binary tree database
    EmployeeInfo employee1("Joe Friday", "One Police Way", "New York", "NY", "(712) 555-5123", 7, 4, 1925, 10001);
    EmployeeInfo employee2("Jacob Marley", "The Square Mile", "London", "UK", "(999) 555-0123", 4, 17, 1767, 10002);
    EmployeeInfo employee3("Ebenezer Scrooge", "The Square Mile", "London", "UK", "(999) 555-9875", 12, 25, 1781, 10003);
    EmployeeInfo employee4("Ichabod Crane", "5 Walking Way", "Sleepy Hollow", "NY", "(123) 555-9876", 9, 12, 1621, 10004);
    EmployeeInfo employee5("Katrina Van Tassle", "8 Big House", "Sleepy Hollow", "NY", "(123) 555-9687", 11, 14, 1630, 10005);
    EmployeeInfo employee6("Horseman", "One Police Way", "Sleepy Hollow", "NY", "(123) 555-4567", 10, 31, 1532, 10006);
    EmployeeInfo employee7("Mitsue Tollner", "7 Eads St", "Chicago", "IL", "(773) 555-6914", 1, 13, 1985, 10007);
    EmployeeInfo employee8("Kris Marrier", "228 Runamuck PL#2808", "Baltimore", "MD", "(410) 555-8723", 8, 11, 1995, 10008);
    EmployeeInfo employee9("Kiley Caldarera", "25 E 75th St #69", "Los Angeles", "CA", "(310) 555-5651", 3, 24, 1975, 10009);
    EmployeeInfo employee10("Mattie Poquette", "73 State Road 434 E", "Phoenix", "AZ", "(6002) 555-4385", 2, 29, 1983, 10010);
    EmployeeInfo employee11("Yuki Whobrey", "1 State Route 27", "Taylor", "MI", "(313) 555-7937", 5, 19, 2001, 10011);
    EmployeeInfo employee12("Ray Moore", "1048 Main St", "Columbia", "MO", "(573) 555-6713", 6, 9, 1966, 10012);

    //Insert the employees into the tree nodes while mixing up the order to test the tree display functions
    //Test removing a node if added by accident at the end
    treeDatabase.insertNode(employee1);
    treeDatabase.insertNode(employee3);
    treeDatabase.insertNode(employee2);
    treeDatabase.insertNode(employee7);
    treeDatabase.insertNode(employee4);
    treeDatabase.insertNode(employee5);
    treeDatabase.insertNode(employee6);
    treeDatabase.insertNode(employee10);
    treeDatabase.insertNode(employee8);
    treeDatabase.insertNode(employee9);
    treeDatabase.insertNode(employee12);
    treeDatabase.insertNode(employee11);
    treeDatabase.insertNode(employee11);
    treeDatabase.remove(employee11);
	
    //Start a loop for the user to search
	do
	{
        //Set the loop flag to false to end if not selected
        runAgain = false;

        //Display the menu to the user
        cout << "\nWhat would you like to do?" << endl;
        cout << "1. Search for an employee Id" << endl;
        cout << "2. Display current employees (displayInOrder function)" << endl;
        cout << "3. Display current employees (displayPreOrder function)" << endl;
        cout << "4. Display current employees (displayPostOrder function)" << endl;
        cout << "-> ";
        cin >> menuInput;
        //Input validation
        while (!validate)
        {
            if (menuInput < 1 || menuInput > 4 || cin.fail())
            {
                cout << "Not a valid choice!  Please enter 1-4." << endl;
                cout << "->";
                cin.clear();
                cin.ignore();
                cin >> menuInput;
            }
            else
            {
                validate = true;
            }
        }
        //Reset the input validation flag
        validate = false;

        switch (menuInput)
        {

        case 1:
            //If the user picks menu choice 1
            cout << "\nEnter employee ID to search for: " << endl;
            cout << "-> ";
            cin >> searchId;
            //Begin the input validation loop
            while (!validate)
            {
                if (searchId < 0 || cin.fail())
                {
                    cout << "Not a valid choice!  Please enter 1 or 2." << endl;
                    cout << "->";
                    cin.clear();
                    cin.ignore();
                    cin >> searchId;
                }
                else
                {
                    validate = true;
                }
            }

            //Set the Id into the employee object for searching the tree
            searchEmployee.SetId(searchId);

            //Run a check using the tree's search function
            if (treeDatabase.searchNode(searchEmployee))
            {
                //Display a message to the user that the Id was located
                cout << "ID Found!" << endl;
            }
            else
            {
                //Display a message to the user the Id entered is not in the list
                cout << "Employee Id (" << searchId << ") not found" << endl;
            }

            break;

        case 2:
            //If the user picks menu choice 2
            cout << "Displaying employee data using the displayInOrder function..." << endl;
            treeDatabase.displayInOrder();
            break;

        case 3:
            //If the user picks menu choice 3
            cout << "Displaying employee data using the displayPreOrder function..." << endl;
            treeDatabase.displayPreOrder();
            break;

        case 4:
            //If the user picks menu choice 4
            cout << "Displaying employee data using the displayPostOrder function..." << endl;
            treeDatabase.displayPostOrder();
            break;
        }
        

        //Prompt the user to return to the menu if they want to
        cout << "\n---------------------------------" << endl;
        cout << "Would you like to return to the menu? (y/n)" << endl;
        cout << "-> ";
        cin >> userInput;

        //Input validation
        while (!validate)
        {
            if (userInput == 'y' || userInput == 'Y' || userInput == 'n' || userInput == 'N' && !cin.fail())
            {
                validate = true;
            }
            else
            {
                cout << "Not a valid choice!  Please enter y or n." << endl;
                cout << "->";
                cin.clear();
                cin.ignore();
                cin >> userInput;
            }
        }
        //Reset the input validation flag
        validate = false;
         
        if (userInput == 'y' || userInput == 'Y')
        {
            runAgain = true;
        }
        else
        {
            //Prompt to close the program window
            cout << "\nThank you for using the system.  Press the enter key to close...";
        }

	} while (runAgain == true);

	cin.get();
	return 0;
}