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
    printf("Initial Values: i = %d, j= %d\n", i, j);


    // Postfix operator
    x = j + i--;
    printf("x = j + i-- evaluates to:\n");
    printf("x = %d, i = %d, j = %d\n\n", x, i, j);
    /*
        x equals 30 and i equals 9
        equivalent code:
        x = i + j;
        i = i - 1;
    */

    // Prefix operator
    i = 10;
    x = j + --i;
    printf("x = j + --i evaluates to:\n");
    printf("x = %d, i = %d, j = %d\n\n", x, i, j);
    /*
        x equals 29 and i equals 9
        equivalent code:
        i = i - 1;
        x = i + j;
    */

    return 0;
}
