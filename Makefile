# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
LDFLAGS = 

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# Source and object files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/snake.c
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Output executable
TARGET = snake

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# PHONY targets
.PHONY: all clean run
