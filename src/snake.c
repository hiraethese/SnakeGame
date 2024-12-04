#include "../include/snake.h"

struct termios origin_tattr;

void clear_terminal() {
    system("clear");
}

void set_input_mode() {
    struct termios tattr;

    tcgetattr(STDIN_FILENO, &origin_tattr);
    tattr = origin_tattr;

    tattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}

void restore_input_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &origin_tattr);
}

void print_grid(char grid[ROWS][COLS]) {
    clear_terminal();

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}
