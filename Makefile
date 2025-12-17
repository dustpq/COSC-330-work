# Makefile for building the microShell program with a static library

# Compiler
CC = clang

# Directories
LIB_DIR = oct29
SRC_DIR = .

# Source files
SOURCES = $(SRC_DIR)/microShell.c $(SRC_DIR)/microShell_functions.c

# Object files
OBJS = $(LIB_DIR)/oct_29_lib.o

# Static library
LIB = $(LIB_DIR)/liboct29.a

# Output executable
OUTPUT = microShell

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Default target
all: $(OUTPUT)

# Build the static library
$(LIB): $(OBJS)
    ar rcs $@ $^
    ranlib $@

# Compile object files
$(LIB_DIR)/oct_29_lib.o: $(LIB_DIR)/oct_29_lib.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the executable
$(OUTPUT): $(SOURCES) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) -L$(LIB_DIR) -loct29

# Clean up build files
clean:
	rm -f $(LIB_DIR)/*.o $(LIB) $(OUTPUT)

.PHONY: all clean