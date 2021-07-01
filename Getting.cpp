#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

#include"texture.h"
#include"message.h"

bool loadmedia()
{
    bool success=true;
    gTexture=loadedTexture("photos/symptoms.jpg");
    return success;
}
//sfsfsfsfs

int main(int argc,char* args[])
{
    init();
    // loadmedia();
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
            message_show_caution();
        }
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);

        SDL_RenderCopy(gRenderer,message_caution_texture,NULL,&message_caution_rect);
        SDL_RenderPresent(gRenderer);
        
    }

    close();

}