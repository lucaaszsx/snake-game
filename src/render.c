#include "settings.h"
#include "render.h"
#include "snake.h"
#include "food.h"
#include "game.h"

void render_set_color(SDL_Renderer *renderer, SDL_Color color);
void render_map(SDL_Renderer *renderer);
void render_snake(SDL_Renderer *renderer, snake_t *snake);
void render_food(SDL_Renderer *renderer, food_t *food);

void render_game(SDL_Renderer *renderer) {
    game_t *game = get_game();

    // Clear the renderer
    render_set_color(renderer, (SDL_Color){0, 0, 0, 0xFF});
    SDL_RenderClear(renderer);

    // Draw elements
    render_map(renderer);
    render_snake(renderer, game->snake);
    render_food(renderer, game->food);

    // Render game update
    SDL_RenderPresent(renderer);
}

void render_set_color(SDL_Renderer *renderer, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer,
                            color. r, color.g, color.b, color.a);
}

void render_fill_rect(SDL_Renderer *renderer,
                      float x, float y) {
    SDL_FRect rect = {x, y, MAP_UNIT, MAP_UNIT};

    SDL_RenderFillRect(renderer, &rect);
}

void render_map(SDL_Renderer *renderer) {
    for (int x = 0; x < SCREEN_WIDTH; x += MAP_UNIT) {
        for (int y = 0; y < SCREEN_HEIGHT; y += MAP_UNIT) {
            SDL_Color color = (x + y) % (2 * MAP_UNIT)
                ? FLOOR_COLOR_LIGHT
                : FLOOR_COLOR_DARK;
            
            render_set_color(renderer, color);
            render_fill_rect(renderer, x, y);
        }
    }
}

void render_snake(SDL_Renderer *renderer, snake_t *snake) {
    render_set_color(renderer, SNAKE_COLOR);

    for (int i = 0; i < snake->size; i++) {
        point_t p = snake->body[i];
        
        render_fill_rect(renderer, p.x * MAP_UNIT, p.y * MAP_UNIT);
    }
}

void render_food(SDL_Renderer *renderer, food_t *food) {
    render_set_color(renderer, FOOD_COLOR);
    render_fill_rect(renderer, food->pos.x * MAP_UNIT, food->pos.y * MAP_UNIT);
}