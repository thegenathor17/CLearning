#include "ui.h"
#include "readFile.h"
#include "txtFunctions.h"
#include "writeFile.h"
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <screenManagment.h>

int main(){
    int c;
    clearConsole();
    while(1){
        char *ptrToOption = BuildUI();
        size_t size;
        if (!ptrToOption) continue;
        if(strcmp(ptrToOption, "exit") == 0 || strcmp(ptrToOption, "Exit") == 0) { clearConsole(); printf("Bye\n"); return 0;}
        if(strcmp(ptrToOption, "h") == 0 || strcmp(ptrToOption, "H") == 0 || strcmp(ptrToOption, "help") == 0 || strcmp(ptrToOption, "Help") == 0) {Help(); continue;}
        if(strcmp(ptrToOption, "version") == 0 || strcmp(ptrToOption, "Version") == 0 || strcmp(ptrToOption, "v") == 0 || strcmp(ptrToOption, "V") == 0 || strcmp(ptrToOption, "cl cxt -v") == 0) {printf("CXT - Text Analyzer v1.0.0\n"); Stop(); system("cls"); continue;}
        void* fileOut = separateFiles(ptrToOption, &size);
        if(fileOut == NULL){
            printf("Error reading file. Please, check the path and try again.\n");
            Stop();
            clearConsole();
            continue;
        }
        if(strstr(ptrToOption, "analysis_report_") != NULL){
            analysisMode(NULL, &size, (AnalyzeTextData*)fileOut);
            // Free AnalyzeTextData
            AnalyzeTextData* d = (AnalyzeTextData*)fileOut;
            for(size_t i = 0; i < d->uniqueWords; i++) free(d->tracker[i].key);
            free(d->tracker);
            free(d->mostUsed);
            free(d->words);
            free(d->newLines);
            free(d);
        } else{
            analysisMode((char*)fileOut, &size, NULL);
            free(fileOut);
        }
        Stop();
        clearConsole();
    }   
}