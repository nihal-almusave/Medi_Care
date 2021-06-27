#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_timer.h>
#include<stdio.h>
#include<string>

using namespace std;

#include"texture.h"
#include"help.h"
#include"first_window.h"
#include"second_window.h"
#include"comment.h"
#include"prevention.h"


enum menu_state{
    main_menu = 0,
    search_doctor=1,
//menu 
};




int main(int argc,char* args[])
{
    init();

    first_window();
    int menu=0,i=0;

    int mousex,mousey;

    bool quit=false;

    while (!quit)
    {
        while (SDL_PollEvent(&event)!=0)
        {
           // SDL_GetMouseState(&mousex,&mousey);
            if (event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if (event.type==SDL_MOUSEBUTTONDOWN||event.type==SDL_KEYDOWN||event.type==SDL_TEXTINPUT)
            //STRUCT OR CLASS for coordinet
            //STRUCT ARRAY NEED
            //
            {
                SDL_GetMouseState(&mousex,&mousey);
                if  (menu == 0)
                {
                    first_window();
                    if (mousex>=69&&mousex<=370)
                    {
                        if (mousey>=111&&mousey<=213)//run over all buttons
                        {
                            //Need a doctor
                            menu=1;

                        }
                        else if (mousey>=253&&mousey<=354)
                        {
                            //Ambulance   
                        }
                        else if (mousey>=385&&mousey<=486)
                        {
                            //Prevention of Diseases
                            menu=7;
                        }
                        else if (mousey>=509&&mousey<=621)
                        {
                            //Give us Advice
                            menu=8;
                        }
                        else if (mousey>=648&&mousey<=749)
                        {
                            //About
                            menu=10;
                        }
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
                        menu=menu+1;
                    }
                    else if (mousex>=653&&mousex<=772&&mousey>=922&&mousey<=955) 
                    {
                        menu=3;
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
                else if (menu==3)
                {
                    symptoms_Rend_Background();
                    input_Symptoms(); 
                    if(mousex>=663&&mousex<=764&&mousey>=923&&mousey<=963) 
                    {
                        //input_symptoms=NULL;
                        SDL_DestroyTexture(Input_Texture);
                        SDL_DestroyTexture(Symptoms_Texture);
                        menu=4;
                    }
                    else if (mousex>=1306&&mousex<=1419&&mousey>=915&&mousey<=968)
                    {
                        menu=1;
                    }
                }
                else if (menu==4)
                {
                    first_window();//for testing
                }
                else if (menu==5)
                {
                    
                }
                else if (menu==6)
                {
                    
                }
                else if (menu==7)
                {
                    prevention_page1(i);
                        if(event.key.keysym.sym==SDLK_RIGHT&&i>=0&&i<5)
                        {
                            //prevention_page1(i);
                            i=i+1;
                            //menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_RIGHT&&i>=5)
                        {
                            //prevention_page1(i);
                            i=i;
                            //menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_LEFT&&i>0&&i<=5)
                        {
                            //prevention_page1(i);
                            i=i-1;
                            //menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_RIGHT&&i<=0)
                        {
                            //prevention_page1(i);
                            i=i;
                            //menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_BACKSPACE)
                        {
                            menu=0;
                        }

                }
                else if (menu==8)
                {
                    CMNT_BACKGROUND();
                    CMNT();
                    if (mousex>=598&&mousex<=723&&mousey>=929&&mousey<=967)  
                    {
                        SDL_DestroyTexture(cmnt_texture);
                        SDL_DestroyTexture(cmnt_text_texture);
                        menu=9;
                    }
                }
                else if (menu==9)
                {
                   CMNT_RETURN();
                   if (mousex>=1269&&mousex<=1410&&mousey>=923&&mousey<=949)
                   {
                       //SDL_DestroyTexture(cmnt_text_texture);
                       //SDL_DestroyTexture(cmnt_texture);
                       menu=0;
                   } 
                }
                else if (menu==10)
                {
                    About_Guide();
                    if (mousey>=908&&mousey<=959&&mousex>=1280&&mousex<=1411)
                    {
                        menu=0;
                    }
                }
            }
            //SDL_RenderClear(gRenderer);
            /*
            if (menu==0) first_window();
            else if (menu==1)
            {
                Symptoms();
            }
            else if (menu==2)
            {
                Symptoms_help();
            }
            else if (menu==3) 
            {
                symptoms_Rend_Background();
                input_Symptoms();
            }
            else if (menu==4)
            {
                first_window();
            }
            else if (menu==5)
            {

            }
            else if (menu==6)
            {

            }
            else if (menu==7)
            {
                prevention_page1(i);
            }
            else if (menu==8)
            {
                CMNT_BACKGROUND();
                CMNT();
            }
            else if (menu==9)
            {
                CMNT_RETURN();
            }
            else if (menu==10)
            {
                About_Guide();
            }
            */
            //ALL RENDERING TO BE DONE HERE
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
    }

    close();
}
//string.c_str();