#include <SDL3/SDL.h>
#include <stdlib.h>
#include "game.h"

SDL_Event event;
game_t *game = NULL;

void game_init(void) {
    game = malloc(sizeof(game_t));

    game->snake = snake_create();
    game->food = food_generate(game->snake);
    game->running = true;
    game->game_over = false;

    SDL_zero(event);
}

void game_clear(void) {
    snake_destroy();
    free(game->food);
    free(game);
}

void game_handle_event(void) {
    // Update keyboard state
    SDL_PumpEvents();

    const bool *state = SDL_GetKeyboardState(NULL);

    // Sets the snake direction based on key pressed
    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) snake_set_dir(UP);
    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) snake_set_dir(LEFT);
    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) snake_set_dir(DOWN);
    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) snake_set_dir(RIGHT);
    
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            game->running = false;
            continue;
        }
    }
}

void game_tick(void) {
    if (game->snake == NULL || game->food == NULL)
        return;
    
    snake_move();
}

bool game_running(void) {
    return game->running;
}

game_t *get_game(void) {
    return game;
}