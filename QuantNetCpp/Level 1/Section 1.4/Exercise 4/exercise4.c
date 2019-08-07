/*
    C code for HW1, Section 1.4, Exercise 4
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    int startTempF = 0;
    int endTempF = 300;
    int stepSize = 20;
    int degF = startTempF;
    double degC;

    printf("Degrees F: \t Degrees C:\n");
    while(degF <= endTempF)
    {
        degC = (double) 5 * (degF - 32)/9;
        printf("%d    \t    %10.1f\n", degF, degC);
        degF += stepSize;
    }
    return 0;
}
