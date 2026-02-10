#include "screenManagment.h"

void clearConsole(){
    system("cls");
}

void Stop(){
    printf("Press enter to continue...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

