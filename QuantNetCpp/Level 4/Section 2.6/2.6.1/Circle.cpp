/*
	C++ code for HW4, Section 2.6, Exercise 1
*/

#define _USE_MATH_DEFINES

// include header and source file
#include "Circle.hpp"
#include "Point.hpp"
// include for math operations
#include <cmath>

// include for cin/cout
#include <iostream>
#include <sstream>

namespace AARONCAO
{
	namespace CAD
	{
		// Default constructor
		Circle::Circle()
		{
		}

		// Constructor with center, radius
		Circle::Circle(const Point& c, double r)
		{
			center = c;
			radius = r;
		}

		// Copy constructor
		Circle::Circle(const Circle& c)
		{
			center = c.center;
			radius = c.radius;
		}

		// Destructor
		Circle::~Circle()
		{

		}

		// Modifier function for center
		void Circle::CentrePoint(const Point& c)
		{
			center = c;
		}

		// Modifier function for radius
		void Circle::Radius(double r)
		{
			radius = r;
		}

		// Selector functions for center, radius
		Point Circle::CentrePoint() const
		{
			return center;
		}

		double Circle::Radius() const
		{
			return radius;
		}

		// Diameter of circle
		double Circle::Diameter() const
		{
			return 2.0 * radius;
		}

		// Area of circle
		double Circle::Area() const
		{
			return M_PI * pow(radius, 2);
		}

		// Circumference of circle
		double Circle::Circumference() const
		{
			return 2.0 * M_PI * radius;
		}

		// Convert circle to string
		string Circle::toString() const
		{
			stringstream stream;

			stream << "Center: " << center.toString() << ", " << "Radius: " << radius;

			return stream.str();
		}

		// Assignment operator
		Circle& Circle::operator = (const Circle& source)
		{
			center = source.center;
			radius = source.radius;

			return *this;
		}

		// Send to ostream
		ostream& operator << (ostream& os, const Circle& c)
		{
			os << c.toString() << endl;

			return os;
		}
	}
}