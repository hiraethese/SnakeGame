#include "../include/snake.h"

int main() {
    char grid[ROWS][COLS];
    char symbol = '#';
    int x = 0, y = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = '.';
        }
    }

    set_input_mode();
    atexit(restore_input_mode);

    while (1) {
        grid[x][y] = symbol;
        print_grid(grid);
        grid[x][y] = '.';

        printf("Use W/A/S/D to move (Q to quit)\n");

        char input = getchar();
        // Q is pressed
        if (input == 'Q' || input == 'q') {
            break;
        }

        switch (input) {
            // W is pressed
            case 'W': case 'w':
                if (x > 0) {
                    x--;
                } else {
                    x = ROWS - 1;
                }
                break;
            // A is pressed
            case 'A': case 'a':
                if (y > 0) {
                    y--;
                } else {
                    y = COLS - 1;
                }
                break;
            // S is pressed
            case 'S': case 's':
                if (x < ROWS - 1) {
                    x++;
                } else {
                    x = 0;
                }
                break;
            // D is pressed
            case 'D': case 'd':
                if (y < COLS - 1) {
                    y++;
                } else {
                    y = 0;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
