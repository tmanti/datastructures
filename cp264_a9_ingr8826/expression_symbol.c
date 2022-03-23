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
  QUEUE queue = {0};
  STACK stack = {0};
  char *p = infixstr;
  int sign = 1;
  int num = 0;
  char symbol[11] = {0}; // the above are data structures to implement the algorithm
  while(*p){
    if ( *p == '-' && (p == infixstr || *(p-1) == '(') ) {// get the sign of an operand
      sign = -1;
    } else if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z'){
      char *sp = symbol;
      *sp = *p;
      while ((*(p+1) >= 'a' && *(p+1) <= 'z') || (*(p+1) >= 'A' && *(p+1) <= 'Z') ||
        (*(p+1) >= '0' && *(p+1) <= '9') ) {
        p++;
        sp++;
        *sp = *p;
      }
      *(sp+1) = '\0';
      HSNODE *node = search(ht, symbol);
      num = node->value;
      enqueue(&queue, new_node(sign*num, 0));
      sign = 1;
    } else if(*p == '('){
      push(&stack, new_node(*p, 2));
    } else if(*p == ')'){
      NODE *n = pop(&stack);
      while(n->type != 2){
        if(n->type == 1){
          enqueue(&queue, n);
        }
        n = pop(&stack);
      }
    } else if(get_priority(*p) == 1){
      push(&stack, new_node(*p, 1));
    }
    p++;
  }

  while(stack.top){
    enqueue(&queue, pop(&stack));
  } 
  return queue;
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
  // your implementation
  QUEUE q = {0};
  q = infix_to_postfix_symbol(infixstr, ht);
  return evaluate_postfix(q);
}


int evaluate_postfix(QUEUE queue) {
// code from A6Q3
  NODE *p = queue.front;
  STACK stack = {0}; // auxilliary stack for postfix evaluation
  int type = 0;
  while (p) { // traversal the queue linked list
    type = p->type;
    if (type == 0) { // operant
      push(&stack, new_node(p->data, 0));
    }
    else if (type==1){ // operator
      int op2 = pop(&stack)->data;
      int op1 = pop(&stack)->data;
      int res;
      if(p->data == '+'){
        res = op1+op2;
      } else if(p->data == '-'){
        res = op1-op2;
      } else if(p->data == '*'){
        res = op1*op2;
      } else if(p->data == '%'){
        res = op1%op2;
      } else if(p->data == '/'){
        res = op1/op2;
      }
      push(&stack, new_node(res, 0));
    }
    p = p->next;
  }
  int result = stack.top->data;
  clean_stack(&stack);
  return result;
}