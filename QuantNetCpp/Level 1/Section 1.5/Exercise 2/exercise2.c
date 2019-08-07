/*
    C code for HW1, Section 1.5, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O

// Factorial function, returns n!
int factorial(int n);

// Main function
int main()
{
    int n = 4;
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}

int factorial(int n)
{
    if (n < 2)
    {
        return 1;
    }
    return (n*factorial(n-1));
}