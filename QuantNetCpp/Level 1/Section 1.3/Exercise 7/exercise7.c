/*
    C code for HW1, Section 1.3, Exercise 7
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    // Declare int x and an int n to perform x*2^n
    int x;
    int n;
    printf("Input a positive integer x: ");
    scanf("%d", &x);
    int y = x;      // For printing at the end
    printf("x will be multiplied by 2^n, input a non-negative n: ");
    scanf("%d", &n);

    // Perform a left shift n times
    int i;
    for(i = 0; i < n; i++)
    {
        x <<= 1;
    }

    printf("%d*(2^%d) = %d\n", y, n, x);

    return 0;
}
