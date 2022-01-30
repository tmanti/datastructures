#include "mystring.h"
#define NULL 0

int str_length(char *s) {
    if (s == NULL) return -1;
    int counter = 0;
    char *p = s;
    while (*p) {
        if ('a' <= *p <= 'z' && 'A' <= *p <= 'Z'){ // pattern
            //printf("%d\n", *p);
            counter++; // action
        }
        p++; // move to next
    }
    return counter;
}

int word_count(char *s) {
    if (s == NULL ) return -1;
    int counter = 0;
    char *p = s;
    int first = 0;
    while (*p) {
        if (('a' <= *p && *p <= 'z' || 'A' <= *p && *p <= 'Z') && (first == 0 || *(p-1) == ' ')){ // pattern “ This is it”, “This is it”
            if(first == 0){
                first++;
            }
            counter++; // action
        }
        p++; // next
    }
    return counter;
}

void lower_case(char *s) {
    if (s == NULL) return;
    char *p = s;
    while (*p) {
        if (*p >= 'A' && *p <= 'Z' ) // pattern
            *p += 32; // action
        p++; // next
    }
}

void trim(char *s) {
    char *p=s, *dp=s;
    while (*p) {
        if (*p != ' ' || (p > s && *(p-1) != ' ' )) { // pattern
            *dp = *p;
            dp++;
        }
        p++; // next
    }
    if(*(dp-1) == ' '){
        *(dp-1) = '\0';
    } else {
        *dp = '\0';
    }
}