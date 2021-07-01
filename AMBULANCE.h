#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<stdio.h>
#include<string>

#include"Ambulance_file.h"

using namespace std;


string Division_add;
static string Division;
string amb_name;
string amb_phone;


SDL_Surface* Division_Surface;
SDL_Surface* Division_text_Surface;

//show
SDL_Surface* Division_show_Surface;
SDL_Surface* Division_show_text_Surface;

SDL_Texture* Division_Texture;
SDL_Texture* Division_text_Texture;

//show
SDL_Texture* Division_show_Texture;
SDL_Texture* Division_show_text_Texture;

SDL_Rect Division_rect;
SDL_Rect Division_text_rect;

//show
SDL_Rect Division_show_rect;
SDL_Rect Division_show_text_rect;



SDL_Surface* amb_name_Surface;
SDL_Surface* amb_name_text_Surface;

//show
SDL_Surface* amb_name_show_Surface;
SDL_Surface* amb_name_show_text_Surface;

SDL_Texture* amb_name_Texture;
SDL_Texture* amb_name_text_Texture;

//show
SDL_Texture* amb_name_show_Texture;
SDL_Texture* amb_name_show_text_Texture;

SDL_Rect amb_name_rect;
SDL_Rect amb_name_text_rect;

//show
SDL_Rect amb_name_show_rect;
SDL_Rect amb_name_show_text_rect;



SDL_Surface* amb_phone_Surface;
SDL_Surface* amb_phone_text_Surface;

//show
SDL_Surface* amb_phone_show_Surface;
SDL_Surface* amb_phone_show_text_Surface;

SDL_Texture* amb_phone_Texture;
SDL_Texture* amb_phone_text_Texture;

//show
SDL_Texture* amb_phone_show_Texture;
SDL_Texture* amb_phone_show_text_Texture;

SDL_Rect amb_phone_rect;
SDL_Rect amb_phone_text_rect;

//show
SDL_Rect amb_phone_show_rect;
SDL_Rect amb_phone_show_text_rect;

//input division
SDL_Surface* Division_input_surface;
SDL_Surface* Division_input_text_surface;

SDL_Texture* Division_input_texture;
SDL_Texture* Division_input_text_texture;

SDL_Rect Division_input_rect;
SDL_Rect Division_input_text_rect;

SDL_Surface* Ambulance_surface;
SDL_Texture* Ambulance_texture;
SDL_Rect Ambulance_rect;


int aa=0,bb=0,current=0;

void CLr()
{
    amb_phone_show_text_Texture=NULL;
    amb_phone_show_Texture=NULL;

    amb_name_show_Texture=NULL;
    amb_name_show_text_Texture=NULL;

    Division_show_Texture=NULL;
    Division_show_text_Texture=NULL;
}

int add_Ambulance_name_Function();
int add_Ambulance_phone_Function();

int add_Ambulance_division_Function()
{
    gTexture=loadedTexture("photos/Add_a_doctor.jpg");
    color={255,255,255};

    font=TTF_OpenFont("arial.ttf",60);
    Ambulance_surface=TTF_RenderText_Solid(font,"Add Ambulance",color);
    Ambulance_texture=SDL_CreateTextureFromSurface(gRenderer,Ambulance_surface);

    Ambulance_rect.x=450;
    Ambulance_rect.y=50;
    Ambulance_rect.w=Ambulance_surface->w;
    Ambulance_rect.h=Ambulance_surface->h;

    font = TTF_OpenFont("arial.ttf",45);

    TTF_Init();
    SDL_StartTextInput();

    Division_Surface=TTF_RenderText_Solid(font,"Division: ",color);
    Division_Texture=SDL_CreateTextureFromSurface(gRenderer,Division_Surface);
    Division_rect.x=50;
    Division_rect.y=150;
    Division_rect.w=Division_Surface->w;
    Division_rect.h=Division_Surface->h;

    

    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            Division_add+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&Division_add.size())
            {
                Division_add.pop_back();
            }
            break;
    }

    if (Division_add.size())
    {
        Division_text_Surface=TTF_RenderText_Blended_Wrapped(font,Division_add.c_str(),color,700);
        Division_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Division_text_Surface);

        Division_text_rect.x=Division_rect.x+Division_rect.w;
        Division_text_rect.y=150;
        Division_text_rect.w=Division_text_Surface->w;
        Division_text_rect.h=Division_text_Surface->h;
    }

    else 
    {
        Division_text_Surface=TTF_RenderText_Solid(font,"",color);
        Division_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Division_text_Surface);

        Division_text_rect.x=Division_rect.x+Division_rect.w;
        Division_text_rect.y=150;
        // Division_text_rect.w=Division_text_Surface->w;
        // Division_text_rect.h=Division_text_Surface->h;
    }
    return aa;

}

int add_Ambulance_name_Function()
{
    font = TTF_OpenFont("arial.ttf",45);

    color={255,255,255};

    amb_name_Surface=TTF_RenderText_Solid(font,"Name: ",color);
    amb_name_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_name_Surface);
    amb_name_rect.x=50;
    amb_name_rect.y=250;
    amb_name_rect.w=amb_name_Surface->w;
    amb_name_rect.h=amb_name_Surface->h;

    TTF_Init();
    SDL_StartTextInput();

    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            amb_name+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&amb_name.size())
            {
                amb_name.pop_back();
            }
            break;
    }

    if (amb_name.size())
    {
        amb_name_text_Surface=TTF_RenderText_Blended_Wrapped(font,amb_name.c_str(),color,700);
        amb_name_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_name_text_Surface);

        amb_name_text_rect.x=amb_name_rect.x+amb_name_rect.w;
        amb_name_text_rect.y=250;
        amb_name_text_rect.w=amb_name_text_Surface->w;
        amb_name_text_rect.h=amb_name_text_Surface->h;
    }

    else 
    {
        amb_name_text_Surface=TTF_RenderText_Solid(font,"",color);
        amb_name_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_name_text_Surface);

        amb_name_text_rect.x=amb_name_rect.x+amb_name_rect.w;
        amb_name_text_rect.y=250;
        // amb_name_text_rect.w=amb_name_text_Surface->w;
        // amb_name_text_rect.h=amb_name_text_Surface->h;
    }
    return aa;

}

int add_Ambulance_phone_Function()
{
    font = TTF_OpenFont("arial.ttf",45);

    color={255,255,255};

    amb_phone_Surface=TTF_RenderText_Solid(font,"Phone: ",color);
    amb_phone_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_phone_Surface);
    amb_phone_rect.x=50;
    amb_phone_rect.y=350;
    amb_phone_rect.w=amb_phone_Surface->w;
    amb_phone_rect.h=amb_phone_Surface->h;

    TTF_Init();
    SDL_StartTextInput();

    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            amb_phone+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&amb_phone.size())
            {
                amb_phone.pop_back();
            }
            break;
    }

    if (amb_phone.size())
    {
        amb_phone_text_Surface=TTF_RenderText_Blended_Wrapped(font,amb_phone.c_str(),color,700);
        amb_phone_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_phone_text_Surface);

        amb_phone_text_rect.x=amb_phone_rect.x+amb_phone_rect.w;
        amb_phone_text_rect.y=350;
        amb_phone_text_rect.w=amb_phone_text_Surface->w;
        amb_phone_text_rect.h=amb_phone_text_Surface->h;
    }

    else 
    {
        amb_phone_text_Surface=TTF_RenderText_Solid(font,"",color);
        amb_phone_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_phone_text_Surface);

        amb_phone_text_rect.x=amb_phone_rect.x+amb_phone_rect.w;
        amb_phone_text_rect.y=350;
    //     amb_phone_text_rect.w=amb_phone_text_Surface->w;
    //     amb_phone_text_rect.h=amb_phone_text_Surface->h;
    }
    return aa;

}


int enter_division_input()
{
    gTexture=loadedTexture("photos/Ambulance Input background.jpg");

    font = TTF_OpenFont("arial.ttf",60);

    color={0,0,0};
    TTF_Init();
    SDL_StartTextInput();

    Division_input_surface=TTF_RenderText_Solid(font," Enter Your Division ",color);
    Division_input_texture=SDL_CreateTextureFromSurface(gRenderer,Division_input_surface);
    Division_input_rect.x=300;
    Division_input_rect.y=200;
    Division_input_rect.w=Division_input_surface->w;
    Division_input_rect.h=Division_input_surface->h;

    

    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            Division+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&Division.size())
            {
                Division.pop_back();
            }
            break;
    }

    font = TTF_OpenFont("arial.ttf",45);

    if (Division.size())
    {
        Division_input_text_surface=TTF_RenderText_Blended_Wrapped(font,Division.c_str(),color,700);
        Division_input_text_texture=SDL_CreateTextureFromSurface(gRenderer,Division_input_text_surface);

        Division_input_text_rect.x=320;
        Division_input_text_rect.y=300;
        Division_input_text_rect.w=Division_input_text_surface->w;
        Division_input_text_rect.h=Division_input_text_surface->h;
    }

    else 
    {
        Division_input_text_surface=TTF_RenderText_Solid(font,"",color);
        Division_input_text_texture=SDL_CreateTextureFromSurface(gRenderer,Division_input_text_surface);

        Division_input_text_rect.x=Division_input_rect.x+Division_input_rect.w;
        Division_input_text_rect.y=200;
        // Division_input_text_rect.w=Division_input_text_surface->w;
        // Division_input_text_rect.h=Division_input_text_surface->h;
    }
    return aa;

    return 0;
}
Ambulance rslt[100];
int maxIn;

int Ambulance_show()
{
    gTexture=loadedTexture("photos/Ambulance background.jpg");

    int ara[8]={0,0,0,0,0,0,0,0};

    if (strstr(Division.c_str(),"Dhaka")||strstr(Division.c_str(),"dhaka")||strstr(Division.c_str(),"DHAKA"))
    {
        ara[0]=1;
    }
    if (strstr(Division.c_str(),"Rajshahi")||strstr(Division.c_str(),"rajshahi")||strstr(Division.c_str(),"RAJSHAHI"))
    {
        ara[1]=1;
    }
    if (strstr(Division.c_str(),"Rangpur")||strstr(Division.c_str(),"rangpur")||strstr(Division.c_str(),"RANGPUR"))
    {
        ara[2]=1;
    }
    if (strstr(Division.c_str(),"Chattogram")||strstr(Division.c_str(),"chattogram")||strstr(Division.c_str(),"CHATTOGRAM"))
    {
        ara[3]=1;
    }
    if (strstr(Division.c_str(),"Sylhet")||strstr(Division.c_str(),"sylhet")||strstr(Division.c_str(),"SYLHET"))
    {
        ara[4]=1;
    }
    if (strstr(Division.c_str(),"Mymensingh")||strstr(Division.c_str(),"mymensingh")||strstr(Division.c_str(),"MYMENSINGH"))
    {
        ara[5]=1;
    }
    if (strstr(Division.c_str(),"Khulna")||strstr(Division.c_str(),"khulna")||strstr(Division.c_str(),"kHULNA"))
    {
        ara[6]=1;
    }
    if (strstr(Division.c_str(),"Barishal")||strstr(Division.c_str(),"barishal")||strstr(Division.c_str(),"BARISHAL"))
    {
        ara[7]=1;
    }

    string med_division;
    string med_name_amb;
    string med_phone_num_amb;

    if (bb==0)
    {
        SEARCH(ara,&maxIn,rslt);
        bb++;
    }
    // for (int f=0;f<maxIn;f++)
    // {
    //     printf ("%s\n",rslt[f].ambulance_Division);
    //     printf("%s\n",rslt[f].ambulance_name);
    //     printf("%s\n",rslt[f].ambulance_phone_number);
    // }

    font=TTF_OpenFont("arial.ttf",45);
    if (event.type==SDL_KEYDOWN)
    {
        if (event.key.keysym.sym==SDLK_RIGHT&&current<maxIn-1)
        {
            current++;
            printf("Current1: %d    %d\n",current,maxIn);
            // clear();
            CLr();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&current>0)
        {
            current--;
            //printf("Current1: %d\n",CurrentIndex);
            printf("Current2: %d\n",current);
            // clear();
            CLr();
        }
        else if (event.key.keysym.sym==SDLK_RIGHT&&current==maxIn-1)
        {
            current=current;
            //printf("Current2: %d\n",CurrentIndex);
            printf("Current3: %d\n",current);
            // clear();
            CLr();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&current==0)
        {
            current=current;
            //printf("Current3: %d\n",CurrentIndex);
            printf("Current4: %d\n",current);
            // clear();
            CLr();
        }
    }

    // for (int k=0;k<maxIn;k++)
    // {
    //     printf ("div: %s\n",Division.c_str());
    //     printf ("nam: %s\n",rslt[k].ambulance_name);
    //     printf ("phn: %s\n",rslt[k].ambulance_phone_number);
    // }

    med_division=Division;
    med_name_amb=rslt[current].ambulance_name;
    med_phone_num_amb=rslt[current].ambulance_phone_number;

    cout<<med_division;
    // cout<<med_phone_num_amb;

    color={0,0,0};

    // phone_number_text_Surface=TTF_RenderText_Solid(font,"Division: ",color);
    Division_show_Surface=TTF_RenderText_Solid(font,"Division: ",color);
    Division_show_Texture=SDL_CreateTextureFromSurface(gRenderer,Division_show_Surface);

    Division_show_rect.x=150;
    Division_show_rect.y=350;
    Division_show_rect.w=Division_show_Surface->w;
    Division_show_rect.h=Division_show_Surface->h;

    Division_show_text_Surface=TTF_RenderText_Blended_Wrapped(font,Division.c_str(),color,900);
    Division_show_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Division_show_text_Surface);

    Division_show_text_rect.x=Division_show_rect.x+Division_show_rect.w;
    Division_show_text_rect.y=350;
    Division_show_text_rect.w=Division_show_text_Surface->w;
    Division_show_text_rect.h=Division_show_text_Surface->h;

    amb_name_show_Surface=TTF_RenderText_Solid(font,"Name: ",color);
    amb_name_show_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_name_show_Surface);

    amb_name_show_rect.x=150;
    amb_name_show_rect.y=450;
    amb_name_show_rect.w=amb_name_show_Surface->w;
    amb_name_show_rect.h=amb_name_show_Surface->h;

    amb_name_show_text_Surface=TTF_RenderText_Blended_Wrapped(font,med_name_amb.c_str(),color,900);
    amb_name_show_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_name_show_text_Surface);

    amb_name_show_text_rect.x=amb_name_show_rect.x+amb_name_show_rect.w;
    amb_name_show_text_rect.y=450;
    amb_name_show_text_rect.w=amb_name_show_text_Surface->w;
    amb_name_show_text_rect.h=amb_name_show_text_Surface->h;


    amb_phone_show_Surface=TTF_RenderText_Solid(font,"phone: ",color);
    amb_phone_show_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_phone_show_Surface);

    amb_phone_show_rect.x=150;
    amb_phone_show_rect.y=550;
    amb_phone_show_rect.w=amb_phone_show_Surface->w;
    amb_phone_show_rect.h=amb_phone_show_Surface->h;

    amb_phone_show_text_Surface=TTF_RenderText_Blended_Wrapped(font,med_phone_num_amb.c_str(),color,900);
    amb_phone_show_text_Texture=SDL_CreateTextureFromSurface(gRenderer,amb_phone_show_text_Surface);

    amb_phone_show_text_rect.x=amb_phone_show_rect.x+amb_phone_show_rect.w;
    amb_phone_show_text_rect.y=550;
    amb_phone_show_text_rect.w=amb_phone_show_text_Surface->w;
    amb_phone_show_text_rect.h=amb_phone_show_text_Surface->h;    

    return 0;
}

void str_clear()
{
    Division_add="";
    amb_name="";
    amb_phone="";

}

