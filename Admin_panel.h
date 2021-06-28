#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_mouse.h>
#include<stdio.h>
#include<string>

using namespace std;



bool admin_or_user_function()
{
    gTexture=loadedTexture("photos/Front page.jpg");

    return true;
}

string username;
string password;
string pseudo_pass;

int k;

//username field
SDL_Surface* username_surface;
SDL_Texture* username_Texture;
SDL_Rect username_rect;

//password field
SDL_Surface* password_surface;
SDL_Texture* password_Texture;
SDL_Rect password_rect;

int login_password();

int login_username()
{
    k=0;
    
    gTexture=loadedTexture("photos/login_page.jpg");

    font = TTF_OpenFont("arial.ttf",45);

    color={0,0,0};

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            username+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&username.size())
            {
                username.pop_back();
            }
            else if (event.key.keysym.sym==SDLK_RETURN)
            {
                k=1;
                printf("k:%d\n",k);
                break;
            }
            break;
    }

    if (username.size())
    {
        username_surface=TTF_RenderText_Blended_Wrapped(font,username.c_str(),color,700);
        username_Texture=SDL_CreateTextureFromSurface(gRenderer,username_surface);

        username_rect.x=400;
        username_rect.y=340;
        username_rect.w=username_surface->w;
        username_rect.h=username_surface->h;
    }

    else 
    {
        username_surface=TTF_RenderText_Solid(font," ",color);
        username_Texture=SDL_CreateTextureFromSurface(gRenderer,username_surface);

        username_rect.x=400;
        username_rect.y=340;
        username_rect.w=username_surface->w;
        username_rect.h=username_surface->h;
    }
    
    return k;
    
}

int login_password()
{
    font = TTF_OpenFont("arial.ttf",45);

    TTF_Init();
    SDL_StartTextInput();

    
    color={0,0,0};
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            password+=event.text.text;
            pseudo_pass+="*";
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&password.size())
            {
                password.pop_back();
                pseudo_pass.pop_back();
            }
        break;
    }

    if (password.size())
    {
        password_surface=TTF_RenderText_Blended_Wrapped(font,pseudo_pass.c_str(),color,700);
        password_Texture=SDL_CreateTextureFromSurface(gRenderer,password_surface);

        password_rect.x=400;
        password_rect.y=535;
        password_rect.w=password_surface->w;
        password_rect.h=password_surface->h;
    }

    else 
    {
        password_surface=TTF_RenderText_Solid(font," ",color);
        password_Texture=SDL_CreateTextureFromSurface(gRenderer,password_surface);

        password_rect.x=400;
        password_rect.y=535;
        password_rect.w=password_surface->w;
        password_rect.h=password_surface->h;
    }

    return k;
}

bool admin_main_menu()
{
    gTexture=loadedTexture("photos/Admin_main_menu.jpg");

    return true;
}

bool wrong()
{
    gTexture=loadedTexture("photos/Wrong portion.jpg");

    return true;
}