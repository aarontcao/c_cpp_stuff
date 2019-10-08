/*
	Header file for HW5, Section 3.6, Exercise 2
*/

#ifndef Array_HPP
#define Array_HPP

// include header and source file
#include "Point.hpp"
using namespace std;

template <typename T>
class Array {
private:
	T* elements;
	int len;

public:
	// Default Consturctor
	Array();

	// Constructor
	Array(int size);

	// Copy constructor
	Array(const Array<T>& arr);

	// Destructor
	~Array();

	// Selector functions for size and elements
	int Size() const;
	T& GetElement(int index) const;

	// Modifier function for elements
	void SetElement(int index, const T& newPoint);

	// Assignment operator
	Array<T>& operator = (const Array<T>& source);

	// Square bracket operator
	T& operator [] (int index);

	// Const square bracket operator for read-only and so that arrays can be declared as const
	const T& operator [] (int index) const;
};

#ifndef Array_CPP
#include "Array.cpp"
#endif

#endif