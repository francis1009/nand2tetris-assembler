#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "symbol_table.h"

const char *translator_a_instruction(Node *symbol_table, char *symbol);
const char *translator_comp_to_bin(char *comp);
const char *translator_dest_to_bin(char *dest);
const char *translator_jump_to_bin(char *jump);

#endif
