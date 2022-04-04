 /*
--------------------------------------------------
Project: CP264-a10q1
File:    edgelist_main.c 
Description: public test driver
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
*/

#include <stdio.h>
#include "edgelist.h"

int main(){
  EDGELIST *elg = new_edgelist();  
  add_edge_end(elg, 0, 2, 3);
  add_edge_end(elg, 2, 1, 4);
  add_edge_end(elg, 1, 3, 9);
  add_edge_end(elg, 1, 4, 11);  
  printf("display_edgelist():\n", weight_edgelist(elg));  
  display_edgelist(elg);
  printf("\nweight:%d\n", weight_edgelist(elg));
  clean_edgelist(&elg);
  return 0;
}
