#include "hub.h"
#include <string.h>
#include <stdlib.h>

void interpreter(void){
    while(1){
        clearConsole();
        char* option = BuildUI();
        if(option == NULL){
            printf("Error building UI\n");
            return;
        }
        if(strcmp(option, "1") == 0){
            printf("Going to CXT...");
            system("cxt.exe");
        }
        else if(strcmp(option, "2") == 0){
            printf("Going to CBA...");
            system("cba.exe");
        }
        else if(strcmp(option, "3") == 0){
            printf("Exiting...");
            return;
        }
        else{
            printf("Invalid option, please try again.");
            Stop();
        }
    }
}