#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

const char* TITLE = "Hello World SDL2 + TTF";
const int WIDTH = 1280, HEIGHT = 720;

int main() {
    SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Event windowEvent;

    TTF_Init();

    TTF_Font *verdanaFont = TTF_OpenFont("arial.ttf", 45);
    SDL_Color textColor = { 0, 0, 34, 255 };
    SDL_Surface *textSurface = TTF_RenderText_Solid(verdanaFont, "Hello World!", textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect;
    textRect.x = WIDTH - textSurface->w * 0.5;
    textRect.y = HEIGHT - textSurface->h * 0.5;
    textRect.w = textSurface->w;
    textRect.h = textSurface->h;

    
    bool isRunning = true;
    while (isRunning) {
        while(SDL_PollEvent(&windowEvent)!=0) {
            switch (windowEvent.type) {
                case SDL_QUIT:
                isRunning = false;
                break;
            }
        }
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_RenderPresent(renderer);
    }
    SDL_FreeSurface(textSurface);
    TTF_Quit();


    SDL_DestroyTexture(textTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}