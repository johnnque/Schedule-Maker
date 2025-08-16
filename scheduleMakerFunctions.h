
// Expected + '\0' + '\n' + '2MoreChar' 
#define courseSize 11   //FDCNSYS
#define sectionSize 8   //ZZ14 
#define timeSize 17     //09:00 - 10:00
#define roomSize 10         //AG1011

// Declare Pointer 
struct Course *courseArray;


// STRUCTURES
struct Course{
    char subject[courseSize];
    char section[sectionSize];
    char time[timeSize];
    char day1;
    char day2;
    char room[roomSize];
};


void makeNewSchedule(){
    int scheduleSize;
    printf("ENTER NUMBER OF COURSES: \n");
    scanf("%d", &scheduleSize);
    while(getchar() != '\n');

    courseArray = malloc(scheduleSize * sizeof(struct Course)); // Allocate size based on user input

    int i;
    for(i = 0; i<scheduleSize; i+=1){
        
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
            
    }



}
    
