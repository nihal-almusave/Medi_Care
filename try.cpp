#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_ttf.h>
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

    Main_menu:
    if (menu==3)
    {
        symptoms_Rend_Background();
        input_Symptoms();
    }

    while (!quit)
    {
        while (SDL_PollEvent(&event)!=0)
        {
           SDL_GetMouseState(&mousex,&mousey);
            if (event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if (event.type==SDL_MOUSEBUTTONDOWN||event.type==SDL_KEYDOWN||event.type==SDL_TEXTINPUT)
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
                            Symptoms();
                            clear();

                        }
                        else if (mousey>=253&&mousey<=354)
                        {
                            menu=5;  
                            ambulace_front();
                            break;
                        }
                        else if (mousey>=385&&mousey<=486)
                        {
                            //Prevention of Diseases
                            menu=7;
                            prevention_page1(i);
                            break;
                        }
                        else if (mousey>=509&&mousey<=621)
                        {
                            //Give us Advice
                            menu=8;
                            CMNT_BACKGROUND();
                            CMNT();
                            break;
                        }
                        else if (mousey>=648&&mousey<=749)
                        {
                            //About
                            menu=10;
                            About_Guide();
                            break;
                        }
                    }
                    
                }
                else if (menu==1)
                {
                    Symptoms();
                    clear();
                    if (mousex>=1256&&mousex<=1401&&mousey>=917&&mousey<=963)
                    {
                        menu=menu-1;
                    }
                    else if (mousex>=42&&mousex<=173&&mousey>=916&&mousey<=964)
                    {
                        menu=menu+1;
                        Symptoms_help();
                        clear();
                    }
                    else if (mousex>=653&&mousex<=772&&mousey>=922&&mousey<=955) 
                    {
                        menu=3;
                        goto Main_menu;
                        // symptoms_Rend_Background();
                        // input_Symptoms();
                    }
                }

                else if (menu==2)
                {
                    Symptoms_help();
                    clear();
                    if(mousex>=1249&&mousex<=1439&&mousey>=888&&mousey<=936)
                    {
                        menu=1;
                    }

                }
                else if (menu==3)
                {
                    symptoms_Rend_Background();
                    input_Symptoms();

                    SDL_GetMouseState(&mousex,&mousey);
                    if(mousex>=763&&mousex<=864&&mousey>=823&&mousey<=863) 
                    {
                        clear();
                        input_symptoms="";
                        menu=4;
                    }
                    
                    else if (mousex>=1306&&mousex<=1419&&mousey>=915&&mousey<=968)
                    {
                        clear();
                        menu=1;
                    }
                }
                else if (menu==4)
                {
                    first_window();//for testing
                }
                else if (menu==5)
                {
                    menu=ambulace_front();
                    if (event.motion.x>=1287 && event.motion.x<=1424 && event.motion.y>=915 && event.motion.y<=968&&menu==5)
                    {
                        menu=0;
                        first_window();
                    }
                }
                else if (menu==6)
                {
                    menu=ambulance_Dhaka();
                }
                else if (menu==7)
                {
                    prevention_page1(i);
                    if (i==0&&event.motion.x>=5&&event.motion.x<=173&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=10;
                        
                    }
                    else if (i==0&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                    }
                    else if (i==1&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                       menu=0;
                       i=0;
                       first_window();
                    }
                    else if (i==2&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                    }
                    else if (i==3&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                    }
                    else if (i==4&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                    }
                    else if (i==5&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                    }
                    if(event.key.keysym.sym==SDLK_RIGHT&&i>=0&&i<5)
                    {
                        i=i+1;
                        menu=7;
                        prevention_page1(i);
                        
                    }
                    else if (event.key.keysym.sym==SDLK_RIGHT&&i>=5)
                    {
                        
                        i=i;
                        menu=7;
                        prevention_page1(i);
                    }
                    else if (event.key.keysym.sym==SDLK_LEFT&&i>0&&i<=5)
                    {
                        
                        i=i-1;
                        menu=7;
                        prevention_page1(i);
                    }
                    else if (event.key.keysym.sym==SDLK_RIGHT&&i<=0)
                    {
                        
                        i=i;
                        menu=7;
                        prevention_page1(i);
                    }

                }
                else if (menu==8)
                {
                    CMNT_BACKGROUND();
                    CMNT();
                    string store;
                    if (mousex>=598&&mousex<=723&&mousey>=929&&mousey<=967)  
                    {
                        store=cmnt;
                        FILE *file_of_message;
                        file_of_message=fopen("message.txt","a");

                        const char *Medium=store.c_str();
                        fputs(Medium,file_of_message);
                        fputs("**",file_of_message);
                        fclose(file_of_message);
                        clear();
                        menu=9;
                    }
                }
                else if (menu==9)
                {
                   CMNT_RETURN();
                   if (mousex>=1269&&mousex<=1410&&mousey>=923&&mousey<=949)
                   {
                       clear();
                       menu=0;
                       cmnt="";
                       //first_window();
                       
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
                else if (menu==11)
                {
                    menu=ambulance_Rajshahi();
                }
                else if (menu==12)
                {
                    menu=ambulance_chittagong();
                }
                else if (menu==13)
                {
                    menu=ambulance_Sylhet();
                }
                else if (menu==14)
                {
                    menu=ambulance_Barisal();
                }
                else  if (menu==15)
                {
                    menu=ambulance_Khulna();
                }
                else if (menu==16)
                {
                    menu=ambulance_Rangpur();
                }
                else if (menu==17)
                {
                    menu=ambulance_Mymensingh();
                }
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