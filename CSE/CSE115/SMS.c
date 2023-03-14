//student management system 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input();
void display();
void search();
void SearchByID();
void SearchByName();
void Modify();


typedef struct  student
{
    char name[30];
    int id;
    double CGPA;
    char dep[40];
    int Enroll_Year;
}stu;
stu s,t;
int stutus;

FILE*infile;

int main()
{
    char name[40];
    int  ch;
    printf("           Student Management System\n");

    while(1)
    {
        
        printf("\n\n1. Add Student: \n");
        printf("2. Search Student: \n");
        printf("3. Modifiy Student Information: \n");
        printf("4. All Student Record: \n");
        printf("5. Delete Stuent: \n");
        printf("0. Logout: \n");
        printf("Plese Enter your choise: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 0: 
            exit(0);

            case 1: 
            input();
            break;

            case 2:
            search();
            break;

            case 3:
            Modify();
            break;

            case 4: 
            display();
            break;

        }
     }  
}
void input()
{
    
     infile= fopen("stuinfo.txt", "a");
     printf("Enter student name: ");
     fflush(stdin);
     gets(s.name);
     fflush(stdin);
     printf("Enter Student ID: ");
     scanf("%d",&s.id);
     printf("Enter CGPA: ");
     scanf("%lf",&s.CGPA);
     fflush(stdin);
     printf("Enter Deparment: ");
     gets(s.dep);
     printf("Enter Enroll year: ");
     scanf("%d",&s.Enroll_Year);

     fprintf(infile,"%s %d %.2lf %s %d\n",s.name,s.id,s.CGPA,s.dep,s.Enroll_Year);
     fclose(infile);
     printf("Record Saved Successful");

    
}

void display()
{
       printf("%-10s %-10s %-10s %-10s %-10s\n", "Name", "ID", "CGPA", "DEP", "Enroll Semister");
        infile= fopen("stuinfo.txt", "r");
        stutus=fscanf(infile,"%s %d %lf %s %d",t.name,&t.id,&t.CGPA,t.dep,&t.Enroll_Year);

        while(stutus != EOF)
        {
            //fscanf(infile,"%s %d %lf %s %d",t.name,&t.id,&t.CGPA,s.dep,&s.Enroll_Year);
            printf("%s    %d     %.2lf       %s        %d\n",t.name,t.id,t.CGPA,t.dep,t.Enroll_Year);
            stutus=fscanf(infile,"%s %d %lf %s %d",t.name,&t.id,&t.CGPA,t.dep,&t.Enroll_Year);
        }
        fclose(infile);
        
}

void search()
{
    int option;
    printf("*Please choose your option*\n");
    printf("\nSearch by ID or Name\n");
    printf("\n1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Please  Enter Your Choise: ");
    scanf("%d",&option);

    switch(option)
    {
        case 0:
        main();
        break;

        case 1:
        SearchByID();
        break;

        case 2:
        SearchByName();
        break;

        default:
        printf("You enter invalid Input");
    }

}

void SearchByID()
{
    int IDno, flag=0;
    printf("Enter Student ID: ");
    scanf("%d",&IDno);
    infile=fopen("stuinfo.txt","r");
    stutus= fscanf(infile,"%s %d %lf %s %d",t.name,&t.id,&t.CGPA,t.dep,&t.Enroll_Year);

    while(stutus !=EOF)
    {
        if(IDno==t.id)
        {
             printf("%s    %d     %.2lf       %s        %d\n",t.name,t.id,t.CGPA,t.dep,t.Enroll_Year);
                flag=1;
            
        }
        stutus= fscanf(infile,"%s %d %lf %s %d",t.name,&t.id,&t.CGPA,t.dep,&t.Enroll_Year);
    }
    
    if(flag==0)
    {
        printf("This %d  not found Our Record.",IDno);
    }
    fclose(infile);
}

void SearchByName()
{
        char name[30];
        int flag=0;
        fflush(stdin);
        printf("Enter Name: ");
        fflush(stdin);
        gets(name);
        
        infile= fopen("stuinfo.txt", "r");
        stutus= fscanf(infile,"%s %d %lf %s %d",s.name,&s.id,&s.CGPA,s.dep,&s.Enroll_Year);
        while(stutus !=EOF)
        {
            if(strcmp(s.name,name)==0)
            {
                printf("%s    %d     %.2lf       %s        %d\n",s.name,s.id,s.CGPA,s.dep,s.Enroll_Year);
                flag=1;
            }
            stutus= fscanf(infile,"%s %d %lf %s %d",s.name,&s.id,&s.CGPA,s.dep,&s.Enroll_Year);
        }
        if(flag==0)
    {
        printf("This %s  not found Our Record.",name);
    }
    fclose(infile);
    

}

void Modify()
{
    int id;
    int flag = 0;
    
    printf("Enter Student ID which Is want to Modify: ");
    scanf("%d",&id);
    infile= fopen("stuinfo.txt","rb+");
    if(infile == NULL)
    {
        printf("File dose not open\n");
    }
    stutus= fscanf(infile,"%s %d %lf %s %d",s.name,&s.id,&s.CGPA,s.dep,&s.Enroll_Year);
    printf("%d stutus value\n",stutus);
    while(stutus != EOF)
    {
        if(id==s.id)
        {
            //fflush(stdin);
            printf("Enter new name: ");
            fflush(stdin);
            gets(s.name);
            printf("Enter New id: ");
            scanf("%d",&s.id);
            printf("Enter new CGPA: ");
            scanf("%lf",&s.CGPA);
            printf("ENter new depertment: ");
            fflush(stdin);
            gets(s.dep);
            printf("Enete enroll Year: ");
            scanf("%d",&s.Enroll_Year);
            //fseek(infile,-sizeof(s),1);
            //fprintf(infile,"%s %d %.2lf %s %d\n",s.name,s.id,s.CGPA,s.dep,s.Enroll_Year);
            fprintf(infile,"\n%s    %d     %.2lf       %s        %d",s.name,s.id,s.CGPA,s.dep,s.Enroll_Year);
            flag=1;
            break;


        }
        stutus= fscanf(infile,"%s %d %lf %s %d",s.name,&s.id,&s.CGPA,s.dep,&s.Enroll_Year);
        
    }

    if(flag==1){
        printf("Record successfully Updeted.");
    }
    else
    {
        printf("This %d ID not foound our Record.",id);
    }

    fclose(infile);
    
    
}