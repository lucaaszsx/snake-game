#include <stdlib.h>
#include "settings.h"
#include "snake.h"

snake_t *snake = NULL;

snake_t *snake_create(void) {
    if (snake != NULL) return snake;

    snake = malloc(sizeof(snake_t));

    snake->size = 1;
    snake->body = malloc(sizeof(point_t));

    point_t p = (point_t){
        rand() % MAP_COLS,
        rand() % MAP_ROWS
    };

    snake->body[0] = p;

    // set the snake's initial direction to the direction fowards the farthest wall
    int dist_left = p.x;
    int dist_right = (MAP_COLS - 1) - p.x;

    snake_dir dir = dist_right > dist_left
        ? RIGHT
        : LEFT;
    
    snake_set_dir(dir);
    
    return snake;
}

void snake_grow(void) {
    // adds another part to the snake's body
    snake->size++;

    int new_size = snake->size;
    
    snake->body = realloc(snake->body, new_size * sizeof(point_t));

    point_t tail = snake->body[new_size - 2];
    
    snake->body[new_size - 1].x = tail.x;
    snake->body[new_size - 1].y = tail.y;
}

void snake_set_dir(snake_dir dir) {
    snake_dir curr_dir = snake->dir;
    
    if (
        (dir == curr_dir) ||
        ((curr_dir == LEFT && dir == RIGHT) ||
         (curr_dir == RIGHT && dir == LEFT) ||
         (curr_dir == UP && dir == DOWN) ||
         (curr_dir == DOWN && dir == UP))
    ) return;

    snake->dir = dir;
}

point_t snake_next_head(void) {
    int dx = 0, dy = 0;

    switch (snake->dir) {
        case UP:
            dy = -1;
            break;
        case DOWN:
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            break;
        case RIGHT:
            dx = 1;
            break;
    }

    point_t head = snake->body[0];

    return (point_t){head.x + dx, head.y + dy};
}

void snake_move(void) {
    point_t next_head = snake_next_head();

    for (int i = snake->size - 1; i > 0; i--) snake->body[i] = snake->body[i - 1];

    snake->body[0].x = next_head.x;
    snake->body[0].y = next_head.y;
}

void snake_destroy(void) {
    free(snake->body);
    free(snake);
}