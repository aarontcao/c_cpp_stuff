/*
	C++ code for HW4, Section 2.4, Exercise 3
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
	Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;
	if (p == (Point)1.0) cout << "Equal!" << endl;

	return 0;
}