#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

TNODE *search(TNODE *root, char *name) {
  // your implementation
  TNODE* current = root;
  int found  = 0;
  while(!found && current){
    int cmp = strcmp(current->data.name, name);
    if(cmp == 0){
      found = 1;
    } else if(cmp > 0) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return current;
}

void insert(TNODE **rootp, char *name, float score) {
  TNODE* newnp = (TNODE*)malloc(sizeof(TNODE));
  RECORD rec = {0};
  strcpy(rec.name, name);
  rec.score = score;
  newnp->data = rec;
  newnp->left = NULL;
  newnp->right = NULL;

  if (*rootp == NULL) { *rootp = newnp; }
  else {
    TNODE *p = *rootp;
    while (1) {
      int cmp = strcmp(name, p->data.name);
      if (cmp == 0) {
        printf("The same key value is found");
        break;
      }
      else if (cmp < 0) {
        if (p->left == NULL) {p->left = newnp; break;}
        else p = p->left;
      }
      else {
        if (p->right == NULL) {p->right = newnp; break;}
        else p = p->right;
      }
    }
  }
}

void delete(TNODE **rootp, char *name) {
  TNODE *curr = *rootp, *tnp;
  TNODE **prev_pnt = NULL;
  int found = 0;
  if(curr == NULL) return;
  while(curr != NULL && !found){
    int cmp = strcmp(curr->data.name, name);
    //printf("\n%s %s %d\n", curr->data.name, name, cmp);
    if(cmp == 0){
      //printf("%d %d\n", curr->left== NULL, curr->right==NULL);
      if(curr->left == NULL && curr->right == NULL){
        free(curr);
        *prev_pnt = NULL;
      } else if(curr->left != NULL && curr->right == NULL){
        tnp = curr->left; *prev_pnt = tnp; free(curr);
      } else if(curr->left == NULL && curr->right != NULL){
        tnp = curr->right; *prev_pnt = tnp; free(curr);
      } else if(curr->left != NULL && curr->right != NULL){
        tnp = extract_smallest_node(&curr->right);
        tnp->left = curr->left;
        tnp->right = curr->right;
        *prev_pnt = tnp; free(curr);
      }
      found = 1;
    } else {
      if(cmp < 0){
        prev_pnt = &curr->right;
        curr = curr->right;
      } else {
        prev_pnt = &curr->left;
        curr = curr->left;
      }
    }
  }
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