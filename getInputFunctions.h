
#include "variablesAndStructures.h"

// Helper Functions
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

// Getters
void getCode(struct Course* course){
    char temp[9];
    int validSize;
    do{
        printf("COURSE CODE: ");
        fgets(temp, 9, stdin);
        clearBuffer();
        validSize= conditionString(temp);
        if(validSize == 0){
            printf("\n[Error] Max Characters: 7\n");
        }
    }while(validSize == 0);

    (*course).code = temp;
    printf("%s", (*course).code);
    return;
}


void getSection(struct Course* course){
    char temp[7];
    int validSize;
    do{
        printf("SECTION: ");
        fgets(temp, 7, stdin);               
        clearBuffer();

        validSize= conditionString(temp);
        if(validSize == 0){
            printf("\n[Error] Max Characters: 5\n");
        }
    }while(validSize == 0);

    (*course).section = temp;
    
    return;
}

void addCourse(){
    struct Course temp;
    struct Course* pTemp = &temp;
    getCode(pTemp);
    getSection(pTemp);

    printf("%s | %s", temp.code, temp.section); //FOR TESTING

    return;
}
