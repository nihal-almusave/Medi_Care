#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_timer.h>
#include<stdio.h>
#include<string>

#include"texture.h"
#include"help.h"
#include"first_window.h"
#include"second_window.h"

enum menu_state{
    main_menu = 0,
    search_doctor=1,
//menu 
};




int main(int argc,char* args[])
{
    init();

    first_window();
    int menu=0;

    int mousex,mousey;

    bool quit=false;

    while (!quit)
    {
        while (SDL_PollEvent(&event)!=0)
        {
            SDL_GetMouseState(&mousex,&mousey);
            if (event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if (event.type==SDL_MOUSEBUTTONDOWN)
            //STRUCT OR CLASS for coordinet
            //STRUCT ARRAY NEED
            //
            {
                if  (menu == 0)
                {
                    first_window();
                    if (mousex>=275&&mousex<=572&&mousey>=243&&mousey<=349)//run over all buttons
                    {
                        menu=1;
                        Symptoms();
                        //instead of loadmedia set some variable to get new texture
                        //menu = doctormenu
                        //tex=...
                    }
                }
                else if (menu==1)
                {
                    Symptoms();
                    if (mousex>=1256&&mousex<=1401&&mousey>=917&&mousey<=963)
                    {
                        menu=menu-1;
                    }
                    else if (mousex>=42&&mousex<=173&&mousey>=916&&mousey<=964)
                    {
                        Symptoms_help();
                        menu=menu+1;
                    }
                }
                else if (menu==2)
                {
                    Symptoms_help();
                    if(mousex>=1249&&mousex<=1439&&mousey>=888&&mousey<=936)
                    {
                        menu=1;
                    }

                }

            }
            
            //ALL RENDERING TO BE DONE HERE
            SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);
            //SDL_RenderCopy(gRenderer,Symptoms_Texture,NULL,NULL);
            //SDL_RenderCopy(gRenderer,Help_texture,NULL,NULL);
            
            SDL_RenderPresent(gRenderer);
            
        }
    }

    close();
}