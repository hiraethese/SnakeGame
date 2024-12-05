#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <signal.h>

#define ROWS 8
#define COLS 16
#define SNAKE_LENGTH 8

typedef enum {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Direction;

typedef struct {
    int body[SNAKE_LENGTH][2];  // Array of coordinates [x, y]
    int length;                 // Predefined length
    Direction direction;        // Current direction of movement
} Snake;

// Clear the terminal.
void clear_terminal();
// Set input mode for terminal.
void set_input_mode();
// Restore the default input mode for terminal.
void restore_input_mode();
// Print the full grid in the terminal.
void print_grid(char grid[ROWS][COLS]);
// Clear the grid.
void clear_grid(char grid[ROWS][COLS]);
// Initialize the snake.
void init_snake(Snake *snake);
// Update the snake position.
void update_snake(Snake *snake);
// Handle user input.
void handle_input(Snake *snake, char input);
// Handle Cltr+C signal.
void handle_signal();
// Check if there's input ready from the user.
int input_available();

#endif // SNAKE_H
