#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<iostream>
#include<sstream>
#include<string>


#include"Doctor_file.h"

using namespace std;



SDL_Texture* Symptoms_Texture;
SDL_Surface* Text_Surface;
SDL_Texture* Text_texture;
SDL_Surface* Input_Surface;
SDL_Texture* Input_Texture;
SDL_Rect Text_Rect;
SDL_Rect Input_Rect;
string input_symptoms;

int CurrentIndex =1;
int f=0;
//for showing information

SDL_Surface* Specality_text_Surface;
SDL_Texture* Specality_text_Texture;
SDL_Rect Specality_text_rect;

SDL_Surface* Doctor_name_text_Surface;
SDL_Texture* Doctor_name_text_Texture;
SDL_Rect Doctor_name_text_Rect;

SDL_Surface* Doctor_date_text_Surface;
SDL_Texture* Doctor_date_text_Texture;
SDL_Rect Doctor_date_text_Rect;

SDL_Surface* Hospital_name_text_Surface;
SDL_Texture* Hospital_name_text_Texture;
SDL_Rect Hospital_name_text_Rect;

SDL_Surface* phone_number_text_Surface;
SDL_Texture* phone_number_text_Texture;
SDL_Rect phone_number_text_rect;



SDL_Surface* Specality_Show_Surface;
SDL_Texture* Specality_Show_Texture;
SDL_Rect Specality_Show_Rect;

SDL_Surface* Doctor_name_Show_Surface;
SDL_Texture* Doctor_name_Show_Texture;
SDL_Rect Doctor_name_Show_Rect;

SDL_Surface* Doctor_date_Show_Surface;
SDL_Texture* Doctor_date_Show_Texture;
SDL_Rect Doctor_date_Show_Rect;

SDL_Surface* Hospital_name_Show_Surface;
SDL_Texture* Hospital_name_Show_Texture;
SDL_Rect Hospital_name_Show_Rect;

SDL_Surface* phone_number_text_show_Surface;
SDL_Texture* phone_number_text_show_Texture;
SDL_Rect phone_number_text_show_rect;



SDL_Event event;

void clR()
{
    Specality_text_Texture=NULL;
    Specality_Show_Texture=NULL;

    Doctor_name_text_Texture=NULL;
    Doctor_name_Show_Texture=NULL;

    Doctor_date_text_Texture=NULL;
    Doctor_date_Show_Texture=NULL;
}

int  Symptoms()
{
    int success=1;

    //Load Image texture
    gTexture =loadedTexture("symptoms.jpg");

    return success;
}
SDL_Color color_Symptoms ={0,0,0};

bool symptoms_Rend_Background()
{
    gTexture=loadedTexture("photos/symptoms_input.jpg");
    font=TTF_OpenFont("arial.ttf",45);
    Text_Surface=TTF_RenderText_Solid(font,"TYPE HERE YOUR MATCHED SYMPTOMS:",color_Symptoms);
    Text_texture=SDL_CreateTextureFromSurface(gRenderer,Text_Surface);
    Text_Rect.x=250;
    Text_Rect.y=100;
    Text_Rect.w=Text_Surface->w;
    Text_Rect.h=Text_Surface->h;

    TTF_Init();
    SDL_StartTextInput();

    return true;
}


bool input_Symptoms()
{
    bool success=true;
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);
    switch(event.type)
    {
        case SDL_TEXTINPUT:
            input_symptoms+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE && input_symptoms.size())
            {
                input_symptoms.pop_back();
            }
            break;

    }

    if (input_symptoms.size())
    {
        Input_Surface=TTF_RenderText_Blended_Wrapped(font,input_symptoms.c_str(),color_Symptoms,550);
        Input_Texture=SDL_CreateTextureFromSurface(gRenderer,Input_Surface);

        Input_Rect.x=110;//-(Input_Surface->w)/2.0f;
        Input_Rect.y=419;
        Input_Rect.w=Input_Surface->w;
        Input_Rect.h=Input_Surface->h;
    }

    else
    {
        Input_Surface=TTF_RenderText_Solid(font," ",color_Symptoms);
        Input_Texture=SDL_CreateTextureFromSurface(gRenderer,Input_Surface);

        Input_Rect.x=110;//-(Input_Surface->w)/2.0f;
        Input_Rect.y=419;
        Input_Rect.w=Input_Surface->w;
        Input_Rect.h=Input_Surface->h;
    }

    return true;

}

Doctor results[100];
 int maxIndex;
int Show_information()
{
    gTexture=loadedTexture("photos/show_information.jpg");
    int arr[5];
    for (int c=0;c<5;c++)
    {
        arr[c]=0;
    }
    if(strstr(input_symptoms.c_str(),"01")||strstr(input_symptoms.c_str(),"02")||strstr(input_symptoms.c_str(),"03")||strstr(input_symptoms.c_str(),"04")||strstr(input_symptoms.c_str(),"05"))
    {
        arr[0]=1;
    }
    if(strstr(input_symptoms.c_str(),"06")||strstr(input_symptoms.c_str(),"07")||strstr(input_symptoms.c_str(),"08")||strstr(input_symptoms.c_str(),"09")||strstr(input_symptoms.c_str(),"10"))
    {
        arr[1]=1;
    }
    if(strstr(input_symptoms.c_str(),"11")||strstr(input_symptoms.c_str(),"12")||strstr(input_symptoms.c_str(),"13")||strstr(input_symptoms.c_str(),"14")||strstr(input_symptoms.c_str(),"15")||strstr(input_symptoms.c_str(),"16")||strstr(input_symptoms.c_str(),"17")||strstr(input_symptoms.c_str(),"18"))
    {
        arr[2]=1;
    }
    if(strstr(input_symptoms.c_str(),"19")||strstr(input_symptoms.c_str(),"20")||strstr(input_symptoms.c_str(),"21")||strstr(input_symptoms.c_str(),"22")||strstr(input_symptoms.c_str(),"23"))
    {
        arr[0]=1;
    }
    if(strstr(input_symptoms.c_str(),"24")||strstr(input_symptoms.c_str(),"25")||strstr(input_symptoms.c_str(),"26")||strstr(input_symptoms.c_str(),"27")||strstr(input_symptoms.c_str(),"28")||strstr(input_symptoms.c_str(),"29"))
    {
        arr[3]=1;
    }
    if(strstr(input_symptoms.c_str(),"30")||strstr(input_symptoms.c_str(),"31")||strstr(input_symptoms.c_str(),"32")||strstr(input_symptoms.c_str(),"33")||strstr(input_symptoms.c_str(),"34")||strstr(input_symptoms.c_str(),"35")||strstr(input_symptoms.c_str(),"36")||strstr(input_symptoms.c_str(),"37"))
    {
        arr[4]=1;
    }

   
    
    string name_a[50];
    string specality_a[50];
    string hospital_a[50];
    string chamber_a[50];
    string phone_a[50];

    if (f==0)
    {
        search(arr,&maxIndex,results);
        f++;
    }
    string medium_Specality;
    string medium_doctor;
    string medium_chamber;
    string medium_hospital;
    string medium_phone_number;

    font=TTF_OpenFont("arial.ttf",45);
    if (event.type==SDL_KEYDOWN)
    {
        if (event.key.keysym.sym==SDLK_RIGHT&&CurrentIndex<maxIndex-1)
        {
            CurrentIndex++;
            printf("Current: %d\n",CurrentIndex);
            clR();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&CurrentIndex>1)
        {
            CurrentIndex--;
            printf("Current1: %d\n",CurrentIndex);
            clR();
        }
        else if (event.key.keysym.sym==SDLK_RIGHT&&CurrentIndex==maxIndex)
        {
            CurrentIndex=CurrentIndex;
            printf("Current2: %d\n",CurrentIndex);
            clR();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&CurrentIndex==1)
        {
            CurrentIndex=CurrentIndex;
            printf("Current3: %d\n",CurrentIndex);
            clR();
        }
    }

    // for (int d=0;d<maxIndex;d++)
    // {
    //     printf("Specality:%s\n",specality_a[d].c_str());
    //     printf("Name: %s\n",name_a[d].c_str());
    //     printf("phone: %s\n",phone_a[d].c_str());
    //     printf("hospital: %s\n",chamber_a[d].c_str());
    //     printf("Chamber: %s\n",hospital_a[d].c_str());
    // }
    
    medium_chamber=results[CurrentIndex].cname;
    medium_Specality=results[CurrentIndex].special;
    medium_doctor=results[CurrentIndex].name;
    medium_hospital=results[CurrentIndex].hname;
    medium_phone_number=results[CurrentIndex].phone;

    // cout<<results[1].special;

    for (int d=0;d<maxIndex;d++)
    {
        
        printf("Name: %s\n",results[d].name);
        
    }

    color={0,0,0};



    Specality_text_Surface=TTF_RenderText_Solid(font,"Specality: ",color);
    Specality_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_text_Surface);

    Specality_text_rect.x=20;
    Specality_text_rect.y=100;
    Specality_text_rect.w=Specality_text_Surface->w;
    Specality_text_rect.h=Specality_text_Surface->h;

    Specality_Show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_Specality.c_str(),color,900);
    Specality_Show_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_Show_Surface);
    Specality_Show_Rect.x=220;
    Specality_Show_Rect.y=100;
    Specality_Show_Rect.w=Specality_Show_Surface->w;
    Specality_Show_Rect.h=Specality_Show_Surface->h;

    Doctor_name_text_Surface=TTF_RenderText_Solid(font,"Doctor's name: ",color);
    Doctor_name_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_name_text_Surface);
    Doctor_name_text_Rect.x=20;
    Doctor_name_text_Rect.y=200;
    Doctor_name_text_Rect.w=Doctor_name_text_Surface->w;
    Doctor_name_text_Rect.h=Doctor_name_text_Surface->h;

    Doctor_name_Show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_doctor.c_str(),color,900);
    Doctor_name_Show_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_name_Show_Surface);
    Doctor_name_Show_Rect.x=320;
    Doctor_name_Show_Rect.y=200;
    Doctor_name_Show_Rect.w=Doctor_name_Show_Surface->w;
    Doctor_name_Show_Rect.h=Doctor_name_Show_Surface->h;

    Doctor_date_text_Surface=TTF_RenderText_Solid(font,"Chamber: ",color);
    Doctor_date_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_date_text_Surface);
    Doctor_date_text_Rect.x=20;
    Doctor_date_text_Rect.y=300;
    Doctor_date_text_Rect.w=Doctor_date_text_Surface->w;
    Doctor_date_text_Rect.h=Doctor_date_text_Surface->h;

    Doctor_date_Show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_chamber.c_str(),color,900);
    Doctor_date_Show_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_date_Show_Surface);
    Doctor_date_Show_Rect.x=220;
    Doctor_date_Show_Rect.y=300;
    Doctor_date_Show_Rect.w=Doctor_date_Show_Surface->w;
    Doctor_date_Show_Rect.h=Doctor_date_Show_Surface->h;

    Hospital_name_text_Surface=TTF_RenderText_Solid(font,"Hospital: ",color);
    Hospital_name_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Hospital_name_text_Surface);
    Hospital_name_text_Rect.x=20;
    Hospital_name_text_Rect.y=400;
    Hospital_name_text_Rect.w=Hospital_name_text_Surface->w;
    Hospital_name_text_Rect.h=Hospital_name_text_Surface->h;

    Hospital_name_Show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_hospital.c_str(),color,900);
    Hospital_name_Show_Texture=SDL_CreateTextureFromSurface(gRenderer,Hospital_name_Show_Surface);
    Hospital_name_Show_Rect.x=230;
    Hospital_name_Show_Rect.y=400;
    Hospital_name_Show_Rect.w=Hospital_name_Show_Surface->w;
    Hospital_name_Show_Rect.h=Hospital_name_Show_Surface->h;

    phone_number_text_Surface=TTF_RenderText_Solid(font,"Phone: ",color);
    phone_number_text_Texture=SDL_CreateTextureFromSurface(gRenderer,phone_number_text_Surface);
    phone_number_text_rect.x=20;
    phone_number_text_rect.y=500;
    phone_number_text_rect.w=phone_number_text_Surface->w;
    phone_number_text_rect.h=phone_number_text_Surface->h;

    phone_number_text_show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_phone_number.c_str(),color,900);
    phone_number_text_show_Texture=SDL_CreateTextureFromSurface(gRenderer,phone_number_text_show_Surface);
    phone_number_text_show_rect.x=210;
    phone_number_text_show_rect.y=500;
    phone_number_text_show_rect.w=phone_number_text_show_Surface->w;
    phone_number_text_show_rect.h=phone_number_text_show_Surface->h;

    
    return 0;
}


void NO_Record_Found()
{
    gTexture=loadedTexture("photos/No Record Found.jpg");
}