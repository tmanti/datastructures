 /*
--------------------------------------------------
Project: CP264-a10q1
File:    mystring_main.c, a test driver
Author:  Thomas Ingram
Version: 2022-04-04 (update)
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
    // your implementation
    EDGELIST *p = malloc(sizeof(EDGELIST));
    // initial setting
    p->size = 0;
    p->start = NULL;
    p->end = NULL;
    return p;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    // your implementation
    EDGE *e = malloc(sizeof(EDGE));
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->next = NULL;
    if(g->end){
        g->end->next = e;
    } else {
        g->start = e;
    }
    g->size++;
    g->end = e;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    // your implementation
    EDGE *e = malloc(sizeof(EDGE));
    e->from = from;
    e->to = to;
    e->weight = weight;
    e->next = g->start;
    if(!g->start){
        g->end = e;
    }
    g->size++;
    g->start = e;
}

int weight_edgelist(EDGELIST *g) {
    // your implementation
    int w = 0;
    EDGE *p = g->start;
    while(p){
        w+=p->weight;
        p = p->next;
    }
    return w;
}

void clean_edgelist(EDGELIST **gp) {
  EDGELIST *g = *gp;
  EDGE *temp, *p = g->start;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  free(g);
  *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}

