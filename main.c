
#include "scheduleMakerFunctions.h"

int main(){

    makeNewSchedule();

    free(courseArray);
    courseArray = NULL;
    return 0;
}