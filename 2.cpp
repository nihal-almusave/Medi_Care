#include<iostream>
//#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<string>

#include"texture.h"
#include"second_window.h"
#include"comment.h"

using namespace std;
bool running=true;



/*

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
SDL_Color color={0,0,0};
SDL_Event event;
bool running =true;

string input;

SDL_Texture* loadTexture(std::string path);


bool init ()
{
    bool success=true;

    gWindow=SDL_CreateWindow("SDL_Modified",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_RESIZABLE);
    gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
    TTF_Init();
    font=TTF_OpenFont("arial.ttf",45);
    SDL_StartTextInput();

    return success;

}

bool LoadMedia()
{
    bool success=true;
    background_texture=loadTexture("960602.jpg");
    //SDL_RenderCopy(gRenderer,background_texture,NULL,NULL); IF i use this then my screen begin blinking

    return success;

}

void Text_Ren()
{
    string text;
    Text_Surface=TTF_RenderText_Solid(font,"Hi ... I am Fine you...Write Down:",color);
    Text_texture=SDL_CreateTextureFromSurface(gRenderer,Text_Surface);
    Text_Rect.x=100;
    Text_Rect.y=100;
    Text_Rect.w=Text_Surface->w;
    Text_Rect.h=Text_Surface->h;
    //SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);IF i use this then my screen begin blinking
}
/*
bool INPUT()
{
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    //Event Loop 
   switch(event.type)
   {
        case SDL_TEXTINPUT:
            input+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE && input.size())
            {
                input.pop_back();
            }
            break;
   }

    if (input.size())
    {
        Input_Surface=TTF_RenderText_Blended_Wrapped(font,input.c_str(),color,740);
        Input_Texture=SDL_CreateTextureFromSurface(gRenderer,Input_Surface);

        Input_Rec.x=200;//-(Input_Surface->w)/2.0f;
        Input_Rec.y=220;
        Input_Rec.w=Input_Surface->w;
        Input_Rec.h=Input_Surface->h;
    }

    else
    {
        Input_Surface=TTF_RenderText_Solid(font," ",color);
        Input_Texture=SDL_CreateTextureFromSurface(gRenderer,Input_Surface);

        Input_Rec.x=200;//-(Input_Surface->w)/2.0f;
        Input_Rec.y=220;
        Input_Rec.w=Input_Surface->w;
        Input_Rec.h=Input_Surface->h;
    }
    return true;

}

SDL_Texture* loadTexture(std::string path)
{
    SDL_Surface* surface=NULL;
    SDL_Texture* texture=NULL;

    surface=IMG_Load(path.c_str());
    texture=SDL_CreateTextureFromSurface(gRenderer,surface);
    SDL_FreeSurface(surface);

    return texture;
}

int main (int argc,char* args[])
{
    string output;
    init();
    
    while(running)
    {
        while (SDL_PollEvent(&event)!=0)
        {
            if (event.type==SDL_QUIT)
            {
                running=false;
            }
            text_Rend_Background();
            input_Symptoms;

            SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);
            SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);
            SDL_RenderCopy(gRenderer,Input_Texture,NULL,&Input_Rect);
            SDL_RenderPresent(gRenderer);
        }
    }
    output=input_symptoms;
    cout<<output<<endl;
    return 0;
}*/
int main (int argc,char* args[])
{
    string output;
    init();
    
    while(running)
    {
        while (SDL_PollEvent(&event)!=0)
        {
            if (event.type==SDL_QUIT)
            {
                running=false;
            }
            symptoms_Rend_Background();
            input_Symptoms();

            SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);
            SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);
            SDL_RenderCopy(gRenderer,Input_Texture,NULL,&Input_Rect);
            SDL_RenderPresent(gRenderer);
        }
    }
    output=input_symptoms;
    cout<<output<<endl;
    return 0;
}
//SDL_Texture* loop_Textures[5];

