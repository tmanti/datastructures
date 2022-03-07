#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(TREE *tree, char *name, float score) {
  // your implementation
  if(search(tree->root, name) == NULL){
    insert(&tree->root, name, score);
    int n = tree->count;
    tree->count += 1;
    float mean = tree->mean;
    tree->mean = (1/(n+1))*(n*mean + score);
    //printf("mean: %f(s), %f, %f, %f\n", score, tree->mean, (1/(n+1)), (n*mean + score));
    //printf("%f\n", (1/(n+1)));
    //printf("%f\n", (n*mean + score));
    float stddev = tree->stddev;
    tree->stddev = sqrtf((1/(n+1))*(n*(stddev*stddev + mean*mean)+(score*score))-(tree->mean*tree->mean));
    //printf("stddev: %f\n", tree->stddev);
  }
}

void remove_data(TREE *tree, char *name) {
// your implementation 
  TNODE *p = search(tree->root, name);
  if(p !=NULL){
    float score = p->data.score;
    delete(&(tree->root), name);
    int count = tree->count;
    float mean = tree->mean;
    float stddev = tree->stddev;
    tree->count = count - 1;
    tree->mean = (1/(tree->count))*(count*mean - score);
    tree->stddev = sqrtf((1/(tree->count))*(count*(stddev*stddev + mean*mean) - (score*score))-(tree->mean*tree->mean));
  }
}


void clean(TREE *tree) {
  TNODE *root = tree->root;
  clean_tree(&root);
  tree->count = 0;
  tree->mean = 0;
  tree->stddev = 0;
}

void file_inorder(TNODE *root, FILE *fp) {
  if (root){
    if (root->left) file_inorder(root->left, fp);
    fprintf(fp, "%s,%c\n", root->data.name, letter_grade(root->data.score));
    if (root->right) file_inorder(root->right, fp);
  }
}


// The following functions are adapted and modified from A5

char letter_grade(float s) {
  char r = 'F';
  if (s >= 90) r = 'S';
  else if (s >= 80) r = 'A';
  else if (s >= 70) r = 'B';
  else if (s >= 60) r = 'C';
  else if (s >= 50) r = 'D';  
  else r = 'F';
  return r;
}

void select_sort(float a[], int left, int right) 
{
  int i, j, k;
  float temp;
  for (i = left; i <= right; ++i) {
    k = i;
    for(j = i+1; j <= right; ++j) { 
      if (a[j] < a[k]) {
        k = j;
      }
    }
    if (i != k) {
      temp = a[k];
      a[k] = a[i];
      a[i] = temp;     
    }
  } 
}

float median(TREE *tree)
{
  if (tree == NULL || tree->root == NULL) return 0;
  int i=0, n = tree->count;
  float a[n]; // array store score values for sorting, fill a[] by bf traversing the tree  
  TNODE *p = tree->root;
  QUEUE queue = {0};
  enqueue(&queue, p);
  while (queue.front) {
    p = dequeue(&queue);
    a[i++] = p->data.score;
   if (p->left)
     enqueue(&queue, p->left);
   if (p->right)
     enqueue(&queue, p->right);
  }
  select_sort(a, 0, n-1);   
  return (n % 2 == 1)? a[n/2] : (a[n/2-1] + a[n/2])/2 ;   
} 

void import_data(TREE *tree, char *filename) {
  char line[40], name[20];
  FILE *fp = fopen(filename, "r");
  char *result = NULL;
  float score = 0;
  char delimiters[] = ",\n";
  if (fp == NULL) {
    perror("Error while opening the file.\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    result = strtok(line, delimiters);
    if (result){
      strcpy(name, result);
      result = strtok(NULL, delimiters);
      score = atof(result);
      add_data(tree, name, score); 
    }
  }
  fclose(fp);
}


STATS report_data(TREE *tree, char *filename) {
  TNODE *root = tree->root; 
  FILE *fp = fopen(filename, "w"); 
  file_inorder(root, fp);
  fclose(fp);
 
  STATS stats = {};
  stats.count = tree->count;
  stats.mean = tree->mean;
  stats.stddev = tree->stddev;
  stats.median = median(tree);
  return stats;
}