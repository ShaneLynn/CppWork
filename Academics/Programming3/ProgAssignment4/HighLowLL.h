/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 4
 Created: 7/19/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This derived class uses LinkedList.h as base class and adds the functions to find the highest and lowest values found in the
 linked list.

 Required Files: LinkedList.h
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/


#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
class HighLowLL : public LinkedList<T>
{
public:
	
	//Calculation Functions
	T FindHighestValue();
	T FindLowestValue();
	

protected:
	//Declare data members
	T highestValue;
	T lowestValue;
	ListNode<T>* nodePtr = nullptr;				//Setup a pointer to move through the list of nodes
};

//Definitions Section - HighLowLL.cpp

//Calculation Functions

/******************************************************************
* This function searches through the linkedlist nodes and finds
the lowest value stored in the data member: data.
******************************************************************/
template <class T>
T HighLowLL<T>::FindLowestValue()
{

	//Set the working pointer to beginning of the list.
	nodePtr = this->head;
	
	//Check to see if the working pointer is not null and set the current
	//lowest value to the first value in the list
	if (nodePtr != nullptr)
	{
		lowestValue = nodePtr->data;
		nodePtr = nodePtr->next;
	}

	//Setup a while loop to check the working pointer is pointing to a node and
	//step through the list.
	while (nodePtr)
	{
		//Setup a check to see if the current node value is is less than the current
		//value stored in lowestValue.  If so, update the value to the current node.
		if (nodePtr->data < lowestValue)
		{
			lowestValue = nodePtr->data;
		}
		
		nodePtr = nodePtr->next;			//Advance to the next node regardless of if check success
	}
	
	//Once the list is checked, return the lowest value found
	return lowestValue;
}

/******************************************************************
* This function searches through the linkedlist nodes and finds
the highest value stored in the data member: data.
******************************************************************/
template <class T>
T HighLowLL<T>::FindHighestValue()
{

	//Set the working pointer to beginning of the list.
	nodePtr = this->head;
	
	//Check to see if the working pointer is not null and set the current
	//highest value to the first value in the list
	if (nodePtr != nullptr)
	{
		highestValue = nodePtr->data;
		nodePtr = nodePtr->next;
	}

	//Setup a while loop to check the working pointer is pointing to a node and
	//step through the list.
	while (nodePtr)
	{
		//Setup a check to see if the current node value is is less than the current
		//value stored in highestValue.  If so, update the value to the current node.
		if (nodePtr->data > highestValue)
		{
			highestValue = nodePtr->data;
		}
		
		nodePtr = nodePtr->next;			//Advance to the next node regardless of if check success
	}
	//Once the list is checked, return the highest value found
	return highestValue;
}

