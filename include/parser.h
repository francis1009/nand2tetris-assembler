#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

typedef enum {
	A_INSTRUCTION,
	C_INSTRUCTION,
	L_INSTRUCTION,
	COMMENT,
	EMPTY
} InstructionType;

typedef struct {
	InstructionType type;
	char symbol[64];
	char dest[4];
	char comp[4];
	char jump[4];
} ParsedLine;

ParsedLine parser_parse(char *line);
void parser_rewind(FILE *file);

#endif
