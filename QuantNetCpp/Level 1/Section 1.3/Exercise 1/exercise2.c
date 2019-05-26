/*
    C code for HW1, Section 1.3, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O


int main()
{
    // Declare variables for calculation
    double base;
    double height;

    // Print the prompt and input base and height
    printf("This program finds the area of a right triangle.\nInput base:");
    scanf("%f", base);
    printf("Input height:")
    scanf("%f", height);   

    // Return the area
    printf("Area equals:")
    return 0.5*base*height;
}