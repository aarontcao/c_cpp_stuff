/*
	Header file for HW5, Section 4.2a, Exercise 1
*/

#ifndef ArrayException_HPP
#define ArrayException_HPP

// include for cin/cout
#include <iostream>
using namespace std;

class ArrayException
{
public:
	// Default constructor
	ArrayException() {}

	// Destructor
	virtual ~ArrayException() {}

	virtual string GetMessage() = 0;
};

#endif