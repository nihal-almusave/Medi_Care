#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

SDL_Surface* Specality_Surface;
SDL_Surface* Specality_Surface_add;

SDL_Texture* Specality_Texture;
SDL_Texture* Specality_Texture_add;

SDL_Rect Specality_Rect;
SDL_Rect Specality_add_Rect;

SDL_Color CL={255,255,255};

SDL_Event e;

TTF_Font* Font =TTF_OpenFont("arial.ttf",45);

bool Specality_function()
{

	bool success=true;

    Specality_Surface=TTF_RenderText_Solid(Font,"Specality:",CL);
    Specality_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_Surface);
    Specality_Rect.x=250;
    Specality_Rect.y=200;
    Specality_Rect.w=Specality_Surface->w;
    Specality_Rect.h=Specality_Surface->h;
    
    return success;
}
