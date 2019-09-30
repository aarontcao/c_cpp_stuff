/*
	C++ code for HW4, Section 2.4, Exercise 2
*/

// include header and source file
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

// include for cin/cout
#include <iostream>
#include <string>
using namespace std;

// main function
int main()
{
	// testing point operators
	Point p1(-5, 7);
	cout << "p1 = " << p1 << endl;

	// testing line operators
	const Point p2(0, 0);
	const Point p3(-1, -2);
	Line l1(p2, p3);
	cout << "l1 = " << l1 << endl;

	// testing circle operators
	const Point center(0, 0);
	double radius = 1.0;
	Circle c1(center, radius);
	cout << "c1 = " << c1 << endl;

	return 0;
}