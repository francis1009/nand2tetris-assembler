#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
		fprintf(stderr, "Usage: %s <asm_file_name>\n", argv[0]);
		return 1;
	}

    return 0;
}