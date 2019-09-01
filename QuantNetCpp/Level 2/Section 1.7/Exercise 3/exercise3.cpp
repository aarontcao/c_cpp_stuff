/*
	C code for HW2, Section 1.7, Exercise 3
*/

/* Predict what will be printed on the screen */

#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialize array
int a[] = { 0, 1, 2, 3, 4 };

int main()
{
	int i;
	int* p;

	for (i = 0; i <= 4; i++) PRD(a[i]); // 1 Output: 01234
	NL;

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p); // 2 Output: 01234
	NL;
	NL;

	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]); // 3 Output: 01234
	NL;

	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4 Output: 024
	NL;
	NL;

	for (p = a + 4; p >= a; p--) PRD(*p); // 5 Output: 43210
	NL;

	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]); // 6 Output: 43210
	NL;

	for (p = a + 4; p >= a; p--) PRD(a[p - a]); // 7 Output: 43210
	NL;

	return 0;
}