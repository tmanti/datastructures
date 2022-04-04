/*--------------------------------------------------
Project: cp264-a7q1
File:    queue_stack.h
Description: header and implementation of queue and stack
Author:  HBF
Version: 2022-02-17
--------------------------------------------------
*/

#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

#include <stdio.h>
#include <stdlib.h>

// definition 
typedef struct node {
  void *data;  // data pointer
  struct node *next;
} NODE;

typedef struct queue {
  NODE *front, *rear;
} QUEUE;

void enqueue(QUEUE *qp, void *data);
void *dequeue(QUEUE *qp);
void clean_queue(QUEUE *qp);

typedef struct stack {
  NODE *top;
} STACK;

void push(STACK *sp, void *data);
void pop(STACK *sp);
void clean_stack(STACK *sp);


// implementation
void enqueue(QUEUE *qp, void *data) {
   NODE *p = (NODE*) malloc(sizeof(NODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}

void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    NODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}

void clean_queue(QUEUE *qp) {
  NODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
  qp->front = NULL;
  qp->rear = NULL;
}


void push(STACK *sp, void *data) {
  NODE *p = (NODE*) malloc(sizeof(NODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}

void pop(STACK *sp) {
  if (sp->top != NULL) {
    NODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}

void clean_stack(STACK *sp) {
  NODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}

#endif