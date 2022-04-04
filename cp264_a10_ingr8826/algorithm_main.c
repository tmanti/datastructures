/*
--------------------------------------------------
Project: CP264-a10q3
File:    algorithm_main.c 
Description: public test driver
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
*/

#include <stdio.h>
#include "edgelist.h"
#include "graph.h"
#include "algorithm.h"
#include "heap.h"

int main(){
  //create a weighted graph
  GRAPH *g = new_graph(5);
  add_edge(g, 0, 1, 7);
  add_edge(g, 1, 0, 7);
  add_edge(g, 0, 2, 3);
  add_edge(g, 2, 0, 3);
  add_edge(g, 1, 2, 4);
  add_edge(g, 2, 1, 4);
  add_edge(g, 2, 3, 10);
  add_edge(g, 3, 2, 10);
  add_edge(g, 1, 3, 9);
  add_edge(g, 3, 1, 9);
  add_edge(g, 1, 4, 11);
  add_edge(g, 4, 1, 11);
  
  printf("display_graph(g):\n");
  display_graph(g);
  

  //compute MST by Prim's algorithm using min-heap 
  printf("\n\nmst_prim(g, 0):\n");
  EDGELIST *t = mst_prim(g, 0);
  display_edgelist(t);
  printf("\nmst weight:%d\n", weight_edgelist(t));
  clean_edgelist(&t);


  //compute SPT by Dijkstra's algorithm using min-heap
  printf("\nspt_dijkstra():");
  t = spt_dijkstra(g, 0);
  display_edgelist(t);
  printf("\nspt weight:%d\n", weight_edgelist(t));
  clean_edgelist(&t);

  //compute SP by Dijkstra's algorithm using min-heap
  int start = 0, end = 4;
  t = sp_dijkstra(g, start, end);
  printf("\nsp_dijkstra(g %d %d):\n",  start, end);
  display_edgelist(t);
  printf("\nsp length:%d", weight_edgelist(t));  
  clean_edgelist(&t);
  clean_graph(&g);
  printf("\n");  
  return 0;
}
