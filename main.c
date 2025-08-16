
#include "scheduleMakerFunctions.h"

int main(){

    int userChoice = 0; 

    do{

        userChoice = menuSelection();

        switch(userChoice){
            case 1:
                
                //TODO can't get the confirmation to work, but makeNewSchedule() function alone works fine
                /*
                printf("WARNING!!!  Pre-existing schedule will be deleted. Do you still wish to process[y/n]: ");
                char confirmInitSched = getchar();
                printf("why not working 0");
                while(getchar() != '\n');

                if(confirmInitSched == 'y'){
                    printf("why not working 1");
                    makeNewSchedule();
                    
                    printf("why not working 2");
                }*/

                makeNewSchedule();
                break;


            case 2:
                printf("Make new class function here\n");
                break;
            
            case 3:
                printf("remove class function here\n");
                break;

            case 4:
                printf("edit class here\n");
                break;

            case 5:
                printf("show schedule function here\n");
                break;

            case 6:
                printf("print user guide here\n");
                break;
            
            case 7:
                break; //while loop condition will handle quitting

            default: 
                printf("Invalid Selection\n");
                userChoice = 0; //To ensure going back to menu
                break; 
        }
    } while(userChoice != 7);


    // FOR TESTING QUITTING
    /*
    int testVar = 0;
    printf("program has terminated\n");
    scanf("%d", &testVar);
    */

    free(courseArray);
    courseArray = NULL;
    return 0;
}