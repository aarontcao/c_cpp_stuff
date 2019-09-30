/*
	C++ code for HW4, Section 2.5, Exercise 2
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
	// Create an array of Point pointers with 3 elements on the heap.
	Point** ptrArr = new Point*[3];

	// Create for each element in the array a point on the heap.
	ptrArr[0] = new Point(1.0, -2.0);
	ptrArr[1] = new Point(-3.0, 4.0);
	ptrArr[2] = new Point(5.0, -6.0);

	// Iterate the array and print each point in the array.
	for(int i = 0; i < 3; i++)
	{
		cout << *ptrArr[i] << endl;
	}

	// Iterate the array again and delete each point in the array.
	for (int i = 0; i < 3; i++)
	{
		delete ptrArr[i];
	}

	// Delete the array itself.
	delete[] ptrArr;

	return 0;
}