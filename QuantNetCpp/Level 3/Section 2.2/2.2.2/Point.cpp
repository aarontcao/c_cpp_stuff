/*
	C++ code for HW3, Section 2.2, Exercise 1
*/

#include "Point.hpp"
#include <sstream>
#include <cmath>
using namespace std;

// Default constructor
Point::Point()
{

}

// Destructor
Point::~Point()
{

}

// Selector functions for each coordinate
double Point::getX() 
{
	return xCoordinate;
}

double Point::getY() 
{
	return yCoordinate;
}

// Modifier functions for each coordinate
void Point::setX(double x)
{
	xCoordinate = x;
}

void Point::setY(double y)
{
	yCoordinate = y;
}

// Convert point to string
string Point::toString()
{
	stringstream pointStream;

	// print format: Point(x, y)
	pointStream << "Point(" << xCoordinate << ", " << yCoordinate << ")";

	// convert to string
	return pointStream.str();
}

// Distance to the origin
double Point::DistanceOrigin()
{
	return sqrt(pow(xCoordinate, 2) + pow(yCoordinate, 2));
}

//Distance between two points
double Point::Distance(Point p)
{
	return sqrt(pow(xCoordinate - p.getX(), 2) + pow(yCoordinate - p.getY(), 2));
}