//
// Created by Amit on 21/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codec.h"
#include <dlfcn.h>



int main(int argc, char** argv)
{
    //Declaring the function pointer
    int (*encode)(char*,char*, int);
    //Declaring the error output
    char* error;

    char* adress = malloc(sizeof(char) *(3 + strlen(argv[1]) +3 +1) );
    strcat(adress , "lib");
    strcat(adress , argv[1]);
    strcat(adress , ".so");


    //Open the Dynamic Library with dlopen
    void *dl = dlopen(adress, RTLD_NOW);
    if (dl==NULL) {
        fprintf(stderr, "ERROR: %s\n", dlerror());
        exit(1);
    }


    //Pulling the function from the Dynamic Library to the Function pointer
    *(void **)(&encode) = dlsym(dl, "encode");
    if((error = dlerror())!=NULL)
    {
        fprintf(stderr, "ERROR: %s\n", error);
        exit(1);
    }

    //Using the function
    int ans = (*encode)("a","b",0);

    return 0;
}