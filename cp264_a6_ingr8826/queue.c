#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    // your implementation
    np->next = NULL;
    if(qp->front){
        qp->rear->next = np;
        qp->rear = np;
    } else {
        qp->front = np;
        qp->rear = np;
    }
    qp->length++;
}  

NODE *dequeue(QUEUE *qp) {
    // your implementation
    NODE *p = qp->front;
    if(p){
        qp->front = p->next;
        p->next = NULL;
        if(!qp->front){
            qp->rear = NULL;
        }
        qp->length--;
    } else {
        printf("UNDERFLOW");
    }
    return p;
}

void clean_queue(QUEUE *qp) {
// your implementation
// call clean() function in common.h
    qp->length = 0;
    if(qp->front){
        clean(&qp->front);
    }
    qp->front = NULL;
    qp->rear = NULL;
}