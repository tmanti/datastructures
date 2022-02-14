#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    insert_end(&bn, new_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        insert_end(&bn, new_node(*p -'0'));
      } else {
        clean(&bn);   
        break;
      }
      p++;
    }
    return bn;
  }
}

void display_bigint(BIGINT bignumber) {
  NODE *ptr = bignumber.start;
  while ( ptr != NULL) {
    printf("%d", ptr->data);
    ptr = ptr->next;
  }
}


BIGINT add(BIGINT op1, BIGINT op2) {
  BIGINT sum = bigint(NULL);
  
  // your implementation of addition algorithm
  NODE *p1 = op1.end;
  NODE *p2 = op2.end;
  int c=0, a, b, s;
  while (p1 || p2 ) { //addition algorithm
    a = 0; b = 0;
    if (p1) {a = p1->data; p1 = p1->prev;}
    if (p2) {b = p2->data; p2 = p2->prev;}
    // compute the sum digit s and insert it at start of the doubly linked list
    s = a+b+c;
    //printf("%d\n", s);
    if(s>=10){
      insert_start(&sum, new_node(s-10));
      c=1;
    } else {
      insert_start(&sum, new_node(s));
      c=0;
    }
  }
  if (c ==1) // insert 1 at start of the doubly linked list
    insert_start(&sum, new_node(c));

  return sum;
}

BIGINT Fibonacci(int n) {
  if (n <= 2 ) {
    return bigint("1");
  } else {
    BIGINT temp = bigint(NULL);  
    BIGINT f1 = bigint("1");
    BIGINT f2 = bigint("1");

    // your implementation of iterative algorithm for Fibonacci number
    for(int i = 3; i <= n; i++){
      temp = f1;
      f1 = f2;
      f2 = add(temp, f1);
    }

    return f2;
  }
}