#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_timer.h>
#include<SDL2/SDL_mixer.h>
#include<stdio.h>
#include<string>


int menu()
{
    bool quit=false;


    while (!quit)
    {
        if (SDL_PollEvent(&event))
        {
           //SDL_GetMouseState(&mousex,&mousey);
             switch (event.type)
            {
                case SDL_QUIT:
                    quit=true;
                    break;

                case SDL_MOUSEBUTTONDOWN://||event.type==SDL_KEYDOWN||event.type==SDL_TEXTINPUT)
                    //if  (menu == 0)
                    //{
                        
                        if (event.motion.x>=69&&event.motion.x<=370)
                        {
                            if (event.motion.y>=111&&event.motion.y<=213)//run over all buttons
                            {
                                //Need a doctor
                                menu=1;

                            }
                            else if (event.motion.y>=253&&event.motion.y<=354)
                            {
                                menu=5;  
                            }
                            else if (event.motion.y>=385&&event.motion.y<=486)
                            {
                                //Prevention of Diseases
                                menu=7;
                            }
                            else if (event.motion.y>=509&&event.motion.y<=621)
                            {
                                //Give us Advice
                                menu=8;
                            }
                            else if (event.motion.y>=648&&event.motion.y<=749)
                            {
                                //About
                                menu=10;
                            }
                        }
                        
                    }
                    else if (menu==1)
                    {
                        
                        if (event.motion.x>=1256&&event.motion.x<=1401&&event.motion.y>=917&&event.motion.y<=963)
                        {
                            menu=menu-1;
                        }
                        else if (event.motion.x>=42&&event.motion.x<=173&&event.motion.y>=916&&event.motion.y<=964)
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
                        
                        if(mousex>=1249&&mousex<=1439&&mousey>=888&&mousey<=936)
                        {
                            menu=1;
                        }

                    }
                    else if (menu==3)
                    {
                        
                        
                        // CMNT_BACKGROUND();
                        // CMNT();

                        SDL_GetMouseState(&mousex,&mousey);
                        if(mousex>=763&&mousex<=864&&mousey>=823&&mousey<=863) 
                        {
                            //input_symptoms=NULL;
                            
                            menu=4;
                        }
                        
                        else if (mousex>=1306&&mousex<=1419&&mousey>=915&&mousey<=968)
                        {
                            menu=1;
                        }
                    }
                    else if (menu==4)
                    {
                        //for testing
                    }
                    else if (menu==5)
                    {
                        menu=;
                    }
                    else if (menu==6)
                    {
                        menu=;
                    }
                    else if (menu==7)
                    {
                        prevention_page1(i);
                        if (i==0&&mousex>=58&&mousex<=181&&mousey>=908&&mousey<=959)
                        {
                            menu=10;
                            
                        }
                        else if (i==0&&mousex>=1257&&mousex<=1406&&mousey>=899&&mousey<=945)
                        {
                            menu=0;
                            i=0;
                        }
                        else if (i==1&&mousex>=1288&&mousex<=1432&&mousey>=910&&mousey<=965)
                        {
                        menu=0;
                        i=0;
                        }
                        else if (i==2&&mousex>=1170&&mousex<=1321&&mousey>=877&&mousey<=929)
                        {
                            menu=0;
                            i=0;
                        }
                        else if (i==3&&mousex>=1271&&mousex<=1416&&mousey>=917&&mousey<=965)
                        {
                            menu=0;
                            i=0;
                        }
                        else if (i==4&&mousex>=1266&&mousex<=1427&&mousey>=911&&mousey<=961)
                        {
                            menu=0;
                            i=0;
                        }
                        else if (i==5&&mousex>=1288&&mousex<=1429&&mousey>=907&&mousey<=960)
                        {
                            menu=0;
                            i=0;
                        }
                        if(event.key.keysym.sym==SDLK_RIGHT&&i>=0&&i<5)
                        {
                            //prevention_page1(i);
                            i=i+1;
                            menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_RIGHT&&i>=5)
                        {
                            //prevention_page1(i);
                            i=i;
                            menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_LEFT&&i>0&&i<=5)
                        {
                            //prevention_page1(i);
                            i=i-1;
                            menu=7;
                        }
                        else if (event.key.keysym.sym==SDLK_RIGHT&&i<=0)
                        {
                            //prevention_page1(i);
                            i=i;
                            menu=7;
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
                            clear();
                            menu=9;
                        }
                        FILE *file_of_message;
                        file_of_message=fopen("message.txt","a");

                        const char *Medium=store.c_str();
                        fputs(Medium,file_of_message);
                        fputs("\n",file_of_message);
                        fclose(file_of_message);
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
                        menu=ambulance_Rajshahi(mousex,mousey);
                    }
                    else if (menu==12)
                    {
                        menu=ambulance_chittagong(mousex,mousey);
                    }
                    else if (menu==13)
                    {
                        menu=ambulamce_Sylhet(mousex,mousey);
                    }
                    else if (menu==14)
                    {
                        menu=ambulance_Barisal(mousex,mousey);
                    }
                    else  if (menu==15)
                    {
                        menu=ambulance_Khulna(mousex,mousey);
                    }
                    else if (menu==16)
                    {
                        menu=ambulance_Rangpur(mousex,mousey);
                    }
                    else if (menu==17)
                    {
                        menu=ambulance_Mymensingh(mousex,mousey);
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
    }
}