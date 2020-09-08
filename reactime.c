#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int reactime()
{
    printf("\nwelcome to the reaction time test");
    char choice;
    int pause = randnum(1,8)*1000;
    while(choice!='0')
        {
            printf("\n\npress any key as soon as color changes to green\n\n");
            color(15,4);
            printf(" wait for green ");
            color(15,2);
            Sleep(pause);
            printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b     green      ");
            clock_t start = clock();
            detectkey();
            clock_t end = clock();
            double elapsed = (double)(end-start)/CLOCKS_PER_SEC;
            printf("\n\ntotal time elapsed : %.0fms",elapsed*1000);
            color(0,14);
            printf("\n\npress any key to play again or '0' to exit");
            choice = getche();
        }
}
