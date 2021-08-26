/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 6
 Created: 7/26/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class sets up three variables to use with the contained functions.  It stores two integers and a string which are used
 to pass to the RecursivePower, StringReverser, and SumOfNumbers functions.  These functions are calculative and action in
 nature and the descriptions provide extra details as to their use.
 

 Required Files:
 Description File: ActionFunctions.cpp

***************************************************************************************************************************/

#pragma once
#include <iostream>

using namespace std;

class ActionFunctions
{

public:

    //CONSTRUCTORS
    ActionFunctions();
    ActionFunctions(int, int, string);

    //Accessors and Mutators - Getters and Setters
    int GetNumber() const;
    void SetNumber(int);

    int GetToPower() const;
    void SetToPower(int);

    string GetText() const;
    void SetText(string);


    //ACTION FUNCTIONS
    int RecursivePower(int, int);
    void StringReverser(string);
    int SumOfNumbers(int);


private:
    //DATA MEMBERS
    //Setup the data members used by the functions
    int number;
    int toPower;
    string text;
};
