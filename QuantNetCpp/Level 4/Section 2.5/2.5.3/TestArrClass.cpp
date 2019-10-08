/*
	C++ code for HW4, Section 2.5, Exercise 3
*/

// include header and source file
#include "Point.hpp"
#include "Array.hpp"

// include for cin/cout
#include <iostream>
#include <string>
using namespace std;

// main function
int main()
{
	// testing constructors
	Array arr1;
	Array arr2(2);
	Array arr3(arr2);

	// testing assignment operator.
	arr1 = arr2;

	// testing []
	arr1[0] = Point(-1, 2);
	arr1[1] = Point(3, -4);

	// testing Size()
	cout << "arr1 size = " << arr1.Size() << endl;

	// testing const []
	cout << "arr1[0] = " << arr1[0] << endl;

	// testing GetElement()
	cout << "arr1[0] = " << arr1.GetElement(0) << endl;

	// testing SetElement().
	arr1.SetElement(0, Point(-5, 6));
	arr2.SetElement(1, Point(7, -8));

	return 0;
}