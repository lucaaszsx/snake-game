#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <SDL3/SDL.h>

/**
 * @brief General app definitions
 */
#define APP_TITLE "Snake Game"

/**
 * @brief Screen size definitions
 */
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400

/**
 * @brief Game map definitions
 */
#define MAP_UNIT 50
#define MAP_ROWS SCREEN_HEIGHT / MAP_UNIT
#define MAP_COLS SCREEN_WIDTH / MAP_UNIT

/**
 * @brief Game board colors
 */
extern const SDL_Color FLOOR_COLOR_LIGHT;
extern const SDL_Color FLOOR_COLOR_DARK;
extern const SDL_Color SNAKE_COLOR;
extern const SDL_Color FOOD_COLOR;

#endif