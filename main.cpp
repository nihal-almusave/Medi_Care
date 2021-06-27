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
#include"Admin_panel.h"
#include"Add_Doctor.h"
#include"message.h"

//int menu=0;

void clear()
{
    cmnt_text_texture=NULL;
    cmnt_texture=NULL;

    Input_Texture=NULL;
    Text_texture=NULL;

    username_Texture=NULL;
    password_Texture=NULL;

    message_texture=NULL;
}

int main(int argc,char* args[])
{
    init();

    admin_or_user_function();
    menu=20;
    int i=0,j=0,m=0;

    int mousex,mousey;

    bool quit=true;

    while(quit)
    {
        while (SDL_PollEvent(&event)!=0)
        {
            if (event.type==SDL_QUIT)
            {
                quit=false;
            }

            else if (event.type==SDL_MOUSEBUTTONDOWN||event.type==SDL_TEXTINPUT||event.type==SDL_KEYDOWN)
            {
                SDL_GetMouseState(&mousex,&mousey);
                if (menu==20)
                {
                    admin_or_user_function();
                    if (event.motion.x>=192&&event.motion.x<=492&&event.motion.y>=439&&event.motion.y<=543)
                    {
                        menu=0;
                        first_window();
                        break;
                    }
                    // else if (event.motion.x>=845&&event.motion.x<=1135&&event.motion.y>=439&&event.motion.y<=543)
                    // {
                    //     menu=18;
                    //     if (j==0)
                    //         {
                    //             j=login_username();
                    //         }
                        
                    //         else if (j==1)
                    //         {
                    //             j=login_password();
                    //         }

                    //         if (event.motion.x>=597&&event.motion.x<=846&&event.motion.y>=749&&event.motion.y<=847)
                    //         {
                    //             if (username=="Admin1"&&password=="medi_care")
                    //             {
                    //                 menu=19;
                    //                 username="";
                    //                 password="";
                    //                 clear();
                    //                 admin_main_menu();
                    //             }
                    //             else 
                    //             {
                    //                 menu=23;
                    //                 username="";
                    //                 password="";
                    //                 clear();
                    //                 wrong();
                    //                 break;
                    //             }
                    //     }
                    // }
                    else if (event.motion.x>=845&&event.motion.x<=1135&&event.motion.y>=439&&event.motion.y<=543)
                    {
                        printf("d:1");
                        menu=18;
                        if (j==0)
                        {
                            j=login_username();
                        }
                       
                        else if (j==1)
                        {
                            login_password();
                        }
                        if (event.motion.x>=597&&event.motion.x<=846&&event.motion.y>=749&&event.motion.y<=847)
                        {
                            j=0;
                            if (username=="Admin1"&&password=="medi_care")
                            {
                                menu=19;
                                j=0;
                                username="";
                                password="";
                                clear();
                                admin_main_menu();
                                
                                break;
                            }
                            else 
                            {
                                menu=23;
                                username="";
                                password="";
                                j=0;
                                clear();
                                wrong();
                                break;
                            }
                        }
                        
                    }
                }
                else if (menu==0)
                {
                    first_window();
                    i=0;
                    if (event.motion.x>=69&&event.motion.x<=370)
                    {
                        if (event.motion.y>=111&&event.motion.y<=213)//run over all buttons
                        {
                            //Need a doctor
                            menu=1;
                            Symptoms();
                            clear();
                            break;
                        }
                        else if (event.motion.y>=253&&event.motion.y<=354)
                        {
                            menu=5;
                            ambulace_front();
                            break;
                        }
                        else if (event.motion.y>=385&&event.motion.y<=486)
                        {
                            //Prevention of Diseases
                            menu=7;
                            prevention_page1(i);
                            break;
                        }
                        else if (event.motion.y>=509&&event.motion.y<=621)
                        {
                            //Give us Advice
                            menu=8;
                            CMNT_BACKGROUND();
                            CMNT();
                            break;
                        }
                        else if (event.motion.y>=648&&event.motion.y<=749)
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
                    if (event.motion.x>=1256&&event.motion.x<=1401&&event.motion.y>=917&&event.motion.y<=963)
                        {
                            menu=menu-1;
                            first_window();
                        }
                        else if (event.motion.x>=42&&event.motion.x<=173&&event.motion.y>=916&&event.motion.y<=964)
                        {
                            menu=menu+1;
                            Symptoms_help();
                            clear();

                        }
                        else if (event.motion.x>=653&&event.motion.x<=772&&event.motion.y>=922&&event.motion.y<=955) 
                        {
                            menu=3;
                            symptoms_Rend_Background();
                            input_Symptoms();
                        }
                }
                else if(menu==2)
                {
                    Symptoms_help();
                    clear();
                    if(event.motion.x>=1249&&event.motion.x<=1439&&event.motion.y>=888&&event.motion.y<=936)
                    {
                        menu=1;
                        Symptoms();
                        clear();
                    }
                }

                else if (menu==3)
                {
                    symptoms_Rend_Background();
                    input_Symptoms();
                    if(event.motion.x>=763&&event.motion.x<=864&&event.motion.y>=823&&event.motion.y<=863) 
                    {
                        clear();
                        f=0;
                        
                        menu=4;
                        Show_information();

                    }
                    
                    else if (event.motion.x>=1306&&event.motion.x<=1419&&event.motion.y>=915&&event.motion.y<=968)
                    {
                        clear();
                        menu=1;
                        Symptoms();
                    }
                }

                //menu==4-----------

                else if (menu==4)
                {

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
                        clear();
                        store=cmnt;
                        cmnt="";
                        FILE *file_of_message;
                        file_of_message=fopen("message.txt","a");

                        const char *Medium=store.c_str();
                        fputs(Medium,file_of_message);
                        fputs("\n",file_of_message);
                        fclose(file_of_message);
                        menu=9;
                        CMNT_RETURN();
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
                       first_window();
                       break;
                       
                    } 
                }

                //menu=10------

                else if (menu==10)
                {
                    About_Guide();
                    if (event.motion.x>=698 && event.motion.x<=834&&event.motion.y>=831&&event.motion.y<=898)
                    {
                        menu=0;
                        first_window();
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

                else if (menu==18)
                {
                    
                    if (j==0)
                    {
                        j=login_username();
                    }
                    
                    else if (j==1)
                    {
                        login_password();
                    }
                    if (event.motion.x>=597&&event.motion.x<=846&&event.motion.y>=749&&event.motion.y<=847)
                        {
                            if (username=="Admin1"&&password=="medi_care")
                            {
                                menu=19;
                                username="";
                                password="";
                                j=0;
                                clear();
                                admin_main_menu();
                            }
                            else 
                            {
                                menu=23;
                                username="";
                                password="";
                                j=0;
                                clear();
                                wrong();
                                break;
                            }
                        }
                    
                }
                else if (menu==19)
                {
                    clear();
                    admin_main_menu();
                    if (event.motion.x>=121 && event.motion.x<=515 && event.motion.y>=172 && event.motion.y<=285)
                    {
                        menu=22;
                        if (m==0)
                        {
                            m=Specality_Function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=1;
                                menu=22;
                                add_doctor_function();
                                break;
                            }
                        }
                        else if (m==1)
                        {
                            add_doctor_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=2;
                                menu=22;
                                add_doctor_time_function();
                                break;
                            }
                        }
                        else if (m==2)
                        {
                            add_doctor_time_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=3;
                                menu=22;
                                add_Hospital_function();
                                break;
                            }
                        }
                        else if (m==3)
                        {
                            add_Hospital_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=4;
                                menu=22;
                                add_phone_number_function();
                                break;
                            }
                        }
                        else if (m==4)printf("sdfsf");
                        {
                            add_phone_number_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                menu=19;
                                append(5,const_cast<char*>(doctor.c_str()),const_cast<char*>(Specality.c_str()),const_cast<char*>(Hospital.c_str()),const_cast<char*>(phone_number.c_str()),const_cast<char*>(Doctor_time.c_str()));
                                break;
                            }
                        }

                    }
                    else if (event.motion.x>=121 && event.motion.x<=515 && event.motion.y>=339 && event.motion.y<=455)
                    {
                        menu=21;
                        message_function();
                        break;
                    }
                    else if (event.motion.x>=121 && event.motion.x<=515 && event.motion.y>=512 && event.motion.y<=625)
                    {
                        menu=0;
                        first_window();
                        break;
                    }
                }

                else if (menu==21)
                {
                    message_function();
                    if (event.motion.x>=1326&&event.motion.x<=1434&&event.motion.y>=913&&event.motion.y<=976)
                    {
                        menu=19;
                        admin_main_menu();
                        break;
                    }
                }

                //Add a doctor
                else if (menu==22)
                {

                    if (m==0)
                    {
                        Specality_Function();
                        if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=1;
                                menu=22;
                                add_doctor_function();
                                break;
                            }
                        
                    }
                    else if (m==1)
                    {
                        add_doctor_function();
                        if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=2;
                                menu=22;
                                add_doctor_time_function();
                                break;
                            }
                    }
                    else if (m==2)
                        {
                            add_doctor_time_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=3;
                                menu=22;
                                add_Hospital_function();
                                break;
                            }
                        }
                        else if (m==3)
                        {
                            add_Hospital_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=4;
                                menu=22;
                                add_phone_number_function();
                                break;
                            }
                        }
                        else if (m==4)
                        {
                            add_phone_number_function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                menu=19;
                                append(5,const_cast<char*>(doctor.c_str()),const_cast<char*>(Specality.c_str()),const_cast<char*>(Hospital.c_str()),const_cast<char*>(phone_number.c_str()),const_cast<char*>(Doctor_time.c_str()));
                                break;
                            }
                        }
                    // if (event.motion.x>=583 && event.motion.x<=690 && event.motion.y>=901 && event.motion.y<=965 )
                    // {

                    // }
                    // else if (event.motion.x>=1280 && event.motion.x<=1407 && event.motion.y>=901 && event.motion.y<=965 )
                    // {
                    //     menu=19;
                    //     admin_main_menu();
                    // }
                    
                }
                else if (menu==23) 
                    {
                        wrong();

                        if (event.motion.x>=795&&event.motion.x<=1075&&event.motion.y>=569&&event.motion.y<=653)
                        {
                            menu=18;
                            j=0;
                            // if (j==0)
                            // {
                            //     j=login_username();
                            // }
                            
                            // else if (j==1)
                            // {
                            //     j=login_password();
                            // }
                            break;

                        }

                        else if (event.motion.x>=795&&event.motion.x<=1075&&event.motion.y>=692&&event.motion.y<=779)
                        {
                            menu=20;
                            clear();
                            username="";
                            password="";
                            admin_or_user_function();
                            break;
                        }
                    }
            }
        }

        //ALL RENDERING TO BE DONE HERE
        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer,gTexture,NULL,NULL);

        
        SDL_RenderCopy(gRenderer,Text_texture,NULL,&Text_Rect);
        SDL_RenderCopy(gRenderer,Input_Texture,NULL,&Input_Rect);
    

        SDL_RenderCopy(gRenderer,cmnt_text_texture,NULL,&cmnt_text_rect);
        SDL_RenderCopy(gRenderer,cmnt_texture,NULL,&cmnt_rect);

        SDL_RenderCopy(gRenderer,username_Texture,NULL,&username_rect);
        SDL_RenderCopy(gRenderer,password_Texture,NULL,&password_rect);

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

        SDL_RenderCopy(gRenderer,message_texture,NULL,&message_rect);
        
        SDL_RenderPresent(gRenderer);

    }

    close();
}




                //SDL_RenderClear(gRenderer);
            