/*
    C code for HW1, Section 1.3, Exercise 6
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    // Declare a signed and an unsigned int for shifting
    unsigned int x = 10;        // Unsigned ints will always be logically shifted
    int y = -10;                // Signed ints will always be arithmetically shifted

    printf("Unsigned int to be logically shifted: x = %d\n", x);
    printf("Signed int to be arithmetically shifted: y = %d\n\n", y);

    // First shift
    x = x >> 1;
    printf("x >> 1 evaluates to: %d\n" , x);
    if (x < 0)
    {
        printf("Negative, a 1 was inserted left\n\n");
    }
    else
    {
        printf("Positive, a 0 was inserted left\n\n");
    }

    y = y >> 1;
    printf("y >> 1 evaluates to: %d\n" , y);
    if (y < 0)
    {
        printf("Negative, a 1 was inserted left\n\n");
    }
    else
    {
        printf("Positive, a 0 was inserted left\n\n");
    }

    // Second shift
    x = x >> 1;
    printf("(x >> 1) >> 1 evaluates to: %d\n" , x);
    if (x < 0)
    {
        printf("Negative, a 1 was inserted left\n\n");
    }
    else
    {
        printf("Positive, a 0 was inserted left\n\n");
    }

    y = y >> 1;
    printf("(y >> 1) >> 1 evaluates to: %d\n" , y);
    if (y < 0)
    {
        printf("Negative, a 1 was inserted left\n\n");
    }
    else
    {
        printf("Positive, a 0 was inserted left\n\n");
    }

    return 0;
}
