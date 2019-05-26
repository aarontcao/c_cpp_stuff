// Aaron Cao, this program determines what you want to wear, its condition, and whether you should wash it or wear it.
#include <stdio.h>
#include <string.h>

//takes the initial input of shirt, pants, or other
int considering(char *prompt)
{
	char str[100];
	printf("What are you considering? ");
	scanf("%s", str);
	strcpy(prompt, str);
	return 0;
}

//function for the decision tree for shirts
int whatKindShirt()
{
	char kind[100];
	printf("What kind? ");
	scanf("%s", kind);
	if (strcmp(kind,"t-shirt")==0)
	{
		char smell[100];
		printf("How does it smell? ");
		scanf("%s", smell);
		if (strcmp(smell,"bad")==0)
		{
			printf("Wash It.\n");
			return 0;
		}
		else if (strcmp(smell,"fine")==0 || strcmp(smell,"marginal")==0)
		{
			char stains[100];
			printf("Are there any stains on it? ");
			scanf("%s", stains);
			if (strcmp(stains,"lots")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(stains,"none")==0 || strcmp(stains,"small")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}
	}
	else if (strcmp(kind,"nice")==0)
	{
		char stains[100];
		printf("Are there any stains on it? ");
		scanf("%s", stains);
		if (strcmp(stains,"lots" )==0 || strcmp(stains,"small")==0)
		{
			printf("Wash It.\n");
			return 0;
		}
		else if (strcmp(stains,"none")==0)
		{
			printf("Wear It.\n");
			return 0;
		}
	}
	else if (strcmp(kind,"sweatshirt")==0)
	{
		int times;
		printf("How many times have you worn them? ");
		scanf("%d", &times);
		if (times<3)
		{
			char stains[100];
			printf("Are there any stains on it? ");
			scanf("%s", stains);
			if (strcmp(stains,"lots" )==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(stains,"none")==0 || strcmp(stains,"small")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}
		else if (times >= 3)
		{
			char smell[100];
			printf("How does it smell? ");
			scanf("%s", smell);
			if (strcmp(smell,"bad")==0 || strcmp(smell,"marginal")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(smell,"fine")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}

	}
	return 0;						
}

//function for the decision tree for pants
int whatKindPants()
{
	char kind[100];
	printf("What kind? ");
	scanf("%s", kind);
	if (strcmp(kind,"jeans")==0)
	{
		int times;
		printf("How many times have you worn them? ");
		scanf("%d", &times);
		if (times<5)
		{
			printf("Wear It.\n");
			return 0;
		}
		else if (times >= 5)
		{
			char smell[100];
			printf("How does it smell? ");
			scanf("%s", smell);
			if (strcmp(smell,"bad")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(smell,"fine")==0 || strcmp(smell,"marginal")==0)
			{
				char stains[100];
				printf("Are there any stains on it? ");
				scanf("%s", stains);
				if (strcmp(stains,"lots" )==0)
				{
					printf("Wash It.\n");
					return 0;
				}
				else if (strcmp(stains,"none")==0 || strcmp(stains,"small")==0)
				{
					printf("Wear It.\n");
					return 0;
				}
			}
		}
	}	
	else if (strcmp(kind,"other")==0)
	{
		char stains[100];
		printf("Are there any stains on it? ");
		scanf("%s", stains);
		if (strcmp(stains,"lots" )==0 || strcmp(stains,"small")==0)
		{
			printf("Wash It.\n");
			return 0;
		}
		else if (strcmp(stains,"none")==0)
		{
			printf("Wear It.\n");
			return 0;
		}
	}
	return 0;						
}

//function for the decision tree for other
int whatKindOther()
{
	char kind[100];
	printf("What kind? ");
	scanf("%s", kind);
	if (strcmp(kind,"socks")==0)
	{
		int times;
		printf("How many times have you worn them? ");
		scanf("%d", &times);
		if (times==0)
		{
			printf("Wear It.\n");
			return 0;
		}
		else if (times >= 1)
		{
			char smell[100];
			printf("How does it smell? ");
			scanf("%s", smell);
			if (strcmp(smell,"bad")==0 || strcmp(smell,"marginal")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(smell,"fine")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}
	}	
	else if (strcmp(kind,"other")==0)
	{
		int times;
		printf("How many times have you worn them? ");
		scanf("%d", &times);
		if (times==1)
		{
			char stains[100];
			printf("Are there any stains on it? ");
			scanf("%s", stains);
			if (strcmp(stains,"lots" )==0 || strcmp(stains,"small")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(stains,"none")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}
		else if (times > 1)
		{
			char smell[100];
			printf("How does it smell? ");
			scanf("%s", smell);
			if (strcmp(smell,"bad")==0)
			{
				printf("Wash It.\n");
				return 0;
			}
			else if (strcmp(smell,"fine")==0 || strcmp(smell,"marginal")==0)
			{
				printf("Wear It.\n");
				return 0;
			}
		}
	}
	return 0;						
}

//the main function that ties it all together
int main()
{
	char string[100];
	considering(string);
	if (strcmp(string, "shirt")==0)
	{
		whatKindShirt();
	}
	else if (strcmp(string, "pants")==0)
	{
		whatKindPants();
	}
	else if (strcmp(string, "other")==0)
	{
		whatKindOther();
	}	
	return 0;
}