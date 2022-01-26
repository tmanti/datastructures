/*
--------------------------------------------------
Project: cp264-a1q2
File:    factorial.c
Author:  Thomas Ingram
Version: 2022-01-16
--------------------------------------------------
*/

// program signature
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[])
{  
  int i, n = 0, f = 1, prev, is_overflow = 0;
  
  if ( argc > 1 ) {
    n = atoi( args[1] );  // convert command line argument to an integer
   
      if (n >= 1) {         // the conversion is successful
       
          // your solution logic code
            int fac = 1;
            int overflow = 0;
            int prev = 1;
            for(int i = 1; i <= n; i++){
                prev = fac;
                fac = fac*i;
                if(prev != fac/i){
                    printf("overflow:%d!\n", i);
                    overflow = 1;
                    break;
                }
                //printf("%d, %d, %d\n", fac, prev, fac/i);
                printf("%11d", fac);
                if(i % 4 == 0 && !(i==n)){
                    printf("\n");
                }
            }
            if(!overflow){
                printf("\n%d!:%d\n", n, fac);
            }
      } else {
        printf("%s:invalid argument\n",args[1]);
      }
  } else {
    printf("no argument");
  }
  return 0;
}