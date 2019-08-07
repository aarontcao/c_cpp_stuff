/*
    C code for HW1, Section 1.5, Exercise 1
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O

// Minus function, returns a - b
double minus(double a, double b);

// Main function
int main()
{
    double a = 10;
    double b = 5;
    printf("%f - %f = %f\n", a, b, minus(a, b));
    return 0;
}

double minus(double a, double b)
{
    return (a - b);
}