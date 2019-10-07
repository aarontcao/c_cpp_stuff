/*
	C++ code for HW5, Section 3.5, Exercise 2
*/

#include "Shape.hpp"

#include <stdlib.h>
#include <sstream>

// Default constructor
Shape::Shape()
{
	id = rand();
}

// Copy constructor
Shape::Shape(const Shape& shape)
{
	id = shape.id;
}

// Destructor
Shape::~Shape()
{
	cout << "Shape Destructor" << endl;
}

// Selector for ID
int Shape::ID() const
{
	return id;
}

// Assignment operator
Shape& Shape::operator = (const Shape& source)
{
	id = source.id;

	return *this;
}

// Convert shape to string
string Shape::toString() const
{
	stringstream shapeStream;

	shapeStream << "Shape ID: " << id;

	return shapeStream.str();
}