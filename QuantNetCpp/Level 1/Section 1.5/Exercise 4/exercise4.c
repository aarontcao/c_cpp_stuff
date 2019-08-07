/*
    C code for HW1, Section 1.5, Exercise 4
*/

// Preprocessor for include files
#include <stdio.h>  // C style I/O
#include <stdlib.h> // C standard library

// Printnumber method
void printnumber(int num)
{  
    // Prints the negative sign in the negative case
    if (num < 0)
    {
        putchar('-');
        putchar('\n');
        num = -num;
    }

    // As long as the number can still be divided by 10 (has a digit to print)
    if(num / 10)
    {
        printnumber(num / 10);
    }

    // Converts every digit to ASCII
    putchar('0' + num % 10);
    putchar('\n');
}

// Main function
int main()
{
    int num;
    printf("Enter an integer:");
    scanf("%d", &num);
    printnumber(num);

    return 0;
}
