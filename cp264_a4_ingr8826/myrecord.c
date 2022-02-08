/*
--------------------------------------------------
Project: CP264-a4q2
File:    myrecord.c, record util files
Author:  Thomas Ingram
Version: 2022-02-07
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100
#define MAX_REC 100

void swap(float *p1, float *p2){
    float temp = *p2;
    *p2 = *p1;
    *p1 = temp;
}

void quick_sort(float *a, int left, int right)
{ 
    // your implementation
    int i, j, k;
    float key;
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

char letter_grade(float s){
    // your implementation
    char g[] = {'S', 'A', 'B', 'C', 'D', 'F'};
    float b[] = {100, 90, 80, 70, 60, 50, 0};
    int left=0, right = sizeof(b)/sizeof(float)-1;
    // binary search for increasing order
    int found = 0;
    while(!found){
        int center = (right+left)/2;
        if(s < b[center]){
            left = center;
        } else {
            right = center;
        }

        if(left == right-1){
            found = 1;
        }
    }
    if (right == left) return g[left-1];
    else return g[left];
}

int import_data(RECORD dataset[], char *filename) {
    // your implementation
    FILE *fp = fopen(filename, "r");
    char delimiters[] = " ,\n\r";
    char line[100];
    int i = 0; // record counter
    char *token = NULL;
    while (fgets (line, sizeof(line), fp) != NULL ) {
        token = (char *) strtok(line, delimiters);
        strcpy(dataset[i].name, token); // copy string char array
        token = (char *) strtok(NULL, delimiters);
        dataset[i].score = atof(token); // convert string to float
        i++;
    }
    fclose(fp);
    return i;
}

STATS report_data(RECORD dataset[], int n, char *filename) {
    STATS stats = {0};
    if (n < 1) return stats;
    // your implementation
    int count = n;;
    stats.count = n;
    float vals[MAX_REC];

    float mean = 0;
    for(int i = 0; i<count; i++){ 
        vals[i] = dataset[i].score;
        mean+= dataset[i].score;
    }
    mean /= count;
    stats.mean = mean;

    float std = 0;
    for(int i = 0; i< count; i++) std += (dataset[i].score-mean)*(dataset[i].score-mean);
    std = sqrtf(std/count);
    stats.stddev = std;

    quick_sort(vals, 0, count-1);
    float median;
    if(n%2 == 1){
        median = vals[count/2];
    } else {
        median = (vals[count/2-1]+vals[count/2])/2;
    }
    stats.median = median;

    FILE *fp = fopen(filename, "w");
    for(int i = 0; i < count; i++){
        fprintf(fp, "%s,%c\n", dataset[i].name, letter_grade(dataset[i].score));
    }
    fclose(fp);

    return stats;
}

