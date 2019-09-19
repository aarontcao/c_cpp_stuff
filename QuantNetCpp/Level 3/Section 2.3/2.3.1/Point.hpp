/*
	Header file for HW3, Section 2.2, Exercise 1
*/

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point {
private:
	double xCoordinate;
	double yCoordinate;

public:
	// Default constructor
	Point();

	// Constructor
	Point(double x, double y);

	// Copy constructor
	Point(const Point& pt);

	// Destructor
	~Point();

	// Selector functions for each coordinate
	double getX();
	double getY();

	// Modifier functions for each coordinate
	void setX(double x);
	void setY(double y);

	// Convert point to string
	string toString();

	// Distance to the origin
	double DistanceOrigin();

	//Distance between two points
	double Distance(Point p);
};

#endif