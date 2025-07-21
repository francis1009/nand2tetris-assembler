#include <stdio.h>

#include "symbol_table.h"
#include "parser.h"
#include "translator.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <asm_file_name>\n", argv[0]);
		return 1;
	}

	const char *asm_filename = argv[1];
	printf("Attempting to read assembly file: %s\n", asm_filename);

	char full_path[256];
	int result = snprintf(full_path, sizeof(full_path), "asm/%s", asm_filename);
	if (result < 0 || result >= (int) sizeof(full_path)) {
		fprintf(stderr, "Error: Assembly filename is too long.\n");
		return 1;
	}

	FILE *file = fopen(full_path, "r");
	if (file == NULL) {
		perror("Error opening assembly file\n");
		return 1;
	}

	Node symbol_table;
	Node *tail = &symbol_table;
	symbol_table_init(&symbol_table, &tail);


	char line[256];
	ParsedLine parsed;
	while (fgets(line, sizeof(line), file)) {
		parsed = parser_parse(line);
	}

	fclose(file);
	return 0;
}
