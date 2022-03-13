#ifndef AVL_H
#define AVL_H

typedef struct record {
  char name[40];
  float score;
} RECORD;

typedef struct tnode {
    RECORD data;
    int height;
    struct tnode *left;
    struct tnode *right;
} TNODE;


/* Return the balance factor at the given node */
int balance_factor(TNODE *root);

/* This checks if the tree is AVL tree, returns 1 if true, 0 otherwise */
int is_avl(TNODE *root);

/* This does the left rotation at the root */
TNODE *rotate_left(TNODE *root);  

/* This does the right rotation at the root */
TNODE *rotate_right(TNODE *root);

/* This inserts record (name, score) into the AVL tree using name as key */
void insert(TNODE **rootp, char *name, float score);

/* This deletes node of data.name from the AVL tree */ 
void delete(TNODE **rootp, char *name);  

// following functions are from A7
TNODE *search(TNODE *root, char *name);
void clean_tree(TNODE **rootp); 

#endif