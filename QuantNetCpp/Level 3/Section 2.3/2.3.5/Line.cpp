/*
	C++ code for HW3, Section 2.3, Exercise 5
*/


#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

Line::Line()
{
	p1(0, 0);
	p2(0, 0);
}

Line::Line(const Point& p1, const Point& p2)
{
	p1(p1);
	p2(p2);
}

Line::Line(const Line& line)
{
	p1(line.p1);
	p2(line.p2);
}

Line::~Line()
{
}

Point Line::P1() const
{
	return p1;
}

Point Line::P2() const
{
	return p2;
}

void Line::P1(const Point& point1)
{
	p1 = point1;
}

void Line::P2(const Point& point2)
{
	p2 = point2;
}

double Line::Length() const
{
	return p1.Distance(p2);
}

string Line::ToString() const
{
	stringstream stream;

	stream << "Line: " << p1.toString() << "-" << p2.toString();

	return stream.str();
}