#include <stdlib.h>
#include "settings.h"
#include "food.h"

food_t *food_generate(snake_t *snake) {
    food_t *food = malloc(sizeof(food_t));
    point_t p;

    do {
        p.x = rand() % MAP_COLS;
        p.y = rand() % MAP_ROWS;
    } while (point_collide_arr(p, snake->body, snake->size));

    food->pos = p;

    return food;
}