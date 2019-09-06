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
	double x, y;

	// Prompt user for input
	cout << "Please input an x- and y- coordinate." << endl;

	// User input for x- and y-coordinates
	cin >> x >> y;

	// Create a Point object
	Point p1;

	// Set the coordinates using the setter functions
	p1.setX(x);
	p1.setY(y);

	// Print the description of the point
	cout << p1.toString() << endl;

	// Print the point coordinates using the selector functions
	cout << "X Coordinate: " << p1.getX() << endl;
	cout << "Y Coordinate: " << p1.getY() << endl;

	return 0;
}