/*--------------------------------------------------
Project: CP264-a7q1
File:    tree_main.c
Description: test driver program
Author:  HBF  
Version: 2022-02-17
--------------------------------------------------
*/
#include <stdio.h>
#include "tree.h"

void search_info(char *sf, char key, TNODE *tnp){
  if (tnp) 
    printf("\n%s(%c):%c", sf, key, tnp->data);
  else
    printf("\n%s(%c):NULL", sf, key);	
}

void display_tree(TNODE *root, int pretype, int prelen) {
  if (root) {
    int i;
    for (i = 0; i < prelen; i++) {
      printf("%c", ' ');
	}
	if (pretype == 0)
      printf("%s", "|___:");
	else if (pretype == 1)
      printf("%s", "|___L:");
	else if (pretype == 2) 
      printf("%s", "|___R:");

    printf("%c\n", root->data);
    display_tree(root->right, 2, prelen + 4);
    display_tree(root->left, 1, prelen + 4);
  }
}

int main() {  
  TNODE *root = NULL;
  int i; 
  for ( i = 0; i<7; i++) {
	  insert_complete(&root, i+'A');
  }
  
  printf("\ndisplay_tree():\n");
  display_tree(root, 0, 0);  
  printf("%s:%d\n", "get_props().order", get_props(root).order);
  printf("%s:%d\n", "get_props().height", get_props(root).height);  
  
  printf("%s:", "display_preorder()");
  display_preorder(root);
    
  printf("\n%s:", "display_postorder()");
  display_postorder(root);
  
  printf("\n%s:", "display_inorder()");
  display_inorder(root);
  
  printf("\n%s:", "display_bforder(root)");
  display_bforder(root);
  
  // testing iterative_bfs function
  char key = 'F';
  TNODE *tnp = iterative_bfs(root, key);
  search_info("iterative_bfs", key, tnp);
  
  key = 'H';
  tnp = iterative_bfs(root, key);
  search_info("iterative_bfs", key, tnp);

  // testing iterative_bfs function
  key = 'F';
  tnp = iterative_dfs(root, key);
  search_info("iterative_dfs", key, tnp);
 
  key = 'H';
  tnp = iterative_dfs(root, key);
  search_info("iterative_dfs", key, tnp);
    
  clean_tree(&root); 
  printf("\n%s:%d", "clean get_props().order", get_props(root).order);
  printf("\n%s:%d\n", "get_props().height", get_props(root).height);  
  
  return 0;
}
