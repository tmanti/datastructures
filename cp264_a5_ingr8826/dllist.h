#ifndef DLLIST_H
#define DLLIST_H

typedef struct node {
  char data;
  struct node *prev;  
  struct node *next;
} NODE;

typedef struct dllist {
  int length;
  NODE *start;
  NODE *end;
} DLLIST;

/*
 * This creates a new node using malloc() with passed data value and returns pointer of the node.
*/
NODE *new_node(char value);

/*
 * This inserts a node at the beginning the of a doubly linked list. 
*/
void insert_start(DLLIST *dllistp, NODE *np);

/*
 * This inserts a node at the end of a doubly linked list.
*/
void insert_end(DLLIST *dllistp, NODE *np);

/*
 * This deletes the first node of a doubly linked list.
*/
void delete_start(DLLIST *dllistp);

/*
 * This deletes the end node of a doubly linked list.
*/
void delete_end(DLLIST *dllistp);

/*
 * This displays data of a doubly linked list from start to end. 
*/
void display_forward(DLLIST *dllistp);


/*
 * This displays data of a doubly linked list from end to start. 
*/
void display_backward(DLLIST *dllistp);

/*
 * This cleans and frees the nodes of a doubly linked list.
*/
void clean(DLLIST *dllistp);

#endif