/*
--------------------------------------------------
Project: cp264-a2q1
File:    fibonacci_main.c public test driver
Author:  HBF
Version: 2022-01-10
Compile: gcc fibonacci.h fibonacci_main.c
--------------------------------------------------
*/
#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int *la;
int *ha;

int main(){
	int i=0, n = 40;
	clock_t t1, t2;	

	/*for(int i = 0; i <= 40; i++)
		printf("%d;%d\n", i, iterative_fibonacci(40));
	for(int i = 0; i <= 40; i++)
		printf("%d;%d\n", i, recursive_fibonacci(i));
	return*/

	printf("**Iterative algorithm measurement**\n");
	ha = &i;
	la = ha;
	printf("iterative_fibonacci(%d):%d\n", n, iterative_fibonacci(n));
	printf("high address:%lu\n", ha);
	printf("low address:%lu\n", la);
	int memory_span1 = (unsigned long) ha - (unsigned long) la;
	printf("iterative_fibonacci(%d) memory span:%d\n", n, memory_span1);

	//run time measuring for iterative_fibonacci
	int m1 = 500000;
	t1=clock();
	for (i=0; i< m1; i++) {
	  iterative_fibonacci(n);
	}
	t2=clock();
	double time_span1 = (double) t2-t1;
	printf("time_span(iterative_fibonacci(%d) for %d times):%0.1f (ms)\n", n, m1, time_span1);
		
	printf("\n**Recursive algorithm measurement**\n");
	la = ha;
	printf("recursive_fibonacci(%d):%d\n", n, recursive_fibonacci(n));
	printf("high address:%lu\n", ha);
	printf("low address:%lu\n", la);
	int memory_span2 = (unsigned long) ha - (unsigned long) la;
	printf("recursive_fibonacci(%d) memory span:%d\n", n, memory_span2);
	//run time measuring recursive_fibonacci
	int m2 = 10;
	t1=clock();
	for (i=0; i<m2; i++) {
      recursive_fibonacci(n);
	}
	t2=clock();
	double time_span2 = t2-t1;
	printf("time_span(recursive_fibonacci(%d) for %d times) in (ms):%0.1f\n", n, m2, time_span2);
	
	printf("\n**Comparison of recursive and iterative algorithms**\n");
	printf("memory_span(recursive_fibonacci(%d))/memory_span(iterative_fibonacci(%d)):%0.1f\n", n, n, ((double) memory_span2)/memory_span1);
	printf("time_span(recursive_fibonacci(%d))/time_span(iterative_fibonacci(%d)):%0.1f\n", n, n, (time_span2/time_span1)*(m1/m2));
	
	return 0;
}
