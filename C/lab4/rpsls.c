#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])  
{
	if (strcmp(argv[1], "rock") == 0)
	{
		if (strcmp(argv[2], "rock") == 0)
		{
			printf("It's a tie.\n");
		}
		else if (strcmp(argv[2], "paper") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "scissors") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "lizard") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "spock") == 0)
		{
			printf("Player Two wins.\n");
		}	
	}
	else if (strcmp(argv[1], "paper") == 0)
	{
		if (strcmp(argv[2], "rock") == 0)
		{
			printf("Player One wins.\n");	
		}
		else if (strcmp(argv[2], "paper") == 0)
		{
			printf("It's a tie.\n");
		}
		else if (strcmp(argv[2], "scissors") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "lizard") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "spock") == 0)
		{
			printf("Player One wins.\n");
		}
	}
	else if (strcmp(argv[1], "scissors") == 0)
	{
		if (strcmp(argv[2], "rock") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "paper") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "scissors") == 0)
		{
			printf("It's a tie.\n");
		}
		else if (strcmp(argv[2], "lizard") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "spock") == 0)
		{
			printf("Player Two wins.\n");
		}
	}
	else if (strcmp(argv[1], "lizard") == 0)
	{
		if (strcmp(argv[2], "rock") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "paper") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "scissors") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "lizard") == 0)
		{
			printf("It's a tie.\n");
		}
		else if (strcmp(argv[2], "spock") == 0)
		{
			printf("Player One wins.\n");
		}
	}
	else if (strcmp(argv[1], "spock") == 0)
	{
		if (strcmp(argv[2], "rock") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "paper") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "scissors") == 0)
		{
			printf("Player One wins.\n");
		}
		else if (strcmp(argv[2], "lizard") == 0)
		{
			printf("Player Two wins.\n");
		}
		else if (strcmp(argv[2], "spock") == 0)
		{
			printf("It's a tie.\n");
		}
	}		

	return 0;
}