#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define daysAWeek 7

// Day Arrays
struct Course* arrayM;
struct Course* arrayT;
struct Course* arrayW;
struct Course* arrayH;
struct Course* arrayF;
struct Course* arrayS;

// Structure
struct Course{
    char* code;       //FDCNSYS
    char* section;    //ZZ14 + 1 more char
    char* time;     //0900-1300
    
    // M = 1, T = 2, W = 3, H = 4, F = 5, S = 6
    int day1;
    int day2;
    char* room;       // ER1011
};

/*  allocations
    code = calloc(9, sizeof(char));
    section = calloc(7, sizeof(char));
    time = calloc(10, sizeof(char)); 
    room = calloc(8, sizeof(char));
*/




