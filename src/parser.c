#include "parser.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

void trim_whitespace(char *line) {
	if (!line || !*line) {
		return;
	}

	char *start = line;
	while (isspace((unsigned char) *start)) {
		start++;
	}
	if (*start == '\0') {
		line[0] = '\0';
		return;
	}
	char *end = start + strlen(start) - 1;
	while (end > start && isspace((unsigned char) *end)) {
		end--;
	}
	end[1] = '\0';

	if (start != line) {
		memmove(line, start, end - start + 2);
	}
}

ParsedLine parser_parse(char *line) {
	ParsedLine parsed;
	parsed.type = EMPTY;
	parsed.symbol[0] = '\0';
	parsed.dest[0] = '\0';
	parsed.comp[0] = '\0';
	parsed.jump[0] = '\0';

	trim_whitespace(line);

	if (line[0] == '/') {
		parsed.type = COMMENT;
	} else if (line[0] == '@') {
		parsed.type = A_INSTRUCTION;
		snprintf(parsed.symbol, sizeof(parsed.symbol), "%s", line + 1);
	} else if (line[0] == '(') {
		parsed.type = L_INSTRUCTION;
		snprintf(parsed.symbol, sizeof(parsed.symbol), "%.*s",
						 (int) sizeof(line) - 2, line + 1);
	} else if (line[0] == '\0') {
		// do nothing
	} else {
		parsed.type = C_INSTRUCTION;
		char *token = strtok(line, "=");
		if (token) {
			snprintf(parsed.dest, sizeof(parsed.dest), "%s", token);
			token = strtok(NULL, ";");
			if (token) {
				snprintf(parsed.comp, sizeof(parsed.comp), "%s", token);
			}
			token = strtok(NULL, "");
			if (token) {
				snprintf(parsed.jump, sizeof(parsed.jump), "%s", token);
			}
		} else {
			token = strtok(line, ";");
			if (token) {
				snprintf(parsed.comp, sizeof(parsed.comp), "%s", token);
				token = strtok(NULL, "");
				if (token) {
					snprintf(parsed.jump, sizeof(parsed.jump), "%s", token);
				}
			} else {
				snprintf(parsed.comp, sizeof(parsed.comp), "%s", line);
			}
		}
	}

	return parsed;
}

void parser_rewind(FILE *file) {
	if (file) {
		rewind(file);
	}
}
