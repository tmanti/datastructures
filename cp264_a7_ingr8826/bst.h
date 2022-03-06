#ifndef BST_H
#define BST_H

typedef struct record {
  char name[40];
  float score;
} RECORD;

typedef struct tnode {
    RECORD data;
    struct tnode *left;
    struct tnode *right;
} TNODE;

/* search bst by data.name */
TNODE *search(TNODE *root, char *name); 

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score); 

/* delete node of data.name from bst */
void delete(TNODE **rootp, char *name);  

/* get and return and delete the node of the smallest data.name node from the bst */
TNODE *extract_smallest_node(TNODE **rootp); 

/* clean the tree */
void clean_tree(TNODE **rootp); 


#endif