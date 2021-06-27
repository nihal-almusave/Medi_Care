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
int Rangpur_District();

//District informatio
int ambulance_Rajshahi();
int ambulance_chittagong();
int ambulance_Sylhet();
int ambulance_Barisal();
int ambulance_Khulna();
int ambulance_Mymensingh();
int ambulance_Dhaka();
int ambulance_Rangpur();


int ambulace_front()
{
    gTexture=loadedTexture("photos/Ambulance service.jpg");
    
    if(event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=668&&event.motion.x<=912)
        {
            if (event.motion.y>=163&&event.motion.y<=230)
            {
                menu=6;
                ambulance_Dhaka();
            }
            else if (event.motion.y>=260&&event.motion.y<=325)
            {
                menu=11;
                ambulance_Rajshahi();
            }
            else if (event.motion.y>=355&&event.motion.y<=419)
            {
                menu=12;
                ambulance_chittagong();
            }
            else if (event.motion.y>=451&&event.motion.y<=515)
            {
                menu=13;
                ambulance_Sylhet();
            }
            else if (event.motion.y>=546&&event.motion.y<=610)
            {
                menu=14;
                ambulance_Barisal();
            }
            else if (event.motion.y>=649&&event.motion.y<=708)
            {
                menu=15;
                ambulance_Khulna();
            }
            else if (event.motion.y>=738&&event.motion.y<=804)
            {
                menu=16; 
                ambulance_Rangpur();              
            }
            else if (event.motion.y>=833&&event.motion.y<=898)
            {
                menu=17;
                ambulance_Mymensingh();
            }
        }
        // else if (event.motion.x>=1287 && event.motion.x<=1424 && event.motion.y>=915 && event.motion.y<=968&&menu==5)
        // {
        //     menu=0;
        //     first_window();
        // }
    }
    return menu;
}

int ambulance_Dhaka()
{
    gTexture=loadedTexture("photos/Dhaka District Ambulance.jpg");

    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=638&&event.motion.x<=876)
        {
            if (event.motion.y>=122&&event.motion.y<=187)
            {
                gTexture=loadedTexture("photos/Slide15.JPG");   
            }
            else if (event.motion.y>=219&&event.motion.y<=284)
            {
                gTexture=loadedTexture("photos/Slide17.JPG");
            }
            else if (event.motion.y>=317&&event.motion.y<=379)
            {
                gTexture=loadedTexture("photos/Slide23.JPG");
            }
            else if (event.motion.y>=409&&event.motion.y<=476)
            {
                gTexture=loadedTexture("photos/Slide20.JPG");
            }
            else if (event.motion.y>=505&&event.motion.y<=571)
            {
                gTexture=loadedTexture("photos/Slide21.JPG");
            }
            else if (event.motion.y>=601&&event.motion.y<=668)
            {
                gTexture=loadedTexture("photos/Slide22.JPG");
            }
            else if (event.motion.y>=696&&event.motion.y<=759)
            {
                gTexture=loadedTexture("photos/Slide16.JPG");
            }
            else if (event.motion.y>=791&&event.motion.y<=858)
            {
            
            }
        }

        else if (event.motion.x>=946&&event.motion.x<=1184)
        {
            if (event.motion.y>=238&&event.motion.y<=306)
            {
                gTexture=loadedTexture("photos/Slide18.JPG");
            }
            else if (event.motion.y>=336&&event.motion.y<=404)
            {
                gTexture=loadedTexture("photos/Slide19.JPG");
            }
            else if (event.motion.y>=432&&event.motion.y<=4970)
            {
                gTexture=loadedTexture("photos/Slide24.JPG");
            }
            else if (event.motion.y>=524&&event.motion.y<=593)
            {
                gTexture=loadedTexture("photos/Slide25.JPG");
            }
            else if (event.motion.y>=622&&event.motion.y<=686)
            {
                gTexture=loadedTexture("photos/Slide26.JPG");
            }
        }
        else if (event.motion.x>=1306&&event.motion.x<=1424&&event.motion.y>=914&&event.motion.y<=959)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Rajshahi()
{
    gTexture=loadedTexture("photos/Rajshahi Division's District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=667&&event.motion.x<=912)
        {
            if (event.motion.y>=167&&event.motion.y<=233)
            {
                gTexture=loadedTexture("photos/Slide38.JPG");
            }
            else if (event.motion.y>=261&&event.motion.y<=328)
            {

            }
            else if (event.motion.y>=359&&event.motion.y<=422)
            {

            }
            else if (event.motion.y>=454&&event.motion.y<=518)
            {

            }
            else if (event.motion.y>=548&&event.motion.y<=610)
            {

            }
            else if (event.motion.y>=644&&event.motion.y<=705)
            {
                gTexture=loadedTexture("photos/Slide37.JPG");
            }
            else if (event.motion.y>=739&&event.motion.y<=801)
            {
                gTexture=loadedTexture("photos/Slide39.JPG");
            }
            else if (event.motion.y>=835&&event.motion.y<=897)
            {

            }
        }
        else if (event.motion.x>=1306&&event.motion.x<=1424&&event.motion.y>=914&&event.motion.y<=959)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_chittagong()
{
    gTexture=loadedTexture("photos/Chittagong Division District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=648 && event.motion.x<=890)
        {
            if (event.motion.y>=158 && event.motion.y<=222)
            {
                gTexture=loadedTexture("photos/Slide9.JPG");
            }
            else if (event.motion.y>=253 && event.motion.y<=319)
            {
                gTexture=loadedTexture("photos/Slide10.JPG");
            }
            else if (event.motion.y>=349 && event.motion.y<=413)
            {
                gTexture=loadedTexture("photos/Slide11.JPG");
            }
            else if (event.motion.y>=442 && event.motion.y<=509)
            {

            }
            else if (event.motion.y>=536 && event.motion.y<=600)
            {
                gTexture=loadedTexture("photos/Slide8.JPG");
            }
            else if (event.motion.y>=635 && event.motion.y<=697)
            {
                gTexture=loadedTexture("photos/Slide14.JPG");
            }   
            else if (event.motion.y>=730 && event.motion.y<=792)
            {
                gTexture=loadedTexture("photos/Slide12.JPG");
            }
            else if (event.motion.y>=825 && event.motion.y<=888)
            {
                gTexture=loadedTexture("photos/Slide6.JPG");
            }
        }
        else if (event.motion.x>=964 && event.motion.x<=1205)
        {
            if (event.motion.y>=374 && event.motion.y<=435)
            {
                gTexture=loadedTexture("photos/Slide7.JPG");
            }
            else if (event.motion.y>=469 && event.motion.y<=532)
            {

            }
            else if (event.motion.y>=562&& event.motion.y<=629)
            {
                gTexture=loadedTexture("photos/Slide13.JPG");
            }
        }
        else if (event.motion.x>=1310&&event.motion.x<=1427&&event.motion.y>=916&&event.motion.y<=968)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Sylhet()
{
    gTexture=loadedTexture("photos/Sylhet Divison's District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=672 && event.motion.x<=909)
        {
            if (event.motion.y>=224 && event.motion.y<=284)
            {

            }
            else if (event.motion.y>=320 && event.motion.y<=380)
            {

            }
            else if (event.motion.y>=412 && event.motion.y<=473)
            {

            }
            else if (event.motion.y>=507 && event.motion.y<=575)
            {

            }
        }
        else if (event.motion.x>=1283 && event.motion.x<=1405 && event.motion.y>=915 && event.motion.y<=972)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Barisal()
{
    gTexture=loadedTexture("photos/Barisal Divison's District.jpg");
    if (event.type=SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=669 && event.motion.x<=912)
        {
            if (event.motion.y>=185 && event.motion.y<=249)
            {
                gTexture=loadedTexture("photos/Slide5.JPG");
            }
            else if (event.motion.y>=281 && event.motion.y<=345)
            {
                gTexture=loadedTexture("photos/Slide40.JPG");
            }
            else if (event.motion.y>=374 && event.motion.y<=439)
            {
                gTexture=loadedTexture("photos/Slide4.JPG");
            }
            else if (event.motion.y>=471 && event.motion.y<=535)
            {
                gTexture=loadedTexture("photos/Slide2.JPG");
            }
            else if (event.motion.y>=567 && event.motion.y<=632)
            {
                gTexture=loadedTexture("photos/Slide1.JPG");
            }
            else if (event.motion.y>=662 && event.motion.y<=720)
            {
                gTexture=loadedTexture("photos/Slide3.JPG");
            }
        }
        else if (event.motion.x>=1290 && event.motion.x<=1423 && event.motion.y>=920 && event.motion.y<=965)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Khulna()
{
    gTexture=loadedTexture("photos/Khulna Division's District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=648 && event.motion.x<=892)
        {
            if (event.motion.y>=157 && event.motion.y<=222)
            {
                gTexture=loadedTexture("photos/Slide31.JPG");
            }
            else if (event.motion.y>=254 && event.motion.y<=317)
            {
                gTexture=loadedTexture("photos/Slide30.JPG");
            }
            else if (event.motion.y>=350 && event.motion.y<=413)
            {
                gTexture=loadedTexture("photos/Slide33.JPG");
            }
            else if (event.motion.y>=449 && event.motion.y<=508)
            {
                gTexture=loadedTexture("photos/Slide32.JPG");
            }
            else if (event.motion.y>=539 && event.motion.y<=602)
            {
                gTexture=loadedTexture("photos/Slide29.JPG");
            }
            else if (event.motion.y>=332 && event.motion.y<=697)
            {
                gTexture=loadedTexture("photos/Slide28.JPG");
            }
            else if (event.motion.y>=728 && event.motion.y<=792)
            {
                gTexture=loadedTexture("photos/Slide27.JPG");
            }
            else if (event.motion.y>=822 && event.motion.y<=888)
            {
                gTexture=loadedTexture("photos/Slide34.JPG");
            }
        }
        else if (event.motion.x>=962 && event.motion.x<=1205)
        {
            if (event.motion.y>=411 && event.motion.y<=477)
            {
                gTexture=loadedTexture("photos/Slide35.JPG");
            }

            else if (event.motion.y>=509 && event.motion.y<=570)
            {
                gTexture=loadedTexture("photos/Slide36.JPG");
            }
        }
        else if (event.motion.x>=1297 && event.motion.x<=1429 && event.motion.y>=901 && event.motion.y<=958)
        {
            menu = 5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Rangpur()
{
    gTexture=loadedTexture("photos/Rangpur Division's District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=669 && event.motion.x<=912)
        {
            if (event.motion.y>=167 && event.motion.y<=232)
            {

            }
            else if (event.motion.y>=264 && event.motion.y<=328)
            {

            }
            else if (event.motion.y>=360 && event.motion.y<=422)
            {

            }
            else if (event.motion.y>=460 && event.motion.y<=522)
            {

            }
            else if (event.motion.y>=547 && event.motion.y<=614)
            {

            }
            else if (event.motion.y>=642 && event.motion.y<=708)
            {

            }
            else if (event.motion.y>=741 && event.motion.y<=805)
            {
                
            }
            else if (event.motion.y>=833 && event.motion.y<=900)
            {

            }
        }
        else if (event.motion.x>=1314 && event.motion.x<=1430 && event.motion.y>=921 && event.motion.y<=970)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int ambulance_Mymensingh()
{
    gTexture=loadedTexture("photos/Mymensingh Division's District.jpg");
    if (event.type==SDL_MOUSEBUTTONDOWN)
    {
        if (event.motion.x>=668 && event.motion.x<=911)
        {
            if (event.motion.y>=223 && event.motion.y<=287)
            {

            }
            else if (event.motion.y>=321 && event.motion.y<=383)
            {

            }
            else if (event.motion.y>=414 && event.motion.y<=476)
            {

            }
            else if (event.motion.y>=507 && event.motion.y<=571)
            {

            }
        }
        else if (event.motion.x>=1289 && event.motion.x<=1404 && event.motion.y>=919 && event.motion.y<=967)
        {
            menu=5;
            ambulace_front();
        }
    }
    return menu;
}

int Rangpur_District()
{
    gTexture=loadedTexture("photos/Rangpur DIvision District Rangpur.jpg");
    if (event.motion.x>=1205 && event.motion.x<=1385 && event.motion.y>=854 && event.motion.y<=936)
    {
        menu=16;
    }
    return menu;
}