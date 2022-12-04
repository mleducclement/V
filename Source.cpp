#include <iostream>
#include <string>

#include <SDL.h>

// CONSTANTS
int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 600;
int SCREEN_FPS = 60;
float SCREEN_TICKS_PER_FRAME = 1000.0f / SCREEN_FPS;

// GLOBAL VARS
SDL_Window* mWindow = NULL;
SDL_Renderer* mRenderer = NULL;
SDL_Texture* mText = NULL;

bool init() {
    bool successFlag = true;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to initialize SDL! SDL_Error: " << SDL_GetError() << std::endl;
        successFlag = false;
    }

    mWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (mWindow == NULL) {
        std::cout << "Failed to create window! SDL_Error: " << SDL_GetError() << std::endl;
        successFlag = false;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRenderer == NULL) {
        std::cout << "Failed to create renderer! SDL_Error: " << SDL_GetError() << std::endl;
        successFlag = false;
    }

    SDL_StartTextInput();

    return successFlag;
}

void close() {
    SDL_StopTextInput();

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;
    mRenderer = NULL;

    SDL_Quit();
}

int main(int argc, char* argv[]) {


    close();
    return 0;
}