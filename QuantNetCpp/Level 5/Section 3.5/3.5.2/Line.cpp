/*
	C++ code for HW5, Section 3.5, Exercise 2
*/

// include header and source file
#include "Line.hpp"
#include "Point.hpp"

// incluse for ostream
#include <sstream>

// Default constructor
Line::Line(): Shape()
{
	p1 = Point(0, 0);
	p2 = Point(0, 0);
	cout << "Default Constructor" << endl;
}

// Constructor with start and end point
Line::Line(const Point& pt1, const Point& pt2): Shape()
{
	p1 = pt1;
	p2 = pt2;
	cout << "Constructor" << endl;
}

// Copy constructor
Line::Line(const Line& line): Shape(line)
{
	p1 = line.p1;
	p2 = line.p2;
	cout << "Copy Constructor" << endl;
}

// Destructor
Line::~Line()
{
	cout << "Line Destructor" << endl;
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
	std::string s = Shape::toString();

	stream << "Line: " << p1.toString() << ", " << p2.toString() << ", " << s;

	return stream.str();
}

// Assignment operator
Line& Line::operator = (const Line& line)
{
	Shape::operator = (line);

	p1 = line.p1;
	p2 = line.p2;

	return *this;
}

// Send to ostream
ostream& operator << (ostream& os, const Line& l)
{
	os << l.toString() << endl;

	return os;
}