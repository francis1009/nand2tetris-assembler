
# Compiler
CC = clang

# C Pre-Processor flags
CPP_FLAGS = -Iinclude

# Compiler flags
CFLAGS_DEBUG = -g -O0 -Wall -Wextra -Wpedantic -fsanitize=address,undefined
CFLAGS_RELEASE = -O2 -DNDEBUG -flto

# Default assembly file to translate
# Usage: make run-debug FILE=Pong.asm
FILE ?= Pong.asm

# Project structure
BUILD_DIR = bin
SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)

# Executable names
TARGET_DEBUG = $(BUILD_DIR)/assembler_debug
TARGET_RELEASE = $(BUILD_DIR)/assembler

# Phony targets
.PHONY: all debug release clean run-debug run-release

# Default target
all: debug

# Build rules
debug: $(TARGET_DEBUG)
release: $(TARGET_RELEASE)

# Generic rule to build targets from source files
$(TARGET_DEBUG): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPP_FLAGS) $(CFLAGS_DEBUG) $^ -o $@

$(TARGET_RELEASE): $(SRC)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CPP_FLAGS) $(CFLAGS_RELEASE) $^ -o $@

# Clean rule
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)

# Run rules
run: run-debug

run-debug: debug
	@echo "--- Running Debug Build with FILE: $(FILE) ---"
	./$(TARGET_DEBUG) $(FILE)

run-release: release
	@echo "--- Running Release Build with FILE: $(FILE) ---"
	./$(TARGET_RELEASE) $(FILE)