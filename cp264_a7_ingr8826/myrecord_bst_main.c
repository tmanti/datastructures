/*--------------------------------------------------
Project: CP264-a7q3
File:    myrecord_bst_main.c
Description: public test driver
Author:  HBF  
Version: 2022-02-17
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "myrecord_bst.h"

void search_info(char *sf, char *key, TNODE *tnp){
  if (tnp) 
    printf("%s(%s):%s %.0f\n", sf, key, tnp->data.name, tnp->data.score);
  else
    printf("%s(%s):NULL\n", sf, key);	
}

void display_inorder(TNODE *root) {
	if (root) {
		if (root->left) display_inorder(root->left);
		printf("%s,%3.1f\n", root->data.name, root->data.score);
		if (root->right) display_inorder(root->right);
	}
}

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  
  
  printf("\n---test data import---\n");
  TREE dstree = {0};  
  import_data(&dstree, infilename);  
  //display_tree(dstree.root, 0, 0);
  display_inorder(dstree.root);
  printf("\ncount:%d\n", dstree.count);
  printf("mean:%.1f\n", dstree.mean);
  printf("stddev:%.1f\n", dstree.stddev);
  printf("median:%.1f\n\n", median(&dstree));
  
  printf("---test record search---\n");
  char *key = "Smith";
  TNODE *tp = search(dstree.root, key);
  search_info("search", key, tp);

  printf("\n---test adding data---\n");
  key = "Moore";
  float score = 92;
  add_data(&dstree, "Moore", score);
  tp = search(dstree.root, key);
  search_info("search", key, tp);

  printf("\n---test remove data---\n");
  key = "Wang";
  remove_data(&dstree, key);  
  tp = search(dstree.root, key);
  search_info("search", key, tp);
  
  printf("\n---test report data---\n");
  STATS stats = report_data(&dstree, outfilename);
  printf("count:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n", stats.median);
  clean(&dstree);
  
  /*
  printf("\n---test file output---\n");
  FILE *fp =fopen(outfilename, "r");
  if ( fp == NULL ) {
    printf("output file does not exist\n");
    return 0;
  }
  char buf[100];
  while( !feof(fp) ) {
     fgets(buf, sizeof(buf), fp);
     printf("%s", buf);
     buf[0] = 0;
  }
  fclose(fp);
  */
  
  return 0;
}

