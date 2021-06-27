#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_mouse.h>
#include<stdio.h>
#include<string>

using namespace std;

#include"texture.h"
#include"help.h"
#include"first_window.h"
#include"second_window.h"
#include"comment.h"
#include"prevention.h"
#include"ambulance.h"

//int menu=0;

void clear()
{
    cmnt_text_texture=NULL;
    cmnt_texture=NULL;

    Input_Texture=NULL;
    Text_texture=NULL;
}

int main(int argc,char* args[])
{
    init();

    first_window();
    int i=0;

    int mousex,mousey;

    bool quit=false;

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)!=0)
        {
           //SDL_GetMouseState(&mousex,&mousey);
            if (event.type==SDL_QUIT)
            {
                quit=true;
            }
            //else if (event.type==SDL_MOUSEBUTTONDOWN||event.type==SDL_TEXTINPUT||event.type==SDL_KEYDOWN)
            {

                symptoms_Rend_Background();
                input_Symptoms();
            }
        }
            //SDL_RenderClear(gRenderer);
            //ALL RENDERING TO BE DONE HERE
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);

            //SDL_RenderCopy(gRenderer,prevention_texture[i],NULL,NULL);
            SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);
            SDL_RenderCopy(gRenderer,Input_Texture,NULL,&Input_Rect);
            //SDL_RenderCopy(gRenderer,cmnt_Background,NULL,NULL);
            //SDL_RenderCopy(gRenderer,Symptoms_Texture,NULL,NULL);
            //SDL_RenderCopy(gRenderer,Help_texture,NULL,NULL);
            //SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);
            //SDL_RenderCopy(gRenderer,Input_Texture,NULL,&Input_Rect);
            SDL_RenderCopy(gRenderer,cmnt_text_texture,NULL,&cmnt_text_rect);
            SDL_RenderCopy(gRenderer,cmnt_texture,NULL,&cmnt_rect);
            
            SDL_RenderPresent(gRenderer);
    }

    close();
}

// if (menu==0)
                // {
                //     first_window();
                //     if (event.motion.x>=69&&event.motion.x<=370)
                //     {
                //         if (event.motion.y>=111&&event.motion.y<=213)//run over all buttons
                //         {
                //             //Need a doctor
                //             menu=1;
                //         }
                //         else if (event.motion.y>=253&&event.motion.y<=354)
                //         {
                //             menu=5;  
                //         }
                //         else if (event.motion.y>=385&&event.motion.y<=486)
                //         {
                //             //Prevention of Diseases
                //             menu=7;
                //         }
                //         else if (event.motion.y>=509&&event.motion.y<=621)
                //         {
                //             //Give us Advice
                //             menu=8;
                //         }
                //         else if (event.motion.y>=648&&event.motion.y<=749)
                //         {
                //             //About
                //             menu=10;
                //         }
                //     }
                // }
                // else if (menu==1)
                // {
                //     Symptoms();
                //     clear();
                //     if (event.motion.x>=1256&&event.motion.x<=1401&&event.motion.y>=917&&event.motion.y<=963)
                //         {
                //             menu=menu-1;
                //         }
                //         else if (event.motion.x>=42&&event.motion.x<=173&&event.motion.y>=916&&event.motion.y<=964)
                //         {
                //             menu=menu+1;
                //         }
                //         else if (event.motion.x>=653&&event.motion.x<=772&&event.motion.y>=922&&event.motion.y<=955) 
                //         {
                //             menu=3;
                //         }
                // }
                // else if(menu==2)
                // {
                //     Symptoms_help();
                //     clear();
                //     if(event.motion.x>=1249&&event.motion.x<=1439&&event.motion.y>=888&&event.motion.y<=936)
                //     {
                //         menu=1;
                //     }
                // }

                // else if (menu==3)
                // {
                //     symptoms_Rend_Background();
                //     input_Symptoms();
                // }

                // else if (menu==8)
                // {
                //     CMNT_BACKGROUND();
                //     CMNT();
                //     if (mousex>=598&&mousex<=723&&mousey>=929&&mousey<=967)  
                //     {
                //         //store=cmnt;
                //         clear();
                //         menu=9;
                //     }
                // }
                // else if (menu==9)
                // {
                //     CMNT_RETURN();
                //     if (mousex>=1269&&mousex<=1410&&mousey>=923&&mousey<=949)
                //     {
                //        clear();
                //        menu=0;
                //        cmnt="";
                //        //first_window();
                       
                //     } 
                // }
                // else if (menu==11)
                // {
                //     menu=ambulance_Rajshahi(mousex,mousey);
                // }
                // else if (menu==12)
                // {
                //     menu=ambulance_chittagong(mousex,mousey);
                // }
                // else if (menu==13)
                // {
                //     menu=ambulamce_Sylhet(mousex,mousey);
                // }
                // else if (menu==14)
                // {
                //     menu=ambulance_Barisal(mousex,mousey);
                // }
                // else  if (menu==15)
                // {
                //     menu=ambulance_Khulna(mousex,mousey);
                // }
                // else if (menu==16)
                // {
                //     menu=ambulance_Rangpur(mousex,mousey);
                // }
                // else if (menu==17)
                // {
                //     menu=ambulance_Mymensingh(mousex,mousey);
                // }