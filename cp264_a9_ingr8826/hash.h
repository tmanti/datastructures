#ifndef HASH_H
#define HASH_H

typedef struct hashnode {
  char key[10];
  int value;
  struct hashnode *next; 
} HSNODE;

typedef struct hashtable {
  HSNODE **hna; // pointer pointing to the array of hashnode pointers 
  int size;     // hash table size, i.e., the modular or length of index array
  int count;    // number of data elements in the hash table
} HASHTABLE;

/* hash function that hash key string to an integer of modular of hash table size */
int hash(char *key); 

/* create dynamically a hash node and set key and value and return the point */
HSNODE *new_hashnode(char *key, int vale); 

/* create dynamically a chained hash table of the given size */
HASHTABLE *new_hashtable(int size); 

/* search the hash table and return the pointer of found hashnode */
HSNODE *search(HASHTABLE *ht, char *key);

/* insert hashnode np to hash table
 * when the named hashnode exists, update the hashnode's value by np->value, return 0;
 * otherwise insert into the hash table, return 1 
*/
int insert(HASHTABLE *ht, HSNODE *np);

/* 
 * delete hashnode by key. If the named hash node exists, delete it and return 1; 
 * otherwise return 0
*/
int delete(HASHTABLE *ht, char *key);

/* 
 * delete all linked list and reset the hash table 
*/
void clean_hash(HASHTABLE **ht);

#endif