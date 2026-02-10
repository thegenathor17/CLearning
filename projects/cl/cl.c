#include "cl.h"
#include <string.h>
#include <stdlib.h>

void interpreter(int argc, char** argv){
    // Version info
    if(argc == 1){
        printf("CL version 1.1.1. Author: Nahum Naranjo \n");
        return;
    }
    if(argv[1] == NULL){
        return;
    }
    if (argv[1] != NULL && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("CL version 1.1.1. Author: Nahum Naranjo \n");
        return;
    }

    //Help info
    if (argv[1] != NULL && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        printf("CL - A bunch of tools made with pure C\n");
        printf("Usage: cl [options] [tool/hub]\n");
        printf("Options:\n");
        printf("  -v, --version       Show version information\n");
        printf("  -h, --help          Show this help message\n");
        printf("  exec, -e            Execute a tool, usage: \"cl exec [toolName]\" (also works with hub)\n");
        return;
    }

    // Exec
    if(argv[1] != NULL && (strcmp(argv[1], "exec") == 0 || strcmp(argv[1], "-e") == 0)){
        if(argv[2] != NULL){
            printf("Interpreting tool: %s\n", argv[2]);        
        } 
        else{
            printf("No tool provided to interpret.\n");
            return;
        }
        if(strcmp(argv[2], "hub") == 0){
            printf("Going to the hub...");
            system("hub.exe");
        }
        if(strcmp(argv[2], "cxt") == 0){
            printf("Executing CXT...");
            system("cxt.exe");
        }
        return;
    }
    // Unknown option
    // TODO: Add cl install to install libraries to projects
    // TODO: Add cba to build CBA projects
    printf("Unknown option: %s\n", argv[1]);
    printf("Use -h or --help for usage information.\n");
    return;
}