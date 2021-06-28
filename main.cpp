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
#include"Admin_panel.h"
#include"Add_Doctor.h"
#include"message.h"
#include"AMBULANCE.h"

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

    Specality_Texture=NULL;
    Specality_add_Texture=NULL;

    Doctor_add_Texture=NULL;
    Doctor_Texture=NULL;

    Hospital_Texture=NULL;
    Hospital_add_Texture=NULL;

    Doctor_time_Texture=NULL;
    Doctor_time_add_Texture=NULL;

    phone_number_Texture=NULL;
    phone_number_add_Texture=NULL;

    Specality_text_Texture=NULL;
    Specality_Show_Texture=NULL;

    Doctor_date_text_Texture=NULL;
    Doctor_date_Show_Texture=NULL;

    Doctor_name_text_Texture=NULL;
    Doctor_name_Show_Texture=NULL;

    Hospital_name_text_Texture=NULL;
    Hospital_name_Show_Texture=NULL;

    phone_number_text_Texture=NULL;
    phone_number_text_show_Texture=NULL;

    Division_Texture=NULL;
    Division_text_Texture=NULL;

    amb_phone_text_Texture=NULL;
    amb_phone_Texture=NULL;

    amb_name_Texture=NULL;
    amb_name_text_Texture=NULL;

    Division_input_texture=NULL;
    Division_input_text_texture=NULL;

    Division_show_Texture=NULL;
    Division_show_text_Texture=NULL;

    amb_name_show_Texture=NULL;
    amb_name_show_text_Texture=NULL;

    amb_phone_show_Texture=NULL;
    amb_phone_show_text_Texture=NULL;


}

int main(int argc,char* args[])
{
    init();

    admin_or_user_function();
    int menu=20;
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
            //admin_or_user_function();
            else if (event.type==SDL_MOUSEBUTTONDOWN||event.type==SDL_TEXTINPUT||event.type==SDL_KEYDOWN)
            {
                if (menu==20)
                {
                    admin_or_user_function();
                    if (event.motion.x>=192&&event.motion.x<=492&&event.motion.y>=439&&event.motion.y<=543)
                    {
                        menu=0;
                        first_window();
                        break;
                    }
                    else if (event.motion.x>=845&&event.motion.x<=1135&&event.motion.y>=439&&event.motion.y<=543)
                    {
                        menu=18;
                        j=0;
                        if (j==0)
                        {
                            j=login_username();
                        }
                        break;
                        
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
                            enter_division_input();
                            break;
                        }
                        else if (event.motion.y>=385&&event.motion.y<=486)
                        {
                            //Prevention of Diseases
                            menu=7;
                            i=0;
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
                    else if (event.motion.x>=1241 && event.motion.x<=1437 && event.motion.y>=921 && event.motion.y<=973)
                    {
                        menu=18;
                        username="";
                        password="";
                        j=0;
                        if (j==0)
                        {
                            j=login_username();
                        }
                        break;
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
                    if(event.motion.x>=665&&event.motion.x<=768&&event.motion.y>=924&&event.motion.y<=961) 
                    {
                        if (strstr(input_symptoms.c_str(),"01")||strstr(input_symptoms.c_str(),"02")||strstr(input_symptoms.c_str(),"03")||strstr(input_symptoms.c_str(),"04")||strstr(input_symptoms.c_str(),"05")||strstr(input_symptoms.c_str(),"06")||strstr(input_symptoms.c_str(),"07")||strstr(input_symptoms.c_str(),"08")||strstr(input_symptoms.c_str(),"09")||strstr(input_symptoms.c_str(),"10")||strstr(input_symptoms.c_str(),"11")||strstr(input_symptoms.c_str(),"12")||strstr(input_symptoms.c_str(),"13")||strstr(input_symptoms.c_str(),"14")||strstr(input_symptoms.c_str(),"15")||strstr(input_symptoms.c_str(),"16")||strstr(input_symptoms.c_str(),"17")||strstr(input_symptoms.c_str(),"18")||strstr(input_symptoms.c_str(),"19")||strstr(input_symptoms.c_str(),"20")||strstr(input_symptoms.c_str(),"21")||strstr(input_symptoms.c_str(),"22")||strstr(input_symptoms.c_str(),"23")||strstr(input_symptoms.c_str(),"24")||strstr(input_symptoms.c_str(),"25")||strstr(input_symptoms.c_str(),"26")||strstr(input_symptoms.c_str(),"27")||strstr(input_symptoms.c_str(),"28")||strstr(input_symptoms.c_str(),"29")||strstr(input_symptoms.c_str(),"30")||strstr(input_symptoms.c_str(),"31")||strstr(input_symptoms.c_str(),"32")||strstr(input_symptoms.c_str(),"33")||strstr(input_symptoms.c_str(),"34")||strstr(input_symptoms.c_str(),"35")||strstr(input_symptoms.c_str(),"36")||strstr(input_symptoms.c_str(),"37"))
                        {
                            clear();
                            f=0;
                            menu=4;
                            Show_information();
                        }
                        else 
                        {
                            menu=12;
                            clear();
                            input_symptoms="";
                            NO_Record_Found();
                            break;
                        }
                    }
                    
                    else if (event.motion.x>=1306&&event.motion.x<=1419&&event.motion.y>=915&&event.motion.y<=968)
                    {
                        clear();
                        menu=1;
                        input_symptoms="";
                        CurrentIndex=1;
                        aa=0;
                        Symptoms();
                    }
                }

                //menu==4-----------

                else if (menu==4)
                {
                    Show_information();
                    if (event.motion.x>=1240 && event.motion.x<=1421 && event.motion.y>=905 && event.motion.y<=960)
                    {
                        menu=0;
                        clear();
                        CurrentIndex=1;
                        aa=0;
                        input_symptoms="";
                        first_window();
                        break;
                    }
                }

                //Ambulance Start
                else if (menu==5)
                {
                    enter_division_input();
                    if (event.motion.x>=654 && event.motion.x<=917 && event.motion.y>=886 && event.motion.y<=944)
                    {
                        if (strstr(Division.c_str(),"Dhaka")||strstr(Division.c_str(),"dhaka")||strstr(Division.c_str(),"DHAKA")||strstr(Division.c_str(),"Rajshahi")||strstr(Division.c_str(),"rajshahi")||strstr(Division.c_str(),"RAJSHAHI")||strstr(Division.c_str(),"Rangpur")||strstr(Division.c_str(),"rangpur")||strstr(Division.c_str(),"RANGPUR")||strstr(Division.c_str(),"Chattogram")||strstr(Division.c_str(),"chattogram")||strstr(Division.c_str(),"CHATTOGRAM")||strstr(Division.c_str(),"Sylhet")||strstr(Division.c_str(),"sylhet")||strstr(Division.c_str(),"SYLHET")||strstr(Division.c_str(),"Mymensingh")||strstr(Division.c_str(),"mymensingh")||strstr(Division.c_str(),"MYMENSINGH")||strstr(Division.c_str(),"Khulna")||strstr(Division.c_str(),"khulna")||strstr(Division.c_str(),"kHULNA")||strstr(Division.c_str(),"Barishal")||strstr(Division.c_str(),"barishal")||strstr(Division.c_str(),"BARISHAL"))
                        {
                            menu=6;
                            clear();
                            Ambulance_show();
                        }

                        else 
                        {
                            menu=12;
                            clear();
                            Division="";
                            NO_Record_Found();
                            break;
                        }

                    }
                    else if (event.motion.x>=52 && event.motion.x<=197 && event.motion.y>=886 && event.motion.y<=944)
                    {

                        menu=14;
                        clear();
                        Division="";
                        ambulance_help();
                        break;
                    }
                    else if (event.motion.x>=1244 && event.motion.x<=1389 && event.motion.y>=886 && event.motion.y<=944)
                    {
                        menu=0;
                        clear();
                        Division="";
                        first_window();
                        break;
                    }
                    
                    
                }
                //Ambulance End

                else if (menu==14)
                {
                    ambulance_help();
                    if (event.motion.x>=1125 && event.motion.x<=1325 && event.motion.y>=861 && event.motion.y<=943)
                    {
                        menu=5;
                        enter_division_input();
                        break;
                    }
                }
                //ambulance Data show start
                else if (menu==6)
                {
                    Ambulance_show();
                    if (event.motion.x>=1244 && event.motion.x<=1389 && event.motion.y>=886 && event.motion.y<=944)
                    {
                        menu=0;
                        Division="";
                        bb=0;
                        current=0;
                        first_window();
                        clear();

                    }
                }
                //Ambulance Data show end

                //prevention Start

                else if (menu==7)
                {
                    prevention_page1(i);
                    if (i==0&&event.motion.x>=5&&event.motion.x<=173&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=30;
                        Help_CLICK();
                        break;
                        
                    }
                    else if (i==0&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                        break;
                    }
                    else if (i==1&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                       menu=0;
                       i=0;
                       first_window();
                       break;
                    }
                    else if (i==2&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                        break;
                    }
                    else if (i==3&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                        break;
                    }
                    else if (i==4&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                        break;
                    }
                    else if (i==5&&event.motion.x>=1268&&event.motion.x<=1437&&event.motion.y>=913&&event.motion.y<=968)
                    {
                        menu=0;
                        i=0;
                        first_window();
                        break;
                    }
                    if(event.key.keysym.sym==SDLK_RIGHT&&i>=0&&i<5)
                    {
                        i=i+1;
                        menu=7;
                        prevention_page1(i);
                        break;
                        
                    }
                    else if (event.key.keysym.sym==SDLK_RIGHT&&i>=5)
                    {
                        
                        i=i;
                        menu=7;
                        prevention_page1(i);
                        break;
                    }
                    else if (event.key.keysym.sym==SDLK_LEFT&&i>0&&i<=5)
                    {
                        
                        i=i-1;
                        menu=7;
                        prevention_page1(i);
                        break;
                    }
                    else if (event.key.keysym.sym==SDLK_LEFT&&i<=0)
                    {
                        
                        i=i;
                        menu=7;
                        prevention_page1(i);
                        break;
                    }
                    
                }
                //prevention end


                //comment start
                else if (menu==8)
                {
                    CMNT_BACKGROUND();
                    CMNT();
                    string store;
                    if (event.motion.x>=598 &&event.motion.x<=723&&event.motion.y>=929&&event.motion.y<=967)  
                    {
                        clear();
                        store=cmnt;
                        cmnt="";
                        FILE *file_of_message;
                        file_of_message=fopen("message.txt","w");

                        const char *Medium=store.c_str();
                        fputs(Medium,file_of_message);
                        fputs("\n",file_of_message);
                        fclose(file_of_message);
                        menu=9;
                        CMNT_RETURN();
                    }

                    else if (event.motion.x>=1284 && event.motion.x<=1415 && event.motion.y>=924 && event.motion.y<=970 )
                    {
                        
                        cmnt="";
                        clear();
                        menu=0;
                        first_window();
                    }
                }
                else if (menu==9)
                {
                    CMNT_RETURN();
                    if (event.motion.x>=1269&&event.motion.x<=1410&&event.motion.y>=923&&event.motion.y<=949)
                    {
                       clear();
                       menu=0;
                       cmnt="";
                       first_window();
                       break;
                       
                    } 
                }

                //comment end


                //menu=10------
                //overall apps
                else if (menu==10)
                {
                    About_Guide();
                    if (event.motion.x>=602 && event.motion.x<=920 && event.motion.y>=883 &&event.motion.y<= 957)
                    {
                        menu=0;
                        first_window();
                        break;
                    }
                }

                else if (menu==12)
                {
                    NO_Record_Found();
                    if (event.motion.x>=1125 && event.motion.x<=1325 && event.motion.y>=861 && event.motion.y<=943)
                    {
                        menu=0;
                        clear();
                        input_symptoms="";
                        first_window();
                        break;
                    }
                }

                //admin panel_login satrt
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
                                pseudo_pass="";
                                j=0;
                                clear();
                                admin_main_menu();
                                m=0;
                            }
                            else 
                            {
                                menu=23;
                                username="";
                                password="";
                                pseudo_pass="";
                                j=0;
                                clear();
                                wrong();
                                break;
                            }
                        }
                    
                }
                //admin_panel_login end

                //Admin panel main menu
                else if (menu==19)
                {
                    clear();
                    admin_main_menu();
                    m=0;
                    if (event.motion.x>=71 && event.motion.x<=365 && event.motion.y>=111 && event.motion.y<=210 )
                    {
                        menu=22;
                        if (m==0)
                        {
                            m=Specality_Function();
                        }
                        break;

                    }

                    else if (event.motion.x>=71 && event.motion.x<=365 && event.motion.y>=276 && event.motion.y<=372)
                    {
                        menu=11;
                        if (m==0)
                        {
                            m=add_Ambulance_division_Function();
                        }
                        break;
                    }
                    else if (event.motion.x>=71 && event.motion.x<=365 && event.motion.y>=437 && event.motion.y<=532 )
                    {
                        menu=21;
                        message_function();
                        break;
                    }
                    else if (event.motion.x>=71 && event.motion.x<=365 && event.motion.y>=595 && event.motion.y<=692 )
                    {
                        menu=0;
                        first_window();
                        break;
                    }
                }


                //Message start
                else if (menu==21)
                {
                    message_function();
                    if (event.motion.x>=1326&&event.motion.x<=1434&&event.motion.y>=913&&event.motion.y<=976)
                    {
                        menu=19;
                        clear();
                        admin_main_menu();
                        break;
                    }
                }
                //message end

                //Add a doctor
                else if (menu==22)
                {

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
                        else if (m==4)
                        {
                            add_phone_number_function();
                            if (event.motion.x>=582 && event.motion.x<=697 && event.motion.y>=905 && event.motion.y<=966)
                            {
                                menu=24;
                                clear();
                                append(5,const_cast<char*>(doctor.c_str()),const_cast<char*>(Specality.c_str()),const_cast<char*>(Hospital.c_str()),const_cast<char*>(phone_number.c_str()),const_cast<char*>(Doctor_time.c_str()));
                                strings_clear();
                                add_a_doctor_Next();
                                break;
                            }
                        
                        }
                        if (event.motion.x>=1278 && event.motion.x<= 1408 && event.motion.y>=904 && event.motion.y<=968)
                        {
                            menu=19;
                            clear();
                            strings_clear();
                            admin_main_menu();
                            break;
                        }

                    
                }
                //add a doctor end

                //add a ambulance start
                else if (menu==11)
                {
                    if (m==0)
                        {
                            m=add_Ambulance_division_Function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=1;
                                menu=11;
                                add_Ambulance_name_Function();
                                break;
                            }
                        }
                        else if (m==1)
                        {
                            add_Ambulance_name_Function();
                            if (event.key.keysym.sym==SDLK_RETURN)
                            {
                                m=2;
                                menu=11;
                                add_Ambulance_phone_Function();
                                break;
                            }
                        }
                        else if (m==2)
                        {
                            add_Ambulance_phone_Function();
                            if (event.motion.x>=582 && event.motion.x<=697 && event.motion.y>=905 && event.motion.y<=966)
                            {
                                menu=24;
                                Ambulance_append(const_cast<char*>(Division_add.c_str()),const_cast<char*>(amb_name.c_str()),const_cast<char*>(amb_phone.c_str()));
                                str_clear();
                                clear();
                                add_a_doctor_Next();
                                break;
                            }
                        
                        }
                    if (event.motion.x>=1278 && event.motion.x<= 1408 && event.motion.y>=904 && event.motion.y<=968)
                        {
                            menu=19;
                            clear();
                            str_clear();
                            admin_main_menu();
                            break;
                        }
                }
                //add a doctor end

                //login wrong
                else if (menu==23) 
                    {
                        wrong();

                        if (event.motion.x>=795&&event.motion.x<=1075&&event.motion.y>=569&&event.motion.y<=653)
                        {
                            menu=18;
                            j=0;
                            if (j==0)
                            {
                                j=login_username();
                            }
                            break;

                        }

                        else if (event.motion.x>=795&&event.motion.x<=1075&&event.motion.y>=692&&event.motion.y<=779)
                        {
                            menu=20;
                            clear();
                            username="";
                            password="";
                            pseudo_pass="";
                            admin_or_user_function();
                            break;
                        }
                    }

                    //login wrong end

                    //add a doctor next page 
                else if (menu==24)
                {
                    add_a_doctor_Next();
                    if (event.motion.x>=1326 && event.motion.x<=1437 && event.motion.y>=900 && event.motion.y<=973)
                    {
                        menu=19;
                        admin_main_menu();
                        break;
                    }
                }



                //prevention Help
                else if (menu==30)
                {
                    Help_CLICK();
                    if (event.motion.x>=1327 && event.motion.x<=1435 && event.motion.y>=913 && event.motion.y<=973)
                    {
                        menu=7;
                        i=0;
                        prevention_page1(i);
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

        SDL_RenderCopy(gRenderer,Specality_text_Texture,NULL,&Specality_text_rect);
        SDL_RenderCopy(gRenderer,Specality_Show_Texture,NULL,&Specality_Show_Rect);

        SDL_RenderCopy(gRenderer,Doctor_name_text_Texture,NULL,&Doctor_name_text_Rect);
        SDL_RenderCopy(gRenderer,Doctor_name_Show_Texture,NULL,&Doctor_name_Show_Rect);

        SDL_RenderCopy(gRenderer,Doctor_date_text_Texture,NULL,&Doctor_date_text_Rect);
        SDL_RenderCopy(gRenderer,Doctor_date_Show_Texture,NULL,&Doctor_date_Show_Rect);

        SDL_RenderCopy(gRenderer,Hospital_name_text_Texture,NULL,&Hospital_name_text_Rect);
        SDL_RenderCopy(gRenderer,Hospital_name_Show_Texture,NULL,&Hospital_name_Show_Rect);

        SDL_RenderCopy(gRenderer,phone_number_text_Texture,NULL,&phone_number_text_rect);
        SDL_RenderCopy(gRenderer,phone_number_text_show_Texture,NULL,&phone_number_text_show_rect);

        SDL_RenderCopy(gRenderer,Division_Texture,NULL,&Division_rect);
        SDL_RenderCopy(gRenderer,Division_text_Texture,NULL,&Division_text_rect);

        SDL_RenderCopy(gRenderer,amb_name_Texture,NULL,&amb_name_rect);
        SDL_RenderCopy(gRenderer,amb_name_text_Texture,NULL,&amb_name_text_rect);

        SDL_RenderCopy(gRenderer,amb_phone_Texture,NULL,&amb_phone_rect);
        SDL_RenderCopy(gRenderer,amb_phone_text_Texture,NULL,&amb_phone_text_rect);

        SDL_RenderCopy(gRenderer,Division_input_texture,NULL,&Division_input_rect);
        SDL_RenderCopy(gRenderer,Division_input_text_texture,NULL,&Division_input_text_rect);

        SDL_RenderCopy(gRenderer,Division_show_Texture,NULL,&Division_show_rect);
        SDL_RenderCopy(gRenderer,Division_show_text_Texture,NULL,&Division_show_text_rect);

        SDL_RenderCopy(gRenderer,amb_name_show_Texture,NULL,&amb_name_show_rect);
        SDL_RenderCopy(gRenderer,amb_name_show_text_Texture,NULL,&amb_name_show_text_rect);

        SDL_RenderCopy(gRenderer,amb_phone_show_Texture,NULL,&amb_phone_show_rect);
        SDL_RenderCopy(gRenderer,amb_phone_show_text_Texture,NULL,&amb_phone_show_text_rect);

        SDL_RenderCopy(gRenderer,message_texture,NULL,&message_rect);
        
        SDL_RenderPresent(gRenderer);

    }

    close();
}

            