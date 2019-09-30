/*
	C++ code for HW4, Section 2.5, Exercise 1
*/

// include header and source file
#include "Point.hpp"

// include for cin/cout
#include <iostream>
#include <string>
using namespace std;

// main function
int main()
{
	// declare points with new
	Point* p1 = new Point(1, -2);
	Point* p2 = new Point(*p1);
	Point* p3 = new Point(-3, 4);

	cout << "p1 = " << *p1 << ", p2 = " << *p2 << ", p3 = " << *p3 << endl;

	// call distance function
	cout << "d(p1, p3) = " << (*p1).Distance(*p3) << endl;

	delete p1;
	delete p2;
	delete p3;

	int size;
	// get size of array from user input
	cout << "Input size of array: " << endl;
	cin >> size;

	// compiler error when trying to create an array on the stack 
	//Point p[size];

	// but we are allowed to create on the heap with new
	Point* p = new Point[size];
	delete[] p;

	return 0;
}