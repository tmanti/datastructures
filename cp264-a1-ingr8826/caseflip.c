/*
--------------------------------------------------
Project: cp264-a1q1
File:    caseflip.c
Author:  Thomas Ingram
Version: 2022-01-16
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL); // turns standard output buffering off

    char input;
    printf("Please enter a character\n");
    do
        input = getchar();
    while (isspace(input));

    while(input != '*'){
        bool valid = false;
        char output;
        if(input >= '0' && input <= '9'){
            int temp = input-'0';
            int out = temp*temp;
            valid = true;
            printf("%c:%d,%d", input, input, out);
        } else if(input >= 'a' && input <= 'z' || input >= 'A' && input <= 'Z'){
            if(input >= 'a' && input <= 'z'){
                output = input-32;
            } else if(input >= 'A' && input <= 'Z'){
                output = input+32;
            }
            valid = true;
            printf("%c:%d,%c", input, input, output);
        }

        if(!valid){
            printf("%c:invalid", input);
        }
        printf("\n");

        printf("Please enter a character\n");
        do
            input = getchar();
        while (isspace(input));
    }
    printf("%c:quit\n", input);
}