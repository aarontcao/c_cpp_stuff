/*
	C++ code for HW5, Section 3.4, Exercise 1
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
	// testing colon syntax
	Line l;

	/*
	With regular syntax, the default and argument constructors are both called 2 times. 
	The assignment operator and destructor are also called 2 times.

	With colon syntax, the argument constructor and destrutor are both called 2 times.
	The colon syntax reduces the number of calls.
	*/

	return 0;
}