/*
--------------------------------------------------
Project: CP264-a2q3
File:    matrix.h - methods headerfile
Author:  Thomas Ingram
Version: 2022-01-24
Compile: gcc matrix.h matrix.c matrix_main.c
--------------------------------------------------
*/
void display_vector(int *v, int n);
int vsum(int *v, int n);
void display_matrix(int *m, int n);
int msum(int *m, int n);
void transpose_matrix(int *m1, int *m2, int n);
void multiply_matrix(int *m1, int *m2, int *m3, int n);
void multiply_vector(int *m, int *v1, int *v2, int n);