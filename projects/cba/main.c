#include "cba.h"
#include "ui.h"
#include <screenManagment.h>


int main(){
    clearConsole();
    printf("Welcome to CBA!\n");
    void* ptrToOption = 1;
    while(ptrToOption != 0){
        // Main loop
        ptrToOption = BuildUI();
        clearConsole();
        if(strstr(ptrToOption, "build") != NULL){
            printf("Building CBA...\n");
            Build();
            Stop();
        }
    }
    return 0;
}