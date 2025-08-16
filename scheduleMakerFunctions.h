#include <stdio.h>
#include <stdlib.h>

// Expected + '\0' + '\n' + '2 More Char' 
#define courseSize 11   //FDCNSYS
#define sectionSize 8   //ZZ14 
#define timeSize 17     //09:00 - 10:00
#define roomSize 10         //AG1011

// Declare Pointer 
struct Course *courseArray;

int scheduleSize = 0;

// STRUCTURES
struct Course{
    char course[courseSize];
    char section[sectionSize];
    char time[timeSize];
    char day1;
    char day2;
    char room[roomSize];
};


void makeNewSchedule(){
    printf("ENTER NUMBER OF COURSES: ");
    scanf("%d", &scheduleSize);
    while(getchar() != '\n');

    courseArray = calloc(scheduleSize, sizeof(struct Course)); // Allocate size based on user input
    // Switched to calloc()

    // Get course input from user
    int i;
    for(i = 0; i<scheduleSize; i+=1){
        struct Course tempCourse;

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

            printf("%d", timesAWeek);

        }while(timesAWeek != 1 && timesAWeek != 2);
        

        printf("ENTER: M, T, W, H, F, S\n");
        printf("DAY 1: ");
        tempCourse.day1 = getchar();
        while(getchar() != '\n');

        if(timesAWeek == 2){
            printf("DAY 2: ");
            tempCourse.day2 = getchar();
            while(getchar() != '\n');
        }
        else{
            tempCourse.day2 = '\0';
        }

        // Room
        printf("ROOM: ");
        fgets(tempCourse.room, roomSize, stdin);
        
        // Send tempCourse object into dynamic array
        courseArray[i] = tempCourse;
    }

}

int menuSelection(){
    int userChoice = 0;

    printf("PROGRAM OPTIONS: \n");
    printf("0| GUIDE FOR OPTIONS");
    printf("1| MAKE NEW SCHEDULE \n");
    printf("2| ENTER A NEW CLASS: \n");
    printf("3| REMOVE A CLASS \n");
    printf("4| EDIT A CLASS \n");
    
    printf("ENTER NUMBER OF OPTION: ");
    scanf("%d", &userChoice);

    int userConfirm = 'n';
    switch(userChoice){
        case 1:
            do{
                printf("WARNING!!!  Pre-existing schedule will be deleted. Do you still wish to process[y/n]: ");
                userChoice = getchar();
            }while(userConfirm != 'y');
            break;
        default: 
            printf("Invalid Selection\n");
            break;
            
    }

    return 0; //Place Holder

}

void checkCurrentSchedule(){ // Currently To Check contents of dynamic array but eventually should print tabulated schedule
    int i;
    for(i = 0; i<scheduleSize; i+=1){
        printf("COURSE: %s\n", courseArray[i].course);
        printf("SECTION: %s\n", courseArray[i].section);
        printf("TIME: %s\n", courseArray[i].time);
        printf("DAY1: %c\n", courseArray[i].day1);
        printf("DAY2: %c\n", courseArray[i].day2);
        printf("ROOM: %s\n", courseArray[i].room);
    }
    return;
}
    
