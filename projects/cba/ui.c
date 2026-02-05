#include "ui.h"

void* BuildUI(){
    char input[256];
    printf("CBA Main menu:\n");
    printf("CBA ");
    scanf("%s", input);
    if(strcmp(input, "exit") == 0 || strcmp(input, "Exit") == 0){
        printf("Exiting CBA...\n");
        return 0;
    }
    return input;
}