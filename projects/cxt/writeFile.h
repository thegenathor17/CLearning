#ifndef WRITEFILE_H
#define WRITEFILE_H
    #include <stdio.h>
    #include <stdbool.h>
    #include "txtFunctions.h"
    #include <io.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <tchar.h>
    #include <time.h>
    #include <sys/stat.h>
    #include <direct.h>

    //writes analysis data to a file
    bool writeFile(const char* path, AnalyzeTextData* data);
    //generates file path based on current time
    char* getFilePath();
    //checks if directory exists
    bool DirectoryExists(const char* path);
#endif