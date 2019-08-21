/*
	C code for HW2, Section 1.7, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Define max String length
#define MAXLINE 30

// Declare the String length function
int Length(char str[]);

// Main function
int main()
{
	char string[MAXLINE + 1]; // Line of maximum 30 chars + \0
	int c; // The input character
	int i = 0; // The counter

	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);

	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0

	printf("String length is %d\n", Length(string));

	return 0;
}

// Implement the length function
int Length(char str[]) 
{
	int len = 0;
	while (str[len] != '\0')
	{
		// add 1 to count if we are not at the end of the string
		len++;
	}
	return --len;
}