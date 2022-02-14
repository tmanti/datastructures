#ifndef SLLIST_H
#define SLLIST_H

typedef struct {
  char name[40];
  float score;
} RECORD;

typedef struct node {
  RECORD data;
  struct node *next;
} NODE;

typedef struct sllist {
  int length;
  NODE *start;
} SLLIST;

/**
 * Display record data in linked list.
 * @param SLLIST *sllistp passes the address of a singly linked list structure.
 */
void display(SLLIST *sllistp);

/**
 * Search singly linked list by name key.
 * @param SLLIST *sllistp provides the address of a singly linked list structure.
 * @param name Key to search
 * @return Pointer to found node if found; otherwise NULL
 */
NODE *search(SLLIST *sllistp, char *name);

/**
 * Insert new record to linked list at the position sorted by record name field.
 * @param @param SLLIST *sllistp provides the address of a singly linked list structure.
 * @param name The name data of new record.
 * @param score The score data of new record
 */
void insert(SLLIST *sllistp, char *name, float score);

/**
 * Delete a node of record matched by the name key from linked list.
 * @param @param SLLIST *sllistp provides the address of a singly linked list structure.
 * @param name  The key used to find the node for deletion. 
 * @return 1 if deleted a matched node, 0 otherwise. 
 */
int delete(SLLIST *sllistp,  char *name);

/**
 * Clean singly linked list, delete all nodes. 
 * @param @param SLLIST *sllistp provides the address of a singly linked list structure.
 */
void clean(SLLIST *sllistp);


// The following are adapted/modified from A4Q2 for A5Q1
typedef struct {
  int count;
  float mean;
  float stddev; 
  float median; 
} STATS;

char letter_grade(float score);
int import_data(SLLIST *sllistp, char *infilename);
STATS report_data(SLLIST *sllistp,  char *outfilename);

#endif