/*
    C code for HW2, Section 1.6, Exercise 1
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include "Defs.h" // Definitions

// Main function
int main()
{
    // Declare two variables for printing
    double a;
    double b;

    // Get input and print
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input b: ");
    scanf("%lf", &b);
    printf("\n");

    // Use the macros for printing
    PRINT1(a);
    PRINT2(a,b);

    return 0;
}