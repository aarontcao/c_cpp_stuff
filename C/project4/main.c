#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scanner.h"
#include "game.h"

int main(int argc, char *argv[]) {
	char *cmd;
	Players *list = NULL;
	FILE *fp = fopen(argv[1], "r");;
	cmd = readToken(fp);
	// Commands are:
	//	add [playername]
	//	printPlayers 
	//	addItem [player, item, count]
	//	countPlayers
	//	countItems [player]
	//	numItems [item]
	//	addOrder [player]
	//	addItemOrder [player, item, count]
	//	gives [player1, player2, item]

	while ( !feof(fp) ) {
		char *player, *item, *player2;
		int quantity;
		// process command
		if (strcmp(cmd, "add") == 0) {
			player = readToken(fp);
			printf("\nAdding the player %s\n", player);
			list = add(list, player);
		}
		if (strcmp(cmd, "printPlayers") == 0) {
			printf("\nPrinting all the players in the game\n");
			printPlayers(list);
		}
		if (strcmp(cmd, "addItem") == 0) {
			player = readToken(fp);
			item = readToken(fp);
			quantity = readInt(fp);
			printf("\nAdding %d copies of %s for player %s\n", quantity, item, player);
			addItem(list, player, item, quantity);
		}
		if (strcmp(cmd, "printEverything") == 0) {
			printf("\nPrinting all information for all players in the game\n");
			printEverything(list);
		}
		if (strcmp(cmd, "countPlayers") == 0) {
			printf("\nCounting the players in the game\n");
			int count = countPlayers(list);
			printf("\tThere are %d players in the game\n", count);
		}
		if (strcmp(cmd, "countItems") == 0) {
			player = readToken(fp);
			printf("\nCounting the number of items for player %s\n", player);
			int count = countItems(list, player);
			printf("\tPlayer %s has %d items\n", player, count);
		}
		if (strcmp(cmd, "numItems") == 0) {
			item = readToken(fp);
			printf("\nCounting the total instances of item %s\n", item);
			int count = numItems(list, item);
			printf("\tThere are %d instances of %s in the game\n", count, item);
		}
		if (strcmp(cmd, "addOrder") == 0) {
			player = readToken(fp);
			printf("\nAdding the player %s in alphabetical order\n", player);
			list = orderedAdd(list, player);
		}
		if (strcmp(cmd, "addItemOrder") == 0) {
			player = readToken(fp);
			item = readToken(fp);
			quantity = readInt(fp);
			printf("\nAdding %d copies of %s for player %s in alphabetical order\n", quantity, item, player);
			orderedAddItem(list, player, item, quantity);
		}
		if (strcmp(cmd, "gives") == 0) {
			player = readToken(fp);
			player2 = readToken(fp);
			item = readToken(fp);
			printf("\nGiving %s's %s to %s\n", player, item, player2);
			gives(list, player, player2, item);
		}
	
		// get next command
		cmd = readToken(fp);
	}
		
	return 0;
}
