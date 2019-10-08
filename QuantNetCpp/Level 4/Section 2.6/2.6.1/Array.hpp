/*
	Header file for HW4, Section 2.6, Exercise 1
*/

#ifndef Array_HPP
#define Array_HPP

// include header and source file
#include "Point.hpp"
using namespace std;

namespace AARONCAO
{
	namespace Containers
	{
		class Array {
		private:
			CAD::Point* elements;
			int len;

		public:
			// Default Consturctor
			Array();

			// Constructor
			Array(int size);

			// Copy constructor
			Array(const Array& arr);

			// Destructor
			~Array();

			// Selector functions for size and elements
			int Size() const;
			CAD::Point& GetElement(int index) const;

			// Modifier function for elements
			void SetElement(int index, const CAD::Point& newPoint);

			// Assignment operator
			Array& operator = (const Array& source);

			// Square bracket operator
			CAD::Point& operator [] (int index);

			// Const square bracket operator for read-only and so that arrays can be declared as const
			const CAD::Point& operator [] (int index) const;
		};
	}
}
#endif