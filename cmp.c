//
// Created by Amit on 20/11/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * How to run the file->
 * 1.Compile (Using makefile)
 * 2. /.cmp <file_1_destination> <file_2_destination>
 */

/**Compare function compare between two files.
 * Return True if identical
 * Return False if not.
 *
 * @param fp1 - Pointer to 1st file
 * @param fp2 - Pointer to 2nd file
 *
 * Source of information
 * https://www.geeksforgeeks.org/c-program-compare-two-files-report-mismatches/
 */

void compareFiles(FILE *fp1, FILE *fp2)
{
    // fetching character of two file
    // in two variable ch1 and ch2
    char ch1 = getc(fp1);
    char ch2 = getc(fp2);

    // error keeps track of number of errors
    // pos keeps track of position of errors
    // line keeps track of error line
    int error = 0, pos = 0, line = 1;

    // iterate loop till end of file
    while (ch1 != EOF || ch2 != EOF)
    {
        pos++;

        // if both variable encounters new
        // line then line variable is incremented
        // and pos variable is set to 0
        if (ch1 == '\n' && ch2 == '\n')
        {
            line++;
            pos = 0;
        }

        // if fetched data is not equal then
        // error is incremented
        if (ch1 != ch2)
        {
            error++;
        }

        // fetching character until end of file
        ch1 = getc(fp1);
        ch2 = getc(fp2);
    }

    if (error == 0 && ch1 == EOF && ch2 == EOF)
    {
        printf("Identical\n");
    }
    else
    {
        printf("Not Identical\n");
    }
}

int main(int argc, char **argv)
{
    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    if (!file1 || !file2)
    {
        printf("Usage : cmp <file1> <file2>\n");
        exit(0);
    }

    compareFiles(file1, file2);

    fclose(file1), fclose(file2);
    return 0;
}
