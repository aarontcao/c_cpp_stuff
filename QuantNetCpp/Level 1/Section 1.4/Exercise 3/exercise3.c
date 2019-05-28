/*
    C code for HW1, Section 1.3, Exercise 3
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O

// Main function
int main()
{
    int x;                    // Declare x

    x = -3+4*5-6;             // x equals 11
    printf("x = %d\n", x);    // prints "x = 11"

    x = 3+4%5-6;              // x equals 1
    printf("x = %d\n", x);    // prints "x = 1"

    x = -3*4%-6/5;            // x equals 0
    printf("x = %d\n", x);    // prints "x = 0"

    x = (7+6)%5/2;            // x equals 1
    printf("x = %d\n", x);    // prints "x = 1"

    return 0;
}