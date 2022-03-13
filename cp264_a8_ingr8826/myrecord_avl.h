#ifndef MYRECORD_AVL_H
#define MYRECORD_AVL_H

#include "avl.h"

typedef struct tree {
    TNODE *root;
    int count;
    float mean;
    float stddev;
} TREE;

/* merge tree rootp2 into tree rootp1 */
void merge_tree(TNODE **rootp1, TNODE **rootp2); 

/* merget data tree t2 to data tree t1 */
void merge_data(TREE *t1, TREE *t2);

// the following are adapted/modified from programs of A5 and A7
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

void add_data(TREE *tree, char *name, float score);
void remove_data(TREE *tree, char *name);
void file_inorder(TNODE *root, FILE *filename);
void clean(TREE *tp);

#endif