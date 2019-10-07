/*
	C++ code for HW5, Section 3.5, Exercise 3
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
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];

	/*
	When the Shape destructor is not virtual,
	~Point() is called 2 times and ~Shape() is called five times.
	Thus, the derived class destructor is not called when the
	destructor is not virtual in the base class.

	When the Shape destructor is virtual,
	~Point() is called five times, ~Line() is called once, and ~Shape() is called seven times.
	This is desired
	*/

	return 0;
}