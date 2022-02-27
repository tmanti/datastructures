#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function 
*/
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}

/*
 * auxiliary function 
*/
int type(char c) {
  if (c >= '0' &&  c <= '9' )
     return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if ( c == ')')
    return 3;  
  else 
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
  // your implementation
  char *p = infixstr;
  QUEUE queue = {0};
  STACK stack = {0};
  int sign = 1, num = 0;
  while(*p){
    if ( *p == '-' && (p == infixstr || *(p-1) == '(') ) {// get the sign of an operand
      sign = -1;
    } else if (*p >= '0' && *p <= '9'){
      num = *p-'0'; while ((*(p+1) >= '0' && *(p+1) <= '9')) { num = num*10 + *(p+1)-'0'; p++; }
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
    } else if(type(*p) == 1){
      push(&stack, new_node(*p, 1));
    }
    p++;
  }

  while(stack.top){
    enqueue(&queue, pop(&stack));
  } 
  return queue;
}

int evaluate_postfix(QUEUE queue) {
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


int evaluate_infix(char *infixstr) {
  // your implementation
  QUEUE postfix = infix_to_postfix(infixstr);
  int result = evaluate_postfix(postfix);
  return result;
}