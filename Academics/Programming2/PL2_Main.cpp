/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 2
 Created: 5/11/2021
*

-------------------------------------------------------------------------------------------------------------------------

 Description:
 This program takes an original array and doubles it using pointers and dynamic memory allocation.


* The program uses one function to double an array:
•	int* ExpandArray(int data[], int size);
	o	The first argument accepts the inital pointer array, and the second accepts the original array size
	o	Variables are created to double the original array size, setup a pointer to return, and create the new array
	o	A for loop is used to copy the original array's data to the doubled array.  A check is used to enter 0 in empty elements.
	o	Returns the pointer memory address for the new array

***************************************************************************************************************************/





#include <iostream>
using namespace std;

//This function doubles the size of the array input and returns the new doubled array's memory address
int* ExpandArray(int data[], int size)
{
	int* newArrayPtr = nullptr;						//Create a new pointer to hold the memory adress to be returned
	int newSize = size * 2;							//New variable that doubles the size of the array size input argument

	int* newArray = new int[newSize];				//Create the new array with the doubled size.

	for (int index = 0; index < newSize; index++)	//Use a loop to copy the data from the original array into the new array
	{
		if (index < size)							//Copy all data from the original array based on its size
		{
			newArray[index] = data[index];
		}	
		else										//Once the original data runs out, enter 0 into the extra data fields.
		{
			newArray[index] = 0;
		}
	}

	newArrayPtr = newArray;							//Assign the new pointer the memory address of the new array

	return newArrayPtr;								//Return the pointer's memory address
}

//Source Lab 2 File provided code
int main()
{
	int size = 2;
	int* values = new int[size];
	values[0] = 55;
	values[1] = 77;

	for (int index = 0; index < size; index++)
	{
		cout << values[index] << endl;
	}

	values = ExpandArray(values, size);

	for (int index = 0; index < size * 2; index++)
	{
		cout << values[index] << endl;
	}

	delete[] values;
	

	
	return 0;
}