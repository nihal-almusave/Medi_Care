#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
//#include<iostream>
#include<string>

const int screen_width=1440;
const int screen_height=980;

SDL_Window* gWindow=NULL;

SDL_Renderer* renderer=NULL;

SDL_Event event;

SDL_Rect DisplayRect;

SDL_Texture* background;

SDL_Rect rectBackground;

TTF_Font* font;

SDL_Surface* message;

SDL_Texture* text;

SDL_Rect textRect;

SDL_Color textColor={255,255,255};

SDL_Texture* loadedTexture(std::string path);

//std::string data

bool init()
{
    bool success=true;

    gWindow=SDL_CreateWindow("text",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_RESIZABLE);

    renderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);

    return success;
}

bool loadmedia()
{
    bool success=true;

    int w=0,h=0;
    int screenw=screen_width;
    int screenh=screen_height;

    background=loadedTexture("960602.jpg");

    SDL_QueryTexture(background,NULL,NULL,&w,&h);
    rectBackground.x=0;
    rectBackground.y=0;
    rectBackground.w=256;
    rectBackground.h=0;

    SDL_GetRendererOutputSize(renderer,&screenw,&screenh);
    DisplayRect.x=DisplayRect.y=0;
    DisplayRect.w=screen_width;
    DisplayRect.h=screen_height;

    return success;
}

bool Text()
{
    bool success=true;
    int w=0,h=0;
    

    font=TTF_OpenFont("arial.ttf",20);

    message=TTF_RenderText_Solid(font,"Hi......Good",textColor);
    text=SDL_CreateTextureFromSurface(renderer,message);

    SDL_QueryTexture(text,NULL,NULL,&w,&h);
    textRect.x=50;
    textRect.y=50;
    textRect.w=w;
    textRect.h=h;
    return success;
}

bool Renderer()
{

    bool success=true;
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,&rectBackground,&DisplayRect);
    //SDL_RenderCopy(renderer,text,NULL,&textRect);
    SDL_RenderPresent(renderer);

    return success;
}

SDL_Texture* loadedTexture(std::string path)
{
    SDL_Surface* surface=NULL;

    SDL_Texture* newTexture=NULL;

    //Load image at specified path
    surface=IMG_Load(path.c_str());

    //Create texture from surface pixels
    newTexture=SDL_CreateTextureFromSurface(renderer,surface);

    //free surface
    SDL_FreeSurface(surface);

    return newTexture;

}

void free()
{
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(text);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);

    IMG_Quit();
    SDL_Quit();
}

int main (int argc,char* args[])
{
    bool success=true;

    init();
    loadmedia();
    Text();

    while (success)
    {
        while(SDL_PollEvent(&event)!=0)
        {
            if (event.type==SDL_QUIT)
            {
                success=false;
            }
        }
        Renderer();
    }

    free();
}