/*
    C code for HW1, Section 1.3, Exercise 9
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O

// Main function
int main()
{
    int x = 1;
    int y = 1;

    x += y += x;                      // x equals 3, y equals 2
    printf("%d\n\n", (x<y)?y:x);      // x is not less than y, so prints 3, which x equals
    printf("%d\n", (x<y)?x++:y++);    // x is not less than y, so prints 2, which y equals, but then postfix ++
    printf("%d\n", x);                // prints 3
    printf("%d\n", y);                // prints 3, since the postfix ++ incremented y
    return 0;
}
