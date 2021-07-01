#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_mouse.h>
#include<SDL2/SDL_ttf.h>
#include<string>
int menu=0;

using namespace std;

// SDL_Event event;
// Ambulance information
SDL_Texture* Dhaka_Textures[12];
SDL_Texture* Rajshahi_Textures[3];
SDL_Texture* Chittagong_Textures[9];
SDL_Texture* Sylhet_Textures[4];
SDL_Texture* Barishal_Textures[5];
SDL_Texture* Khulna_Textures[10];
SDL_Texture* Rangpur_Textures[7];
SDL_Texture* Mymensingh_Textures[4];



//District informatio

int a=0,b=0,c=0,d=0,e=0,g=0,h=0,p=0;

int ambulace_front()
{
    gTexture=loadedTexture("photos/Ambulance service.jpg");
    
    return menu;
}

int ambulance_Dhaka(int a)
{
    Dhaka_Textures[0]=loadedTexture("photos/Slide15.JPG");
    Dhaka_Textures[1]=loadedTexture("photos/Slide17.JPG");
    Dhaka_Textures[2]=loadedTexture("photos/Slide23.JPG");
    Dhaka_Textures[3]=loadedTexture("photos/Slide20.JPG");
    Dhaka_Textures[4]=loadedTexture("photos/Slide21.JPG");
    Dhaka_Textures[5]=loadedTexture("photos/Slide22.JPG");
    Dhaka_Textures[6]=loadedTexture("photos/Slide16.JPG");
    Dhaka_Textures[7]=loadedTexture("photos/Slide18.JPG");
    Dhaka_Textures[8]=loadedTexture("photos/Slide19.JPG");
    Dhaka_Textures[9]=loadedTexture("photos/Slide24.JPG");
    Dhaka_Textures[10]=loadedTexture("photos/Slide25.JPG");
    Dhaka_Textures[11]=loadedTexture("photos/Slide26.JPG");

    gTexture=Dhaka_Textures[a];

    return menu;
}

int ambulance_Rajshahi(int b)
{

    Rajshahi_Textures[0]=loadedTexture("photos/Slide38.JPG");
    Rajshahi_Textures[1]=loadedTexture("photos/Slide37.JPG");
    Rajshahi_Textures[2]=loadedTexture("photos/Slide39.JPG");
    
    gTexture=Rajshahi_Textures[b];

    return menu;
}

int ambulance_chittagong(int c)
{
    
    Chittagong_Textures[0]=loadedTexture("photos/Slide9.JPG");
    Chittagong_Textures[1]=loadedTexture("photos/Slide10.JPG");
    Chittagong_Textures[2]=loadedTexture("photos/Slide11.JPG");
    Chittagong_Textures[3]=loadedTexture("photos/Slide8.JPG");
    Chittagong_Textures[4]=loadedTexture("photos/Slide14.JPG");
    Chittagong_Textures[5]=loadedTexture("photos/Slide12.JPG");
    Chittagong_Textures[6]=loadedTexture("photos/Slide6.JPG");
    Chittagong_Textures[7]=loadedTexture("photos/Slide7.JPG");
    Chittagong_Textures[8]=loadedTexture("photos/Slide13.JPG");
        
    gTexture=Chittagong_Textures[c];
    return menu;
}

int ambulance_Sylhet(int d)
{
    Sylhet_Textures[0]=loadedTexture("photos/ambulance12.JPG");
    Sylhet_Textures[1]=loadedTexture("photos/ambulance13.JPG");
    Sylhet_Textures[2]=loadedTexture("photos/ambulance14.JPG");
    Sylhet_Textures[3]=loadedTexture("photos/ambulance15.JPG");
    
    gTexture=Sylhet_Textures[d];
    return menu;
}

int ambulance_Barisal(int e)
{
    
    Barishal_Textures[0]=loadedTexture("photos/Slide5.JPG");
    Barishal_Textures[1]=loadedTexture("photos/Slide4.JPG");
    Barishal_Textures[2]=loadedTexture("photos/Slide2.JPG");
    Barishal_Textures[3]=loadedTexture("photos/Slide1.JPG");
    Barishal_Textures[4]=loadedTexture("photos/Slide3.JPG");
    
    gTexture=Barishal_Textures[e];
    return menu;
}

int ambulance_Khulna(int g)
{
    Khulna_Textures[0]=loadedTexture("photos/Slide31.JPG");
    Khulna_Textures[1]=loadedTexture("photos/Slide30.JPG");
    Khulna_Textures[2]=loadedTexture("photos/Slide33.JPG");
    Khulna_Textures[3]=loadedTexture("photos/Slide32.JPG");
    Khulna_Textures[4]=loadedTexture("photos/Slide29.JPG");
    Khulna_Textures[5]=loadedTexture("photos/Slide28.JPG");
    Khulna_Textures[6]=loadedTexture("photos/Slide27.JPG");
    Khulna_Textures[7]=loadedTexture("photos/Slide34.JPG");
    Khulna_Textures[8]=loadedTexture("photos/Slide35.JPG");
    Khulna_Textures[9]=loadedTexture("photos/Slide36.JPG");

    gTexture=Khulna_Textures[g];
    return menu;
}

int ambulance_Rangpur(int h)
{
    

    Rangpur_Textures[0]=loadedTexture("photos/ambulance2.JPG");
    Rangpur_Textures[1]=loadedTexture("photos/ambulance3.JPG");
    Rangpur_Textures[2]=loadedTexture("photos/ambulance4.JPG");
    Rangpur_Textures[3]=loadedTexture("photos/ambulance5.JPG");
    Rangpur_Textures[4]=loadedTexture("photos/ambulance6.JPG");
    Rangpur_Textures[5]=loadedTexture("photos/ambulance1.JPG");
    Rangpur_Textures[6]=loadedTexture("photos/ambulance7.JPG");

    gTexture=Rangpur_Textures[h];
    
    return menu;
}

int ambulance_Mymensingh(int p)
{
    Mymensingh_Textures[0]=loadedTexture("photos/ambulance8.JPG");
    Mymensingh_Textures[1]=loadedTexture("photos/ambulance9.JPG");
    Mymensingh_Textures[2]=loadedTexture("photos/ambulance10.JPG");
    Mymensingh_Textures[3]=loadedTexture("photos/ambulance11.JPG");

    gTexture=Mymensingh_Textures[p];
    return menu;
}


