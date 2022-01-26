/*
-------------------------------------
File:    cubes_02.c
Project: Lab02_cp264_t2
file description
-------------------------------------
Author:  Thomas Ingram
ID:      200188260
Email:   ingr8826@mylaurier.ca
Version  2021-01-20
Modified: 2022-01-17
-------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 12

int main(int argc, char *argv[]) {
//==============================
    setbuf(stdout, NULL);           // turns standard output buffering off

    int i;                          // Loop counter/index.

    int      values [ARR_SIZE];     // Integer Array of size 10.
    long int cubes[ARR_SIZE];     // integer Array of size 10.

    int      *pV;                   // Integer Pointer.
    long int *pS;                   // Long Integer Pointer.

    pV = values;                    // or: pV = &values[0];    Set pV to point to first element of array "values".
    pS = cubes;                   // or: pS = &squares[0];   Set pS to point to first element of array "squares".

    // === NOTE: From this point on, to the end of the program, you are NOT allowed
    // ===       to use or write the "values" or "squares" array names.
    // ===       You must reference these arrays ONLY by using the respective pointers "pV" and "pS".

                                    // Populate the "values" array with consecutive integers
                                    // [1,2,3, ..., 10]
    //<*** your code here ***>								{
    for(i = 0; i < ARR_SIZE; i++){
    	*(pV+i) = i+1;
    }
                                    // Populate each element of the "squares" array with the
                                    // square value of its corresponding integer value stored in
                                    // the "values" array.
    //<*** your code here ***>
    for(i = 0; i < ARR_SIZE; i++){
    	*(pS+i) = (*(pV+i))*(*(pV+i))*(*(pV+i));
    }

                                    // Print the table of values
    printf("\n");
    printf("Array traversal by \"POINTER INDEXING\"\n");
    printf("=====================================\n");
    printf("\n");
    printf("Value       Cube  \n");
    printf("=====     ==========\n");

    //<*** your code here ***>
    for(i = 0; i < ARR_SIZE; i++){
		printf("%3d     %8ld\n", *(pV+i), *(pS+i));
    }

    printf(":::\n");
    printf("::: Program Terminated.\n");
    printf(":::\n");

    return 0;
}

