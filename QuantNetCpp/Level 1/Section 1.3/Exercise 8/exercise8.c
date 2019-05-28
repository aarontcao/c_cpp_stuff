/*
    C code for HW1, Section 1.3, Exercise 8
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    int x = 2;
    int y;
    int z;

    x *= 3+2;               // x equals 10
    printf("x = %d\n", x);


    x *= y = z = 4;         // x equals 40, y equals z equals 4
    printf("x = %d\n", x);

    x = y == z;             // x equals 1, y equals z equals 4
    printf("x = %d\n", x);

    return 0;
}
