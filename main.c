#include "getInputFunctions.h"


int main(){
    addCourse();

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