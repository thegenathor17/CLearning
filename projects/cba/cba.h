#ifndef CBA_H
#define CBA_H
    #include <stdio.h>
    #include <windows.h>
    #include <string.h>

    typedef struct {
        char version[50];
        char name[100];
        char cmakeMinVersion[20];
        char ninjaMinVersion[20];
    } BuildInfo;

    void* Build();
#endif