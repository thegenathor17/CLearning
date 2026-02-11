#ifndef STRINGMANIPULATION_H
#define STRINGMANIPULATION_H
    #include <string.h>
    #include <stdio.h>

    char* trimWhitespace(char* str);
    char* LineGetter(char* line, size_t size, FILE* file);
#endif