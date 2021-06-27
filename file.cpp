#include<iostream>
#include<stdio.h>


using namespace std;

int main (int args, char *argc[])
{
    FILE *fp;
    char line[4096],medium[4096];
    fp=fopen("message.txt","a");
    char ch=fgetc(fp);
    int i=0;

    string speciality,doctor,TIme,location;
    speciality="Medicine";
    doctor="MD. Abdullah";
    TIme="09:00 A.M. to 12:00 P.M.";
    location="Dhaka Medical Collegee";

    const char *Speciality,*Doctor,*Time,*Location;

    Speciality=speciality.c_str();
    Doctor=doctor.c_str();
    Time=TIme.c_str();
    Location=location.c_str();


    fputs(Speciality,fp);
    fputs("**",fp);


    string some(line);
    cout<<some;
    fclose(fp);
}