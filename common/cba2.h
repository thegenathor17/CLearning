#ifndef CBA2_H
#define CBA2_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <direct.h>
    #include <windows.h>
    #include <string.h>
    #include <lookForRootFiles.h>
    #include <stringManipulation.h>
    #include "generalData.h"

    void* Build();
    void prepare(BuildInfo* buildInfo);
    void BuildParser(FILE* file, BuildInfo* buildInfo);
    char* trimWhitespace(char* str);
    void clean();
    void generateFiles();
#endif