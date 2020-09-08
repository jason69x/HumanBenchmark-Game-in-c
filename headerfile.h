#ifndef HEADERFILE_H_INCLUDED
#define HEADERFILE_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sodium.h>
#include <rlutil.h>
#include <unistd.h>
#include <time.h>
#include <string.h>


unsigned long int randnum(unsigned long int dig,unsigned long int max);
void color(int a,int b);
void detectkey();
void compare(FILE *ft,FILE *fs,int choice,double timetaken);


#endif // HEADERFILE_H_INCLUDED
