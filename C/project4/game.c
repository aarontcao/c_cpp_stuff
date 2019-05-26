#include "game.h"
#include "stdlib.h"

// the two print routines have already been written for you

void printPlayers(Players *list) {
	Players *ptr = list;
	printf("Printing the current list of players : \n");
	while (ptr != NULL) {
		printf("\tName: %s\n", ptr->name);
		ptr = ptr->next;
	}
	printf("End of player list\n");
	return;
}

void printEverything(Players *list) {
	Players *ptr = list;
	printf("Printing the current players and their possessions: \n");
	while (ptr != NULL) {
		printf("\tName: %s\n", ptr->name);
		Items *ptr2 = ptr->things;
		while (ptr2 != NULL) {
			printf("\t\t%d %s\n", ptr2->count, ptr2->name);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	printf("End of listing\n");
	return;
}

// this function adds players to the list of players
Players *add(Players *list, char *name) {
	Players *newPlayer=(Players*)malloc(sizeof(Players));
	newPlayer->name=(char*)malloc(strlen(name)+1);
	strcpy(newPlayer->name, name);
	newPlayer->next=list;
	return newPlayer;
}

// this function adds items to a player
void addItem(Players *list, char *p, char *item, int num) {
	Items *newItem=(Items*)malloc(sizeof(Items));
	newItem->name=(char*)malloc(strlen(item)+1);
	strcpy(newItem->name, item);
	newItem->count=num;

	Players *namePtr;
	for (namePtr=list; namePtr!=NULL; namePtr=namePtr->next) 
	{
		if (strcmp(p, namePtr->name)==0)
		{
			if (namePtr->things==NULL)
			{
				namePtr->things=newItem;
				namePtr->things->next=NULL;
				return;
			}

			else
			{
				Items *itemPtr;
				for (itemPtr=namePtr->things; itemPtr!=NULL; itemPtr=itemPtr->next) 
				{
					if (strcmp(item, itemPtr->name)==0)
					{
						namePtr->things->count+=num;
						return;
					}
					else
					{
						newItem->next=namePtr->things;
						namePtr->things=newItem;
						return;
					}
				}
				return;
			}
			return;
		}
	}
	return;
}

// this functon counts the number of players
int countPlayers(Players *list) {
	Players *namePtr;
	int count=0;
	for (namePtr=list; namePtr!=NULL; namePtr=namePtr->next) 
	{
		count++;
	}
	return count;
}

// this function counts the number of item for a particular player
int countItems(Players *list, char *name) {
	int count=0;
	Players *namePtr;
	for (namePtr=list; namePtr!=NULL; namePtr=namePtr->next) 
	{
		if (strcmp(name, namePtr->name)==0)
		{
			if (namePtr->things==NULL)
			{
				return count;
			}

			else
			{
				Items *itemPtr;
				for (itemPtr=namePtr->things; itemPtr!=NULL; itemPtr=itemPtr->next) 
				{
					count+=itemPtr->count;
				}
			}
		}
	}
	return count;
}

// this function counts the number of a particular item for all players
int numItems(Players *list, char *item) {
	int count=0;
	Players *namePtr;
	for (namePtr=list; namePtr!=NULL; namePtr=namePtr->next) 
	{
		Items *itemPtr;
		for (itemPtr=namePtr->things; itemPtr!=NULL; itemPtr=itemPtr->next) 
		{
			if (strcmp(item, itemPtr->name)==0)
			{
				count+=itemPtr->count;
			}
		}
	}
	return count;
}

// this function adds players to a list in alphabetical order
Players *orderedAdd(Players *list, char *name) {
	Players *ptr, *nextPtr;
	Players *newPlayer=(Players*)malloc(sizeof(Players));
	newPlayer->name=(char*)malloc(strlen(name)+1);
	strcpy(newPlayer->name, name);
	newPlayer->next=NULL;

	// case #1 list is empty
	if (list==NULL)
	{
		return newPlayer;
	}
	// case #2 add to the front
	else if (strcmp(name,list->name) <= 0)
	{
		newPlayer->next=list;
		return newPlayer;
	}
	else
	{
		ptr=list;
		nextPtr=ptr->next;
		while (ptr != NULL)
		{
			//case #3 add to the back
			if (ptr->next == NULL)
			{
				ptr->next = newPlayer;
				return list;
			}
			//case #4 add in between
			else if(strcmp(newPlayer->name,nextPtr->name) <= 0)
			{
				newPlayer->next=nextPtr;
				ptr->next=newPlayer;
				return list;
			}
			ptr=ptr->next;
			nextPtr=ptr->next;
		}
	}
	return NULL;
}

// this function adds items to a player in alphabetical order
void orderedAddItem(Players *list, char *p, char *item, int num) {
	Items *newItem=(Items*)malloc(sizeof(Items));
	newItem->name=(char*)malloc(strlen(item)+1);
	strcpy(newItem->name, item);
	newItem->count=num;
	newItem->next=NULL;
	Items *ptr, *nextPtr;

	Players *namePtr;
	for (namePtr=list; namePtr!=NULL; namePtr=namePtr->next) 
	{
		if (strcmp(p, namePtr->name)==0)
		{
			// case #1 list is empty
			if (namePtr->things==NULL)
			{
				namePtr->things=newItem;
				namePtr->things->next=NULL;
				return;
			}

			else
			{
				Items *itemPtr;
				for (itemPtr=namePtr->things; itemPtr!=NULL; itemPtr=itemPtr->next) 
				{
					// check if the item already exists
					if (strcmp(item, itemPtr->name)==0)
					{
						itemPtr->count+=num;
						return;
					}
				}

				for (itemPtr=namePtr->things; itemPtr!=NULL; itemPtr=itemPtr->next) 
				{
					// case #2 add to the front
					if (strcmp(item, namePtr->things->name) <= 0)
					{
						newItem->next=namePtr->things;
						namePtr->things=newItem;
						return;
					}
					else
					{
						ptr=namePtr->things;
						nextPtr=ptr->next;
						while (ptr != NULL)
						{
							//case #3 add to the back
							if (ptr->next == NULL)
							{
								ptr->next = newItem;
								return;
							}
							//case #4 add in between
							else if(strcmp(newItem->name,nextPtr->name) <= 0)
							{
								newItem->next=nextPtr;
								ptr->next=newItem;
								return;
							}
							ptr=ptr->next;
							nextPtr=ptr->next;
						}
					}
				}
				return;
			}
			return;
		}
	}
	return;
}

// this function makes a player give all of one particular item to another player
void gives(Players *list, char *p1, char *p2, char *item) {
	Players *namePtr1, *namePtr2;
	Items *itemPtr1;
	for (namePtr1=list; namePtr1!=NULL; namePtr1=namePtr1->next) 
	{
		if (strcmp(p1, namePtr1->name)==0)
		{
			for (namePtr2=list; namePtr2!=NULL; namePtr2=namePtr2->next) 
			{
				if (strcmp(p2, namePtr2->name)==0)
				{
					for (itemPtr1=namePtr1->things; itemPtr1!=NULL; itemPtr1=itemPtr1->next)
					{
						if (strcmp(item, itemPtr1->name)==0)
						{
							orderedAddItem(list, p2, item, itemPtr1->count);
							// deleting the first item
						    if (strcmp(item, namePtr1->things->name)==0)
							{
								Items *pNewHead=namePtr1->things->next;
								free(namePtr1->things);
								namePtr1->things=pNewHead;
								return;
							}
							// deleting an in between item
							Items *ptr;
							for (ptr=namePtr1->things; ptr->next != NULL; ptr=ptr->next)
							{
								if (strcmp(ptr->next->name, item)==0)
								{
									Items *pDel=ptr->next;
									ptr->next=ptr->next->next;
									free(pDel->name);
									free(pDel);
									return;
								}
							}
						}
					}			
				}
			}
		}
	}
	return;
}