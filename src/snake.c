#include "../include/snake.h"

struct termios origin_tattr;

void clear_terminal() {
    printf("\033[H\033[J");
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

void clear_grid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = '.';
        }
    }
}

void init_snake(Snake *snake) {
    snake->length = SNAKE_LENGTH;
    snake->direction = RIGHT;

    for (int i = 0; i < snake->length; i++) {
        snake->body[i][0] = 0;
        snake->body[i][1] = (snake->length - 1) - i;
    }
}

void update_snake(Snake *snake) {
    int new_head_x = snake->body[0][0];
    int new_head_y = snake->body[0][1];

    // Calculate the new head position based on direction
    switch (snake->direction) {
        case UP:
            new_head_x--;
            break;
        case LEFT:
            new_head_y--;
            break;
        case DOWN:
            new_head_x++;
            break;
        case RIGHT:
            new_head_y++;
            break;
        default:
            break;
    }

    // Teleport the snake if out of bounds
    if (new_head_x < 0) {
        new_head_x = ROWS - 1;
    }
    if (new_head_x >= ROWS) {
        new_head_x = 0;
    }
    if (new_head_y < 0) {
        new_head_y = COLS - 1;
    }
    if (new_head_y >= COLS) {
        new_head_y = 0;
    }

    // Shift body positions
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i][0] = snake->body[i - 1][0];
        snake->body[i][1] = snake->body[i - 1][1];
    }

    // Update the new head position
    snake->body[0][0] = new_head_x;
    snake->body[0][1] = new_head_y;
}

void handle_input(Snake *snake, char input) {
    switch (input) {
        case 'W': case 'w':
            if (snake->direction != DOWN) {
                snake->direction = UP;
            }
            break;
        case 'A': case 'a':
            if (snake->direction != RIGHT) {
                snake->direction = LEFT;
            }
            break;
        case 'S': case 's':
            if (snake->direction != UP) {
                snake->direction = DOWN;
            }
            break;
        case 'D': case 'd':
            if (snake->direction != LEFT) {
                snake->direction = RIGHT;
            }
            break;
    }
}

void handle_signal() {
    restore_input_mode();
    exit(0);
}
