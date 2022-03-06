#ifndef TREE_H
#define TREE_H
 
/* node structure of a binary tree */ 
typedef struct tnode {
  int data;
  struct tnode *left;
  struct tnode *right;
} TNODE;

/* a structure to represent tree properties: order and height */
typedef struct tree_props {
  int order;   // as the number of nodes in a tree
  int height;  // as the height of a tree
} TPROPS;

/* this creates a TNODE node and sets the data to value and returns the pointer */
TNODE *new_node(int value);

/* this computes and returns TPROPS value containing the number of nodes and height 
 * of tree passed by root address. 
*/
TPROPS get_props(TNODE *root);

/* this displays the node data of the tree in pre-order. */
void display_preorder(TNODE *root);

/* this displays the node data of the tree in in-order. */
void display_inorder(TNODE *root);

/* this displays the node data of the tree in post-order. */
void display_postorder(TNODE *root);

/* this displays the tree in breadth-first-order using an auxiliary queue. */ 
void display_bforder(TNODE *root);

/* this does the breadth-first-search using an auxiliary queue. */
TNODE *iterative_bfs(TNODE *root, int val);

/* this does the depth-first-search using an auxiliary stack */
TNODE *iterative_dfs(TNODE *root, int val);


/* this cleans the tree passed by address root pointer. */
void clean_tree(TNODE **rootp);

/* this inserts nodes into a complete binary tree using an auxiliary queue. */ 
void insert_complete(TNODE **rootp, int val);

#endif