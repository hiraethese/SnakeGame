#include "../include/snake.h"
#include <stdio.h>

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    char grid[ROWS][COLS];
    Snake snake;

    init_snake(&snake);

    set_input_mode();
    atexit(restore_input_mode);

    while (1) {
        clear_grid(grid);

        for (int i = 0; i < snake.length; i++) {
            grid[snake.body[i][0]][snake.body[i][1]] = '#';
        }

        print_grid(grid);
        printf("Use W/A/S/D to move (Q to quit)\n");

        char input;
        if (read(STDIN_FILENO, &input, 1) == 1) {
            if (input == 'Q' || input == 'q') {
                break;
            }
            handle_input(&snake, input);
        }

        update_snake(&snake);
    }

    return 0;
}
