/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This class holds an exception value passed to it from a throw statement.  It also has a get method to retreive that value when
 working with error handling.  This class is setup as a template so the value caught can be of a variable type.

 Required Files: 
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/

#pragma once

template <class T>
class InputError
{

public:

	//Constructors
	InputError();
	InputError(T value);
		
	//Accessor 
	T GetErrorValue();
	void SetErrorValue(T);

private:
	//Declare data members
	T value;

};

//Constructors
/***************************************************************
* this constructor accepts the error message and the value that caused the error
*****************************************************************/
template <class T>
InputError<T>::InputError()
{

}
//Param constructor
template <class T>
InputError<T>::InputError(T error)
{
	this->value = error;

}

/***************************************************************
* This method gets the error value stored at creation
*****************************************************************/
template <class T>
T InputError<T>::GetErrorValue()
{
	return value;
}

/***************************************************************
* This method gets the error value stored at creation
*****************************************************************/
template <class T>
void InputError<T>::SetErrorValue(T error)
{
	this->value = error;
}