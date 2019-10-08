/*
	Header file for HW5, Section 3.6, Exercise 1
*/

#ifndef Array_HPP
#define Array_HPP

// include header and source file
#include "Point.hpp"
using namespace std;

class Array {
private:
	Point* elements;
	int len;

public:
	// Default Consturctor
	Array();

	// Constructor
	Array(int size);

	// Copy constructor
	Array(const Array& arr);

	// Destructor
	~Array();

	// Selector functions for size and elements
	int Size() const;
	Point& GetElement(int index) const;

	// Modifier function for elements
	void SetElement(int index, const Point& newPoint);

	// Assignment operator
	Array& operator = (const Array& source);

	// Square bracket operator
	Point& operator [] (int index);

	// Const square bracket operator for read-only and so that arrays can be declared as const
	Point& operator [] (int index) const;
};

#endif