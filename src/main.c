#include <SDL3/SDL_main.h>
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "settings.h"
#include "render.h"
#include "game.h"

void print_banner(void);

int main(void) {
    print_banner();

    // Uses the number of seconds that have been passed since the Unix Epoch Time as a seed to generate random numbers
    srand(time(NULL));

    // Initialize SDL, window and renderer
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Log("SDL initialized successfully!");

    SDL_Window *window;

    if ((window = SDL_CreateWindow(APP_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, 0)) == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL window initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Log("SDL window initialized successfully!");

    SDL_Renderer *renderer;

    if ((renderer = SDL_CreateRenderer(window, NULL)) == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL renderer initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Log("SDL renderer initialized successfully!");

    // Initializes the game
    game_init();

    // Creates the main game loop
    uint64_t last_tick = 0;
    
    while (game_running()) {
        game_handle_event();
        
        uint64_t current_tick = SDL_GetTicks();

        if ((current_tick - last_tick) >= 100) {
            last_tick = current_tick;
            game_tick();
        }

        render_game(renderer);
    }

    // Closes the SDL process
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window = NULL;
    renderer = NULL;
    SDL_Quit();

    // Clear the game variables
    game_clear();
    
    return 0;
}

void print_banner(void) {
    printf("███████╗███╗   ██╗ █████╗ ██╗  ██╗███████╗\n");                      
    printf("██╔════╝████╗  ██║██╔══██╗██║ ██╔╝██╔════╝\n");                      
    printf("███████╗██╔██╗ ██║███████║█████╔╝ █████╗\n");                        
    printf("╚════██║██║╚██╗██║██╔══██║██╔═██╗ ██╔══╝\n");                        
    printf("███████║██║ ╚████║██║  ██║██║  ██╗███████╗\n");                      
    printf("╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝\n");                      
                                                                    
    printf(" ██████╗  █████╗ ███╗   ███╗███████╗\n");
    printf("██╔════╝ ██╔══██╗████╗ ████║██╔════╝\n");
    printf("██║  ███╗███████║██╔████╔██║█████╗\n");  
    printf("██║   ██║██╔══██║██║╚██╔╝██║██╔══╝\n");  
    printf("╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗\n");
    printf("╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝\n");
}