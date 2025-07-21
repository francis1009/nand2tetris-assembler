#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "symbol_table.h"
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

	FILE *asm_file = fopen(full_path, "r");
	if (asm_file == NULL) {
		perror("Error opening assembly file\n");
		return 1;
	}

	FILE *hack_file = fopen("output.hack", "w");

	Node symbol_table;
	Node *tail = &symbol_table;
	symbol_table_init(&symbol_table, &tail);

	char line[256];
	ParsedLine parsed;
	while (fgets(line, sizeof(line), asm_file)) {
		parsed = parser_parse(line);
		if (parsed.type == EMPTY || parsed.type == COMMENT ||
				parsed.type == L_INSTRUCTION) {
			continue;
		}
		char output[17];
		if (parsed.type == A_INSTRUCTION) {
			char *bin = translator_a_instruction(&symbol_table, parsed.symbol);
			snprintf(output, sizeof(output), "0%s", bin);
			free(bin);
		} else if (parsed.type == C_INSTRUCTION) {
			snprintf(output, sizeof(output), "111%s%s%s",
							 translator_comp_to_bin(parsed.comp),
							 translator_dest_to_bin(parsed.dest),
							 translator_jump_to_bin(parsed.jump));
		}
		fprintf(hack_file, "%s\n", output);
	}

	symbol_table_free(&symbol_table);
	fclose(asm_file);
	fclose(hack_file);
	return 0;
}
