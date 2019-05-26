#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  
{
	int x;
	x = atoi(argv[2]);
	int result;
	if (strcmp(argv[1], "1") == 0)
	{
		result = x;
	}
	else if (strcmp(argv[1], "2") == 0)
	{
		result = x+31;
	}
	else if (strcmp(argv[1], "3") == 0)
	{
		result = x+31+29;
	}
	else if (strcmp(argv[1], "4") == 0)
	{
		result = x+31+29+31;
	}
	else if (strcmp(argv[1], "5") == 0)
	{
		result = x+31+29+31+30;
	}	
	else if (strcmp(argv[1], "6") == 0)
	{
		result = x+31+29+31+30+31;
	}	
	else if (strcmp(argv[1], "7") == 0)
	{
		result = x+31+29+31+30+31+30;
	}	
	else if (strcmp(argv[1], "8") == 0)
	{
		result = x+31+29+31+30+31+30+31;
	}	
	else if (strcmp(argv[1], "9") == 0)
	{
		result = x+31+29+31+30+31+30+31+31;
	}	
	else if (strcmp(argv[1], "10") == 0)
	{
		result = x+31+29+31+30+31+30+31+31+30;
	}	
	else if (strcmp(argv[1], "11") == 0)
	{
		result = x+31+29+31+30+31+30+31+31+30+31;
	}	
	else if (strcmp(argv[1], "12") == 0)
	{
		result = x+31+29+31+30+31+30+31+31+30+31+30;
	}			
	printf("Your day of the year is %d", result);
	return 0;
}