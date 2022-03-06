/*--------------------------------------------------
Project: CP264-a7q2
File:    bst_main.c
Description: public test driver
Author:  HBF  
Version: 2022-02-17
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

void search_info(char *sf, char *key, TNODE *tnp){
  if (tnp) 
    printf("\n%s(%s):%s,%.1f\n", sf, key, tnp->data.name, tnp->data.score);
  else
    printf("\n%s(%s):NULL\n", sf, key);	
}

void display_inorder_line(TNODE *root) {
  if (root) {
    if (root->left) display_inorder_line(root->left);
    printf("%s ", root->data.name, root->data.score);
    if (root->right) display_inorder_line(root->right);
  }
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left) display_inorder(root->left);
		printf("%s,%3.1f\n", root->data.name, root->data.score);
		if (root->right) display_inorder(root->right);
	}
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
    printf("%s,%.1f\n", root->data.name,root->data.score);
    display_tree(root->right, 2, prelen + 4);
    display_tree(root->left, 1, prelen + 4);
  }
}


int main(int argc, char* args[]) {  
  TNODE *root = NULL;  
  insert(&root, "D", 1);
  insert(&root, "B", 2);
  insert(&root, "F", 3);
  insert(&root, "A", 4);
  insert(&root, "C", 5);
  insert(&root, "E", 6);    
  insert(&root, "G", 7);

    printf("\n");
  display_tree(root, -1, 0);
  printf("\ninorder:");
  display_inorder_line(root);
  
  //printf("\ntest bst search\n");  
  char *key = "A";
  TNODE *tp = search(root, key);
  search_info("search", key, tp);

  //printf("test bst insert\n");
  key = "H";
  tp = search(root, key);
  search_info("search", key, tp);
  
  float score = 8;
  insert(&root, key, score);
  display_tree(root, -1, 0);
  printf("\ninorder:");
  display_inorder_line(root);
  tp = search(root, key);
  search_info("search", key, tp);

  //printf("test bst delete\n");
  key = "F";
  delete(&root, key);
  display_tree(root, -1, 0);
  printf("\ninorder:");
  display_inorder_line(root);

  clean_tree(&root);   

  return 0;
}

