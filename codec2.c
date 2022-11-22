//
// Created by Amit on 21/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "codec.h"


/**
 * Encode function calculate every char NEG value
 * By doing Not(char) + 1
 * @param src Source string
 * @param dst Destination string
 * @param len Length of both strings
 * @return 1 at success
 */
int encode(char * src, char * dst, int len)
{
    int count = 0;
    char temp;
    //For each Char in Source
    while (count < len)
    {
        //Insert into temp Not(current char)
        temp = ~(src[count]);
        //Add 1 to convert to Neg value
        temp = temp +1 ;
        dst[count]=temp;
        count ++ ;
    }
    // printf("DL:Codec 2 \n"
    //        "Function: endoce\n"
    //        "Input : %s\n"
    //        "Outpur : %s",src,dst);
    printf("encoded %s\n", dst);
    return 0;
}

/**
 * Convert Neg value into Original Char
 * By Not(char - 1)
 * @param src Source string
 * @param dst Destination string
 * @param len Length of both strings
 * @return 1 at success
 */
int decode(char * src, char * dst, int len)
{

    int count =0;
    char temp;
    //For each Char in Source
    while (count<len)
    {
        //Insert into temp Not(current char - 1) to get to original value
        temp = ~((src[count] - 1));
        dst[count] = temp;
        //Increment Counter
        count++;
    }


    // printf("DL:Codec 2 \n"
    //        "Function: endoce\n"
    //        "Input : %s\n"
    //        "Outpur : %s",src,dst);
    printf("decoded %s\n", dst);
    return 0;
}