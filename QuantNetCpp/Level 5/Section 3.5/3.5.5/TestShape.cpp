/*
	C++ code for HW5, Section 3.5, Exercise 5
*/

// include header and source file
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

using namespace std;

// main function
int main()
{
	Point p(1, -2);
	Line l(Point(-3, 4), Point(5, -6));
	p.Print();
	l.Print();

	// The correct information is printed

	return 0;
}