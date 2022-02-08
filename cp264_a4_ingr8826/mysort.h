/*
--------------------------------------------------
Project: CP264-a4q1
File:    mysort.h, mysort.c headerfile
Author:  Thomas Ingram
Version: 2022-02-07
--------------------------------------------------
*/

#ifndef MYSORT_H
#define MYSORT_H 

// define enum type BOOLEAN 
typedef enum {
    false=0,
    true=1,
} BOOLEAN;

BOOLEAN is_sorted(int *a, int left, int right);
void select_sort(int *a, int left, int right);
void quick_sort(int *a, int left, int right);

#endif