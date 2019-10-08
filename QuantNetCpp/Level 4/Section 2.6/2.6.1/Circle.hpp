/*
	Header file for HW4, Section 2.6, Exercise 1
*/

#ifndef Circle_HPP
#define Circle_HPP

// include header and source file
#include "Point.hpp"

namespace AARONCAO
{
	namespace CAD
	{
		class Circle {
		private:
			Point center;
			double radius;

		public:
			// Default constructor
			Circle();

			// Constructor with center, radius
			Circle(const Point& c, double r);

			// Copy constructor
			Circle(const Circle& c);

			// Destructor
			~Circle();

			// Selector functions for center, radius
			Point CentrePoint() const;
			double Radius() const;

			// Modifier functions for center, radius
			void CentrePoint(const Point& c);
			void Radius(double r);

			// Diameter of circle
			double Diameter() const;

			// Area of circle
			double Area() const;

			// Circumference of circle
			double Circumference() const;

			// Convert circle to string
			string toString() const;

			// Assignment operator
			Circle& operator = (const Circle& source);
		};

		// Send to ostream
		ostream& operator << (ostream& os, const Circle& c);
	}
}
#endif