/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This derived class uses the data in the base class Shape.h and it creates a geometric square pyramid.  This shape
 has specialized data members that hold the the calculations for the perimeter, total surface area, volume, and slant height.
 The data members from the base shape class (length, and height) are used to store the data for this shape with
 the length member converting to a sideLength member as found in the cube shape.

 Required Files: Shape.h
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/


#pragma once
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Pyramid : public Shape<T>
{
public:
	//Constructors
	Pyramid();
	Pyramid(T, T, T);

	//Accessors and Mutators (setters and getters)
	T GetSideLength() const;
	void SetSideLength(T);

	T GetSlantHeight() const;
	T GetPerimeter() const;
	T GetSurfaceArea() const;
	T GetVolume() const;

	//Calculation functions
	void CalculatePyramidData();
	void CalculatePerimeter();
	void CalculateSurfaceArea();
	void CalculateSlantHeight();
	void CalculateVolume();


protected:
	//Declare data members
	T sideLength;
	T slantHeight;
	T perimeter;
	T surfaceArea;
	T volume;
};

//Definitions Section - Pyramid.cpp

//Constructors
/*************************************
* Default constructor
**************************************/
template <class T>
Pyramid<T>::Pyramid() : Shape<T>()
{
	sideLength = 0;
	slantHeight = 0;
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

/******************************************************************
* Parameter constructor that accepts the length, width, height as input.
The pyramid does not need any information besides the length, and height
but it stores the variables in the base class locations if needed.  The 
constructor also populates the radius input needed for the base class constructor 
with the height variable since it is not needed.
******************************************************************/
template <class T>
Pyramid<T>::Pyramid(T l, T w, T h) : Shape<T>(l, w, h, h)
{
	sideLength = l;
	slantHeight = 0;
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

//Accessors and Mutators (setters and getters)

/******************************************************************
* This function gets the value stored in the sideLength data member.
******************************************************************/
template <class T>
T Pyramid<T>::GetSideLength() const
{
	return sideLength;
}

/******************************************************************
* This function sets the value stored in the sideLength data member.
******************************************************************/
template <class T>
void Pyramid<T>::SetSideLength(T l)
{
	sideLength = l;
}

/******************************************************************
* This function gets the value stored in the slantHeight data member.
******************************************************************/
template <class T>
T Pyramid<T>::GetSlantHeight() const
{
	return slantHeight;
}

/******************************************************************
* This function gets the value stored in the perimeter data member.
******************************************************************/
template <class T>
T Pyramid<T>::GetPerimeter() const
{
	return perimeter;
}

/******************************************************************
* This function gets the value stored in the surfaceArea data member.
******************************************************************/
template <class T>
T Pyramid<T>::GetSurfaceArea() const
{
	return surfaceArea;
}

/******************************************************************
* This function gets the value stored in the volume data member.
******************************************************************/
template <class T>
T Pyramid<T>::GetVolume() const
{
	return volume;
}

//Calculation Functions

/******************************************************************
* This function runs all of the calculations to populate the cube data members.
******************************************************************/
template <class T>
void Pyramid<T>::CalculatePyramidData()
{
	CalculateSlantHeight();
	CalculatePerimeter();
	CalculateSurfaceArea();
	CalculateVolume();
}

/******************************************************************
* This function calculates the value for and stores it in the perimeter data member.
******************************************************************/
template <class T>
void Pyramid<T>::CalculatePerimeter()
{
	perimeter = 4 * sideLength;

}

/******************************************************************
* This function calculates the value for and stores it in the perimeter data member.
******************************************************************/
template <class T>
void Pyramid<T>::CalculateSlantHeight()
{
	slantHeight = sqrt(pow(sideLength / 2, 2) + pow(Shape<T>::GetHeight(), 2));

}

/******************************************************************
* This function calculates the value for and stores it in the surfaceArea data member.
* CalculateSlantHeight must be used first to populate the data member or the totals will be incorrect.
******************************************************************/
template <class T>
void Pyramid<T>::CalculateSurfaceArea()
{
	surfaceArea = pow(sideLength, 2) + ((.50 * sideLength) * slantHeight * 4);
}

/******************************************************************
* This function calculates the value for and stores it in the volume data member.
******************************************************************/
template <class T>
void Pyramid<T>::CalculateVolume()
{
	volume = ((sideLength * sideLength) * Shape<T>::GetHeight()) / 3;
}
