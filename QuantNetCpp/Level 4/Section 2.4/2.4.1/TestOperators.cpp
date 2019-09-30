/*
	C++ code for HW4, Section 2.4, Exercise 1
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
	Point p2(11, -13);
	cout << "p1 = " << p1.toString() << ", " << "p2 = " << p2.toString() << endl;

	Point p3 = -p1;
	cout << "p3 = -p1 = " << p3.toString() << endl;

	Point p4 = p2 + p3;
	cout << "p4 = p2 + p3 = " << p4.toString() << endl;

	Point p5 = p4 * 5.0;
	cout << "p5 = p4 * 5.0 = " << p5.toString() << endl;

	cout << "p5 == p4 evaluates to: " << (p5 == p4) << endl;

	p5 *= 5.0;
	cout << "p5 *= 5.0 evaluates to: " << p5.toString() << endl;

	// testing line operators
	const Point p6(0, 0);
	const Point p7(-1, -2);
	Line l1(p6, p7);
	cout << "l1 = " << l1.toString() << endl;

	Line l2 = l1;
	cout << "Assign l2 = l1, now l2 = " << l2.toString() << endl;

	// testing circle operators
	const Point center(0, 0);
	double radius = 1.0;
	Circle c1(center, radius);
	cout << "c1 = " << c1.toString() << endl;

	Circle c2 = c1;
	cout << "Assign c2 = c1, now c2 = " << c2.toString() << endl;

	return 0;
}