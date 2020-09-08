#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>
#include <rlutil.h>
#include <unistd.h>
#include <conio.h>

// Function for printing random number upto specified digits

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

// Function To play game

int play(int *level,int *score,unsigned long int *min,unsigned int *max)
{
    hidecursor();
    unsigned int real_ans,your_ans;
    char choice = 'y';
    real_ans = randnum(*(min),*(max));

    setColor(15);
    setBackgroundColor(9);

    printf("\n\nHere is the Number :           %u",real_ans);

    if(*(level)<=5) //loops for delay
        msleep(230);
    if(*(level)>=6&&*(level)<8)
        msleep(800);
    if(*(level)>=8)
        msleep(2000);

    fflush(stdout);
    printf("\b\b\b\b\b\b\b\b\b\b               \n"); // To Hide the displayed number
    fflush(stdout);

    setColor(3);
    setBackgroundColor(15);

    printf("\nEnter the correct number :");
    scanf("%u",&your_ans);
    fflush(stdin);

    setColor(0);
    setBackgroundColor(10);

    printf("\ncorrect answer : %d\nyour answer : %d",real_ans,your_ans);

    if(your_ans==0)
        {
            setColor(0);
            setBackgroundColor(12);
            exit(0);
        }
    else if(real_ans == your_ans)
        {
            (*(score))+=1;
            (*(level))++;

            setColor(0);
            setBackgroundColor(14);

            printf("\nYour current score : %d",*(score));
            printf("\nNext Level : %d",*(level));
            (*(min))*=10;
            (*(max))*=10;

            return 1;
        }
    else
        {
            setColor(15);
            setBackgroundColor(4);

            printf("\nincorrect answer");
            return 0;
        }
}
//

int numbertest()
{
    hidecursor(); // Function to hide cursor ( defined in rlutil.h )

    unsigned int  level=1,score=0,min=1,max=10,flag;
    char choice='y',ch;

    setColor(15);                //   defined in rlutil.h used to change text colors
    setBackgroundColor(3);       //   these functions use ascii color codes for changing colors

    printf("\n\t\tWelcome to Number Memory Test\t\t\n");
    printf("\nWhile in a Game you can press 0 to exit\n");

    printf("\npress any key to start:");
    scanf("%c",&ch);

    while(choice='y')
        {
            flag = play(&level,&score,&min,&max);

            if(flag==1)
                {
                    choice='y';
                }
            else
                {
                    choice ='n';
                }
        }

    return 0;
}

// Function for changing text background and text color

void color(int a,int b)
{
    setColor(a);
    setBackgroundColor(b);
}

// Function for detecting key for reaction time game

void detectkey()
{
    anykey(NULL);
}

