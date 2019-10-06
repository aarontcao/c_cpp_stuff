/*
	Header file for HW5, Section 3.4, Exercise 2
*/

#ifndef Shape_HPP
#define Shape_HPP

// include for cin/cout
#include <iostream>
using namespace std;

class Shape
{
private:
	int id; // ID

public:
	// Default constructor
	Shape();

	// Copy constructor
	Shape(const Shape& shape);

	// Destructor
	virtual ~Shape();

	// Selector function for ID
	int ID() const;

	// Assignment operator
	Shape& operator = (const Shape& shape);

	// Convert shape to string
	string toString() const;
};

#endif