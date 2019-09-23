/*
	C++ code for HW3, Section 2.3, Exercise 6
*/

#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double x, y, r;

	// User input for center and radius
	cout << "Please enter an x and y coordinate for the center of the circle and the radius: " << endl;
	cin >> x >> y >> r;

	// Create center and point using center, radius
	Point center(x, y);
	Circle circle(center, r);

	// Display circle center and radius
	cout << circle.toString() << endl;

	// Display diameter of circle
	cout << "Diameter: " << circle.Diameter() << endl;

	// Display area of circle
	cout << "Area: " << circle.Area() << endl;

	// Display circumference of circle
	cout << "Circumference: " << circle.Circumference() << endl;

	return 0;
}