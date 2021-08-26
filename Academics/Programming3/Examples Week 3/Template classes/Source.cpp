#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
	Rectangle<int> myRectI(10, 20);
	Rectangle<double> myRectD(10.23, 20.65);

	cout << "Area of the rectangle is " << myRectI.CalculateArea() << endl;
	cout << "Area of the rectangle is " << myRectD.CalculateArea() << endl;

	system("pause");
	return 0;
}