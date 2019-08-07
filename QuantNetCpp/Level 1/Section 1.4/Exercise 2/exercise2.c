/*
    C code for HW1, Section 1.4, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <stdlib.h> // C standard library

// Main function
int main()
{
    // Initialize characters c1 and c2 for current and previous input
    char c1;
    char c2 = ' ';

    // Initialize counters, EOF is not counted as a character
    int numChar = -1;
    int numWords = 0;
    int numLines = 1;
    /*
        Start at line 1 even if the first thing sent is Ctrl + D 
        because I didn't want to write another condition to handle that case lol
    */

    printf("Type to your heart's content, then send Ctrl + D when finished:\n");

    // Will run until Ctrl + D is executed
    do
    {
        // When a character is input, store it and increment the character counter
        c1 = c2;
        c2 = getchar();
        numChar++;

        // Cases to handle words
        if(((c2 == ' ' || c2 == '\n' || c2 == '\t') && c1 != ' ' && c1 != '\n' && c1 != '\t') || (c2 == EOF && c1 != ' ' && c1 != '\n' && c1 != '\t'))
        {
            numWords++;
        }
        
        // Number of lines is always (number of \n's) + 1
        if(c2 == '\n')
        {
            numLines++;
        }
    } while(c2 > 0);

    printf("\nTotal Characters: %d\n", numChar);
    printf("Total Words: %d\n", numWords);
    printf("Total Lines: %d\n", numLines);


    return 0;
}
