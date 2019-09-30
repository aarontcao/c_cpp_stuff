/*
	C++ code for HW4, Section 2.4, Exercise 1
*/


#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

// Default constructor
Line::Line()
{
	p1 = Point(0, 0);
	p2 = Point(0, 0);
}

// Constructor with stand and end point
Line::Line(const Point& pt1, const Point& pt2)
{
	p1 = pt1;
	p2 = pt2;
}

// Copy constructor
Line::Line(const Line& line)
{
	p1 = line.p1;
	p2 = line.p2;
}

// Destructor
Line::~Line()
{
}

// Overloaded getter for p1
Point Line::P1() const
{
	return p1;
}

// Overloaded getter for p2
Point Line::P2() const
{
	return p2;
}

// Overloaded setter for p1
void Line::P1(const Point& point1)
{
	p1 = point1;
}

// Overloaded setter for p2
void Line::P2(const Point& point2)
{
	p2 = point2;
}

// function returns length of the line
double Line::Length() const
{
	return p1.Distance(p2);
}

// function returns line description
string Line::toString() const
{
	stringstream stream;

	stream << "Line: " << p1.toString() << ", " << p2.toString();

	return stream.str();
}

// Assignment operator
Line& Line::operator = (const Line& source)
{
	p1 = source.p1;
	p2 = source.p2;

	return *this;
}