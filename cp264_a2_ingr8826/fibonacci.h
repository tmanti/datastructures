/*
--------------------------------------------------
Project: CP264-a2q3
File:    fibonacci.h methods file
Author:  Thomas Ingram
Version: 2022-01-24
Compile: gcc fibonacci.h fibonacci_main.c
--------------------------------------------------
*/

extern int *la;  // global pointer variable to get local variable address

int iterative_fibonacci(int n)
{
    if (&n < la) la = &n;   

    // your implementation
    int prev1 = 0;
    int prev2 = 1;
    int curr = 0;
    for(int i = 0; i <= n; i++){
        if(i<=1){
            curr = i;
        } else {
            curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        //printf("%d:%d\n",i, curr);
    }
    return curr;
}

int recursive_fibonacci(int n) {
  if (&n < la) la = &n;
  // your implementation
  if(n <= 0) return 0;
  if(n <= 2) return 1;
  else return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
}