/*
	Header file for HW5, Section 3.6, Exercise 2
*/

#ifndef Point_HPP
#define Point_HPP

// include header and source file
#include "Shape.hpp"

// include for cin/cout
#include <iostream>
using namespace std;

class Point: public Shape {
private:
	double xCoordinate;
	double yCoordinate;

public:
	// Default constructor
	Point();

	// Constructor
	Point(double x, double y);

	// Explicit single-argument constructor
	explicit Point(double value);

	// Copy constructor
	Point(const Point& pt);

	// Destructor
	virtual ~Point();

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

	// Negate the coordinates
	Point operator - () const;

	// Scale the coordinates
	Point operator * (double factor) const;

	// Add coordinates
	Point operator + (const Point& p) const;

	// Equally compare operator
	bool operator == (const Point& p) const;

	// Assignment operator
	Point& operator = (const Point& source);

	// Scale the coordinates & assign
	Point& operator *= (double factor);

	// Send to ostream
	friend ostream& operator << (ostream& os, const Point& p);

	// Draw
	void Draw() const;
};

// Normal inline functions for selecting coordinates
inline double Point::X() const { return xCoordinate; }
inline double Point::Y() const { return yCoordinate; }

#endif