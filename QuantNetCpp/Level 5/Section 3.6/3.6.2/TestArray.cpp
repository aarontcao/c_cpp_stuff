/*
	C++ code for HW5, Section 3.6, Exercise 2
*/

// include header and source file
#include "Point.hpp"
#include "Array.hpp"
#include "Shape.hpp"
#include "ArrayException.hpp"

using namespace std;

// main function
int main()
{
	Array arr(1);

	try
	{
		cout << arr.GetElement(2) << endl;
	}

	catch (ArrayException& arrEx)
	{
		cout << arrEx.GetMessage() << endl;
	}

	return 0;
}