//
// Created by Amit on 20/11/2022.
//

#include <stdio.h>
#include <stdlib.h> // For exit()


/**
 * How to run the file->
 * 1.Compile (Using makefile)
 * 2. /.copy <copy_from_destination> <copy_to_destination>
 */

/**Copy function Copy between two files.

 * @param fp1 - Pointer to 1st file -> Copy from destination
 * @param fp2 - Pointer to 2nd file -> Copy to destination
 *
 * Source of information
 * https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
 */


int main(int argc, char **argv)
{
    //Open 2 input files
    FILE *fptr1 = fopen(argv[2], "r");
    FILE *fptr2 = fopen(argv[3], "w");;

    //Check for valid files
    if (!fptr1 || !fptr2)
    {
        printf("Cannot open files \n");
        exit(0);
    }
    // Read contents from file and copy it to the 2nd file
    char c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("file is copied");
    // Close files
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}