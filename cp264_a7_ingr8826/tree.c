#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TNODE *new_node(int value) {
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np == NULL) return NULL;
  np->data = value;
  np->left = NULL;
  np->right = NULL;
  return np;
}


TPROPS get_props(TNODE *root) {
    // your implementation
    TPROPS r = {0};
    if(root == NULL) return r;
    else {
        TPROPS lp = get_props(root->left);
        TPROPS rp = get_props(root->right);
        r.order = lp.order + rp.order + 1;
        r.height = (lp.height>rp.height)?lp.height+1:rp.height+1;
        return r;
    }
}

void display_preorder(TNODE *root) {
    // your implementation
    if (root) {
        printf("%c ", root->data);
        display_preorder(root->left);
        display_preorder(root->right);
    }
}

void display_inorder(TNODE *root) {
    // your implementation
    if (root) {
        display_inorder(root->left);
        printf("%c ", root->data);
        display_inorder(root->right);
    }
}

void display_postorder(TNODE *root) {
    // your implementation
    if (root) {
        display_postorder(root->left);
        display_postorder(root->right);
        printf("%c ", root->data);
    }
}

/* use auxiliary queue data structure for the algorithm  */
void display_bforder(TNODE *root) {
    // your implementation
    if (root == NULL) return;
    QUEUE q = {0};
    TNODE *p = NULL;
    enqueue(&q, root);
    while (q.front) {
        p = dequeue(&q);
        if(p){
            printf("%c ", p->data);
            enqueue(&q, p->left);
            enqueue(&q, p->right);
        }
    }
}

/* use auxiliary queue data structure for the algorithm  */
TNODE *iterative_bfs(TNODE *root, int val) {
    // your implementation
    QUEUE queue = {0}; // auxiliary queue
    TNODE *r = NULL, *p = NULL;
    if (root != NULL) {
        enqueue(&queue, root);
        while (queue.front) {
            p = dequeue(&queue);
            // check match, if matched, set r=p, break;
            if(p->data == val){
                r=p; 
                break;
            }
            if (p->left) enqueue(&queue, p->left);
            if (p->right) enqueue(&queue, p->right);
        }
        // clean queue
        clean_queue(&queue);
    }
    return r;
}

TNODE *iterative_dfs(TNODE *root, int val) {
    // your implementation
    STACK stack = {0};
    TNODE *r = NULL, *p = NULL;
    if (root != NULL) {
        push(&stack, root);
        while(stack.top){
            p = (TNODE *) (stack.top)->data; pop(&stack);
            // or change pop() so that p = pop(&stack);
            // check match, if matched, set r=p, break;
            if(p->data == val){
                r=p; 
                break;
            }
            if (p->right) push(&stack, p->right);
            if (p->left) push(&stack, p->left); // left child first search
        }
    }
    // clean stack
    clean_stack(&stack);
    return r;
}


// the following functions are given, need to add to your program.

void clean_tree(TNODE **rootp) {
  TNODE *p = *rootp;
  if (p) {
    if (p->left)
      clean_tree(&p->left);
    if (p->right)
      clean_tree(&p->right);
    free(p);
  }
  *rootp = NULL;
}

void insert_complete(TNODE **rootp, int val){
  if( *rootp == NULL) { 
    *rootp = new_node(val);
  } else {
    QUEUE queue = {0};
    TNODE *p;
    enqueue(&queue, *rootp);
    while(queue.front){
      p = dequeue(&queue);
      if(p->left == NULL){
        p->left = new_node(val);
        break;
      } else {
        enqueue(&queue, p->left);
      }
      
      if(p->right == NULL){
        p->right = new_node(val);
        break;
      } else  {
        enqueue(&queue, p->right);
      }
    }
  }
}

