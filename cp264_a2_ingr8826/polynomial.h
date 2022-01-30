/*
--------------------------------------------------
Project: CP264-a2q3
File:    polynomial.h methods file
Author:  Thomas Ingram
Version: 2022-01-24
Compile: gcc polynomial.h polynomial_main.c -lm
--------------------------------------------------
*/
 
#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6

void display_polynomial(float p[], int n, float x)
{
    // your implementation
    for(int i = 0; i < n; i++){
        if(i!=n-1)
            printf("%.2f*%.2f^%d+", p[i], x, n-(i+1));
        else printf("%.2f*%.2f^%d", p[i], x, n-(i+1));
    }
}

float horner(float p[], int n, float x)
{
    // your implementation
    float out = 0;
    for(int i = 0; i < n; i++){
        out += p[i]*powf(x, n-(i+1));
    }
    return out;
}

float bisection(float p[], int n, float a, float b)
{
// your implementation
    float c = (a+b)/2;
    while(fabs(horner(p, n, c)) >= EPSILON){
        if(horner(p, n, c)*horner(p, n, a) > 0){
            a = c;
        } else {
            b = c;
        }
        c = (a+b)/2;
        //printf("%f:%f:%f:%f:%f:%d\n", a,b,c,horner(p, n, c), horner(p, n, a), horner(p, n, c) >= EPSILON);
    }

    return c;
}