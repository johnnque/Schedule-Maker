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


// FUNCTIONS

int menuSelection(){
    int userChoice = 0;
    do{
        

        printf("========SCHEDULE MAKER========\n");
        printf("Program Options: \n");
        printf("1| MAKE NEW schedule \n");
        printf("2| ENTER a new class \n");
        printf("3| REMOVE a class \n");
        printf("4| EDIT a class \n");
        printf("5| SHOW SCHEDULE\n");
        printf("6| HELP \n");
        printf("7| QUIT PROGRAM\n");
        
        printf("ENTER OPTION NUMBER: ");
        scanf("%d", &userChoice);

        if(userChoice <= 0 || userChoice >7){
            printf("Invalid input, please enter 1 to 7 only\n\n");
        }

    }while(userChoice <= 0 || userChoice >7);

    return userChoice;  // Return 1 to repeat, return 0 to end
}


void makeNewSchedule(){
    printf("ENTER NUMBER OF COURSES: ");
    scanf("%d", &scheduleSize);
    while(getchar() != '\n');

    // Switched to calloc()
    courseArray = calloc(scheduleSize, sizeof(struct Course)); // Allocate size based on user input
    

    // Get course input from user
    int i;
    for(i = 0; i<scheduleSize; i+=1){
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



void addClass(){

    // increment allocation 
    scheduleSize = scheduleSize + 1;
    struct Course* temp;
    temp = realloc(courseArray, scheduleSize * sizeof(struct Course));

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
    courseArray[scheduleSize - 1] = tempCourse;


    return;
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
    
