/*
--------------------------------------------------
Project: CP264-a4q1
File:    mysort.c, sort util files
Author:  Thomas Ingram
Version: 2022-02-07
--------------------------------------------------
*/

#include "mysort.h"

BOOLEAN is_sorted(int *a, int left, int right)
{
    // your implementation
    BOOLEAN result = true;
    int i = left;
    while(result && i<right){
        if(*(a+i) > *(a+i+1)){
            result = false;
        }
        i++;
    }
    return result;
}

void swap(int *p1, int *p2){
    int temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}

void select_sort(int *a, int left, int right)
{
    // your implementation
    int i, j, k;
    int n = right - left + 1;
    for (i = 0; i < n; ++i) {
        k = i;
        for(j = i+1; j < n ; ++j) {
            if (*(a+j) < *(a+k)) {
                k = j;
            }
        }
        if (i != k) {
            //swap the values at a+k and a+i
            swap(a+k, a+i);
        }
    }
}

void quick_sort(int *a, int left, int right)
{ 
    // your implementation
    int key,i,j,k;
    if( left < right ) {
        k = (left+right)/2;
        key = *(a+k); // use *(a+k) as the pivot
        // split a[left...right] that element at j is equal to key
        // elements from left to j-1 are less or equal to key
        // elements from j+1 to right are bigger than key

        i = left-1;
        j = right+1;
        int loop = 1;
        while(loop){
            do{
                i++;
            } while(*(a+i) < key);

            do{
                j--;
            } while(*(a+j) > key);

            if(i>= j){
                loop = 0;
            } else {
                //printf("%d %d", *(a+i), *(a+j));
                swap(a+i, a+j);
            }
        }

        quick_sort(a, left, j);
        quick_sort(a, j+1, right);
    }
}