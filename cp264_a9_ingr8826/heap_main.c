/*--------------------------------------------------
Project: CP264-a9q3
File:    heap_main.c
Description: public test driver
Author:  HBF
Version: 2022-02-22
--------------------------------------------------
*/   

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"

void display_heap(HEAP *hp) {
  printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
  printf("(index,key,data):");
  int i;
  for (i=0; i < hp->size; i++) {
    printf("(%d,%d,%d) ", i, hp->hna[i].key, hp->hna[i].data);
    if (i % 10 == 9) printf("\n");    
  }
  printf("\n");
}

int main(int argc, char *args[]) {
  int c = 4;  // initial capacity
  int n = 10; // max size for testing
  int v = 6;  // data vale to find for index
  int k = 2;  // new key value
  int i;
  
  // get and set the testing parameters from command line arguments
  if (argc > 1) {
    c = atoi(args[1]);
  }
  if (argc > 2) {
    n = atoi(args[2]);
  }
  if (argc > 3) {
    v = atoi(args[3]);
  }
  if (argc > 4) {
    k = atoi(args[4]);
  }
  
  // create heap 
  HEAP *hp = new_heap(c);
  if (hp->hna == NULL) return 0;
  printf("\nnew heap:");  
  display_heap(hp);
  
  HNODE hd;
  for (i = 1; i <= n; i++) {
     hd.key = n-i+4;
     hd.data = i;
     insert(hp, hd);
  }
  printf("\nheap after insertions:");
  display_heap(hp);
  
  v = 6;
  i = find_data_index(hp, v);
  hd = hp->hna[i];
  printf("(find_data_index(hp,%d),key,data):(%d,%d,%d)\n", v, i, hd.key, hd.data);
  
  int j = change_key(hp, i, k);
  printf("change_key(hp,%d,%d):%d\n", i, k, j);
  printf("change_key(hp,%d,%d):(%d,%d,%d)->(%d,%d,%d)", i, k, i, hd.key, hd.data, j, hp->hna[j].key, hp->hna[j].data);
  display_heap(hp);
  
  
  i = find_data_index(hp, v);
  hd = hp->hna[i];
  printf("(find_data_index(hp,%d),key,data):(%d,%d,%d)\n", v, i, hd.key, hd.data);
  
  k = 8;
  j = change_key(hp, i, k);
  printf("change_key(hp,%d,%d):%d\n", i, k, j);
  printf("change_key(hp,%d,%d):(%d,%d,%d)->(%d,%d,%d)", i, k, i, hd.key, hd.data, j, hp->hna[j].key, hp->hna[j].data);
  display_heap(hp);
 
  printf("call extract_min %d times:", 4 * n / 5);
  for (i = 0; i < 4 * n / 5; i++) {
    hd = extract_min(hp);
    printf("(%d %d) ", hd.key, hd.data);
  }

  printf("\nheap after extract_min operations:");
  display_heap(hp);

  return 0;
}