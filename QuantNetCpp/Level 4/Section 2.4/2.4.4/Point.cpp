/*
	C++ code for HW4, Section 2.4, Exercise 4
*/

#include "Point.hpp"
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

// Default constructor
Point::Point()
{
	cout << "Default Constructor" << endl;
}

// Constructor
Point::Point(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
	cout << "Constructor" << endl;
}

// Explicit single-argument constructor
Point::Point(double value)
{
	xCoordinate = value;
	yCoordinate = value;
	cout << "Explicit Single-Argument Constructor" << endl;
}

// Copy constructor
Point::Point(const Point& pt)
{
	xCoordinate = pt.xCoordinate;
	yCoordinate = pt.yCoordinate;
	cout << "Copy Constructor" << endl;
}

// Destructor
Point::~Point()
{
	cout << "Destructor" << endl;
}

// Convert point to string
string Point::toString() const
{
	stringstream pointStream;

	// print format: Point(x, y)
	pointStream << "Point(" << xCoordinate << ", " << yCoordinate << ")";

	// convert to string
	return pointStream.str();
}

// Distance to the origin
double Point::Distance() const
{
	return sqrt(pow(xCoordinate, 2) + pow(yCoordinate, 2));
}

//Distance between two points
double Point::Distance(const Point& p) const
{
	return sqrt(pow(xCoordinate - p.xCoordinate, 2) + pow(yCoordinate - p.yCoordinate, 2));
}

// Negate the coordinates
Point Point::operator - () const
{
	return Point(-xCoordinate, -yCoordinate);
}

// Scale the coordinates
Point Point::operator * (double factor) const
{
	return Point(factor * xCoordinate, factor * yCoordinate);
}

// Add coordinates
Point Point::operator + (const Point& p) const
{
	return Point(xCoordinate + p.xCoordinate, yCoordinate + p.yCoordinate);
}

// Equally compare operator
bool Point::operator == (const Point& p) const
{
	if(xCoordinate == p.xCoordinate && yCoordinate == p.yCoordinate)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Assignment operator
Point& Point::operator = (const Point& source)
{
	xCoordinate = source.xCoordinate;
	yCoordinate = source.yCoordinate;

	return *this;
}

// Scale the coordinates & assign
Point& Point::operator *= (double factor)
{
	xCoordinate *= factor;
	yCoordinate *= factor;

	return *this;
}

// Send to ostream
ostream& operator << (ostream& os, const Point& p)
{
	os << p.toString() << endl;

	return os;
}