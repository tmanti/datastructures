/*
--------------------------------------------------
Project: cp264-a8q2
File:    myrecord_avl_main.c
Description: public test driver program
Author:  HBF  
Version: 2022-02-22
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "myrecord_avl.h"


void display_inorder(TNODE *root) {
  if (root) {
    if (root->left) display_inorder(root->left);
    printf("%s,%.1f\n", root->data.name, root->data.score);
    if (root->right) display_inorder(root->right);
  }
}


int main(int argc, char* args[]) {
  char infilename1[40] = "marks1.txt";
  char infilename2[40] = "marks2.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename1, args[1]);
    if (argc >= 3) strcpy(infilename2, args[2]);
    if (argc >= 4) strcpy(outfilename, args[3]);
  }  
  
  printf("\nInport data from %s:\n", infilename1);
  TREE t1 = {0};
  import_data(&t1, infilename1);
  display_inorder(t1.root);
  printf("count:%d\n", t1.count);
  printf("mean:%.1f\n", t1.mean);
  printf("stddev:%.1f\n", t1.stddev);
  printf("median:%.1f\n", median(&t1));
  
  printf("\nInport data from %s:\n", infilename2);
  TREE t2 = {0};
  import_data(&t2, infilename2); 
  display_inorder(t2.root);
  printf("count:%d\n", t2.count);
  printf("mean:%.1f\n", t2.mean);
  printf("stddev:%.1f\n", t2.stddev);
  printf("median:%.1f\n", median(&t2));
  
  printf("\nMerge:\n");
  merge_data(&t1, &t2);
  clean(&t2);  
  display_inorder(t1.root);
  printf("count:%d\n", t1.count);
  printf("mean:%.1f\n", t1.mean);
  printf("stddev:%.1f\n", t1.stddev);
  printf("median:%.1f\n", median(&t1));

  printf("\nReport data:\n", outfilename);
  STATS stats = report_data(&t1, outfilename);
  printf("count:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n", stats.median);
  
  clean(&t1);
  /*
  printf("\nRead file %s\n", outfilename);
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

