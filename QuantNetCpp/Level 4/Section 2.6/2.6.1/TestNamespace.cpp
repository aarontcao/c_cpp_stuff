/*
	C++ code for HW4, Section 2.6, Exercise 1
*/

// include header and source file
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"

// include for cin/cout
#include <iostream>
#include <string>
using namespace std;

// main function
int main()
{
	// namespace for Point
	AARONCAO::CAD::Point p1(1, -2);
	AARONCAO::CAD::Point p2(-3, 4);
	cout << "p1 = "<< p1 << ", p2 = " << p2 << endl;

	// using namespace for Line
	using AARONCAO::CAD::Line;
	cout << "Line between p1 and p2 = " << Line(p1, p2) << endl;

	// using namespace for Containers
	using namespace AARONCAO::Containers;
	Array arr(2);
	arr[0] = AARONCAO::CAD::Point(5, -6);
	cout << "First element of arr = " << arr[0] << endl;

	// using the namespace for Circle
	namespace ME = AARONCAO::CAD;
	using ME::Circle;
	Circle circ(ME::Point(0, 0), 1);
	cout << "Unit circle = " << circ << endl;

	return 0;
}