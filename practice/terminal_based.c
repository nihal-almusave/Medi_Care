#include<stdio.h>

void D_D_Medicine()
{
    FILE* fp=fopen("fp.txt","r");
    char ch;
    
    do 
    {
        ch=fgetc(fp);

        putchar(ch);

    }while (ch!=EOF);
    printf ("\n");

    fclose(fp);
}
void D_D_Department()
{
    printf ("Medicine\n");
    printf ("Orthopedic\n");

    int a;

    printf ("choose:");
    scanf ("%d",&a);

    if (a==1)
    {
        D_D_Medicine();
    }
}

void D_District()
{
    printf ("Dhaka\n");
    printf ("Narayanganj\n");

int a;

printf ("Choose:");
scanf ("%d",&a);

if (a==1)
{
    D_D_Department();
}
}
void need_doctor()
{
    int a;
    printf ("Division:\n");

    printf ("Dhaka\n");
    printf ("Chottogram\n");
    printf ("Sylhet\n");
    printf ("Barishal\n");
    printf ("Dinajpur\n");
    printf ("Rangpur\n");
    printf ("Khulna\n");
    printf ("Mymensingh\n");

    printf ("Choose :");
    scanf ("%d",&a);

    if (a==1)
    {
        D_District();
    }
    else if (a==2)
    {

    }
    else if (a==3)
    {

    }
    else if (a==4)
    {

    }
    else if (a==5)
    {

    }
    else if (a==6)
    {

    }
    else if (a==7)
    {

    }
    else if (a==8)
    {

    }

}

void need_ambulance()
{
    

}

void Symptoms_Deseses()
{
    
}
void list()
{
    printf ("Need a Doctor\n");
    printf ("Need Ambulance\n");
    printf ("Symptoms of Diseases\n");

    int b;
    printf ("Choose : ");
    scanf ("%d",&b);

    if (b==1)
    {
        need_doctor();
    }
    else if (b==3)
    {
        need_ambulance();
    }
    else if (b==4)
    {
        Symptoms_Deseses();
    }
}


int main()
{
    list();
    return 0;
}