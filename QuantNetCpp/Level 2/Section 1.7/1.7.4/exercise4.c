/*
C code for HW2, Section 1.7, Exercise 4
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Declare DayName function
void DayName(int inputNum);


// Implement DayName function
void DayName(int inputNum)
{
	// Array to save days of the week as strings
	char* dayToName[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	printf("Day %i is a %s.\n", inputNum, dayToName[inputNum - 1]);
}

// Main function
int main()
{
	int daynumber;
	printf("Please indicate the day number you would like to output (1-7 represents Sunday-Saturday):\n");

	// User inputs day number they would like to output
	scanf_s("%d", &daynumber);

	// Error check to ensure valid day of the week
	if (daynumber > 0 && daynumber < 8) 
	{
		// Display day of the week
		DayName(daynumber);
	}
	return 0;
}
