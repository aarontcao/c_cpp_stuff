/*
	C code for HW2, Section 1.9, Exercise 1
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{	
	int charCount = 0;
	// Create char array to hold each line of characters
	char line[99999];

	printf("Please write characters to your heart's content. Hit ENTER to display each line. Type CTRL + A to end the program.\n");

	// User inputs char
	int chIn = getchar();

	// CTRL+A is 1, program's stop condition
	while (chIn != 1) 
	{
		// line feed char is 10, used to end line
		if (charCount > 0 && chIn == 10)
		{
			// after user ends line, display characters in that line. Array size to display is character count.
			printf("Output Line: ");
			for (int i = 0; i < charCount; i++)
			{
				putchar(line[i]);
			}
			putchar('\n');

			// reset character count
			charCount = 0;
			continue;
		}
		// store input character in next empty slot of the array
		line[charCount] = chIn;

		// increment the count
		charCount++;

		// get next input before rerunning the loop
		chIn = getchar();
	}

	// if there are characters left in the array, output them
	if (charCount > 0)
	{
		printf("Output Line: ");
		for (int i = 0; i < charCount; i++)
		{
			putchar(line[i]);
		}
		putchar('\n');
	}

	printf("CTRL + A is a correct ending.\n");
	return 0;
}
