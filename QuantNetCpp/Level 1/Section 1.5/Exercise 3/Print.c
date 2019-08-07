/*
    C code for HW1, Section 1.5, Exercise 3
*/

// Preprocessor for include files
#include <stdio.h> // C style I/O
#include "Print.h" // Print method, Main.c and Print.c must be compiled together 

void print(int i)
{
    i *= 2;
    printf("%d\n", i);
    return;
}