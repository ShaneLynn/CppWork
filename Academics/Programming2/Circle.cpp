/***************************************************************************************************************************
*Author: Christopher S Lynn
 CISS 242 -  Programming II
*Programming Lab 6
 Created: 6/08/2021
*
*

-------------------------------------------------------------------------------------------------------------------------

 Description:
 This is the Circle class and it us used to store and geneate on a circle using a radius.  This is the function definition
 portion of the class that covers the following functions:


***************************************************************************************************************************/

//Function definitions for the Circle class

#include "Circle.h"

/****************************************************************************************
This function sets the radius entered by the user to the private radius variable.
It validates the input from the user to not allow negative inputs by using an IF check to
set the radius to 0 if a negative value is entered.  It also prompts the user telling them
that the radius has been set to 0 due to the invalid entry.
****************************************************************************************/
void Circle::SetRadius(double r)
{
	if (r < 0)
	{
		cout << "Invalid entry, the radius cannot be a negative number. Setting to 0 " << endl;
		radius = 0.0;
	}
	else
	{
		radius = r;
	}
}

/****************************************************************************************
This function prompts the user and collects the radius of the circle to store in the
radius private variable.
****************************************************************************************/
void Circle::RadiusInput()
{
	double radiusIn = 0.0;

	cout << "\nWhat is the radius of the circle?: ";
	cin >> radiusIn;

	SetRadius(radiusIn);
}

/****************************************************************************************
This function gets the radius from the private variable as a const to avoid any changes.
****************************************************************************************/
double Circle::GetRadius() const
{
	return radius;
}

/****************************************************************************************
This function multiplies the radius from the private variable to calculate the diameter.
****************************************************************************************/
double Circle::GetDiameter() const
{
	return (radius * 2);
}

/****************************************************************************************
This function multiplies the radius variable by itself and PI to calculate the area.
****************************************************************************************/
double Circle::CalculateArea() const
{
	return (PI * radius * radius);
}

/****************************************************************************************
This function multiplies the radius variable by 2 and PI to calculate the circumference.
****************************************************************************************/
double Circle::CalculateCircumference() const
{
	return (2 * PI * radius);
}

/****************************************************************************************
This function displays the final calculations of the circle to the user based on the radius.
****************************************************************************************/
void Circle::DisplayCalculations()
{
	cout << fixed << showpoint << setprecision(2);
	cout << setw(20) << "\nCircle Statistics" << endl;
	cout << setw(20) << "-----------------" << endl;
	cout << setw(20) << right << "Radius: " << GetRadius() << endl;
	cout << setw(20) << right << "Diameter: " << GetDiameter() << endl;
	cout << setw(20) << right << "Area: " << CalculateArea() << endl;
	cout << setw(20) << right << "Circumference: " << CalculateCircumference() << endl;
}

