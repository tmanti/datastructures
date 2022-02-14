/*
--------------------------------------------------
Project: CP264-a5q1
File:    myrecord_llist_main.c   public test driver
Author:  HBF
Version: 2022-02-02
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "myrecord_sllist.h"


void searh_message(NODE *p, char *name) {
  if (p == NULL)
    printf("%s:not fount\n", name);
  else
    printf("%s:%.1f\n", p->data.name, p->data.score);
}

int main(int argc, char* args[]) {
  char infilename[40] = "marks.txt";
  char outfilename[40] = "report.txt";
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  

  printf("\nImport and display\n");
  SLLIST sllist = {0};   
  import_data(&sllist, infilename);
  display(&sllist);


  // testing insert and search
  printf("\nInsert and search\n");
  char name[20] = "Moore";
  insert(&sllist, name, 92.0);
  NODE *p = search(&sllist, name);
  searh_message(p, name);
  
  printf("\nDelete and search\n");
  strcpy(name, "Wang");
  delete(&sllist, name);
  p = search(&sllist, name);
  searh_message(p, name);
 
  printf("\nReport\n");
  STATS stats = report_data(&sllist, outfilename);
  printf("count:%d\n", stats.count);
  printf("mean:%.1f\n", stats.mean);
  printf("stddev:%.1f\n", stats.stddev);
  printf("median:%.1f\n", stats.median);
  
  printf("\nClean\n");
  clean(&sllist);
  printf("length:%d\n", sllist.length);
  
  return 0;
}

