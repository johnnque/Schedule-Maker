
#include "scheduleMakerFunctions.h"

int main(){

    initializeProgram();
    
    int userChoice = 0; 

    do{

        userChoice = menuSelection();

        switch(userChoice){
            case 1:
                addClass();
                break;

            case 2:
                printf("remove class function here\n");
                break;
            
            case 3:
                printf("edit class here\n");
            break;

            case 4:
                displaySchedule(); 
                //printClassTestFunction();
                break;

            case 5:
                printf("print user guide here\n");
                break;

            case 6://while loop condition will handle quitting
                break;    

            default: 
                printf("Invalid Selection\n");
                break; 
        }
    } while(userChoice != 6);


    // FOR TESTING QUITTING
    /*
    int testVar = 0;
    printf("program has terminated\n");
    scanf("%d", &testVar);
    */

    free(arrayM);
    free(arrayT);
    free(arrayW);
    free(arrayH);
    free(arrayF);
    free(arrayS);
    arrayM = NULL;
    arrayT = NULL;
    arrayW = NULL;
    arrayH = NULL;
    arrayF = NULL;
    arrayS = NULL;
    return 0;
}