#ifndef MAP_H
#define MAP_H
    #include <stdbool.h>
    #include <stddef.h>

    typedef struct {
        char* key;
        int timesAppeared;
    } Map;

    // Index of key in map, or -1 if not found. Pass used count as n.
    int FindKey(char* key, Map* map, size_t n);
    // True if key exists in the first n entries.
    bool ExistKey(char* key, Map* map, size_t n);

#endif