/*
--------------------------------------------------
Project: CP264-a9q3
File:    heap.c
Description: implementation of heap.h
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"

HEAP *new_heap(int capacity)
{
  HEAP *hp = (HEAP*) malloc(sizeof(HEAP));
  if (hp == NULL) return NULL;
  hp->hna = (HNODE *) malloc(sizeof(HNODE) * capacity);
  if ( hp->hna == NULL) { free(hp); return NULL; };

  hp->capacity = capacity;
  hp->size = 0;
  return hp;
}

void insert(HEAP *heap, HNODE new_node)
{
  unsigned int index, parent;
  HNODE *temp;

  // Resize the array if it is overflow
  if (heap->size == heap->capacity)
  {
    heap->capacity <<= 1;
    
    temp = realloc(heap->hna, sizeof(HNODE) * heap->capacity);
      if (temp) {
      heap->hna = temp;
    } else {
      temp = malloc(sizeof(HNODE) * heap->capacity);
      if (temp) {
        memcpy(temp, heap->hna, sizeof(HNODE) * heap->size);
        free(heap->hna);
        heap->hna = temp;
      } else {
        printf("memory expansion failed\n");
        exit(1);
      }
    }
  }
  
  for(index = heap->size; index; index = parent)
  {
    parent = (index - 1) >> 1;
    if (cmp(heap->hna[parent].key, new_node.key)<=0)
      break;
    heap->hna[index] = heap->hna[parent];
  }
  heap->hna[index] = new_node;
  heap->size++;
}


HNODE extract_min(HEAP *heap)
{
  unsigned int index, swap, other;
  HNODE top = heap->hna[0];
  HNODE temp = heap->hna[--heap->size];

  // Resize the array size to a 1/4
  if ((heap->size <= (heap->capacity >> 2)) && (heap->capacity > MIN_CAPACITY)) {
    heap->capacity >>= 1;
    heap->hna = realloc(heap->hna, sizeof(HNODE) * heap->capacity);
    if (!heap->hna) exit(1); // Exit if the memory allocation fails
  }

  //heapify_down
  for(index = 0; 1; index = swap) {
    swap = (index << 1) + 1;
    if (swap >= heap->size) break;
    other = swap + 1;
    if ((other < heap->size) && cmp(heap->hna[other].key, heap->hna[swap].key)<=0)
      swap = other;
    if (cmp(temp.key, heap->hna[swap].key)<=0)
      break;
    heap->hna[index] = heap->hna[swap];
  }

  heap->hna[index] = temp;
  return top;
}


int change_key(HEAP *heap, int index, KEYTYPE new_key)
{
  unsigned int i, swap, other;
  HNODE temp; 
  // new_key < current key, heapify up
  if ( heap->hna[index].key > new_key) { 
    heap->hna[index].key = new_key;
    for(i = index; i; i = swap)
    {
      swap = (i - 1) >> 1;
      if (heap->hna[swap].key <= new_key) break;
      temp = heap->hna[swap];
	  heap->hna[swap] = heap->hna[i];
	  heap->hna[i] = temp;
    }
  }
  // new_key > current key, heapify down
  else if ( heap->hna[index].key < new_key) { 
    temp = heap->hna[index];
	temp.key = new_key;
    for(i = 0; 1; i = swap) {
      swap = (i << 1) + 1;   // index of left child
      if (swap >= heap->size) break;
      if ((swap + 1 < heap->size) && cmp(heap->hna[swap + 1].key, heap->hna[swap].key)<=0) swap++;
      if (cmp(temp.key, heap->hna[swap].key)<=0) break;
        heap->hna[i] = heap->hna[swap];
     }
     heap->hna[i] = temp;
  }
  
  return i;
   
}

int find_data_index(HEAP *heap, DATA data) {
  int i;
  for (i=0; i<heap->size; i++) {
    if (heap->hna[i].data == data)
      return i;
  }
  return -1;
}

int cmp(KEYTYPE a, KEYTYPE b) {
  if (a < b) 
    return -1;
  else if (a==b) 
    return 0;
  else 
    return 1;
}
