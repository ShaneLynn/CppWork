#pragma once

template <class T>
class Rectangle
{
	private:
		T width;
		T length;
	public:
		Rectangle(T width, T length);
		T CalculateArea();
};

template <class T>
Rectangle<T>::Rectangle(T width, T length)
{
	this->width = width;
	this->length = length;
}

template <class T>
T Rectangle<T>::CalculateArea()
{
	T result;
	result = length * width;
	return result;
}
