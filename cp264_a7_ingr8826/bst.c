#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

TNODE *search(TNODE *root, char *name) {
// your implementation
}

void insert(TNODE **rootp, char *name, float score) {
// your implementation
}

void delete(TNODE **rootp, char *name) {
// your implementation
}


/* auxiliary function for delete */
TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *p = *rootp, *parent = NULL;
  if (p) {
    while (p->left) {
      parent = p;
      p = p->left;
    }
    
    if (parent == NULL)
      *rootp = p->right;
    else
      parent->left = p->right;
    
    p->left = NULL;
    p->right = NULL;
  }
  
  return p;
}


// the following functions are given for testing, need to add to your program.
void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_tree(&root->left);
        if (root->right)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}