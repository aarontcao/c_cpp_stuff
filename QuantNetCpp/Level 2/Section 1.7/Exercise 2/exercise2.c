/*
    C code for HW2, Section 1.7, Exercise 2
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <stdlib.h> // C Standard library

// Declare the swap function
void Swap(double* i, double* j);

// Implement the swap function
void Swap(double* i, double* j)
{   
    double temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

// Main function
int main()
{
    // Declare the initial variables
    double i = 5; 
    double j = 10;

    // Print their initial values
    printf("Value of i before swapping: %lf\n", i);
    printf("Value of j before swapping: %lf\n", j);

    // Swap the variables
    Swap(&i, &j);

    // Print their post-swap values
    printf("Value of i after swapping: %lf\n", i);
    printf("Value of j after swapping: %lf\n",j);

    return 0;
}

