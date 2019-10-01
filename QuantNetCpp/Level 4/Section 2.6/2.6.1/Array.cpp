/*
	C++ code for HW4, Section 2.6, Exercise 1
*/

// include header and source file
#include "Point.hpp"
#include "Array.hpp"
using namespace std;

namespace AARONCAO
{
	namespace Containers
	{
		// Default Consturctor
		Array::Array()
		{
			elements = new CAD::Point[10];
			len = 10;
		}

		// Constructor
		Array::Array(int size)
		{
			elements = new CAD::Point[size];
			len = size;
		}

		// Copy constructor
		Array::Array(const Array& arr)
		{
			elements = new CAD::Point[arr.len];
			len = arr.len;

			for (int i = 0; i < len; i++)
			{
				elements[i] = arr.elements[i];
			}
		}

		// Destructor
		Array::~Array()
		{
			delete[] elements;
		}

		// Selector functions for size and elements
		int Array::Size() const
		{
			return len;
		}

		CAD::Point& Array::GetElement(int idx) const
		{
			if (idx >= len)
			{
				return elements[0];
			}

			return elements[idx];
		}

		// Modifier function for elements
		void Array::SetElement(int idx, const CAD::Point& element)
		{
			if (idx >= len)
			{
				return;
			}

			elements[idx] = element;
		}

		// Assignment operator
		Array& Array::operator = (const Array& arr)
		{
			delete[] elements;

			elements = new CAD::Point[arr.len];
			len = arr.len;

			for (int i = 0; i < len; i++)
			{
				elements[i] = arr.elements[i];
			}

			return *this;
		}

		// Square bracket operator
		CAD::Point& Array::operator [] (int idx)
		{
			if (idx >= len)
			{
				return elements[0];
			}

			return elements[idx];
		}

		// Const square bracket operator for read-only and so that arrays can be declared as const
		const CAD::Point& Array::operator [] (int idx) const
		{
			if (idx >= len)
			{
				return elements[0];
			}

			return elements[idx];
		}
	}
}