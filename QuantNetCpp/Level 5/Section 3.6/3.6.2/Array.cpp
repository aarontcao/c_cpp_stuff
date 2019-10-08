/*
	C++ code for HW5, Section 3.6, Exercise 2
*/

// include header and source file
#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;


// Default Consturctor
Array::Array()
{
	elements = new Point[10];
	len = 10;
}

// Constructor
Array::Array(int size)
{
	elements = new Point[size];
	len = size;
}

// Copy constructor
Array::Array(const Array& arr)
{
	elements = new Point[arr.len];
	len = arr.len;

	for (int i = 0; i < len; i++)
	{
		elements[i] = arr.elements[i];
	}
}

// Destructor
Array::~Array()
{
	delete[] elements;
}

// Selector functions for size and elements
int Array::Size() const
{
	return len;
}

Point& Array::GetElement(int idx) const
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}

// Modifier function for elements
void Array::SetElement(int idx, const Point& element)
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	elements[idx] = element;
}

// Assignment operator
Array& Array::operator = (const Array& arr)
{
	delete[] elements;

	elements = new Point[arr.len];
	len = arr.len;

	for (int i = 0; i < len; i++)
	{
		elements[i] = arr.elements[i];
	}

	return *this;
}

// Square bracket operator
Point& Array::operator [] (int idx)
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}

// Const square bracket operator for read-only and so that arrays can be declared as const
Point& Array::operator [] (int idx) const
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}