#ifndef CBA_H
#define CBA_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <direct.h>
    #include <windows.h>
    #include <string.h>
    #include <lookForRootFiles.h>

    typedef struct {
        char version[50];
        char name[100];
        char cmakeMinVersion[20];
        char ninjaMinVersion[20];
        char output[100];
    } BuildInfo;

    void* Build();
    void prepare(BuildInfo* buildInfo);
    void Parser(FILE* file, BuildInfo* buildInfo);
    char* trimWhitespace(char* str);
    
#endif