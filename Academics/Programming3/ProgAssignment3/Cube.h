/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 243 -  Programming III
*Programming Assignment 3
 Created: 7/05/2021

 ----------------------------------------------------------------------------------------------------------------------------

 Description:
 This derived class uses the data in the base class Shape.h and it creates a geometric cube.  Cubes have a specialized data
 member called side length that determines the calculations in the other data members perimeter, total surface area, and volume.

 Required Files: Shape.h
 Description File: Template file, definitions follow the class

***************************************************************************************************************************/


#pragma once
#include <iostream>

using namespace std;

template <class T>
class Cube : public Shape<T>
{
public:
	//Constructors
	Cube();
	Cube(T, T, T);

	//Accessors and Mutators (setters and getters)
	T GetSideLength() const;
	void SetSideLength(T);
	T GetPerimeter() const;
	T GetSurfaceArea() const;
	T GetVolume() const;

	//Calculation functions
	void CalculateCubeData();
	void CalculatePerimeter();
	void CalculateSurfaceArea();
	void CalculateVolume();
	

protected:
	//Declare data members
	T sideLength;
	T perimeter;
	T surfaceArea;
	T volume;
};

//Definitions Section - Cube.cpp

//Constructors
/*************************************
* Default constructor
**************************************/
template <class T>
Cube<T>::Cube() : Shape<T>()
{
	sideLength = 0;
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

/******************************************************************
* Parameter constructor that accepts the length, width, height as input.
Cube does not need any information besides the length, but it stores the
variables in the base class locations.  It also populates the radius input
needed in the base class constructor with the height variable since it is
not needed.
******************************************************************/
template <class T>
Cube<T>::Cube(T l, T w, T h) : Shape<T>(l, w, h, h)
{
	sideLength = l;
	perimeter = 0;
	surfaceArea = 0;
	volume = 0;
}

//Accessors and Mutators (setters and getters)

/******************************************************************
* This function gets the value stored in the sideLength data member.
******************************************************************/
template <class T>
T Cube<T>::GetSideLength() const
{
	return sideLength;
}

/******************************************************************
* This function sets the value stored in the sideLength data member.
******************************************************************/
template <class T>
void Cube<T>::SetSideLength(T l)
{
	sideLength = l;
}

/******************************************************************
* This function gets the value stored in the perimeter data member.
******************************************************************/
template <class T>
T Cube<T>::GetPerimeter() const
{
	return perimeter;
}

/******************************************************************
* This function gets the value stored in the surfaceArea data member.
******************************************************************/
template <class T>
T Cube<T>::GetSurfaceArea() const
{
	return surfaceArea;
}

/******************************************************************
* This function gets the value stored in the volume data member.
******************************************************************/
template <class T>
T Cube<T>::GetVolume() const
{
	return volume;
}

//Calculation Functions

/******************************************************************
* This function runs all of the calculations to populate the cube data members.
******************************************************************/
template <class T>
void Cube<T>::CalculateCubeData()
{
	CalculatePerimeter();
	CalculateSurfaceArea();
	CalculateVolume();
}

/******************************************************************
* This function calculates the value for and stores it in the perimeter data member.
******************************************************************/
template <class T>
void Cube<T>::CalculatePerimeter()
{
	perimeter = 12 * sideLength;
}

/******************************************************************
* This function calculates the value for and stores it in the surfaceArea data member.
******************************************************************/
template <class T>
void Cube<T>::CalculateSurfaceArea()
{
	surfaceArea = 6 * (sideLength * sideLength);
}

/******************************************************************
* This function calculates the value for and stores it in the volume data member.
******************************************************************/
template <class T>
void Cube<T>::CalculateVolume()
{
	volume = sideLength * sideLength * sideLength;
}

