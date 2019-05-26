#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  
{
	int array[5];
	array[0] = atoi(argv[1]);
	array[1] = atoi(argv[2]);
	array[2] = atoi(argv[3]);
	array[3] = atoi(argv[4]);
	array[4] = atoi(argv[5]);			
	int range, i;
	int max=array[0];
	int min=array[0];
	for (i=0; i<5; i++)
	{
		if (array[i]>max)
		{
			max = array[i];
		}
	}

	for (i=0; i<5; i++)
	{
		if (array[i]<min)
		{
			min = array[i];
		}
	}

	range = max - min;
	printf("The range is %d", range);
	return 0;
}