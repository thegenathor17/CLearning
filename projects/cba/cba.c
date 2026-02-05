#include "cba.h"

void* Build(){
    char line[256];
    char option[10];
    FILE *fp;
    BuildInfo buildInfo;
    fp = fopen("\\cba.build", "r");
    if(fp == NULL){
        printf("Error: Could not open build file.\n");
        printf("Make sure that the .build file is in the working directory of the project.\n");
        printf("Current working directory: ");
        char cwd[1024];
        GetCurrentDirectoryA(1024, cwd);
        printf("%s\n", cwd);
        printf("Do you want to run that command? [Y] [N]\n");
        scanf("%s", option);
        if(strcmp(option, "Y") == 0 || strcmp(option, "y") == 0){
            printf("Preparing build environment...\n");
            lookForRootFiles("configs\\cba.build");
            prepare(&buildInfo);
            printf("Build environment prepared.\n");
            return NULL;
        } else {
            printf("Exiting...\n");
        }
        return NULL;
    }
    // read line by line
    Parser(fp, &buildInfo);
}


void Parser(FILE* file, BuildInfo* buildInfo) {
    char line[256];
    
    while (fgets(line, sizeof(line), file)) {
        // Remove newline
        line[strcspn(line, "\n")] = 0;
        
        // Skip empty lines/comments
        if (line[0] == '\0' || line[0] == '#') continue;
        
        // Find '=' with optional spaces
        char* key = line;
        char* value = strchr(line, '=');
        
        if (!value) continue;  // No '=' found
        
        *value = '\0';  // Split string at '='
        value++;        // Move past '='
        
        // Trim whitespace
        key = trim_whitespace(key);
        value = trim_whitespace(value);

        if(strcmp(key, "version") == 0){
            strcpy(buildInfo->version, value);
        } else if(strcmp(key, "name") == 0){
            strcpy(buildInfo->name, value);
        } else if(strcmp(key, "cmakeMinVersion") == 0){
            strcpy(buildInfo->cmakeMinVersion, value);
        } else if(strcmp(key, "ninjaMinVersion") == 0){
            strcpy(buildInfo->ninjaMinVersion, value);
        }
        key = strtok(NULL, "=");
    }
}


void* prepare(BuildInfo* buildInfo){

}