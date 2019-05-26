#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct item {
	char *name;
	int count;
	struct item *next;
} Items;

typedef struct player {
	char *name;
	Items *things;
	struct player *next;
} Players;

Players *add(Players *, char *);
void printPlayers(Players *);

void addItem(Players *, char *, char *, int);
void printEverything(Players *);

int countPlayers(Players *);
int countItems(Players *, char *);
int numItems(Players *, char *);

Players *orderedAdd(Players *, char *);
void orderedAddItem(Players *, char *p, char *i, int n);

void gives(Players *, char *, char *, char *);