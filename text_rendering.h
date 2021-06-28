#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>
#include<string>

using namespace std;

TTF_Font* in_font;
SDL_Rect name_rect;
SDL_Rect location_rect;
SDL_Rect time_rect;
SDL_Surface* output_Surface;
SDL_Texture* output_Texture;
SDL_Color Cl={255,255,255};
SDL_Event event;

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
SDL_Rect Specality_name_text_Rect;

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
SDL_Rect Specality_name_Show_Rect;

SDL_Surface* phone_number_text_show_Surface;
SDL_Texture* phone_number_text_show_Texture;
SDL_Rect phone_number_text_show_rect;

int j=0;

// void clear()
// {
//     output_Texture=NULL;
//     output_Surface=NULL;
// }

string temp;
struct Doctor
{
    char const *name;
    char const *location;
    char const *time;
    char const *day;
    char const *speciality;
};

// int output(int x, int y)
// {
//     int n;
//     n=10;
//     struct Doctor out_put[n];
    

//     if (e.type==SDL_KEYDOWN)
//     {
//         if (e.key.keysym.sym==SDLK_RIGHT&&j<9)
//         {
//             j++;
//             clear();
//         }
//         else if (e.key.keysym.sym==SDLK_LEFT&&j>0)
//         {
//             j--;
//             clear();
//         }
//         else if (e.key.keysym.sym==SDLK_RIGHT&&j==9)
//         {
//             j=j;
//             clear();
//         }
//         else if (e.key.keysym.sym==SDLK_LEFT&&j==0)
//         {
//             j=j;
//             clear();
//         }
//     }
//     out_put[0].name="Md. Atikur Rahman";

//     temp=out_put[j].name;

//     in_font=TTF_OpenFont ("arial.ttf",45);
//     output_Surface=TTF_RenderText_Solid(in_font,temp.c_str(),Cl);
//     output_Texture=SDL_CreateTextureFromSurface(gRenderer,output_Surface);
//     name_rect.x=250;
//     name_rect.y=200;
//     name_rect.w=output_Surface->w;
//     name_rect.h=output_Surface->h;

//     return 0;
// }

int CurrentIndex=0;

void clR()
{
    Specality_text_Texture=NULL;
    Specality_Show_Texture=NULL;
}


bool SHOW_NFO()
{

    int maxIndex=10;

    struct Doctor results[10];
    
    results[0].name="Md. Atikur Rahman";
    results[1].name="Md. Anisur Rahman";
    results[2].name="Md. Atikur Rahman";
    results[3].name="Md. Azizur Rahman";
    results[4].name="Md. Atikur Rahman";
    results[5].name="Md. abdur Rahman";
    results[6].name="Md. abdul batunur Rahman";
    results[7].name="Md. farukur Rahman";
    results[8].name="Md. mozammel Rahman";
    results[9].name="Md. Atikur Rahman";


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
            clR();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&CurrentIndex>0)
        {
            CurrentIndex--;
            clR();
        }
        else if (event.key.keysym.sym==SDLK_RIGHT&&CurrentIndex==(maxIndex-1))
        {
            CurrentIndex=CurrentIndex;
            clR();
        }
        else if (event.key.keysym.sym==SDLK_LEFT&&CurrentIndex==0)
        {
            CurrentIndex=CurrentIndex;
            clR();
        }
    }

    medium_Specality=results[CurrentIndex].name;

    // medium_chamber=results[CurrentIndex].cname;
    // medium_Specality=results[CurrentIndex].special;
    // medium_doctor=results[CurrentIndex].name;
    // medium_hospital=results[CurrentIndex].hname;
    // medium_phone_number=results[CurrentIndex].phone;

    color={255,255,255};


    Specality_text_Surface=TTF_RenderText_Solid(font,"Specality: ",color);
    Specality_text_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_text_Surface);

    Specality_text_rect.x=50;
    Specality_text_rect.y=100;
    Specality_text_rect.w=Specality_text_Surface->w;
    Specality_text_rect.h=Specality_text_Surface->h;

    Specality_Show_Surface=TTF_RenderText_Blended_Wrapped(font,medium_Specality.c_str(),color,900);
    Specality_Show_Texture=SDL_CreateTextureFromSurface(gRenderer,Specality_Show_Surface);
    Specality_Show_Rect.x=250;
    Specality_Show_Rect.y=100;
    Specality_Show_Rect.w=Specality_Show_Surface->w;
    Specality_Show_Rect.h=Specality_Show_Surface->h;

    return true;
}