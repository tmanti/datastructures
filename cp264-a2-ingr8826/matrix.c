/*
--------------------------------------------------
Project: CP264-a2q3
File:    matrix.c - methods sourcefile
Author:  Thomas Ingram
Version: 2022-01-24
Compile: gcc matrix.h matrix.c matrix_main.c
--------------------------------------------------
*/
#include<stdio.h>
#include "matrix.h"

void display_vector(int *v, int n) {
    int *p = v, i, j;
    for (i = 0; i < n; i++) {
       printf("%-4d", *p++); 
    }
    printf("\n");
}

void display_matrix(int *m, int n) {
    int *p = m, i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) printf("%4d", *p++);
        printf("\n");
    }
}

int vsum(int *v, int n) {
    // your implementation
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += *(v + i);
    }
    return sum;
}

int msum(int *m, int n) {
    // your implementation
    int sum = 0;
    for(int i = 0; i < n*n; i++){
        sum += *(m + i);
    }
    return sum;
}


void transpose_matrix(int *m1, int *m2, int n) {
    // your implementation
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            *(m2 + j*n + i) = *(m1 + i*n + j);
        }
    }
}


void multiply_matrix(int *m1, int *m2, int *m3, int n) {
    // your implementation
    int i, j, k, sum;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += *(m1 + i*n + k) * *(m2 + k*n + j);
                //printf("%d:%d\n", *(m1 + i*n + k), *(m2 + k*n + j));
            }
            *(m3 + i * n + j) = sum;
        }
    }
}


void multiply_vector(int *m, int *vin, int *vout, int n) {
    // your implementation
    int i, k, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (k = 0; k < n; k++) {
            sum += *(m + i*n + k) * *(vin + k);
            //printf("%d:%d\n", *(m1 + i*n + k), *(m2 + k*n + j));
        }
        *(vout + i) = sum;
    }
}