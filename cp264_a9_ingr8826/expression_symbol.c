#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}


QUEUE infix_to_postfix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
}


int evaluate_postfix(QUEUE queue) {
// code from A6Q3
}