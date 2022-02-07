// your signature

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