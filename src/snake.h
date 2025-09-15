#ifndef _SNAKE_H
#define _SNAKE_H

#include "point.h"

/**
 * @brief Snake directions
 */
typedef enum {
    UP,
    RIGHT,
    DOWN,
    LEFT
} snake_dir;

/**
 * @brief Snake structure
 */
typedef struct snake {
    point_t *body;
    int size;
    snake_dir dir;
} snake_t;

snake_t *snake_create(void);
void snake_grow(void);
void snake_set_dir(snake_dir dir);
void snake_move();
void snake_destroy(void);

#endif