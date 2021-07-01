#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

SDL_Surface* cmnt_surface;
SDL_Texture* cmnt_texture;
SDL_Surface* cmnt_text_Surface;
SDL_Texture* cmnt_text_texture;
SDL_Texture* cmnt_Background;
SDL_Rect cmnt_rect;
SDL_Rect cmnt_text_rect;

using namespace std;

string cmnt;

SDL_Color Color={0,0,0};

bool CMNT_BACKGROUND()
{
    bool success=true;
    gTexture=loadedTexture("photos/cmnt.jpg");
    font = TTF_OpenFont("arial.ttf",45);
    cmnt_text_Surface=TTF_RenderText_Solid(font,"Give us your valuable opinion",Color);
    cmnt_text_texture=SDL_CreateTextureFromSurface(gRenderer,cmnt_text_Surface);
    cmnt_text_rect.x=300;
    cmnt_text_rect.y=200;
    cmnt_text_rect.w=cmnt_text_Surface->w;
    cmnt_text_rect.h= cmnt_text_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    //SDL_DestroyTexture(cmnt_Background);

    return true;
}

bool CMNT()
{
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch(event.type)
    {
        case SDL_TEXTINPUT:
            cmnt+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE && cmnt.size())
            {
                cmnt.pop_back();
            }
            break;

    }
    if (cmnt.size())
    {
        cmnt_surface=TTF_RenderText_Blended_Wrapped(font,cmnt.c_str(),Color,1100);
        cmnt_texture=SDL_CreateTextureFromSurface(gRenderer,cmnt_surface);

        cmnt_rect.x=100;//-(Input_Surface->w)/2.0f;
        cmnt_rect.y=300;
        cmnt_rect.w=cmnt_surface->w;
        cmnt_rect.h=cmnt_surface->h;
    }

    else
    {
        cmnt_surface=TTF_RenderText_Solid(font," ",Color);
        cmnt_texture=SDL_CreateTextureFromSurface(gRenderer,cmnt_surface);

        cmnt_rect.x=100;//-(Input_Surface->w)/2.0f;
        cmnt_rect.y=300;
        cmnt_rect.w=cmnt_surface->w;
        cmnt_rect.h=cmnt_surface->h;
    }
    return true;
}
bool CMNT_RETURN()
{
    //cmnt="";
    gTexture=loadedTexture("photos/CMNT_Return.jpg");

    return true;
}