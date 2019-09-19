/*
	C++ code for HW3, Section 2.2, Exercise 1
*/

// include header and source file
#include "Point.hpp"
// #include "Point.hpp"

// include for cin/cout
#include <iostream>
#include <string>
using namespace std;


// main function
int main() {
	double x, y, a, b;

	// Prompt user for input
	cout << "Please input an x- and y- coordinate for two points (in the order X1, Y1, X2, Y2)." << endl;

	// User input for x- and y-coordinates
	cin >> x >> y >> a >> b;

	// Create a Point object
	Point p1;

	// Set the coordinates using the setter functions
	p1.setX(x);
	p1.setY(y);

	// Create second Point object
	Point p2(a, b);

	// Print the description of the point
	cout << p1.toString() << endl;

	// Print the point 1 coordinates using the selector functions
	cout << "Point 1" << endl;
	cout << "X Coordinate: " << p1.getX() << endl;
	cout << "Y Coordinate: " << p1.getY() << endl;

	// Print the point 2 coordinates using the selector functions
	cout << "Point 2" << endl;
	cout << "X Coordinate: " << p2.getX() << endl;
	cout << "Y Coordinate: " << p2.getY() << endl;

	// Find the distance between p1 and the origin
	cout << "The distance between your point and the origin is: " << p1.DistanceOrigin() << endl;
	
	// Find the distance between p1 and p2
	cout << "The distance between your two points is: " << p1.Distance(p2) << endl;
	


	return 0;
}