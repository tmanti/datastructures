// your code signature

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"

extern int htsize;

extern int htsize;

int hash(char* word) {
  unsigned int hash = 0, i;
  for (i = 0; word[i] != '\0'; i++) {
    hash = 31 * hash + word[i];
  }
  return hash % htsize;
}

HSNODE *new_hashnode(char *key, int value) {
    HSNODE *hn = (HSNODE*) malloc(sizeof(HSNODE));
    strcpy(hn->key, key);
    hn->value = value;
    hn->next = NULL;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *ht = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    ht->hna = (HSNODE**) malloc(sizeof(HSNODE**)*size);
    int i;
    for (i=0; i<size; i++) *(ht->hna+i) = NULL; // initialize to NULL
    ht->size = size;
    ht->count = 0;  
    return ht;
}

HSNODE *search(HASHTABLE *ht, char *key) { 
    int i = hash(key); // compute the hash index of name
    HSNODE *p = ht->hna[i]; // get the linked list of the hash value
    // search the linked list, if name is matched, return the node
    while(p){
        if(strcmp(p->key, key) == 0){
            break;
        } else {
            p = p->next;
        }
    }
    return p;
}

int insert(HASHTABLE *ht, HSNODE *np) {
    int i = hash(np->key);
    HSNODE *p = ht->hna[i]; // get the linked list of the hash value
    int f = 0;
    if(p){
        do{
            if(strcmp(p->key, np->key)==0){
                //printf("%s %d\n", np->key, i);
                f = 1;
                p->value = np->value;
            } else {
                p=p->next;
            }
        }while(!f && p);
        if(!f){
            p->next = np;
            ht->count++;
        }
    } else {
        ht->hna[i] = np;
        ht->count++;
    }

    return !f;
}

int delete(HASHTABLE *ht, char *key) {
    // your implementation
    int i = hash(key);
    HSNODE *p = ht->hna[i]; // get the linked list of the hash value
    HSNODE *prev = NULL;
    int del = 0;
    while(p){
        if(strcmp(p->key, key)==0){
            if(prev){
                prev->next = p->next;
            } else {
                ht->hna[i] = p->next;
            }
            free(p);
            del = 1;
            ht->count--;
        } else {
            prev = p;
            p=p->next;
        }
    }
    return del;
}


void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HSNODE *sp = ht->hna[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  ht->hna = NULL;
  *htp = NULL;
}
