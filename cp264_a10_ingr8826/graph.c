

// your code signature

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h" 
#include "graph.h"

GRAPH *new_graph(int order) {
  GRAPH *p = malloc(sizeof(GRAPH)); // create a graph object in heap region
  // set the order and size here
  p->order = order;
  p->size = 0;

  p->nodes = malloc(order * sizeof(GNODE*)); // create array of GNODE pointers
  int i;
  for (i = 0; i < order; i++) {
    p->nodes[i] = malloc(sizeof(GNODE)); // create a GNOGE object
    p->nodes[i]->nid = i; // set node id to be i
    p->nodes[i]->neighbor = NULL; // Initialize neighbor linked list
  }
  return p;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
  // your implementation
  ADJNODE *p = g->nodes[from]->neighbor;
  int found = 0;
  if(p){
    while(p->next){
      if(p->nid == to){
        found = 1;
        break;
      }
      p = p->next;
    }
    if(p->nid == to){
        found = 1;
    }
    if(found){
      p->weight = weight;
    } else {
      ADJNODE *n = malloc(sizeof(ADJNODE));
      n->next = NULL;
      n->nid = to;
      n->weight = weight;
      p->next = n;
    }
  } else {
    ADJNODE *n = malloc(sizeof(ADJNODE));
    n->next = NULL;
    n->nid = to;
    n->weight = weight;
    g->nodes[from]->neighbor = n;
  }
  g->size++;
}

void display_bforder(GRAPH *g, int start) {
  // your implementation
  if (g == NULL) return;
  int n = g->order, visited[n], i;
  for (i=0; i<n;i++) visited[i] = 0;
  // bread-first traversal algorithm, similar to the A7Q1 iterative_bf_search()
  QUEUE queue = {0};
  GNODE *gnp = NULL;
  ADJNODE *anp = NULL;
  enqueue(&queue, g->nodes[start]);
  visited[start] = 1;
  while (queue.front) {
    gnp = (GNODE*) dequeue(&queue);
    printf("%d ", gnp->nid);
    // traverse the neighbor linked list, if a neighbor node is not visited, enqueue and set it visited.
    ADJNODE *p = gnp->neighbor;
    while(p){
      if(!visited[p->nid]){
        enqueue(&queue, g->nodes[p->nid]);
        visited[p->nid] = 1;
      }
      p=p->next;
    }
  }
  clean_queue(&queue);
}

void display_dforder(GRAPH *g, int start) {
  // your implementation
  // your implementation
  if (g == NULL) return;
  int n = g->order, visited[n], i;
  for (i=0; i<n;i++) visited[i] = 0;
  // bread-first traversal algorithm, similar to the A7Q1 iterative_bf_search()
  STACK stack = {0};
  GNODE *gnp = NULL;
  ADJNODE *anp = NULL;
  push(&stack, g->nodes[start]);
  visited[start] = 1;
  while (stack.top) {
    gnp = (GNODE*) stack.top->data;
    pop(&stack);
    printf("%d ", gnp->nid);
    // traverse the neighbor linked list, if a neighbor node is not visited, enqueue and set it visited.
    ADJNODE *p = gnp->neighbor;
    while(p){
      if(!visited[p->nid]){
        push(&stack, g->nodes[p->nid]);
        visited[p->nid] = 1;
      }
      p=p->next;
    }
  }
  clean_stack(&stack);
}


int get_weight(GRAPH *g, int from, int to) {
  ADJNODE *p = g->nodes[from]->neighbor;
  int result = INFINITY;
  while (p) {
    if (p->nid == to) {
        result = p->weight;
        break;
    }
    p = p->next;
  }
  return result;
}

void clean_graph(GRAPH **gp) {
  int i;
  GRAPH *g = *gp;
  ADJNODE *temp, *ptr;
  for (i = 0; i < g->order; i++) {
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      temp = ptr;
      ptr = ptr->next;
      free(temp);
    }
    free(g->nodes[i]);
  }
  free(g->nodes);
  free(g);
  *gp = NULL;
}

void display_graph(GRAPH *g) {
  if (g == NULL) return;
  printf("order:%d\n", g->order);
  printf("size:%d\n", g->size);
  printf("from:(to weight)");
  int i;
  ADJNODE *ptr;
  for (i = 0; i < g->order; i++) {
    printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;
    while (ptr != NULL) {
      printf("(%d %d) ", ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
}

