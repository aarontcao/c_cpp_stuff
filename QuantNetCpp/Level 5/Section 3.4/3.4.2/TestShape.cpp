/*
	C++ code for HW5, Section 3.4, Exercise 2
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
	cout << s.ToString() << endl; // Print shape.
	cout << p.ToString() << endl; // Print point.
	cout << l.ToString() << endl; // Print line
	cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
	cout << "Point ID: " << p.ID() << endl; // ID of the point. Does this work? This works.
	cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work? This works.
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. Possible? This is possible.
	cout << sp->ToString() << endl; // What is printed? ID: 18467
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
	// the base class assignment in point? 
	// Yes, the ID is copied.

	return 0;
}