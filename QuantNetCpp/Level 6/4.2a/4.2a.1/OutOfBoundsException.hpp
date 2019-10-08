/*
	Header file for HW5, Section 4.2a, Exercise 1
*/

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

// include header and source file
#include "ArrayException.hpp"

// include for cin/cout
#include <iostream>
#include <sstream>
using namespace std;

class OutOfBoundsException : public ArrayException
{
private:
	int idx;

public:
	// Default constructor
	OutOfBoundsException() : ArrayException()
	{
	}

	// Constructor with index argument
	OutOfBoundsException(int index) : ArrayException()
	{
		idx = index;
	}

	// Destructor
	virtual ~OutOfBoundsException()
	{
	}

	// Error message
	string GetMessage()
	{
		stringstream messageStream;

		messageStream << "Index: " << idx << " out of bounds!";

		return messageStream.str();
	}
};

#endif