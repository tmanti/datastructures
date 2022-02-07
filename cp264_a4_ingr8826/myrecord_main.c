/*
--------------------------------------------------
Project: CP264-a4q2
File:    myrecord_main.c  public test driver
Author:  HBF
Version: 2022-01-26
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"
#define MAX_REC 100
 
int main(int argc, char *args[]) {  
  char infilename[40] = "marks.txt";    //default input file name
  char outfilename[40] = "report.txt";  //default output file name
  if (argc > 1) {
    if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }  
  RECORD dataset[MAX_REC]; // declare array of RECORD to store record data
  int record_count = import_data(dataset, infilename); 
  if (record_count >=1) { 
    STATS stats = report_data(dataset, record_count, outfilename);
	printf("count:%d\n", stats.count);
	printf("mean:%.1f\n", stats.mean);
	printf("stddev:%.1f\n", stats.stddev);
	printf("median:%.1f\n", stats.median);
  } else 
    printf("no data is found");
  
  return 0;
}
