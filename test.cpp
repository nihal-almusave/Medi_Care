#include<iostream>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<string>

#include"texture.h"
#include"first_window.h"
#include"second_window.h"
//#include"text_rendering.h"
#include"Add_Doctor.h"
#include"Admin_panel.h"
#include"message.h"

using namespace std;

bool run =true;

void clear()
{
    Specality_Texture=NULL;
    Specality_add_Texture=NULL;

    Doctor_Texture=NULL;
    Doctor_add_Texture=NULL;

    Doctor_time_Texture=NULL;
    Doctor_time_add_Texture=NULL;

    Hospital_Texture=NULL;
    Hospital_add_Texture=NULL;

    username_Texture=NULL;
    password_Texture=NULL;

    phone_number_Texture=NULL;
    phone_number_add_Texture=NULL;
}

int main(int argc,char* args[])
{
    init();

    Show_information();

    int menu=0;
    while (run)
    {
        while (SDL_PollEvent(&event)!=0)
        {
            if (event.type==SDL_QUIT)
            {
                run =false;
            }
            Show_information();
            
        }
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);

        // SDL_RenderCopy(gRenderer,output_Texture,NULL,&name_rect);
        SDL_RenderCopy(gRenderer,Specality_Texture,NULL,&Specality_rect);
        SDL_RenderCopy(gRenderer,Specality_add_Texture,NULL,&Specality_add_rect);

        SDL_RenderCopy(gRenderer,Doctor_Texture,NULL,&Doctor_rect);
        SDL_RenderCopy(gRenderer,Doctor_add_Texture,NULL,&Doctor_add_rect);

        SDL_RenderCopy(gRenderer,Doctor_time_Texture,NULL,&Doctor_time_rect);
        SDL_RenderCopy(gRenderer,Doctor_time_add_Texture,NULL,&Doctor_time_add_rect);

        SDL_RenderCopy(gRenderer,Hospital_Texture,NULL,&Hospital_rect);
        SDL_RenderCopy(gRenderer,Hospital_add_Texture,NULL,&Hospital_add_rect);

        SDL_RenderCopy(gRenderer,phone_number_Texture,NULL,&phone_number_rect);
        SDL_RenderCopy(gRenderer,phone_number_add_Texture,NULL,&phone_number_add_rect);


        SDL_RenderCopy(gRenderer,username_Texture,NULL,&username_rect);
        SDL_RenderCopy(gRenderer,password_Texture,NULL,&password_rect);

        SDL_RenderCopy(gRenderer,Specality_text_Texture,NULL,&Specality_text_rect);
        SDL_RenderCopy(gRenderer,Specality_Show_Texture,NULL,&Specality_Show_Rect);

        SDL_RenderCopy(gRenderer,message_texture,NULL,&message_rect);

        SDL_RenderPresent(gRenderer);
    }

    close();
}
