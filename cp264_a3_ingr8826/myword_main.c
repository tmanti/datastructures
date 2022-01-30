/*
--------------------------------------------------
Project: CP264-a3q2
File:    myword_main.c, a public test driver
Author:  HBF
Version: 2022-01-20
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

void display_word_summary(WORDINFO *wip) {
  printf("%s:%d\n", "line count", wip->line_count);
  printf("%s:%d\n", "word count", wip->word_count);
  printf("%s:%d\n", "distinct word count", wip->distinct_word_count);
  int i;
  for (i = 0; i < wip->distinct_word_count; i++) {
    printf("%s:%d\n", wip->word_array[i].word, wip->word_array[i].frequency);
  }
}

int main(int argc, char *args[]) {  
  char infilename[40] = "textdata.txt"; //default input file name
  char outfilename[40] = "result.txt";  //default output file name

  if (argc > 1) {  
	if (argc >= 2) strcpy(infilename, args[1]);
    if (argc >= 3) strcpy(outfilename, args[2]);
  }

  WORDINFO wordinfo = {0}; 
  process_word(infilename, &wordinfo);  
  printf("word processing:done\n");
  display_word_summary(&wordinfo);
  save_to_file(outfilename, &wordinfo); 
  printf("saving result to file:done\n");

  return 0;
}


