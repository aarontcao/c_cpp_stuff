/*
	Header file for HW5, Section 3.5, Exercise 1
*/

#ifndef Line_HPP
#define Line_HPP

// include header and source file
#include "Point.hpp"
#include "Shape.hpp"

// include for cin/cout
#include <iostream>
using namespace std;

class Line: public Shape
{
private:
	// Starting point
	Point p1;

	// End point
	Point p2;

public:
	// Default constructor
	Line(); 

	// Constructor
	Line(const Point& p1, const Point& p2);

	// Copy constructor
	Line(const Line& line);

	// Destructor
	virtual ~Line();

	// Selector functions for the start and end points
	Point P1() const;
	Point P2() const;

	// Modifier functions for the start and end points
	void P1(const Point& point1);
	void P2(const Point& point2);

	// Length of the line
	double Length() const;

	// Line description
	string toString() const;

	// Assignment operator
	Line& operator = (const Line& source);

	// Send to ostream
	friend ostream& operator << (ostream& os, const Line& l);
};

#endif