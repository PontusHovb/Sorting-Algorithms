CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

# Include path for SDL2 (adjust if needed)
SDL2_INCLUDE_DIR = /usr/include/SDL2

# Libraries
LDFLAGS = -lSDL2

# Targets
TARGETS = sorting

# Rules
all: $(TARGETS)

# Sorting executable
sorting: gui.o sorting_algorithms.o help_functions.o
	$(CC) $(CFLAGS) -I$(SDL2_INCLUDE_DIR) $^ $(LDFLAGS) -o sorting

# Object file rules
gui.o: gui.c functions.h
	$(CC) $(CFLAGS) -I$(SDL2_INCLUDE_DIR) -c gui.c

sorting_algorithms.o: sorting_algorithms.c functions.h
	$(CC) $(CFLAGS) -I$(SDL2_INCLUDE_DIR) -c sorting_algorithms.c

help_functions.o: help_functions.c functions.h
	$(CC) $(CFLAGS) -I$(SDL2_INCLUDE_DIR) -c help_functions.c

clean:
	rm -f $(TARGETS) gui.o sorting_algorithms.o help_functions.o

.PHONY: all clean
