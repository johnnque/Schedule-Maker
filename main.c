
#include "scheduleMakerFunctions.h"

int main(){

    makeNewSchedule();
    checkCurrentSchedule();


    free(courseArray);
    courseArray = NULL;
    return 0;
}