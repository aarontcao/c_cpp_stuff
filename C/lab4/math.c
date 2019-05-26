#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  
{
	int x,y;
	x = atoi(argv[1]);
	y = atoi(argv[3]);
	double result;
	if (strcmp(argv[2], "+") == 0)
	{
		result = x+y;
	}
	else if (strcmp(argv[2], "-") == 0)
	{
		result = x-y;
	}
	else if (strcmp(argv[2], "*") == 0)
	{
		result = x*y;
	}
	else if (strcmp(argv[2], "/") == 0)
	{
		result = (double)x/y;
	}
	else if (strcmp(argv[2], "%") == 0)
	{
		result = x%y;
	}		
	printf("Your result is %lf", result);
	return 0;
}