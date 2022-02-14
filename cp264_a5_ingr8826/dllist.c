#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *new_node(char data) {
  // your implementation
  NODE* n = (NODE *)malloc(sizeof(NODE));
  n->data = data;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void insert_start(DLLIST *dllistp, NODE *np) {
  // your implementation
  if (dllistp->start == NULL) { // when the dllist is empty
    np->prev = NULL;
    np->next = NULL;
    dllistp->start = np;
    dllistp->end = np;
  } else { // the following linking operations to set np at start
    np->prev = NULL; // this set prev of np to NULL, as start node
    np->next = dllistp->start; // set next of np to the current start
    dllistp->start->prev = np; // set the prev of current start to np
    dllistp->start = np; // set the start of the dllist to np
  }
  dllistp->length++;
}

void insert_end(DLLIST *dllistp, NODE *np) {
  // your implementation
  if (dllistp->end == NULL) { // when the dllist is empty
    np->prev = NULL;
    np->next = NULL;
    dllistp->start = np;
    dllistp->end = np;
  } else { // the following linking operations to set np at start
    np->next = NULL; // this set prev of np to NULL, as start node
    np->prev = dllistp->end; // set next of np to the current start
    dllistp->end->next = np; // set the prev of current start to np
    dllistp->end = np; // set the start of the dllist to np
  }
  dllistp->length++;
}

void delete_start(DLLIST *dllistp) {
  // your implementation
  NODE *ptr = dllistp->start;
  if(ptr == NULL){
    printf("Underflow on delete_start");
  } else {
    dllistp->start = dllistp->start->next;
    dllistp->start->prev = NULL;
    free(ptr);
    if(dllistp->start == NULL){
      dllistp->end == NULL;
    }
    dllistp->length--;
  }
}

void delete_end(DLLIST *dllistp) {
  // your implementation
  NODE *ptr = dllistp->end;
  if(ptr == NULL){
    printf("Underflow on delete_end");
  } else {
    dllistp->end = dllistp->end->prev;
    dllistp->end->next = NULL;
    free(ptr);
    if(dllistp->end == NULL){
      dllistp->start == NULL;
    }
    dllistp->length--;
  }
}

void display_forward(DLLIST *dllistp) {
  NODE *np = dllistp->start;
  while ( np != NULL) {
    printf("%c", np->data);
    np = np->next;
  }
}

void display_backward(DLLIST *dllistp) {
  NODE *np = dllistp->end;
  while ( np != NULL) {
    printf("%c", np->data);
    np = np->prev;
  }
}

void clean(DLLIST *dllistp) {
  NODE *temp, *np = dllistp->start;
  while (np != NULL) {
    temp = np;
    np = np->next;
    free(temp);
  }
  dllistp->start = NULL;
  dllistp->end = NULL;
  dllistp->length = 0;
}