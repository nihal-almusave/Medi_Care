#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<string>

using namespace std;

const int screen_width=980;
const int screen_height=1440;

SDL_Window* gWindow=NULL;
SDL_Renderer* gRenderer=NULL;
SDL_Texture* background_texture=NULL;
SDL_Texture* Text_texture=NULL;
SDL_Texture* Input_Texture=NULL;
SDL_Surface* Background_Surface=NULL;
SDL_Surface* Text_Surface=NULL;
SDL_Surface* Input_Surface=NULL;
SDL_Rect Text_Rect;
SDL_Rect Input_Rec;

TTF_Font* font;
SDL_Color color;
SDL_Event event;

string input;
