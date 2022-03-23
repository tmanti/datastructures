/*--------------------------------------------------
Project: CP264-a6q2
File:     stack.c
Description: implementation of stack.h
Author:  HBF  
Version: 2022-02-10
--------------------------------------------------
*/

#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
  if (sp == NULL || np == NULL) return; 	
  if (sp->top == NULL) {
    sp->top = np;
    sp->top->next = NULL;
  }
  else {
    np->next = sp->top;
    sp->top = np;
  }
  sp->height++;
}

NODE *pop(STACK *sp) {
  if (sp == NULL || sp->top == NULL) return NULL;
  NODE *tmp = sp->top;
  sp->top = tmp->next;
  sp->height--;
  tmp->next = NULL;
  return tmp;
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->height=0;
}


