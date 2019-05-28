/*
    C code for HW1, Section 1.3, Exercise 4
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    // Declare an int takes value 0 or 1 to represent marriage state
    int married = 0;
    printf("Assigned married = %d\n", married);

    // Conditional print statement
    printf("Marriage status: %c\n", married ? 'T' : 'F');   
    return 0;
}
