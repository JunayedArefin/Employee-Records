#include <stdio.h>
#include <stdlib.h>



int main()

{

    int n;

    while(1)

    {

        system("cls");

        printf("\n");

        printf("\t\t\t\t           ____________________________________\n");

        printf("\n\t\t\t\t\t     /    Employee Record System    /\n");

        printf("\t\t\t\t           ____________________________________\n");

        printf("\n\t\t\t\t          Here you can control Employee Records!    \n");

        printf("\n");

        printf("\t\t\t\t                ><><><><><> o <><><><><><        \n");

        printf("\n");

        printf("\n");

        printf("\t\t\t\t\t          ________Menu________");



        printf("\n");

        printf("\n\t\t\t\t                   |1| Add Employee |");

        printf("\n\t\t\t\t                   |2| Records List |");

        printf("\n\t\t\t\t                   |3| Search       |");

        printf("\n\t\t\t\t                   |4| Delete       |");

        printf("\n\t\t\t\t                   |5| Exit         |");

        printf("\n");

        printf("\t\t\t\t\t          ____________________");



        printf("\n\n\n\t\t\tEnter an Option no.: ");

        scanf("%d",&n);

        switch(n)

        {

        case 1:

            EmAdd();

            break;

         case 2:

             EmList();

             break;

        case 3:

             search();

             break;

         case 4:

             EmDelete();

             break;

        case 5:

            return 0;

            break;

        }

    }



}

struct records

{

    char name[30],eID[30],ePost[30],eSlry[30];



};

struct records r;

void EmAdd()

{

    getchar();

    system("cls");

    FILE *file;

    file = fopen("file.txt","ab+");

    printf("\t\t\t\t             _____________________________________________\n");

    printf("\n\t\t\t\t\t     /    Here You Can Add Employee Details!    /\n");

    printf("\t\t\t\t             _____________________________________________\n");

    printf("\n\t\t\t\tEnter Name : ");

    gets(r.name);

    printf("\n\t\t\t\tEnter ID : ");

    gets(r.eID);

    printf("\n\t\t\t\tEnter Post : ");

    gets(r.ePost);

    printf("\n\t\t\t\tEnter Salary : ");

    gets(r.eSlry);

    fwrite(&r,sizeof(r),1,file);

    printf("Employee Details Added Successfully");

    fclose(file);



}





void EmDelete()

{

    getchar();

    system("cls");



    char name[40];

    unsigned flag=0;



    FILE *file,*file2;

    file=fopen("file.txt","rb");

            printf("\t\t\t\t             ____________________________________\n");

        printf("\n\t\t\t\t\t     /    Delete Any Employees Records   /\n");

        printf("\t\t\t\t             ____________________________________\n");



    printf("\n_________________ \n");

    printf("\nEnter Name for delete \n");



    printf("_______________________ ");

    gets(name);



    file2=fopen("file2.txt","ab+");

    while(fread(&r,sizeof(r),1,file)==1)

    {

        if(strcmp(name,r.name)!=0)

        {

            printf("\n\n");

            printf("     Details Deleted Successfully!\n");

            fwrite(&r,sizeof(r),1,file2);

        }

        else

            flag=1;

    }



        fclose(file);

        fclose(file2);

        remove("file.txt");

        rename("source2.txt","file.txt");

        printf("\n\t____________________\n");

        printf("\n\t/ Updated Details! /\n");

        printf("\t____________________\n");



    printf("\n\nPress Any Key to Return...");

    getch();

}



void EmList()

{

    char ch;

    system("cls");

    FILE *file;

    file = fopen("file.txt","rb");



    printf("\t\t\t\t             ____________________________________\n");

    printf("\n\t\t\t\t\t     /    Here The List of Employees    /\n");

    printf("\t\t\t\t             ____________________________________\n");

    printf("\n\n");

    printf("     ____________________________________________________________________________________\n\n");

    printf("\tName\t\t|\tID\t\t|\tPost\t\t|\tSalary\t\n");

    printf("     ____________________________________________________________________________________");





    while(fread(&r,sizeof(r),1,file)==1)

        printf("\n\n\t%s\t\t%s\t\t%s\t\t\t%s\n",r.name,r.eID,r.ePost,r.eSlry);

        fclose(file);



    printf("\n\nPress Any Key to Return...");

    getch();

}





void search()

{

    system("cls");

    char id[25];

    unsigned flag=0;

    FILE *file;

    file=fopen("file.txt","ab+");

        printf("\t\t\t\t             _____________________\n");

    printf("\n\t\t\t\t\t     /    Search here    /\n");

    printf("\t\t\t\t             _____________________\n");

    printf("\n________________ \n");

    printf("\nEnter ID for search \n");



    printf("_____________________ ");

    scanf("%s",&id);

    while(fread(&r,sizeof(r),1,file)>0 && flag==0)

    {

        if(strcmp(id,r.eID)==0)

        {

            flag=1;

            printf("\n\n\tName : %s\n\tID : %s\n\tPost : %s\n\tSalary : %s\n",r.name,r.eID,r.ePost,r.eSlry);

        }

    }

    fclose(file);

    printf("\n\nPress Any Key to Return...");

    getch();

}
