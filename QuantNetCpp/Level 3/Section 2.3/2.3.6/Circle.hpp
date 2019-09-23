/*
	Header file for HW3, Section 2.3, Exercise 6
*/

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"

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
};
#endif