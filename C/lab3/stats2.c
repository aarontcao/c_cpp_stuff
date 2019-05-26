#include <stdio.h>
#include <math.h>

void readData(int *array)
{
	printf("Enter five integers: \n");
	scanf("%d", &array[0]);
	scanf("%d", &array[1]);
	scanf("%d", &array[2]);
	scanf("%d", &array[3]);
	scanf("%d", &array[4]);
	return;
}	
double findMean(int *array)
{
	double mean;
	mean = (double)(array[0] + array[1] + array[2] + array[3] + array[4])/5;
	return mean;
}
double findVariance(int *array, double mean)
{
	double a, b, c, d, e;
	a = array[0] - mean;
	b = array[1] - mean;
	c = array[2] - mean;
	d = array[3] - mean;
	e = array[4] - mean;
	double v, w, x, y, z;
	v = pow(a, 2);
	w = pow(b, 2);
	x = pow(c, 2);
	y = pow(d, 2);
	z = pow(e, 2);	
	double variance;
	variance = (double)(v+w+x+y+z)/5;
	return variance;						
}
void printResults(double mean, double variance, double stddev)
{
	printf("Your mean is %lf, your variance is %lf, and your standard deviation is %lf.\n", mean, variance, stddev);
	return;
}

int main( ) {
	int array[5];
	readData(array);
	double mean, variance, stddev;
	mean = findMean(array);
	variance = findVariance(array, mean);
	stddev = sqrt(variance);
	printResults(mean, variance, stddev);
	return 0;
}
