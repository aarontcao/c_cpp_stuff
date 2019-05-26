#include <stdio.h>
#include <stdlib.h>

int **allocMatrix(int row, int col)
{
	int i;
	int **array;
	array=malloc(sizeof(int *) *row);
	for (i=0; i<row; i++)
	{
		array[i]=malloc(sizeof(int) *col);
	}
	return array;
}

void initMatrix(int **array, int row, int col)
{
	int i, j;
	FILE* f = fopen("Data1", "r");
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			fscanf(f, "%d", &array[i][j]);
		}
	}
	fclose(f);
	return;
}

void printMatrix(int **array, int row, int col)
{
	int i, j;
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
	return;
}

int addMatrix(int **array, int row, int col)
{
	int i, j, sum=0;
	for (i=0; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			sum+=array[i][j];
		}
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int **arr;
	int row=atoi(argv[1]);
	int col=atoi(argv[2]);
	arr=allocMatrix(row, col);
	initMatrix(arr, row, col);
	printf("Array size = %d rows and %d columns, the sum of all the elements in the array is %d\n", row, col, addMatrix(arr, row, col));
	return 0;
}