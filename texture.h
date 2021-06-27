#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

const int SCREEN_WIDTH=1440;
const int SCREEN_HEIGHT=980;

SDL_Renderer* gRenderer=NULL;

SDL_Texture* gTexture=NULL;

SDL_Window* gWindow=NULL;

SDL_Surface* gSurface=NULL;

TTF_Font* font;
SDL_Color color;

bool init()
{
    bool success=true;
    //Create Window 
    gWindow=SDL_CreateWindow("Medi Care",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_RESIZABLE);

    //Create Renderer
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

    //initialize ttf 
    TTF_Init();

    return success;
}

void close()
{
    SDL_DestroyTexture(gTexture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    IMG_Quit();
    SDL_Quit();
}

SDL_Texture* loadedTexture(std::string path)
{
    SDL_Surface* surface=NULL;

    SDL_Texture* newTexture=NULL;

    //Load image at specified path
    surface=IMG_Load(path.c_str());

    //Create texture from surface pixels
    newTexture=SDL_CreateTextureFromSurface(gRenderer,surface);

    //free surface
    SDL_FreeSurface(surface);

    return newTexture;

}