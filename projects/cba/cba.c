#include "cba.h"

void* Build(){
    char line[256];
    char option[10];
    FILE *fp;
    BuildInfo buildInfo;
    fp = fopen("cba.build", "r");
    if(fp == NULL){
        printf("Error: Could not open build file.\n");
        printf("Make sure that the .build file is in the working directory of the project.\n");
        printf("Current working directory: ");
        char cwd[1024];
        GetCurrentDirectoryA(1024, cwd);
        printf("%s\n", cwd);
        printf("Do you want to run \"prepare\" command? [Y] [N]\n");
        scanf("%s", option);
        if(strcmp(option, "Y") == 0 || strcmp(option, "y") == 0){
            printf("Preparing build environment...\n");
            fp = lookForRootFiles("configs\\cba.build", "r");
            Parser(fp, &buildInfo);
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
        key = trimWhitespace(key);
        value = trimWhitespace(value);

        if(strcmp(key, "version") == 0){
            strcpy(buildInfo->version, value);
        } else if(strcmp(key, "name") == 0){
            strcpy(buildInfo->name, value);
        } else if(strcmp(key, "cmakeMinVersion") == 0){
            strcpy(buildInfo->cmakeMinVersion, value);
        } else if(strcmp(key, "ninjaMinVersion") == 0){
            strcpy(buildInfo->ninjaMinVersion, value);
        }   else if(strcmp(key, "output") == 0){
            strcpy(buildInfo->output, value);
        }
    }
}

char* trimWhitespace(char* str) {
    char* end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    if(*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Write new null terminator
    *(end+1) = 0;

    return str;
}


void prepare(BuildInfo* buildInfo){
    if(system("cmake --version > /dev/null 2>&1") != 0){
        printf("Error: CMake is not installed or not in PATH.\n");
        return;
    }
    if(system("ninja --version > /dev/null 2>&1") != 0){
        printf("Error: Ninja is not installed or not in PATH.\n");
        return;
    }
    FILE *fp;
    fp = fopen("CMakeLists.txt", "w");
    if(fp == NULL){
        printf("Error: Could not create CMakeLists.txt file.\n");
        return;
    }
    // Main CMakeLists.txt content
    fprintf(fp, "cmake_minimum_required(VERSION %s)\n", buildInfo->cmakeMinVersion);
    fprintf(fp, "project(%s VERSION %s)\n", buildInfo->name, buildInfo->version);
    fprintf(fp, "set(CMAKE_CXX_STANDARD 11)\n");
    fprintf(fp, "set(CMAKE_CXX_STANDARD_REQUIRED True)\n");
    fprintf(fp, "set(CMAKE_MAKE_PROGRAM ninja)\n");
    fprintf(fp, "file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS \"*.c\")\n");
    fprintf(fp, "file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS \"*.h\")\n");
    fprintf(fp, "add_executable(%s ${SOURCES} ${HEADERS})\n", buildInfo->name);
    char* directory = malloc(1024 * sizeof(char));
    _getcwd(directory, sizeof(directory));
    char* directories = ListDirectories(directory);
    char dirArray[1024][256];  // Assuming max 1024 directories, each up to 255 chars
    size_t dirCount = 0;
    if(directories != NULL){
        char* dir = strtok(directories, "\n");
        while(dir != NULL){
            fprintf(fp, "add_subdirectory(%s)\n", dir);
            strcpy(dirArray[dirCount], dir);
            dirCount++;
            dir = strtok(NULL, "\n");
        }
        free(directories);
        free(directory);
    }
    fclose(fp);
    for (int i = 0; i < dirCount; i++) {
        char subDirPath[512];
        if(
            strcmp(dirArray[i], "build") == 0 || 
            strcmp(dirArray[i], ".git") == 0 || 
            strcmp(dirArray[i], ".vscode") == 0 || 
            strcmp(dirArray[i], ".github") == 0 || 
            strcmp(dirArray[i], ".idea") == 0 ||
            strcmp(dirArray[i], "configs") == 0 ||
            strcmp(dirArray[i], "docs") == 0 ||
            strcmp(dirArray[i], "tests") == 0 ||
            strcmp(dirArray[i], ".cbaignore") == 0 ||
            strcmp(dirArray[i], "public") == 0
        ) continue;
        //prepares CMakeLists.txt in each subdirectory
        // common folder is treated differently
        if(strcmp(dirArray[i], "common") == 0) {
            fprintf(fp, "file(GLOB COMMON_SOURCES \"common/*.c\")\n");
            fprintf(fp, "add_library(common STATIC ${COMMON_SOURCES})\n");
            fprintf(fp, "target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})\n");
            fprintf(fp, "set_target_properties(common PROPERTIES C_STANDARD 11)\n");
            fclose(fp);
            continue;
        }
        snprintf(subDirPath, sizeof(subDirPath), "%s\\%s", directory, dirArray[i]);
        fp = fopen(subDirPath, "w");
        if(fp == NULL){
            printf("Error: Could not create CMakeLists.txt in %s\n", dirArray[i]);
            continue;
        }
        fprintf(fp, "file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS \"*.c\")\n");
        fprintf(fp, "file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS \"*.h\")\n");
        char istr[10];
        sprintf(istr, "_%d", i);
        fprintf(fp, "target_sources(%s PRIVATE ${SOURCES} ${HEADERS})\n", strcat(buildInfo->name, istr));
        fprintf(fp, "set_target_libraries(%s PRIVATE common)\n", buildInfo->name);

        fclose(fp);
    }

    // Generate build files
    system("cmake -B build -G Ninja");

    FILE *configFile = lookForRootFiles("configs\\cba.config", "rb");
    if(configFile == NULL){
        printf("Error: Could not open cba.config file.\n");
        return;
    }
    FILE *outputFile = fopen("cba.build", "wb");
    if(outputFile == NULL){
        printf("Error: Could not create cba.build file.\n");
        return;
    }
    char configLine[256];
    while (fgets(configLine, sizeof(configLine), configFile)) {
        // Remove newline
        configLine[strcspn(configLine, "\n")] = 0;
        
        // Skip empty lines/comments
        if (configLine[0] == '\0' || configLine[0] == '#') continue;

        fprintf(outputFile, "%s\n", configLine);
    }
    fclose(configFile);
    fclose(outputFile);
}