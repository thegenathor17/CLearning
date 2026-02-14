#ifndef GENERALDATA_H
#define GENERALDATA_H
    #include <stdio.h>
    #include "map.h"
    
    typedef struct {
        Map* tracker;
        char* mostUsed;
        size_t* words;
        size_t* newLines;
        size_t uniqueWords;
    } AnalyzeTextData;
    typedef struct  {
        Map* tracker;
        char* mostUsed;
        size_t count;
    } commonWordsData;

#endif