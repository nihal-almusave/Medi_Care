#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Doctor {
    int no;
    char name[20];
    //int scode;//
    char special[20];
    char hname[20];
    //int mark;//
	int phone;
    char cname[20]; 
    /*int total;
    float per;*/
}Doctor;

void create () {
    Doctor *s;
    FILE *fp;
    int n, i, j;
    printf("Number of Doctors :");
    scanf("%d",&n);

    s = (Doctor*)calloc(n, sizeof(Doctor));
    fp = fopen("Doctors.txt","w");

    for(i=0;i<n;i++){
        /*s[i].total = 0;
        s[i].per = 0;*/
        printf("Enter serial No. : ");
        scanf("%d",&s[i].no);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%s",s[i].name);
		printf("");
        fwrite(&s[i], sizeof(Doctor),1,fp);
    }
    fclose(fp);

}
Doctor* display () {
    Doctor s1[100];
    FILE *fp;
    int i = 0, j;
    fp = fopen("Doctors.txt","r");
    while(fread(&s1[i],sizeof(Doctor),1,fp))
    {
		printf("")
		i++;//END
    }


    fclose(fp);
	return s1;
}
void append(/*arguments*/){
    Doctor s;
    FILE *fp;
    int n, i, j;
    //printf("Enter how many students you want :");
    //scanf("%d",&n);

    //s = (Doctor*)calloc(n, sizeof(Doctor));
    fp = fopen("Doctors.txt","a");



        
        s.no=inputno;
        s.name=inputname;
        fwrite(&s[i], sizeof(Doctor),1,fp);

    fclose(fp);
}
void noofrec() {
    Doctor s1;
    FILE *fp;
    fp = fopen("Doctors.txt","r");
    fseek(fp,0,SEEK_END);
    int n =ftell(fp)/sizeof(Doctor);
    printf("\n\n NO OF RECORDS = %d",n);
    fclose(fp);
}
// void search(){
//     Doctor s1;
//     FILE *fp;
//     int j,no,found=0;
//     fp = fopen("Doctors.txt","r");
//     printf("Enter rollno to Search : ");//argument as an array  0,1 array for specality
//     scanf("%d",&no);
//     while(fread(&s1,sizeof(Doctor),1,fp))
//     {
//         if(s1.no == no){
//             found =1;
//             printf("\n%-5d%-20s",s1.no,s1.name);
//             for(j=0;j<3;j++) {
//                 printf("%4d",s1.sub[j].mark);
//             }
//             printf("%5d%7.2f",s1.total,s1.per);
//         }
//     }
//     if(!found)
//             printf("\nRecord Not Found\n");


//     fclose(fp);
// }
Doctor* search(int flags[6]){
	Doctor result[100];
	Doctor temp;
	int found = 0, i = 0;
	char s_name[6][15] = ["medicine", "neurology", ""]; //sure na konta age hobe, 6 na 15

	fp = fopen("Doctors.txt", "r");

	while(fread(&temp, sizeof(Doctor), 1, fp)){
		for(j = 0; j < 6; j++){
			if(flags[j] == 1){
				if(!strcmp(temp.special, s_name[j])){	//! hobe kina sure na
					result[i] = temp;
					i++;
				}
			}
		}
	}

	return result;
}
void update(){
    Doctor s1;
    FILE *fp,*fp1;
    int j,no,found=0;
    fp = fopen("Doctors.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("Enter rollno to Update : ");
    scanf("%d",&no);
    while(fread(&s1,sizeof(Doctor),1,fp))
    {
        if(s1.no == no){
            s1.total = 0;
            s1.per = 0;
            found =1;
            fflush(stdin);
            printf("Enter New Name : ");
            scanf("%s",s1.name);
            for(j=0;j<3;j++) {
                printf("Enter New marks of Subject%d : ",j+1);
                scanf("%d",&s1.sub[j].mark);
                s1.total += s1.sub[j].mark;
            }
            s1.per = s1.total / 3.0;


        }
        fwrite(&s1,sizeof(Doctor),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1= fopen("temp.txt","r");
        fp = fopen ("Doctors.txt","w");
        while(fread(&s1,sizeof(Doctor),1,fp1)){
            fwrite(&s1,sizeof(Doctor),1,fp);
        }
        fclose(fp1);
        fclose(fp);
    }
    else
        printf("\nRecord Not Found\n");
}


//fclose(fp);
//}
void delete_rec(){
    Doctor s1;
    FILE *fp,*fp1;
    int j,no,found=0;
    fp = fopen("Doctors.txt","r");
    fp1 = fopen("temp.txt","w");
    printf("Enter rollno to Delete : ");
    scanf("%d",&no);
    while(fread(&s1,sizeof(Doctor),1,fp))
    {
        if(s1.no == no){
            found = 1;
        }
        else
            fwrite(&s1,sizeof(Doctor),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1= fopen("temp.txt","r");
        fp = fopen ("Doctors.txt","w");
        while(fread(&s1,sizeof(Doctor),1,fp1)){
            fwrite(&s1,sizeof(Doctor),1,fp);
        }
        fclose(fp1);
        fclose(fp);
    }
    else
        printf("\nRecord Not Found\n");
}


//fclose(fp);
//}
void sort_total_on_screen(){
    Doctor *s,s1;
    FILE *fp;
    int i,j;
    fp=fopen("Doctors.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(Doctor);
    s= (Doctor*)calloc(n,sizeof(Doctor));
    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(Doctor),1,fp);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(s[i].total < s[j].total){
                s1= s[i];
                s[i]= s[j];
                s[j]= s1;
            }
        }

    }
    for(i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].no,s1.name);
        for(j=0;j<3;j++) {
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);

    }

    fclose(fp);
}
void sort_total_in_file(){
   Doctor *s,s1;
   FILE *fp;
   int i,j;
   fp=fopen("Doctors.txt","r");
   fseek(fp,0,SEEK_END);
   int n = ftell(fp)/sizeof(Doctor);
   s= (Doctor*)calloc(n,sizeof(Doctor));
   rewind(fp);
   for(i=0;i<n;i++)
    fread(&s[i],sizeof(Doctor),1,fp);
fclose(fp);
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(s[i].total < s[j].total){
            s1= s[i];
            s[i]= s[j];
            s[j]= s1;
        }
    }

}
fp = fopen("Doctors.txt","w");
for(i=0;i<n;i++){
    printf("\n%-5d%-20s",s[i].no,s1.name);
    for(j=0;j<3;j++) {
        printf("%4d",s[i].sub[j].mark);
    }
    printf("%5d%7.2f",s[i].total,s[i].per);
    fwrite(&s[i],sizeof(Doctor),1,fp);
}
fclose(fp);
}
void sort_name_on_screen(){
    Doctor *s,s1;
    FILE *fp;
    int i,j;
    fp=fopen("Doctors.txt","r");
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(Doctor);
    s= (Doctor*)calloc(n,sizeof(Doctor));
    rewind(fp);
    for(i=0;i<n;i++)
        fread(&s[i],sizeof(Doctor),1,fp);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(s[i].name , s[j].name)>0){
                s1= s[i];
                s[i]= s[j];
                s[j]= s1;
            }
        }

    }
    for(i=0;i<n;i++){
        printf("\n%-5d%-20s",s[i].no,s1.name);
        for(j=0;j<3;j++) {
            printf("%4d",s[i].sub[j].mark);
        }
        printf("%5d%7.2f",s[i].total,s[i].per);

    }

fclose(fp);
}


int main() {
    int ch;
    do{
      printf("\n1.CREATE");
      printf("\n2.DISPLAY");
      printf("\n3.APPEND");
      printf("\n4.NO OF RECORDS");
      printf("\n5.SEARCH");
      printf("\n6.UPDATE");
      printf("\n7.DELETE");
      printf("\n8.SORT BY TOTAL DESC - ON SCREEN");
      printf("\n9.SORT BY TOTAL DESC - IN FILE");
      printf("\n10.SORT BY NAME - ON SCREEN");
      printf("\n0.EXIT");

      printf("\nEnter your choice : ");
      scanf("%d", &ch);
      printf("%d", ch);

      switch(ch) {
        case 1:
        create();
        break;
        case 2:
        display();
        break;
        case 3:
        append();
        break;
        case 4:
        noofrec();
        break;
        case 5:
        search();
        break;
        case 6:
        update();
        break;
        case 7:
        delete_rec();
        break;
        case 8:
        sort_total_on_screen();
        break;
        case 9:
        sort_total_in_file();
        break;
        case 10:
        sort_name_on_screen();
        break;
    }

}while(ch!=0);


return 0;
}