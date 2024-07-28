#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void DrawBar(SDL_Renderer *renderer, int x, int height, SDL_Color color) {
    // Draw the new bar
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect bar = {x * BAR_WIDTH, WINDOW_HEIGHT - height, BAR_WIDTH, height};
    SDL_RenderFillRect(renderer, &bar);
}

void DrawBars(SDL_Renderer *renderer, int arr[], SDL_Color color, int highlight, int pause) {
    if (VISUALIZE == 1) {
        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw each bar
        for (int i = 0; i < NUM_BARS; i++) {
            if (i == highlight) {   
                DrawBar(renderer, i, arr[i], GREEN);
            }   
            else {
                DrawBar(renderer, i, arr[i], color);
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(pause);
    }
}

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow(ALGORITHM,
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Event event;
    int running = 1;
    int numSorted = 0;

    clock_t startTime = clock();
    while (running && (numSorted < NUM_SORTS)) {
        SDL_PumpEvents();
        numSorted += Sort(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }
    clock_t endTime = clock();
    printf("Array of size %d sorted in %fms on average\n", NUM_BARS, 1000 * ((double)(endTime - startTime) / CLOCKS_PER_SEC) / NUM_SORTS);

    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;

}
