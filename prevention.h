#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<string>

using namespace std;

SDL_Texture* prevention_texture[6];

SDL_Texture* prevention_tex;



bool prevention_page1(int i)
{
    prevention_texture[0]=loadedTexture("photos/prevention_page1.JPG");
    prevention_texture[1]=loadedTexture("photos/prevention_page2.JPG");
    prevention_texture[2]=loadedTexture("photos/prevention_page3.JPG");
    prevention_texture[3]=loadedTexture("photos/prevention_page4.JPG");
    prevention_texture[4]=loadedTexture("photos/prevention_page5.JPG");
    prevention_texture[5]=loadedTexture("photos/prevention_page6.JPG");

    gTexture=prevention_texture[i];

    return true;
}
