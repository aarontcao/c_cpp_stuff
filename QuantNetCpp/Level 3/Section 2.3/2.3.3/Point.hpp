/*
	Header file for HW3, Section 2.3, Exercise 3
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
	double X();
	double Y();

	// Modifier functions for each coordinate
	void X(double x);
	void Y(double y);

	// Convert point to string
	string toString();

	// Distance to the origin
	double Distance();

	//Distance between two points
	double Distance(const Point& p);
};

#endif