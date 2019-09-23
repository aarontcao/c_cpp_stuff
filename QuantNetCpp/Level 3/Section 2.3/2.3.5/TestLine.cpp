/*
	C++ code for HW3, Section 2.3, Exercise 5
*/

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double x, y, a, b;

	// User input for point 1
	cout << "Please input x and y coordinate of the start point" << endl;

	cin >> x >> y;

	// Ask the user for the x- and y-coordinates of the end point.
	cout << "Please input x and y coordinate of the end point" << endl;

	cin >> a >> b;

	// Create the start point and end point.
	const Point p1(x, y);
	const Point p2(a, b);

	// Create the line object.
	Line line(p1, p2);

	cout << "Start point: (" << line.P1().X() << ", " << line.P1().Y() << ")" << endl;
	cout << "End point: (" << line.P2().X() << ", " << line.P2().Y() << ")" << endl;

	cout << line.toString() << endl;
	cout << "Length: " << line.Length() << endl;
	return 0;
}