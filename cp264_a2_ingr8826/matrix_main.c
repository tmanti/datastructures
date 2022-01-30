/*
--------------------------------------------------
Project: CP264-a2q3
File:    matrix_main.c  public test driver
Author:  HBF
Version: 2022-01-10
Compile: gcc matrix.h matrix.c matrix_main.c
--------------------------------------------------
*/

#include<stdio.h>
#include "matrix.h"

#define n 3

int main() {
  int m1[n][n];
  int m2[n][n];
  int m3[n][n];

/* assign 3X3 matrix to following values
 8     1     6
 3     5     7
 4     9     2
 */
  int v[9] = { 8, 1, 6, 3, 5, 7, 4, 9, 2 };
  int i, *p = &v[0];
  int *p1 = &m1[0][0];
  for (i = 0; i < 9; i++) *p1++ = *p++;
  
  printf("\nm1:\n");
  display_matrix(&m1[0][0], n);
  printf("msum(m1):%d\n", msum(&m1[0][0], n));

  printf("\nm2=m1':\n");
  transpose_matrix(&m1[0][0], &m2[0][0], n);
  display_matrix(&m2[0][0], n);
  printf("msum(m2):%d\n", msum(&m2[0][0], n));
  
  multiply_matrix(&m1[0][0], &m2[0][0], &m3[0][0], n);  
  printf("\nm3=m1*m2':\n");
  display_matrix(&m3[0][0], n);
  printf("msum(m3):%d\n", msum(&m3[0][0], n));
  
  // vector
  int v1[] = {1, 1, 1};
  printf("\nv1:\n");
  display_vector(v1, n);
  printf("vsum(v1):%d\n", vsum(v1, n));
  
  int v2[n];
  multiply_vector(&m1[0][0], v1, v2, n);  
  printf("\nv2=m1*v1':\n");
  display_vector(v2, n);
  printf("vsum(v2):%d", vsum(v2, n));
  
  return 0;
}
