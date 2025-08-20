#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

void sortTime(){
    int i, j;

    for(i = 0; i < sizeM; i+=1){
        for(j = i + 1; j < sizeM; j+=1){
            if(strcmp(arrayM[i].time, arrayM[j].time) > 0){
                struct Course temp = arrayM[i];
                arrayM[i] = arrayM[j];
                arrayM[j] = temp;
            }
        }
    }

     for(i = 0; i < sizeT; i+=1){
        for(j = i + 1; j < sizeT; j+=1){
            if(strcmp(arrayT[i].time, arrayT[j].time) > 0){
                struct Course temp = arrayT[i];
                arrayT[i] = arrayT[j];
                arrayT[j] = temp;
            }
        }
    }

     for(i = 0; i < sizeW; i+=1){
        for(j = i + 1; j < sizeW; j+=1){
            if(strcmp(arrayW[i].time, arrayW[j].time) > 0){
                struct Course temp = arrayW[i];
                arrayW[i] = arrayW[j];
                arrayW[j] = temp;
            }
        }
    }

     for(i = 0; i < sizeH; i+=1){
        for(j = i + 1; j < sizeH; j+=1){
            if(strcmp(arrayH[i].time, arrayH[j].time) > 0){
                struct Course temp = arrayH[i];
                arrayH[i] = arrayH[j];
                arrayH[j] = temp;
            }
        }
    }

     for(i = 0; i < sizeF; i+=1){
        for(j = i + 1; j < sizeF; j+=1){
            if(strcmp(arrayF[i].time, arrayF[j].time) > 0){
                struct Course temp = arrayF[i];
                arrayF[i] = arrayF[j];
                arrayF[j] = temp;
            }
        }
    }

     for(i = 0; i < sizeS; i+=1){
        for(j = i + 1; j < sizeS; j+=1){
            if(strcmp(arrayS[i].time, arrayS[j].time) > 0){
                struct Course temp = arrayS[i];
                arrayS[i] = arrayS[j];
                arrayS[j] = temp;
            }
        }
    }
}


void displaySchedule(){ // Currently To Check contents of dynamic array but eventually should print tabulated schedule
    /*
    int i;
    for(i = 0; i<scheduleSize; i+=1){
        printf("COURSE: %s\n", courseArray[i].course);
        printf("SECTION: %s\n", courseArray[i].section);
        printf("TIME: %s\n", courseArray[i].time);
        printf("DAY1: %c\n", courseArray[i].day1);
        printf("DAY2: %c\n", courseArray[i].day2);
        printf("ROOM: %s\n", courseArray[i].room);
    }
    */
    
    sortTime();
    printf("|%-17s|%-17s|%-17s|%-17s|%-17s|%-17s|\n", "MON", "TUE", "WED", "THU", "FRI", "SAT");


    int i = 0;
    while(i<sizeM || i < sizeT || i < sizeW || i < sizeH || i < sizeF || i < sizeS){

        // SUBJECT PRINTING
        if(arrayM != NULL){
            if(strcmp(arrayM[i].course, "\0") == 0){
                printf("|%-17s|", arrayM[i].course);
            }
        }
        else{
            printf("|%-17s|", " ");
        }

        if(arrayT != NULL){
            if(strcmp(arrayT[i].course, "\0") == 0){
                printf("%-17s|", arrayT[i].course);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayW != NULL){
            if(strcmp(arrayW[i].course, "\0") == 0){
                printf("%-17s|", arrayW[i].course);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayH != NULL){
            if(strcmp(arrayH[i].course, "\0") == 0){
                printf("%-17s|", arrayH[i].course);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayF != NULL){
            if(strcmp(arrayF[i].course, "\0") == 0){
                printf("%-17s|", arrayF[i].course);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayS != NULL){
            if(strcmp(arrayS[i].course, "\0") == 0){
                printf("%-17s|\n", arrayS[i].course);
            }
        }
        else{
            printf("%-17s|\n", " ");
        }


        // SECTION PRINTING
                if(arrayM != NULL){
            if(strcmp(arrayM[i].section, "\0") == 0){
                printf("|%-17s|", arrayM[i].section);
            }
        }
        else{
            printf("|%-17s|", " ");
        }

        if(arrayT != NULL){
            if(strcmp(arrayT[i].section, "\0") == 0){
                printf("%-17s|", arrayT[i].section);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayW != NULL){
            if(strcmp(arrayW[i].section, "\0") == 0){
                printf("%-17s|", arrayW[i].section);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayH != NULL){
            if(strcmp(arrayH[i].section, "\0") == 0){
                printf("%-17s|", arrayH[i].section);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayF != NULL){
            if(strcmp(arrayF[i].section, "\0") == 0){
                printf("%-17s|", arrayF[i].section);
            }
        }
        else{
            printf("%-17s|", " ");
        }

        if(arrayS != NULL){
            if(strcmp(arrayS[i].section, "\0") == 0){
                printf("%-17s|\n", arrayS[i].section);
            }
        }
        else{
            printf("%-17s|\n", " ");
        }

        // Increment
        i = i + 1;

    }

    return;
}
    
