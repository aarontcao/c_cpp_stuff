/*
	C++ code for HW5, Section 3.6, Exercise 1
*/

// include header and source file
#include "Point.hpp"
#include "Array.hpp"
#include "Shape.hpp"

using namespace std;

// main function
int main()
{
	Array arr(1);

	try
	{
		cout << arr.GetElement(2) << endl;
	}

	catch (int error)
	{
		if (error == -1)
		{
			cout << "Out of bounds error!" << endl;
		}
	}

	return 0;
}