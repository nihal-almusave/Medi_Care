#include<iostream>
#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>

using namespace std;

TTF_Font in_font;

struct Doctor
{
    char name[50];
    char location[50];
    char time[30];
    char day[40];
};

int output(int x, int y)
{
    struct Doctor out_put[10];
    out_put[0].name="Md. Atikur Rahman";
    out_put[1].name="Md. Atikur Rahman1";
    out_put[2].name="Md. Atikur Rahman2";
    out_put[3].name="Md. Atikur Rahman3";
    out_put[4].name="Md. Atikur Rahman4";
    out_put[5].name="Md. Atikur Rahman5";
    out_put[6].name="Md. Atikur Rahman6";
    out_put[7].name="Md. Atikur Rahman7";
    out_put[8].name="Md. Atikur Rahman8";
    out_put[9].name="Md. Atikur Rahman9";
    out_put[0].location="Dhaka Medical College";
    out_put[1].location="Dhaka Medical College";
    out_put[2].location="Dhaka Medical College";
    out_put[3].location="Dhaka Medical College";
    out_put[4].location="Dhaka Medical College";
    out_put[5].location="Dhaka Medical College";
    out_put[6].location="Dhaka Medical College";
    out_put[7].location="Dhaka Medical College";
    out_put[8].location="Dhaka Medical College";
    out_put[9].location="Dhaka Medical College";
    out_put[0].time="01:01 P.M.";
    out_put[1].time="01:01 P.M.";
    out_put[2].time="01:01 P.M.";
    out_put[3].time="01:01 P.M.";
    out_put[4].time="01:01 P.M.";
    out_put[5].time="01:01 P.M.";
    out_put[6].time="01:01 P.M.";
    out_put[7].time="01:01 P.M.";
    out_put[8].time="01:01 P.M.";
    out_put[9].time="01:01 P.M.";

    int i=0;
    SDL_Rect name;
    SDL_Rect location;
    SDL_Rect time;
    SDL_Surface* output_Surface;
    SDL_Color Cl={255,255,255};
    
    in_font=TTF_OpenFont ("arial.ttf",45);
    output_Surface=TTF_RenderText_Solid(in_font,out_put[0].name_c.str(),Cl);
    gTexture=SDL_CreateTextureFromSurface(gRenderer,output_Surface);
    name.x=250;
    name.y=200;
    name.w=output_Surface->w;
    name.h=output_Surface->h;

    
}
