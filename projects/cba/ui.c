#include "ui.h"

void* BuildUI(){
    char input[256];
    printf("CBA Main menu:\n");
    scanf("%s", input);
    // Exit command
    if(strcmp(input, "exit") == 0 || strcmp(input, "Exit") == 0){
        printf("Exiting CBA...\n");
        return 0;
    }
    // build
    if(strcmp(input, "build") == 0 || strcmp(input, "Build") == 0){
        printf("Building project...\n");
        Build();
        return 0;
    }
    // prepare
    if( strcmp(input, "generate") == 0 || 
        strcmp(input, "Generate") == 0 ||
        strcmp(input, "-g") == 0 ||
        strcmp(input, "-G") == 0
    ){
        generateFiles();
        printf("Build files generated. Run \"build\" command to build the project.\n");
        return 0;
    }
    //clean
    if(strcmp(input, "clean") == 0 || strcmp(input, "Clean") == 0){
        clean();
        printf("Build directory cleaned.\n");
        return 0;
    }
    // config
    if((strcmp(input, "config") == 0 || strcmp(input, "Config") == 0) && (strstr(input, "-n") != NULL || strstr(input, "-N") != NULL)){
        printf("Opening config file...\n");
        system("notepad configs\\cba.config");
        return 0;
    }
    else if(strcmp(input, "config") == 0 || strcmp(input, "Config") == 0){
        config('c');
        return 0;
    }

    // build change
    if(strcmp(input, "change") == 0 || strcmp(input, "Change") == 0 && strstr(input, "-n") != NULL && strstr(input, "-N") != NULL){
        printf("Changing build configuration...\n");
        system("notepad cba.build");
        return 0;
    } else {
        config('b');
        return 0;
    }
    printf("Unknown command. Type \"help\" for a list of available commands.\n");
    return input;
}

void config(char type){
    if(type != 'c' && type != 'b') return;
    FILE* fp;
    if(type == 'c'){
        // Null checkers and declarations
        BuildInfo buildInfo;
        fp = lookForRootFiles("configs\\cba.config", "r");
        if(fp == NULL) printf("Error: Could not open cba.config file.\n"); return;
        char* path[512] = malloc(512 * sizeof(char));
        if(path == NULL) {
            printf("Error: Could not allocate memory for path.\n");
            return;
        }
        // Construct path to config file
        strcpy(path, "type ");
        strcat(path, rootFilePath());
        strcat(path, "configs\\cba.config");

        // first loop
        while(true){
        }
    } else {
        fp = lookForRootFiles("cba.build", "r");
        if(fp == NULL){
            printf("Error: Could not open cba.build file.\n");
            return;
        }
    }

}

void Help(){
    printf("Available commands:\n");
    printf("build - Builds the project using the generated build files.\n");
    printf("generate - Generates build files based on the cba.config file.\n");
    printf("clean - Cleans the build directory.\n");
    printf("config - Opens the cba.config file for editing.\n");
    printf("exit - Exits the CBA tool.\n");
}

void writeConfigFile(char* path){
    system(path);
}