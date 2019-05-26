#include <stdio.h>

int getNumber(char *string)
{
	int a;
	printf("Please enter the %s number: \n", string);
	scanf("%d", &a);
	return a; 
}

int main( ) 
{
	int x = getNumber("first");
	int y = getNumber("second");
	int z = getNumber("third");
	int sum = x + y + z;
	double avg = sum / 3.0;
	printf("\nThe average of these three numbers is %lf\n", avg);
	return 0;
}
