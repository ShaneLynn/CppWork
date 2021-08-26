/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This base class sets up data members which can be used by rectangular, square, and circular geometric shapes in derived classes.

 Required Files:
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/


#pragma once
#include <iostream>

using namespace std;

template <class T>
class Shape
{
public:
	//Constructors
	Shape();
	Shape(T, T, T, T);

	//Accessors and Mutators (setters and getters)
	virtual T GetLength() const;
	virtual void SetLength(T);

	virtual T GetWidth() const;
	virtual void SetWidth(T);

	virtual T GetHeight() const;
	virtual void SetHeight(T);

	virtual T GetRadius() const;
	virtual void SetRadius(T);

protected:
	//Declare data members
	T length;
	T width;
	T height;
	T radius;
	double pi;
};

//Definitions Section - Shape.cpp

//Constructors
/*************************************
* Default constructor
**************************************/
template <class T>
Shape<T>::Shape()
{
	length = 0;
	width = 0;
	height = 0;
	radius = 0;
	pi = 3.14;
}

/******************************************************************
* Parameter constructor that accepts the length, width, height, and
radius input.  It does not accept a value for pi and instead uses the
default value of pi to set the variable.
******************************************************************/
template <class T>
Shape<T>::Shape(T l, T w, T h, T r)
{
	length = l;
	width = w;
	height = h;
	radius = r;
	pi = 3.14;
}

//Accessors and Mutators (setters and getters)

/******************************************************************
* This function gets the value stored in the length data member.
******************************************************************/
template <class T>
T Shape<T>::GetLength() const
{
	return length;
}

/******************************************************************
* This function gets the value stored in the length data member.
******************************************************************/
template <class T>
void Shape<T>::SetLength(T l)
{
	length = l;
}

/******************************************************************
* This function gets the value stored in the width data member.
******************************************************************/
template <class T>
T Shape<T>::GetWidth() const
{
	return width;
}

/******************************************************************
* This function gets the value stored in the width data member.
******************************************************************/
template <class T>
void Shape<T>::SetWidth(T w)
{
	width = w;
}

/******************************************************************
* This function gets the value stored in the height data member.
******************************************************************/
template <class T>
T Shape<T>::GetHeight() const
{
	return height;
}

/******************************************************************
* This function gets the value stored in the height data member.
******************************************************************/
template <class T>
void Shape<T>::SetHeight(T h)
{
	height = h;
}

/******************************************************************
* This function gets the value stored in the height data member.
******************************************************************/
template <class T>
T Shape<T>::GetRadius() const
{
	return radius;
}

/******************************************************************
* This function gets the value stored in the height data member.
******************************************************************/
template <class T>
void Shape<T>::SetRadius(T r)
{
	radius = r;
}

