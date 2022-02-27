#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    // your implementation
    np->next = sp->top;
    sp->top = np;
    sp->height++;
}

NODE *pop(STACK *sp) {
    // your implementation
    NODE *p = sp->top;
    if(!p){
        printf("UNDERFLOW");
    } else {
        sp->top = p->next;
        p->next = NULL;
        sp->height--;
    }
    return p;
}

void clean_stack(STACK *sp) {
    // your implementation,  
    // call clean() function in common.h 
    sp->height = 0;
    if(sp->top){
        clean(&sp->top);
    }
    sp->top = NULL;
}