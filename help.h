#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>


SDL_Texture* Help_texture=NULL;

bool Symptoms_help()
{
    bool success=true;

    gTexture=loadedTexture("photos/Help_texture1.jpg");
    font=TTF_OpenFont("arial.ttf",46);
    //SDL_RenderCopy(gRenderer,Help_texture,NULL,NULL);

    return success;
}

bool About_Guide()
{
    gTexture=loadedTexture("photos/About page.jpg");

    return true;
}
