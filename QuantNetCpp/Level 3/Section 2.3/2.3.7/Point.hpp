/*
	Header file for HW3, Section 2.3, Exercise 7
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
	double X() const;
	double Y() const;

	// Modifier functions for each coordinate using default inline
	void X(double x) { xCoordinate = x; }
	void Y(double y) { yCoordinate = y; }

	// Convert point to string
	string toString() const;

	// Distance to the origin
	double Distance() const;

	//Distance between two points
	double Distance(const Point& p) const;
};

// Normal inline functions for selecting coordinates
inline double Point::X() const { return xCoordinate; }
inline double Point::Y() const { return yCoordinate; }

#endif