/*
    C code for HW1, Section 1.3, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O

// Main function
int main()
{
    // Declare variables for calculation
    double base;
    double height;

    // Print the prompt and input base and height
    printf("This program finds the area of a right triangle.\nInput base:");
    scanf("%lf", &base);
    printf("Input height:");
    scanf("%lf", &height);   

    // Print the area
    printf("Area equals: %lf\n", 0.5*base*height);    
    return 0;
}
