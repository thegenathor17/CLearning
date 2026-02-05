#include "lookForRootFiles.h"

FILE* lookForRootFiles(char* filename){
    FILE *fp;
    filename = strcat("C:\\InCGames\\CL\\", filename);
    fp = fopen(filename, "r");
    if(fp == NULL){
        return NULL;
    } else {
        fclose(fp);
        return fp;
    }
}