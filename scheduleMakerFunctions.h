#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Expected + '\0' + '\n' + '2 More Char' 
#define courseSize 11   //FDCNSYS
#define sectionSize 8   //ZZ14 
#define timeSize 17     //09:00 - 10:00
#define roomSize 10         //AG1011

// Declare Pointer 
struct Course * arrayM;
struct Course * arrayT;
struct Course * arrayW;
struct Course * arrayH;
struct Course * arrayF;
struct Course * arrayS;

int sizeM = 0;
int sizeT = 0;
int sizeW = 0;
int sizeH = 0;
int sizeF = 0;
int sizeS = 0;


// STRUCTURES
struct Course{
    char course[courseSize];
    char section[sectionSize];
    char time[timeSize];
    char day1;
    char day2;
    char room[roomSize];
};


// FUNCTIONS
void initializeProgram(){
    arrayM = NULL;
    arrayT = NULL;
    arrayW = NULL;
    arrayH = NULL;
    arrayF = NULL;
    arrayS = NULL;
}

int menuSelection(){
    int userChoice = 0;
    do{
        

        printf("========SCHEDULE MAKER========\n");
        printf("Program Options: \n");
        printf("1| ENTER a new class \n");
        printf("2| REMOVE a class \n");
        printf("3| EDIT a class \n");
        printf("4| SHOW SCHEDULE\n");
        printf("5| HELP \n");
        printf("6| QUIT PROGRAM\n");
        
        printf("ENTER OPTION NUMBER: ");
        scanf("%d", &userChoice);

        if(userChoice <= 0 || userChoice >7){
            printf("Invalid input, please enter 1 to 7 only\n\n");
        }

    }while(userChoice <= 0 || userChoice >7);

    return userChoice;  // Return 1 to repeat, return 0 to end
}


void addClass(){
    int invalidInputDetected = 0;
    do{
        struct Course* temp;

        // get class info
        struct Course tempCourse;
        
        while(getchar() != '\n');
        // Course Code
        printf("COURSE CODE: ");
        fgets(tempCourse.course, courseSize, stdin);

        // Section
        printf("SECTION: ");
        fgets(tempCourse.section, sectionSize, stdin);

        // Time
        printf("TIME [Enter 09:50 - 13:00]: ");
        fgets(tempCourse.time, timeSize, stdin);

        // Day 1 and Day 2
        int timesAWeek = 0;
        do{
            printf("ONCE OR TWICE A WEEK [Enter 1 or 2]: ");
            scanf("%d", &timesAWeek);
            while(getchar() != '\n');

            if(timesAWeek != 1 && timesAWeek != 2){
                printf("Please enter only 1 or 2 for once or twice a week\n");
            }

            

        }while(timesAWeek != 1 && timesAWeek != 2);
        

        printf("ENTER: M, T, W, H, F, S\n");
        printf("DAY 1: ");
        tempCourse.day1 = toupper(getchar());
        while(getchar() != '\n');

        if(timesAWeek == 2){
            printf("DAY 2: ");
            tempCourse.day2 = toupper(getchar());
            while(getchar() != '\n');
        }
        else{
            tempCourse.day2 = '\0';
        }

        // Room
        printf("ROOM: ");
        fgets(tempCourse.room, roomSize, stdin);
        
        
        // ADD THE COURSE INTO MEMORY
        switch(tempCourse.day1){
            case 'M':
                if(arrayM == NULL){
                    sizeM = sizeM + 1;
                    arrayM = calloc(sizeM, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeM = sizeM + 1;
                    temp = realloc(arrayM, sizeof(struct Course)*sizeM);
                    arrayM = temp; 
                }
                arrayM[sizeM - 1] = tempCourse;
                invalidInputDetected = 0;
                break;

            case 'T':
                if(arrayT == NULL){
                    sizeT = sizeT + 1;
                    arrayT = calloc(sizeT, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeT = sizeT + 1;
                    temp = realloc(arrayT, sizeof(struct Course)*sizeT);
                    arrayT = temp; 
                }
                arrayT[sizeT - 1] = tempCourse;
                invalidInputDetected = 0;
                break;

            case 'W':
                if(arrayW == NULL){
                    sizeW = sizeW + 1;
                    arrayW = calloc(sizeW, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeW = sizeW + 1;
                    temp = realloc(arrayW, sizeof(struct Course)*sizeW);
                    arrayW = temp; 
                }
                arrayW[sizeW - 1] = tempCourse;
                invalidInputDetected = 0;
                break;

            case 'H':
                if(arrayH == NULL){
                    sizeH = sizeH + 1;
                    arrayH = calloc(sizeH, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeH = sizeH + 1;
                    temp = realloc(arrayH, sizeof(struct Course)*sizeH);
                    arrayH = temp; 
                }
                arrayH[sizeH - 1] = tempCourse;
                invalidInputDetected = 0;
                break;

            case 'F':
                if(arrayF == NULL){
                    sizeF = sizeF + 1;
                    arrayF = calloc(sizeF, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeF = sizeF + 1;
                    temp = realloc(arrayF, sizeof(struct Course)*sizeF);
                    arrayF = temp; 
                }
                arrayF[sizeF - 1] = tempCourse;
                invalidInputDetected = 0;
                break;
                
            case 'S':
                if(arrayS == NULL){
                    sizeS = sizeS + 1;
                    arrayS = calloc(sizeS, sizeof(struct Course)); 
                }
                else{
                    struct Course * temp;
                    sizeS = sizeS + 1;
                    temp = realloc(arrayS, sizeof(struct Course)*sizeS);
                    arrayS = temp; 
                }
                arrayS[sizeS - 1] = tempCourse;
                invalidInputDetected = 0;
                break;
            default:
                invalidInputDetected = 1;
                printf("ERROR: Invalid input detected\nPlease fill up the course info again\n\n");
                printf("Press [ENTER] to continue: ");
                break;
        }

        // MEMORY ALLOCAITON FOR DAY 2 
        if(tempCourse.day2 != '\0' ){
            switch(tempCourse.day2){
                case 'M':
                    if(arrayM == NULL){
                        sizeM = sizeM + 1;
                        arrayM = calloc(sizeM, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeM = sizeM + 1;
                        temp = realloc(arrayM, sizeof(struct Course)*sizeM);
                        arrayM = temp; 
                    }
                    arrayM[sizeM - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;

                case 'T':
                    if(arrayT == NULL){
                        sizeT = sizeT + 1;
                        arrayT = calloc(sizeT, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeT = sizeT + 1;
                        temp = realloc(arrayT, sizeof(struct Course)*sizeT);
                        arrayT = temp; 
                    }
                    arrayT[sizeT - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;

                case 'W':
                    if(arrayW == NULL){
                        sizeW = sizeW + 1;
                        arrayW = calloc(sizeW, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeW = sizeW + 1;
                        temp = realloc(arrayW, sizeof(struct Course)*sizeW);
                        arrayW = temp; 
                    }
                    arrayW[sizeW - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;

                case 'H':
                    if(arrayH == NULL){
                        sizeH = sizeH + 1;
                        arrayH = calloc(sizeH, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeH = sizeH + 1;
                        temp = realloc(arrayH, sizeof(struct Course)*sizeH);
                        arrayH = temp; 
                    }
                    arrayH[sizeH - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;

                case 'F':
                    if(arrayF == NULL){
                        sizeF = sizeF + 1;
                        arrayF = calloc(sizeF, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeF = sizeF + 1;
                        temp = realloc(arrayF, sizeof(struct Course)*sizeF);
                        arrayF = temp; 
                    }
                    arrayF[sizeF - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;
                    
                case 'S':
                    if(arrayS == NULL){
                        sizeS = sizeS + 1;
                        arrayS = calloc(sizeS, sizeof(struct Course)); 
                    }
                    else{
                        struct Course * temp;
                        sizeS = sizeS + 1;
                        temp = realloc(arrayS, sizeof(struct Course)*sizeS);
                        arrayS = temp; 
                    }
                    arrayS[sizeS - 1] = tempCourse;
                    invalidInputDetected = 0;
                    break;
                default:
                    invalidInputDetected = 1;
                    printf("ERROR: Invalid input detected\nPlease fill up the course info again\n\n");
                    printf("Press [ENTER] to continue: ");
                    break;
            }
        }

    }while(invalidInputDetected == 1);
    return;
}

void checkCurrentSchedule(){ // Currently To Check contents of dynamic array but eventually should print tabulated schedule
    int i;
    /*
    for(i = 0; i<scheduleSize; i+=1){
        printf("COURSE: %s\n", courseArray[i].course);
        printf("SECTION: %s\n", courseArray[i].section);
        printf("TIME: %s\n", courseArray[i].time);
        printf("DAY1: %c\n", courseArray[i].day1);
        printf("DAY2: %c\n", courseArray[i].day2);
        printf("ROOM: %s\n", courseArray[i].room);
    }
    */
    return;
}
    
