// Function for printing random number upto specified digits
#include "headerfile.h"
unsigned long int randnum(unsigned long int dig,unsigned long int max)
{
    char string[32];
    uint32_t myint;
    if(sodium_init()<0)
    {
        return 1;
    }
    randombytes_buf(string,32);
    myint = randombytes_uniform(max) + dig;
    if(myint>=max)
    {
        myint-=dig;
    }
    return myint;
}

// coloring

void color(int a,int b)
{
    setColor(a);
    setBackgroundColor(b);
}
void detectkey()
{
    anykey(NULL);
}


// compare func typing test

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
