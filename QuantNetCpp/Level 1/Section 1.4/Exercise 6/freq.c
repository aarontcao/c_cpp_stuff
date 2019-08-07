/*
    C code for HW1, Section 1.4, Exercise 6
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <stdlib.h> // C standard library

// Main function
int main()
{
    // Initialize character for input
    char c = ' ';

    // Initialize counters, EOF is not counted as a character
    int numZero = 0;
    int numOne = 0;
    int numTwo = 0;
    int numThree = 0;
    int numFour = 0;
    int numOther = -1;

    printf("Type to your heart's content, then send Ctrl + Z when finished:\n");

    // Will run until Ctrl + Z is executed
    while(c != EOF)
    {
        // When a character is input, store it and increment the character counter
        c = getchar();

        switch(c)
        {
            case '0':
            {
                numZero++;
                break;
            }
            case '1':
            {
                numOne++;
                break;
            }
            case '2':
            {
                numTwo++;
                break;
            }
            case '3':
            {
                numThree++;
                break;
            }
            case '4':
            {
                numFour++;
                break;
            }
            default:
            {
                numOther++;
                break;
            }
        }
    }

    printf("\nZeroes: %d, Ones: %d, Twos: %d, Threes: %d, Fours: %d, Other: %d\n", numZero, numOne, numTwo, numThree, numFour, numOther);

    return 0;
}
