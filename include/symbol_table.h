#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct Node {
	char *symbol;
	unsigned int value;
	struct Node *next;
} Node;

void symbol_table_init(Node *symbol_table, Node **tail);
void symbol_table_add(Node **tail, char *symbol, unsigned int value);
unsigned int symbol_table_search(Node *symbol_table, char *symbol);

#endif
