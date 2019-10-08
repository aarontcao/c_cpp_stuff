/*
	C++ code for HW5, Section 3.5, Exercise 2
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
	Shape s; // Create shape.
	Point p(10, 20); // Create point.
	Line l(Point(1, 2), Point(3, 4)); // Create line.

	cout << s.toString() << endl; // Print shape.
	cout << p.toString() << endl; // Print point.
	cout << l.toString() << endl; // Print line

	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. It works.
	cout << "Line ID: " << l.ID() << endl; // ID of the line. It works.

	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. It's possible.

	// Call the toString() function of Point, also prints ID
	cout << sp->toString() << endl; // Point(10, 20) is printed

	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // The ID is copied even though the base class assignment is not called.

	return 0;
}