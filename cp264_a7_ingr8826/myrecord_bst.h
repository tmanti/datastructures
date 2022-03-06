#ifndef MYRECORD_BST_H
#define MYRECORD_BST_H

#include "bst.h"

/* tree type */
typedef struct {
  TNODE *root;
  int count;
  float mean;
  float stddev;   
} TREE;

/* add a record (name, score) into the bst and update the stats info incrementally */
void add_data(TREE *tree, char *name, float score);

/* delete a record of name from the bst and update the stats info incrementally */
void remove_data(TREE *tree, char *name);

/* clean the bst and reset the simple stats info */
void clean(TREE *tree);

void file_inorder(TNODE *root, FILE *filename);


// the following are adapted/modified from programs of A5
typedef struct {
  int count;
  float mean;
  float stddev; 
  float median; 
} STATS;

char letter_grade(float s);
float median(TREE *tree);
void import_data(TREE *tree, char *filename);
STATS report_data(TREE *tree, char *filename);

#endif