#include "stringManipulation.h"

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

char* LineGetter(char* line, size_t size, FILE* file) {
    if (fgets(line, size, file) != NULL) {
        line[strcspn(line, "\n")] = 0;
    }
    return NULL; // EOF or error
}