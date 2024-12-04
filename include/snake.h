#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define ROWS 8
#define COLS 16

// Clear the terminal.
void clear_terminal();
// Set input mode for terminal.
void set_input_mode();
// Restore the default input mode for terminal.
void restore_input_mode();
// Print the full grid in the terminal.
void print_grid(char grid[ROWS][COLS]);

#endif // SNAKE_H
