#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define WORDS 20

void visualmemory()
{
    FILE *fs;
    fs = fopen("words.txt","r");
    if(fs==NULL)
        {
            printf("\ncannot open source file");
            exit(0);
        }
    int rand,i=0,lives=3;
    char *word[20],ans;
    for(i=0; i<20; i++)
        {
            fscanf(fs,"%s",word[i]);
        }
    for(i=0; i<20; i++)
        {
            printf("%s",word[i]);
        }

}



