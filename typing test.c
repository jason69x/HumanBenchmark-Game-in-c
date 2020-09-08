#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

// Function for comparing files
void compare(FILE *ft,FILE *fs,int choice,double timetaken)
{
    char c1,c2;
    int error=0;
    switch(choice)
        {
        case 1:
            ft = fopen("general.txt","r");
            break;
        case 2:
            ft = fopen("capital.txt","r");
            break;
        case 3:
            ft = fopen("numbers.txt","r");
            break;
        case 4:
            ft = fopen("symbols.txt","r");
            break;
        }
    fs = fopen("source.txt","r");
    printf("\n");
    while((c1=getc(fs))!=EOF)
        {
            c2=getc(ft);
            if(c1==c2)
                {
                    color(10,0);
                    printf("%c",c1);
                }
            if(c1!=c2)
                {
                    color(4,0);
                    printf("%c",c1);
                    error++;
                }
        }
    color(0,14);
    printf("\n\n\t\ttotal no. of errors: %d\n",error);
    printf("\t\ttotal time taken:    %.2lfs\n",(timetaken)/1000);
    color(0,15);
}
void typingtest()
{
    FILE *ft,*fs;
    int  choice;
    char ch,str[650];
    color(13,0);
    printf("\n\t\t\t\tWelcome to typing test\t\t\t\t");
    color(9,0);
    printf("\n\n\t\tplease select a test from the list");
    printf("\n\n\t\t1.general\n\t\t2.Capitalization\n\t\t3.Numbers\n\t\t4.Symbols\n");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
            ft = fopen("general.txt","r");
            break;
        case 2:
            ft = fopen("capital.txt","r");
            break;
        case 3:
            ft = fopen("numbers.txt","r");
            break;
        case 4:
            ft = fopen("symbols.txt","r");
            break;
        default:
            printf("\ninvalid choice exiting test");
            exit(0);
        }
    fs = fopen("source.txt","w");
    if(fs==NULL||ft==NULL)
        {
            printf("\ncannot open source or target file");
            exit(1);
        }
    color(9,0);
    printf("\n\n\t\tHere is the text:\n\n");
    color(3,15);
    while((ch=fgetc(ft))!=EOF)
        {
            if(choice==2)
                {
                    printf("%c",ch);
                    continue;
                }
            printf("%c",ch);
        }
    color(3,0);
    printf("\n\n\t\tstart typing:\n\n");
    clock_t starttime = clock();
    fflush(stdin);
    while(strlen(gets(str))!=0)
        {
            fputs(str,fs);
        }
    clock_t endtime = clock();
    double timetaken = (double)(endtime-starttime);
    fclose(fs);
    fclose(ft);
    color(4,0);
    printf("\n\n\t\terrors:");
    compare(ft,fs,choice,timetaken);
}
