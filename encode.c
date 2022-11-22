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

    char* DL_Address = malloc(sizeof(char) *(8 + strlen(argv[1])) );
    strcat(DL_Address , "./lib");
    strcat(DL_Address , argv[1]);
    strcat(DL_Address , ".so");



    //Open the Dynamic Library with dlopen
    void *dl = dlopen(DL_Address, RTLD_NOW);
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

    //allocating memory for the answer
    char* dest = malloc(sizeof(char) *(strlen(argv[2])+1));
    //Using the function
    int ans = (*encode)(argv[2],dest,strlen(argv[2]));



    //Closing Dynamic Library
    if(dlclose(dl) != 0)
    {
        printf("Error closing DL");
    }
    //Free allocate memory
    free(DL_Address);
    free(dest);

    return 0;
}