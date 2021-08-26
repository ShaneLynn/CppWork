/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This derived class uses the data in the base class Shape.h and it creates a geometric rectangular prism (cubiod).  This shape
 has specialized data members that hold the the calculations for the perimeter, total surface area, and volume of the prism.
 The data members from the base shape class (length, width, and height) are used to store the data for this specialized shape.

 Required Files: Shape.h
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/


#pragma once
#include <iostream>

using namespace std;

template <class T>
class RectPrism : public Shape<T>
{
public:
	//Constructors
	RectPrism();
	RectPrism(T, T, T);

	//Accessors and Mutators (setters and getters)
	T GetPerimeter() const;
	T GetSurfaceArea() const;
	T GetVolume() const;

	//Calculation functions
	void CalculatePrismData();
	void CalculatePerimeter();
	void CalculateSurfaceArea();
	void CalculateVolume();


protected:
	//Declare data members
	T perimeter;
	T surfaceArea;
	T volume;
};

//Definitions Section - RecPrism.cpp

//Constructors
/*************************************
* Default constructor
**************************************/
template <class T>
RectPrism<T>::RectPrism() : Shape<T>()
{
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

/******************************************************************
* Parameter constructor that accepts the length, width, height as input.
Rectangular Prism collects the length, width, and height as data while storing
variables in the base class locations.  It also populates the radius input
needed in the base class constructor with the height variable since it is
not needed.
******************************************************************/
template <class T>
RectPrism<T>::RectPrism(T l, T w, T h) : Shape<T>(l, w, h, h)
{
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

//Accessors and Mutators (setters and getters)

/******************************************************************
* This function gets the value stored in the perimeter data member.
******************************************************************/
template <class T>
T RectPrism<T>::GetPerimeter() const
{
	return perimeter;
}

/******************************************************************
* This function gets the value stored in the surfaceArea data member.
******************************************************************/
template <class T>
T RectPrism<T>::GetSurfaceArea() const
{
	return surfaceArea;
}

/******************************************************************
* This function gets the value stored in the volume data member.
******************************************************************/
template <class T>
T RectPrism<T>::GetVolume() const
{
	return volume;
}

//Calculation Functions

/******************************************************************
* This function runs all of the calculations to populate the prism data members.
******************************************************************/
template <class T>
void RectPrism<T>::CalculatePrismData()
{
	CalculatePerimeter();
	CalculateSurfaceArea();
	CalculateVolume();
}

/******************************************************************
* This function calculates the value for and stores it in the perimeter data member.
******************************************************************/
template <class T>
void RectPrism<T>::CalculatePerimeter()
{
	perimeter = (2 * Shape<T>::GetLength()) + (2 * Shape<T>::GetWidth());
	
}

/******************************************************************
* This function calculates the value for and stores it in the surfaceArea data member.
******************************************************************/
template <class T>
void RectPrism<T>::CalculateSurfaceArea()
{
	surfaceArea = 2 * ((Shape<T>::GetLength() * Shape<T>::GetWidth()) + (Shape<T>::GetWidth() * Shape<T>::GetHeight()) + (Shape<T>::GetLength() * Shape<T>::GetHeight()));
}

/******************************************************************
* This function calculates the value for and stores it in the volume data member.
******************************************************************/
template <class T>
void RectPrism<T>::CalculateVolume()
{
	volume = Shape<T>::GetLength() * Shape<T>::GetWidth() * Shape<T>::GetHeight();
}
