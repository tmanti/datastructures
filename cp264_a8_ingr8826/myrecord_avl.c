#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {
  // use recursive or iterative algorithm to traverse tree rootp2, 
  // get record data of each node and insert into rootp1
  QUEUE q = {0};
  TNODE *p;
  enqueue(&q, *rootp2);
  while(q.front != NULL){
    p = dequeue(&q);
    if(p->left)
      enqueue(&q, p->left);
    if(p->right)
      enqueue(&q, p->right);

    RECORD r = p->data;
    insert(rootp1, r.name, r.score);
  }
}

void merge_data(TREE *t1, TREE *t2){
  // call the merge_tree function to merge t2->root into t1->root
  // update the simple stats of the merged data set using the stats of t1 and t2. 
  merge_tree(&t1->root, &t2->root);
  float count1 = (float) t1->count;
  float count2 = (float) t2->count;
  float count = count1 +count2;
  float mean1 = t1->mean;
  float mean2 = t2->mean;
  t1->count = t1->count + t2->count;
  t1->mean = (t1->mean*(float)count1 + t2->mean*(float)t2->count)/(float)t1->count;
  t1->stddev = sqrtf((1/count)*(t1->stddev*t1->stddev*count1 + mean1*mean1*count1 + t2->stddev*t2->stddev*count2 + mean2*mean2*count2)-(t1->mean*t1->mean));
}


// the following are adapted from  A5 and A7
void add_data(TREE *tree, char *name, float score) {
  if (search(tree->root, name) == NULL) {
    insert(&(tree->root), name, score);
    int count = tree->count;
    float mean = tree->mean;
    float stddev = tree->stddev;
    tree->count = count + 1;
    tree->mean =  (mean*count + score) / (count+1);
    tree->stddev = sqrt(score*score/(count+1.0) + (stddev * stddev + mean * mean) * (count/(count+1.0)) - tree->mean * tree->mean ); 
  } else {
    printf("record exits");
  }
}

void remove_data(TREE *tree, char *name) {
  TNODE *np = NULL;
  if ( (np = search(tree->root, name)) != NULL) {
    float score = np->data.score;
    delete(&(tree->root), name);
    int count = tree->count;
    float mean = tree->mean;
    float stddev = tree->stddev;
    tree->count = count - 1;
    tree->mean =  (mean*count - score) / (count-1.0);
    tree->stddev = sqrt( (stddev * stddev + mean * mean) * (count/(count-1.0)) - score*score/(count-1.0) - tree->mean * tree->mean );
  } else {
    printf("record does not exit");   
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