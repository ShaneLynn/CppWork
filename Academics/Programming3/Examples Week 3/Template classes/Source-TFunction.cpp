#include <iostream>
using namespace std;


template <class T>
double Divide(T value1, T value2)
{
	return (double)value1 / value2;
}

int main()
{

	Divide(5, 2);
	Divide(5.6, 4.5);
	
	system("pause");
	return 0;
}