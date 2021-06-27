#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

const int screen_width=1440;
const int screen_height=980;

SDL_Window* gWindow=NULL;
SDL_Renderer* grenderer=NULL;
SDL_Surface*GSURFACE=NULL;
SDL_Texture* GTEXTURE;
SDL_Surface* gSurface=NULL;
SDL_Texture* text_texture=NULL;
SDL_Color color={255,255,255};
SDL_Rect dest;
TTF_Font* font;
SDL_Rect Background;

SDL_Texture* loadedTexture(std::string path)
{
    SDL_Surface* surface=NULL;

    SDL_Texture* newTexture=NULL;

    //Load image at specified path
    surface=IMG_Load(path.c_str());

    //Create texture from surface pixels
    newTexture=SDL_CreateTextureFromSurface(grenderer,surface);

    //free surface
    SDL_FreeSurface(surface);

    return newTexture;

}


int main (int argc,char*args[])
{
    gWindow=SDL_CreateWindow("SDL text",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,screen_width,screen_height,SDL_WINDOW_RESIZABLE);
    grenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
    TTF_Init();
    font=TTF_OpenFont("arial.ttf",40);
    if (!font)
    {
        printf ("Failed to load Font\n");
    }
    GTEXTURE=loadedTexture("960602.jpg");
    if (!GTEXTURE)
    {
        printf("Failed\n");
    }
    gSurface=TTF_RenderText_Solid(font,"HELLO WORLD!",color);
    if (!gSurface)
    {
        printf ("Failed to render text");
    }
    text_texture=SDL_CreateTextureFromSurface(grenderer,gSurface);
    dest.x=30;
    dest.y=0;
    dest.w=700;
    dest.h=100;

    Background.x=0;
    Background.y=0;
    Background.w=screen_width;
    Background.h=screen_height;

    SDL_RenderClear(grenderer);

    SDL_RenderCopy(grenderer,GTEXTURE,NULL,NULL);
    SDL_RenderCopy(grenderer,text_texture,NULL,&dest);
    
    SDL_RenderPresent(grenderer);

    SDL_Delay(5000);
    SDL_Quit();
}
