#include "symbol_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void symbol_table_init(Node *symbol_table, Node **tail) {
	symbol_table->symbol = NULL;
	symbol_table->value = 0;
	symbol_table->next = NULL;

	char *symbols[] = {"R0",		 "R1",	"R2",	 "R3",	"R4",	 "R5",	 "R6",	"R7",
										 "R8",		 "R9",	"R10", "R11", "R12", "R13",	 "R14", "R15",
										 "SCREEN", "KBD", "SP",	 "LCL", "ARG", "THIS", "THAT"};
	unsigned values[] = {0,	 1,	 2,	 3,	 4,			5,		 6, 7, 8, 9, 10, 11,
											 12, 13, 14, 15, 16384, 24576, 0, 1, 2, 3, 4};

	for (unsigned long i = 0; i < sizeof(symbols) / sizeof(symbols[0]); i++) {
		symbol_table_add(tail, symbols[i], values[i]);
	}
}

void symbol_table_add(Node **tail, char *symbol, unsigned int value) {
	Node *new_node = malloc(sizeof(Node));
	if (!new_node) {
		fprintf(stderr, "Error: Failed to allocate memory for new node.\n");
	}

	new_node->symbol = strdup(symbol);
	new_node->value = value;
	new_node->next = NULL;

	(*tail)->next = new_node;
	*tail = new_node;
}

unsigned int symbol_table_search(Node *symbol_table, char *symbol) {
	Node *current = symbol_table->next;
	while (current != NULL) {
		if (strcmp(current->symbol, symbol) == 0)
			return current->value;
		current = current->next;
	}

	return SYMBOL_NOT_FOUND;
}

void symbol_table_free(Node *symbol_table) {
	Node *current = symbol_table->next;
	while (current != NULL) {
		Node *to_free = current;
		free(to_free->symbol);
		current = current->next;
		free(to_free);
	}

	symbol_table->next = NULL;
}
