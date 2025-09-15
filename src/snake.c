#include <stdlib.h>
#include "settings.h"
#include "snake.h"
#include<SDL3/SDL.h>
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

    // Set the snake's initial direction to the direction fowards the farthest wall
    int dist_left = p.x;
    int dist_right = (MAP_COLS - 1) - p.x;

    snake_dir dir = dist_right > dist_left
        ? RIGHT
        : LEFT;
    
    snake_set_dir(dir);
    
    return snake;
}

void snake_grow(void) {
    snake->size++;
    snake->body = realloc(snake->body, snake->size);
    // to-do: grow
}

void snake_set_dir(snake_dir dir) {
    snake_dir curr_dir = snake->dir;
    SDL_Log("curr=%d,new=%d",curr_dir,dir);
    if (
        (dir != curr_dir) ||
        ((curr_dir == LEFT && dir == RIGHT) ||
         (curr_dir == RIGHT && dir == LEFT) ||
         (curr_dir == UP && dir == DOWN) ||
         (curr_dir == DOWN && dir == UP))
    ) return;

    snake->dir = dir;
}

void snake_move() {
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

    for (int i = snake->size - 1; i > 0; i--) {
        snake->body[i].x += snake->body[i - 1].x;
        snake->body[i].y += snake->body[i - 1].y;
    }

    snake->body[0].x += dx;
    snake->body[0].y += dy;
}

void snake_destroy(void) {
    free(snake->body);
    free(snake);
}