/*
	C code for HW2, Section 1.9, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <stdlib.h>

// Main function
int main()
{
	int charCount = 0;
	// Create char array to hold each line of characters
	char line[99999];
	char fileName[50];

	// User input file name
	printf("Please input file name including extension.\n");

	// Get file name
	gets(fileName);

	// Open file for reading and appending
	FILE* fp;
	fopen_s(&fp, fileName, "a+");

	printf("Please write characters to your heart's content. Hit ENTER to display each line. Type CTRL + A to end the program.\n");

	// User inputs char
	int chIn = getchar();

	// CTRL+A is 1, program's stop condition
	while (chIn != 1)
	{
		// line feed char is 10, used to end line
		if (charCount > 0 && chIn == 10)
		{
			// Append line to file
			for (int i = 0; i <= charCount - 1; i++)
			{
				fputc(line[i], fp);
			}

			fputc('\n', fp);

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
		// Append line to file
		for (int i = 0; i <= charCount - 1; i++)
		{
			fputc(line[i], fp);
		}

		fputc('\n', fp);
	}

	printf("CTRL + A is a correct ending.\n");

	// Close the file.
	fclose(fp);

	return 0;
}