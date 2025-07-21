#include "symbol_table.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void symbol_table_init(Node *symbol_table, Node **tail) {
    symbol_table->symbol = NULL;
    symbol_table->value = 0;
    symbol_table->next = NULL;

    Node *tail = symbol_table;
    symbol_table_add(tail, "R0", 0);
    symbol_table_add(tail, "R1", 1);
    symbol_table_add(tail, "R2", 2);
    symbol_table_add(tail, "R3", 3);
    symbol_table_add(tail, "R4", 4);
    symbol_table_add(tail, "R5", 5);
    symbol_table_add(tail, "R6", 6);
    symbol_table_add(tail, "R7", 7);
    symbol_table_add(tail, "R8", 8);
    symbol_table_add(tail, "R9", 9);
    symbol_table_add(tail, "R10", 10);
    symbol_table_add(tail, "R11", 11);
    symbol_table_add(tail, "R12", 12);
    symbol_table_add(tail, "R13", 13);
    symbol_table_add(tail, "R14", 14);
    symbol_table_add(tail, "R15", 15);
    symbol_table_add(tail, "SCREEN", 16384);
    symbol_table_add(tail, "KBD", 24576);
    symbol_table_add(tail, "SP", 0);
    symbol_table_add(tail, "LCL", 1);
    symbol_table_add(tail, "ARG", 2);
    symbol_table_add(tail, "THIS", 3);
    symbol_table_add(tail, "THAT", 4);
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
        if (strcmp(current->symbol, symbol) == 0) return current->value;
        current = current->next;
    }

    return -1;
}
