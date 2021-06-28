#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Ambulance {
    char ambulance_Division[100];
    char ambulance_name[100];
    char ambulance_phone_number[100];
 
 
}Ambulance;


void Ambulance_append(char AMBULANCE_DIVISION[100],char AMBULANCE_NAME[100],char AMBULANCE_Phone_NUMBER[100])
{
    Ambulance amb;
    FILE *filepointer;
    int n, i, j;

    filepointer = fopen("ambulance.txt","a");

    strcpy(amb.ambulance_Division,AMBULANCE_DIVISION);
    strcpy(amb.ambulance_name,AMBULANCE_NAME);
    strcpy(amb.ambulance_phone_number,AMBULANCE_Phone_NUMBER);
  
    fwrite(&amb, sizeof(Ambulance),1,filepointer);

    fclose(filepointer);
}
void Ambulance_noofrec() {
 Ambulance amb1;
 FILE *fp;
 fp = fopen("ambulance.txt","r");
 fseek(fp,0,SEEK_END);
 int n =ftell(fp)/sizeof(Ambulance);
 printf("\n\n NO OF RECORDS = %d",n);
 fclose(fp);
}



Ambulance* SEARCH(int flags[5],int *count,Ambulance rslt[])//string name_a[],string specality_a[],string hospital_a[],string chamber_a[],string phone_a[])
{//{0,1,.}&variable name,
    static Ambulance *reslt;
    Ambulance tem;
    FILE *fp;
    int found = 0, i = 0,j;
    reslt= (Ambulance*)calloc(100,sizeof(Ambulance));
    char am_name[8][18] = {"Dhaka","Rajshahi","Rangpur","Chattogram","Sylhet","Mymensingh","Khulna","Barishal"}; 

    fp = fopen("ambulance.txt", "r");

    while(fread(&tem, sizeof(Ambulance), 1, fp))
    {
     
        for(j = 0; j < 8; j++)
        {
        //printf ("%s \n",temp.special);//s_name[j]);
            if(flags[j] == 1)
            {

                if(!strcmp(tem.ambulance_Division, am_name[j]))
                { 
                // printf("Specality:%s\n",temp.special);
                // printf("Name: %s\n",temp.name);
                // printf("phone: %s\n",temp.phone);
                // printf("hospital: %s\n",temp.hname);
                // printf("Chamber: %s\n",temp.cname);
                // name_a[i]=temp.name;
                // hospital_a[i]=temp.hname;
                // specality_a[i]=temp.special;
                // chamber_a[i]=temp.cname;
                // phone_a[i]=temp.phone;
                strcpy(rslt[i].ambulance_Division,tem.ambulance_Division);
                strcpy(rslt[i].ambulance_name,tem.ambulance_name);
                strcpy(rslt[i].ambulance_phone_number,tem.ambulance_phone_number);
                //printf("%s\n",temp.special);
            
            i++;
            // printf("%d\n",i);
            }
        // printf("%s\n",temp.special);
            //printf("%s\n",temp.name);
        
        }

        // printf("%d",flags[j]);
        }

    }
 //printf("%d\n",i);
//  for (int d=0;d<i;d++)
//     {
//         printf("division: %s\n",rslt[d].ambulance_Division);
//         printf("name : %s\n",rslt[d].ambulance_name);
//         printf("phn:%s\n",rslt[d].ambulance_phone_number);
//     }
*count = i;

 return reslt;
}



//void create () {
//  Doctor *s;
//  FILE *fp;
//  int n, i, j;
//  printf("Number of Doctors : ");
//  scanf(" %d",&n);

//  s = (Doctor*)calloc(n, sizeof(Doctor));
//  fp = fopen("Doctors.txt","w");

//  for(i=0;i<n;i++){
//  /*s[i].total = 0;
//  s[i].per = 0;*/
//  printf("Enter serial No. : ");
//  scanf("%d",&s[i].no);
//  fflush(stdin);
//  printf("Enter Name: ");
//  fgets(s[i].name,100,stdin);
//  printf("Enter Speciality: ");
//  fgets(s[i].special,100,stdin);
//  printf("Enter hospital name: ");
//  fgets(s[i].hname,100,stdin);
//  printf("Enter phone number: ");
//  fgets(s[i].phone,100,stdin);
//  printf("Enter chamber name: ");
//  fgets(s[i].cname,100,stdin);

//  fwrite(&s[i], sizeof(Doctor),1,fp);
//  }
//  fclose(fp);

// }