/*
    C code for HW1, Section 1.4, Exercise 5
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    int startTempC = 0;
    int endTempC = 19;
    int stepSize = 1;
    int degC;
    double degF;

    printf("Degrees C: \t Degrees F:\n");
    for(degC = startTempC; degC <= endTempC; degC += stepSize)
    {
        degF = (double) 9 * degC/5 + 32;
        printf("%d    \t    %10.1f\n", degC, degF);
    }
    return 0;
}
