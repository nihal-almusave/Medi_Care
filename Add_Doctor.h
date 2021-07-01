#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

string Specality;
string doctor;
string Doctor_time;
string Hospital;
string phone_number;

//field name:Specality
SDL_Surface* Specality_Surface;
SDL_Texture* Specality_Texture;

//Specality field input
SDL_Surface* Specality_add_Surface;
SDL_Texture* Specality_add_Texture;;

//Specality rect
SDL_Rect Specality_rect;

//Specality  add rect
SDL_Rect Specality_add_rect;

//Doctor field
SDL_Surface* Doctor_Surface;
SDL_Texture* Doctor_Texture;

//Doctor field input
SDL_Surface* Doctor_add_Surface;
SDL_Texture* Doctor_add_Texture;;

//doctor rect
SDL_Rect Doctor_rect;

//doctor add rect
SDL_Rect Doctor_add_rect;

//Doctor time field
SDL_Surface* Doctor_time_Surface;
SDL_Texture* Doctor_time_Texture;

//Doctor field input
SDL_Surface* Doctor_time_add_Surface;
SDL_Texture* Doctor_time_add_Texture;;

//doctor time rect
SDL_Rect Doctor_time_rect;

//doctor time add rect
SDL_Rect Doctor_time_add_rect;

//Hospital field
SDL_Surface* Hospital_Surface;
SDL_Texture* Hospital_Texture;

//Hospital add input
SDL_Surface* Hospital_add_Surface;
SDL_Texture* Hospital_add_Texture;;

//Hospital rect
SDL_Rect Hospital_rect;

//Hospiatal add rect
SDL_Rect Hospital_add_rect;

SDL_Surface* phone_number_Surface;
SDL_Texture* phone_number_Texture;

//Hospital add input
SDL_Surface* phone_number_add_Surface;
SDL_Texture* phone_number_add_Texture;;

//Hospital rect
SDL_Rect phone_number_rect;

//Hospiatal add rect
SDL_Rect phone_number_add_rect;

//ADD DOCTOR
SDL_Surface* add_doctor_surface;
SDL_Texture* add_doctor_Texture;
SDL_Rect add_doctor_rect;


int i=0;

int add_doctor_function();

int add_doctor_time_function();

int add_Hospital_function();

int add_phone_number_function();


int Specality_Function()
{
    gTexture=loadedTexture("photos/Add_a_doctor.jpg");

    color={255,255,255};

    font =TTF_OpenFont("arial.ttf",60);
    add_doctor_surface=TTF_RenderText_Solid(font,"Add Doctor's Information",color);
    add_doctor_Texture=SDL_CreateTextureFromSurface(gRenderer,add_doctor_surface);

    add_doctor_rect.x=450;
    add_doctor_rect.y=50;
    add_doctor_rect.w=add_doctor_surface->w;
    add_doctor_rect.h=add_doctor_surface->h;

    font = TTF_OpenFont("arial.ttf",40);

    
    Specality_Surface=TTF_RenderText_Solid(font,"Specality: ",color);
    Specality_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_Surface);
    Specality_rect.x=50;
    Specality_rect.y=150;
    Specality_rect.w=Specality_Surface->w;
    Specality_rect.h=Specality_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            Specality+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&Specality.size())
            {
                Specality.pop_back();
            }
            break;
    }

    if (Specality.size())
    {
        Specality_add_Surface=TTF_RenderText_Blended_Wrapped(font,Specality.c_str(),color,700);
        Specality_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_add_Surface);

        Specality_add_rect.x=Specality_rect.x+Specality_rect.w;
        Specality_add_rect.y=150;
        Specality_add_rect.w=Specality_add_Surface->w;
        Specality_add_rect.h=Specality_add_Surface->h;
    }

    else 
    {
        Specality_add_Surface=TTF_RenderText_Solid(font," ",color);
        Specality_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_add_Surface);

        Specality_add_rect.x=Specality_rect.x+Specality_rect.w;
        Specality_add_rect.y=150;
        Specality_add_rect.w=Specality_add_Surface->w;
        Specality_add_rect.h=Specality_add_Surface->h;
    }

    return i;
}

int add_doctor_function()
{
    font = TTF_OpenFont("arial.ttf",40);
    color={255,255,255};
    
    Doctor_Surface=TTF_RenderText_Solid(font,"Doctor's Name: ",color);
    Doctor_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_Surface);


    Doctor_rect.x=50;
    Doctor_rect.y=250;
    Doctor_rect.w=Doctor_Surface->w;
    Doctor_rect.h=Doctor_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            doctor+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&doctor.size())
            {
                doctor.pop_back();
            }
        break;
    }

    if (doctor.size())
    {
        Doctor_add_Surface=TTF_RenderText_Blended_Wrapped(font,doctor.c_str(),color,700);
        Doctor_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_add_Surface);

        Doctor_add_rect.x=Doctor_rect.x+Doctor_rect.w;
        Doctor_add_rect.y=250;
        Doctor_add_rect.w=Doctor_add_Surface->w;
        Doctor_add_rect.h=Doctor_add_Surface->h;
    }

    else 
    {
        Doctor_add_Surface=TTF_RenderText_Solid(font," ",color);
        Doctor_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_add_Surface);

        Doctor_add_rect.x=Doctor_rect.x+Doctor_rect.w;
        Doctor_add_rect.y=Doctor_rect.y;
        Doctor_add_rect.w=Doctor_add_Surface->w;
        Doctor_add_rect.h=Doctor_add_Surface->h;
    }

    return i;
}

int add_doctor_time_function()
{
    font = TTF_OpenFont("arial.ttf",40);
    color={255,255,255};
    
    Doctor_time_Surface=TTF_RenderText_Solid(font,"Chamber: ",color);
    Doctor_time_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_time_Surface);


    Doctor_time_rect.x=50;
    Doctor_time_rect.y=350;
    Doctor_time_rect.w=Doctor_time_Surface->w;
    Doctor_time_rect.h=Doctor_time_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            Doctor_time+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&Doctor_time.size())
            {
                Doctor_time.pop_back();
            }
        break;
    }

    if (Doctor_time.size())
    {
        Doctor_time_add_Surface=TTF_RenderText_Blended_Wrapped(font,Doctor_time.c_str(),color,700);
        Doctor_time_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_time_add_Surface);

        Doctor_time_add_rect.x=Doctor_time_rect.x+Doctor_time_rect.w;
        Doctor_time_add_rect.y=350;
        Doctor_time_add_rect.w=Doctor_time_add_Surface->w;
        Doctor_time_add_rect.h=Doctor_time_add_Surface->h;
    }

    else 
    {
        Doctor_time_add_Surface=TTF_RenderText_Solid(font," ",color);
        Doctor_time_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Doctor_time_add_Surface);

        Doctor_time_add_rect.x=Doctor_time_rect.x+Doctor_time_rect.w;
        Doctor_time_add_rect.y=350;
        Doctor_time_add_rect.w=Doctor_time_add_Surface->w;
        Doctor_time_add_rect.h=Doctor_time_add_Surface->h;
    }

    return i;
}

int add_Hospital_function()
{
    font = TTF_OpenFont("arial.ttf",40);
    color={255,255,255};
    
    Hospital_Surface=TTF_RenderText_Solid(font,"Hospital Name: ",color);
    Hospital_Texture=SDL_CreateTextureFromSurface(gRenderer,Hospital_Surface);


    Hospital_rect.x=50;
    Hospital_rect.y=450;
    Hospital_rect.w=Hospital_Surface->w;
    Hospital_rect.h=Hospital_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            Hospital+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&Hospital.size())
            {
                Hospital.pop_back();
            }
        break;
    }

    if (Hospital.size())
    {
        Hospital_add_Surface=TTF_RenderText_Blended_Wrapped(font,Hospital.c_str(),color,700);
        Hospital_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Hospital_add_Surface);

        Hospital_add_rect.x=Hospital_rect.x+Hospital_rect.w;
        Hospital_add_rect.y=450;
        Hospital_add_rect.w=Hospital_add_Surface->w;
        Hospital_add_rect.h=Hospital_add_Surface->h;
    }

    else 
    {
        Hospital_add_Surface=TTF_RenderText_Solid(font," ",color);
        Hospital_add_Texture=SDL_CreateTextureFromSurface(gRenderer,Hospital_add_Surface);

        Hospital_add_rect.x=Hospital_rect.x+Hospital_rect.w;
        Hospital_add_rect.y=450;
        Hospital_add_rect.w=Hospital_add_Surface->w;
        Hospital_add_rect.h=Hospital_add_Surface->h;
    }

    return i;
}

int add_phone_number_function()
{
    font = TTF_OpenFont("arial.ttf",40);
    color={255,255,255};
    
    phone_number_Surface=TTF_RenderText_Solid(font,"Phone Number: ",color);
    phone_number_Texture=SDL_CreateTextureFromSurface(gRenderer,phone_number_Surface);


    phone_number_rect.x=50;
    phone_number_rect.y=550;
    phone_number_rect.w=phone_number_Surface->w;
    phone_number_rect.h=phone_number_Surface->h;

    TTF_Init();
    SDL_StartTextInput();
    
    static const unsigned char* keys=SDL_GetKeyboardState(NULL);

    switch (event.type)
    {
        case SDL_TEXTINPUT:
            phone_number+=event.text.text;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym==SDLK_BACKSPACE&&phone_number.size())
            {
                phone_number.pop_back();
            }
        break;
    }

    if (phone_number.size())
    {
        phone_number_add_Surface=TTF_RenderText_Blended_Wrapped(font,phone_number.c_str(),color,700);
        phone_number_add_Texture=SDL_CreateTextureFromSurface(gRenderer,phone_number_add_Surface);

        phone_number_add_rect.x=phone_number_rect.x+phone_number_rect.w;
        phone_number_add_rect.y=550;
        phone_number_add_rect.w=phone_number_add_Surface->w;
        phone_number_add_rect.h=phone_number_add_Surface->h;
    }

    else 
    {
        phone_number_add_Surface=TTF_RenderText_Solid(font," ",color);
        phone_number_add_Texture=SDL_CreateTextureFromSurface(gRenderer,phone_number_add_Surface);

        phone_number_add_rect.x=phone_number_rect.x+phone_number_rect.w;
        phone_number_add_rect.y=550;
        phone_number_add_rect.w=phone_number_add_Surface->w;
        phone_number_add_rect.h=phone_number_add_Surface->h;
    }

    return i;
}


int add_a_doctor_Next()
{
    gTexture=loadedTexture("photos/return_add.jpg");

    return 0;
}

bool strings_clear()
{
    Specality="";
    Hospital="";
    doctor="";
    Doctor_time="";
    phone_number="";

    return true;
}

void ambulance_help()
{
    gTexture=loadedTexture("photos/help Button page.jpg");
}