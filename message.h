#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

string msg;

SDL_Surface* message_surface;
SDL_Texture* message_texture;
SDL_Rect message_rect;

SDL_Texture* message_caution_texture;
SDL_Rect message_caution_rect;

SDL_Surface* message_header_surface;
SDL_Texture* message_header_texture;
SDL_Rect message_header_rect;


string readFile4( string filename )             // @lastchance: just add chars
{
   char c;
   ifstream file( filename );

   string s;
   file >> noskipws;           // needed to prevent loss of spaces and linefeeds
   while ( file >> c ) s += c;

   return s;
}


bool message_function()
{
    string filename="message.txt";
    string msg;

    msg=readFile4(filename);
    
    //msg="Hi";

    gTexture=loadedTexture("photos/mesage.JPG");

    
    color={255,255,255};

    font=TTF_OpenFont("arial.ttf",55);
    message_header_surface=TTF_RenderText_Solid(font,"User's Message",color);
    message_header_texture=SDL_CreateTextureFromSurface(gRenderer,message_header_surface);

    message_header_rect.x=450;
    message_header_rect.y=50;
    message_header_rect.w=message_header_surface->w;
    message_header_rect.h=message_header_surface->h;

    font=TTF_OpenFont("arial.ttf",40);

    message_surface=TTF_RenderText_Blended_Wrapped(font,msg.c_str(),color,900);
    message_texture=SDL_CreateTextureFromSurface(gRenderer,message_surface);

    message_rect.x=100;
    message_rect.y=200;
    message_rect.w=message_surface->w;
    message_rect.h=message_surface->h;

    return true;

}

bool Help_CLICK()
{
    gTexture=loadedTexture("photos/Prevention Help.jpg");

    return true;
}

bool message_show_caution()
{
    message_caution_texture=loadedTexture("photos/message_caution.jpg");

    message_caution_rect.x=300;
    message_caution_rect.y=300;
    message_caution_rect.w=800;
    message_caution_rect.h=400;

    return true;
}

bool message_show_caution_add()
{
    message_caution_texture=loadedTexture("photos/message_caution_add.JPG");

    message_caution_rect.x=300;
    message_caution_rect.y=300;
    message_caution_rect.w=800;
    message_caution_rect.h=400;

    return true;
}