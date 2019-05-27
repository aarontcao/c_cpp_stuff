/*
    C code for HW1, Section 1.3, Exercise 5
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    int i = 10;         // i equals 10
    int j = 20;         // j equals 20
    int x;

    // Postfix operator
    x = j + i--;
    /*
        x equals 30 and i equals 9
        equivalent code:
        x = i + j;
        i = i - 1;
    */

    // Prefix operator
    i = 10;
    x = j + --i;
    /*
        x equals 29 and i equals 9
        equivalent code:
        i = i - 1;
        x = i + j;
    */

    return 0;
}
