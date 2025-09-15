#ifndef _FOOD_H
#define _FOOD_H

#include "snake.h"
#include "point.h"

/**
 * @brief Game food structure
 */
typedef struct food {
    point_t pos;
} food_t;

food_t *food_generate(snake_t *snake);

#endif