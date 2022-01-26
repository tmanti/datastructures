/*
--------------------------------------------------
Project: cp264-a1q3
File:    factorial.c
Author:  Thomas Ingram
Version: 2022-01-16
--------------------------------------------------
*/
// program signature
#include <stdio.h>
#include <math.h>  // need this library for maths functions fabs() and sqrt()
 
#define EPSILON 0.000001   
// or #define EPSILON 1e-6

// program signature
#include <stdio.h>
#include <math.h>  // need this library for maths functions fabs() and sqrt()
 
#define EPSILON 0.000001   
// or #define EPSILON 1e-6

int main() {
  // setbuf(stdout, NULL); // uncomment this line for using Eclipse console
    
  float a, b, c, d, x1, x2;
  int inn;
  char temp;
  
  do { // do-while for new input problem
    
    do { // do-while loop to get correct input of three floating numbers
        
      printf("Please enter the coefficients a,b,c\n");
      inn = scanf("%f,%f,%f", &a,&b,&c);
      
      if (inn != 3 ) {
         printf("input:Invalid input\n");
      } else
        break;
       
      do {  // flush the input buffer
        scanf("%c", &temp);
        if (temp == '\n') break;
      } while (1);

    } while (1);

    if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
      printf("input:quit\n");
      break;
   
        } else if (fabs(a) < EPSILON ) {
      printf("input:not a quadratic equation\n");
    
        } else { 
    
      d = b * b - 4 * a * c;  // compute the discriminant
   
        // your solution logic
        if(d == 0){//two equal roots 
            printf("The equation has two equal real roots\n");
            //calc root
            float root = -b/(2*a);
            printf("x:%f\n", root);
        } else if (d > 0 ){//two distinct real roots
            printf("The equation has two distinct real roots\n");
            float root1 = (-b+sqrt(d))/(2*a);
            float root2 = (-b-sqrt(d))/(2*a);
            printf("x1:%f\n", root1);
            printf("x2:%f\n", root2);
        } else {//complex roots
            printf("The equation has two complex roots\n");
            float real = -b/(2*a);
            float imag = sqrt(-d)/(2*a);
            printf("real:%f\n", real);
            printf("imaginary:%f\n", imag);
        }

      }
  } while (1);
  return 0;
}