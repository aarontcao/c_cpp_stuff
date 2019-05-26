// Aaron Cao
// This program will use functions to convert the amount of money you have on you to pennies. Then it will tell you the weight and volume of your money in pennies.
#include <stdio.h>

void putInArray(int *array)
{
	printf("Enter the amount of each type of money you have on you\n");
	printf("$20 bills: ");
	scanf("%d", &array[0]);
	printf("$10 bills: ");
	scanf("%d", &array[1]);
	printf("$5 bills: ");
	scanf("%d", &array[2]);
	printf("$1 bills: ");
	scanf("%d", &array[3]);	
	printf("Quarters: ");
	scanf("%d", &array[4]);	
	printf("Dimes: ");
	scanf("%d", &array[5]);	
	printf("Nickels: ");
	scanf("%d", &array[6]);
	printf("Pennies: ");
	scanf("%d", &array[7]);
	return;
}

int convertToPennies(int *array)
{
	int pennies;
	pennies = 20*100*array[0]+10*100*array[1]+5*100*array[2]+100*array[3]+25*array[4]+10*array[5]+5*array[6]+array[7];
	return pennies;
}

double convertWeight(int pennies)
{
	double weight;
	weight = pennies*2.5*0.00220462;
	return weight;
}

double convertVolume(int pennies)
{
	double volume;
	volume = (double)pennies*0.009525*0.009525*3.1415926535*0.00152*35.3147;
	// here 9.525mm is the radius of a penny, we're calculating volume in cubic meters though
	return volume;
}

int main()
{
	int array[8];
	printf("This program will convert the amount of money you have on you to pennies. Then it will tell you the weight and volume of your money in pennies.\n");
	putInArray(array);
	int pennies;
	pennies = convertToPennies(array);
	double weight;
	weight = convertWeight(pennies);
	double volume;
	volume = convertVolume(pennies);
	printf("You have %d pennies. This will weigh %lf pounds and take up %lf cubic feet of space.\n", pennies, weight, volume);
	return 0;
}