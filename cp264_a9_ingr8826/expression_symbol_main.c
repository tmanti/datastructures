/*
--------------------------------------------------
Project: CP264-a9q2
File:    expression_symbol_main.c
Description: public test driver
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"
#include "expression_symbol.h"   

int htsize = 10;

int resolve_symbol(char* statement, HASHTABLE *ht) {
  char name[10] = { 0 };
  char *dest = strstr(statement, "=");
  if (dest) 
    *dest = '\0';
  else 
    dest = statement;
  strcpy(name, statement);
  
  if ( (name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z')) {
	  
    int value = evaluate_infix_symbol(dest + 1, ht);

	if (value == 99999)  // escape value
      return 2;
	else {
      insert(ht, new_hashnode(name, value));
    }
	return 1;
  }
  return 0;
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

int main(int argc, char* args[]) {
  char infilename[40] = "expression.txt";0;
  if (argc >1) strcpy(infilename, args[1]);
  
  if (argc >2) htsize = atoi(args[2]);

  HASHTABLE *ht = new_hashtable(htsize);

  char line[100];
  char delimiters[] = ";\n";
  char *st;
    
  FILE *fp = fopen(infilename, "r");
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    return 0;
  }
  printf("Symbolic expressions:\n"); 
  while (fgets(line, sizeof(line), fp) != NULL) {
    st = strtok(line, delimiters);
	printf("%s\n", st);
    while (st != NULL) {
      resolve_symbol(st, ht);
      st = strtok(NULL, delimiters);
    }
  }
  fclose(fp);
  
  printf("\nSymbolic expression evaluation:\n");  
  display_hashtable(ht,1);
  clean_hash(&ht);
  return 0;
}


 
 