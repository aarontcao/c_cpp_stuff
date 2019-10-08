/*
	C++ code for HW5, Section 4.2a, Exercise 1
*/

#ifndef Array_CPP
#define Array_CPP

// include header and source file
#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;


// Default Consturctor
template <typename T>
Array<T>::Array()
{
	elements = new T[10];
	len = 10;
}

// Constructor
template <typename T>
Array<T>::Array(int size)
{
	elements = new T[size];
	len = size;
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& arr)
{
	elements = new T[arr.len];
	len = arr.len;

	for (int i = 0; i < len; i++)
	{
		elements[i] = arr.elements[i];
	}
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

// Selector functions for size and elements
template <typename T>
int Array<T>::Size() const
{
	return len;
}

template <typename T>
T& Array<T>::GetElement(int idx) const
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}

// Modifier function for elements
template <typename T>
void Array<T>::SetElement(int idx, const T& element)
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	elements[idx] = element;
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& arr)
{
	delete[] elements;

	elements = new T[arr.len];
	len = arr.len;

	for (int i = 0; i < len; i++)
	{
		elements[i] = arr.elements[i];
	}

	return *this;
}

// Square bracket operator
template <typename T>
T& Array<T>::operator [] (int idx)
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}

// Const square bracket operator for read-only and so that arrays can be declared as const
template <typename T>
const T& Array<T>::operator [] (int idx) const
{
	if (idx < 0 || idx >= len)
	{
		throw OutOfBoundsException(idx);
	}

	return elements[idx];
}

#endif