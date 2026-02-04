#ifndef TXTFUNCTIONS_H
#define TXTFUNCTIONS_H
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>
    #include <stddef.h>
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

    //counts all words in the txt file
    size_t countWords(char **txt);
    //counts new lines
    size_t countNewLines(char **txt);
    //finds most common words in the file
    commonWordsData mostCommonWord(char **txt);
    //! UNUSED FUNCTION
    /*
    //checks if the word 
    bool compareWords(char **token, Map *wordMap, size_t **size);
    */
    //analyzes the text and returns both data
    AnalyzeTextData* AnalyzeText(char **txt, size_t *size);
#endif