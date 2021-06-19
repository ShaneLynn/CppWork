#pragma once
/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 6
 Created: 6/08/2021
*
*

-------------------------------------------------------------------------------------------------------------------------

 Description:
 This is the Circle class and it us used to store and geneate on a circle using a radius.  This is the class header file
 portion of the class that covers the following variables and function prototypes:

***************************************************************************************************************************/

//Class definitions for the Circle class

#pragma once
#include <iomanip>
#include <iostream>
#include <cstdlib>


using namespace std;

class Circle
{

	private:

		double radius;
		const double PI = 3.14;

	public:
	
		void SetRadius(double);
		double GetRadius() const;
		void RadiusInput();
		double CalculateArea() const;
		double CalculateCircumference() const;
		double GetDiameter() const;
		void DisplayCalculations();
	

};
