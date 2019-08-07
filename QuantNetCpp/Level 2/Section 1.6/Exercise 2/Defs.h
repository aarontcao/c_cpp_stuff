/*
    C code for HW2, Section 1.6, Exercise 2
*/

// Avoid multiple inclusion
#ifndef DEFS
#define DEFS

// Define macros for maximum
#define MAX2(x, y) ((x > y) ? (x) : (y))
#define MAX3(x, y, z) ((MAX2(x, y) > z) ? MAX2(x, y) : (z))

#endif