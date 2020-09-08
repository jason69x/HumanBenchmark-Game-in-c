#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    printf("\t\t* HUMAN BENCHMARK SYSTEM *\n");
    int choice;
    printf("\n \t choose a test : \n\n");
    printf("\n \t 1.number memory test \n \t 2.typing test \n \t 3.reaction time test \n \t 4.visual memory test \n \t 5.exit \n");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
            numbertest();
            break;
        case 2:
            typingtest();
            break;
        case 3:
            reactime();
            break;
        case 4:
            visualmemory();
            break;
        case 0:
            exit(0);
        default:
            printf("\n invalid choice closing program :/\n");
        }
}
