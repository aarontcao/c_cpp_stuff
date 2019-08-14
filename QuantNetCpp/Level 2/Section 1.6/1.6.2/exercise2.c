/*
    C code for HW2, Section 1.6, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include "Defs.h" // Definitions

// Main function
int main()
{
    // Declare three variables for finding maximums
    double x;
    double y;
    double z;

    // Get inputs
    printf("Input x: ");
    scanf("%lf", &x);
    printf("Input y: ");
    scanf("%lf", &y);
    printf("Input z: ");
    scanf("%lf", &z);
    printf("\n");

    // Use the macros for finding max
    printf("Larger of x and y is: %lf\n", MAX2(x, y));
    printf("Larger of x, y, and z is: %lf\n", MAX3(x, y, z));

    return 0;
}