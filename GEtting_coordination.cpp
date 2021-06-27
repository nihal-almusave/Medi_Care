#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

#include"texture.h"

bool loadmedia()
{
    bool success=true;
    gTexture=loadedTexture("photos/mesage.JPG");
    return success;
}
//sfsfsfsfs

int main(int argc,char* args[])
{
    init();
    loadmedia();
    int mousex=0,mousey=0;

    bool quit=false;
    SDL_Event event;

    while (!quit)
    {
        while(SDL_PollEvent(&event)!=0)
        {
            SDL_GetMouseState(&mousex,&mousey);
            printf ("%d     %d\n",mousex,mousey);
            if (event.type==SDL_QUIT)
            {
                quit=true;
            }

        }
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);
        SDL_RenderPresent(gRenderer);
        
    }

    close();

}