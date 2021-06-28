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

    font=TTF_OpenFont("arial.ttf",30);
    color={255,255,255};


    message_surface=TTF_RenderText_Blended_Wrapped(font,msg.c_str(),color,800);
    message_texture=SDL_CreateTextureFromSurface(gRenderer,message_surface);

    message_rect.x=100;
    message_rect.y=100;
    message_rect.w=message_surface->w;
    message_rect.h=message_surface->h;

    return true;

}

bool Help_CLICK()
{
    gTexture=loadedTexture("photos/Prevention Help.jpg");

    return true;
}