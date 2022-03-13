/*
--------------------------------------------------
Project: CP264-a8q1
File:    avl_main.c
Description: public test driver program
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void display_inorder_line(TNODE *root) {
  if (root) {
    if (root->left) display_inorder_line(root->left);
    printf("%s ", root->data.name);
    if (root->right) display_inorder_line(root->right);
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
    printf("%s,%.1f,%d\n", root->data.name,root->data.score, root->height);
    display_tree(root->right, 2, prelen + 4);
    display_tree(root->left, 1, prelen + 4);
  }
}

int main(int argc, char* args[])
{
  int n = 7;
  if (argc >1) sscanf(args[1], "%d", &n);
  if (n > 26) n = 26;
  
  printf("\nAVL insertions:\n");
  TNODE *root = NULL, *np;
  int i;
  char key[20];
  float value = 0;
  for (i = 0; i < n; i++) {
    key[0] = 'A' + i; 
	key[1] = 0; 
	value = i+1.0;
	printf("insert(&root, %s, %.1f):\n", key, value);
    insert(&root, key, value);  // use number i as score data
  }
  display_tree(root, 0, 0);
  printf("is_val(&root):%d\n", is_avl(root));
  printf("inorder:");
  display_inorder_line(root);
  printf("\nAVL deletions:\n");
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      key[0] = 'A' + i; 
	  key[1] = 0; 
	  printf("delete(&root, %s):\n", key);
      delete(&root, key);
    }
  }
  display_tree(root, 0, 0);
  printf("is_val(&root):%d\n", is_avl(root));
  printf("inorder:");
  display_inorder_line(root);
  printf("\n");
  clean_tree(&root);
  return 0;
}

