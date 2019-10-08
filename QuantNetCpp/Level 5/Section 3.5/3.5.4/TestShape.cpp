/*
	C++ code for HW5, Section 3.5, Exercise 4
*/

// include header and source file
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"

using namespace std;

// main function
int main()
{
	Shape* shapes[10];
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	shapes[3] = new Circle(Point(0, 0), 1);
	for (int i = 0; i != 4; i++) shapes[i]->Draw();
	for (int i = 0; i != 4; i++) delete shapes[i];

	// Not possible to make an instance of Shape

	return 0;
}