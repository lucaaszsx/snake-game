#ifndef _GAME_H
#define _GAME_H

#include "snake.h"
#include "food.h"

/**
 * @brief Game structure
 */
typedef struct game {
    snake_t *snake;
    food_t *food;
    bool game_over;
    bool running;
} game_t;

void game_init(void);
void game_clear(void);
void game_handle_event(void);
void game_tick(void);
bool game_running(void);
game_t *get_game(void);

#endif