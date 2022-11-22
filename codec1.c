//
// Created by Amit on 21/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "codec.h"

/**
 * Encode function convert every Uppercase char to lower case char
 * @param src Source string
 * @param dst Destination string
 * @param len Length of both strings
 * @return 1 at success
 */
int encode(char * src, char * dst, int len)
{
    int count =0;
    //For Each Char in Source String
    while ( count < len)
    {
        //Case 1: src[count] is UpperCase Char -> Convert to LowerCase
        if (src[count]>=65 && src[count]<=90)
        {
            dst[count] = src[count] + 32;
        }

        //Case 2: Don't change the characters
        else
        {
            dst[count] = src[count];
        }
        count ++;
    }
    printf("DL:Codec 1 \n"
           "Function: endoce\n"
           "Source: %s\n"
           "Destination %s",src,dst);
    return 0;
}

/**
 * Decode function convert every Lowercase char to Uppercase char
 * @param src Source string
 * @param dst Destination string
 * @param len Length of both strings
 * @return 1 at success
 */
int decode(char * src, char * dst, int len)
{
    int count =0;
    //For Each Char in Source String
    while ( count < len)
    {
        // Case 1: If the current char is lowwer case -> convert to upper
        if(src[count]>=97 && src[count]<=122)
        {
            dst[count] = src[count] - 32;
        }
        //Case 2: Don't change the characters
        else
        {
            dst[count] = src[count];
        }
        count++;

    }
    printf("DL:Codec 1 \n"
           "Function: decode\n"
           "Source: %s\n"
           "Destination %s",src,dst);
    return 1;
}