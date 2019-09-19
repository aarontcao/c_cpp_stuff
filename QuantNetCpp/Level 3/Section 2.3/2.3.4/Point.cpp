/*
	C++ code for HW3, Section 2.3, Exercise 4
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

// Selector functions for each coordinate
double Point::X() const
{
	return xCoordinate;
}

double Point::Y() const
{
	return yCoordinate;
}

// Modifier functions for each coordinate
void Point::X(double x)
{
	xCoordinate = x;
}

void Point::Y(double y)
{
	yCoordinate = y;
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