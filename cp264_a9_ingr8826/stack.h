/*--------------------------------------------------
Project: cp264-a6q2
File:    stack.h
Description: header of stack ds
Author:  HBF  
Version: 2022-02-10
--------------------------------------------------
*/

#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
  int height;
  NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void clean_stack(STACK *sp);

#endif
