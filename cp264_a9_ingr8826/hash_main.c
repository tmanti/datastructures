/*--------------------------------------------------
Project: CP264-a9q1
File:    hash_main.c 
Description: public test driver
Author:  HBF
Version: 2022-02-22
--------------------------------------------------
*/   

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "hash.h"

int htsize = 5;

void search_info(char *key, HSNODE *p){
  if (p) 
    printf("search(%s):(%s,%d)\n", key, p->key, p->value);
  else
    printf("search(%s):NULL\n", key);	
}

void display_hashtable(HASHTABLE *ht, int option) {
  int i = 0;
  HSNODE *p;
  if (option == 0) {
    printf("size:%d\n", ht->size);
    printf("count:%d", ht->count);
    for (i = 0; i < ht->size; i++) {
      p = *(ht->hna + i);
	  if (!p) printf("\n%d:NULL", i);
      else { printf("\n%d:", i); 
	    while (p) {
          printf("(%s,%d) ", p->key, p->value);
          p = p->next;
        }
	  }
    }
    printf("\n");
  } else { 
    for (i = 0; i < ht->size; i++) {
      p = *(ht->hna + i);
      while (p) {
        printf("%s:%d\n", p->key, p->value);
        p = p->next;
      }
    }  
  }
}

int main(int argc, char *argv[]) {
  int n = 20;	
  if (argc > 1) htsize = atoi(argv[1]);
  if (argc > 2) n = atoi(argv[2]);
  
  HASHTABLE *ht = new_hashtable(htsize);
  
  int i;
  char name[10];
  for (i=0; i<n; i++) {
	name[0] = i+'a';
  	name[1] = '\0';
	insert(ht, new_hashnode(name, i));
  }
  printf("\nhash table after insertions:\n");
  display_hashtable(ht, 0);
  char *key = "a";
  HSNODE *hn = search(ht, key);
  search_info(key, hn);
  
  for (i=0; i<n/2; i++) {
	name[0] = i+'a';
  	name[1] = '\0';
	delete(ht, name);
  }
  printf("hash table after deletions:\n");
  display_hashtable(ht, 0);  
  key = "b";
  hn = search(ht, key);
  search_info(key, hn);
 
  clean_hash(&ht);
  
  return 0;
}



