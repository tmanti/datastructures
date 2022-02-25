/*--------------------------------------------------
Project: cp264-a6
File:    common.c
Description: implementation of common.h
Author:  HBF  
Version: 2022-02-10
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

NODE *new_node(int data, int type) {
  NODE *np = (NODE *) malloc(sizeof(NODE));
  np->data = data;
  np->type = type;
  np->next = NULL;
  return np;
}

void display(NODE *start) {
  while (start) {
    if (start->type == 0) 
      printf("%d", start->data);
    else 
      printf("%c", start->data);      
    
    start = start->next;
    
    if (start) printf(" ");
  }
}

void clean(NODE **startp) {
  NODE *p = *startp;
  while (p) {
    NODE *tmp = p;
    p = p->next;
    free(tmp);
  }
  *startp = NULL;
}
