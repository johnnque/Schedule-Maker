
#include "variablesAndStructures.h"

void clearBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    return;
}

int conditionString(char* string){

    int i;
    for(i = 0; i < strlen(string); i += 1){

        if(string[i] == '\n'){
            string[i] = '\0';
            return 1; //Found '\n'
        }
    }
    return 0; //FAILED: NO '\n'
}


void getCode(){
    char temp[9];
    int validSize;
    do{
        clearBuffer();

        printf("COURSE CODE: ");
        fgets(temp, 9, stdin);
        validSize= conditionString(temp);
        if(validSize == 0){
            printf("\n[Error] Max Characters: 7\n");
        }
    }while(validSize == 0);

    //TODO pass by ref to instance of struct
    return;
}

