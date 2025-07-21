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
    char symbol[32];
    char dest[8];
    char comp[8];
    char jump[8];
} ParsedLine;

ParsedLine parser_parse(char *line);
void parser_rewind(FILE *file);

#endif
