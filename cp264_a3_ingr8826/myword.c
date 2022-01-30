#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"


int process_word(char *infilename, WORDINFO *wip)
{
  const char delimiters[] = " .,;:!()&?-\n\t\r\"\'"; 
  // your implementation
  char line[MAX_LINE_LEN];
  char *word_token = NULL; int j;
  FILE *fp = fopen(infilename, "r");
  while (fgets(line, MAX_LINE_LEN, fp) != NULL) { // traversing all lines
    wip->line_count++;
    lower_case(line); // your function in mystring.c
    trim(line); // your function in mytring.c
    word_token = (char *) strtok(line, delimiters); // get the first word
    while (word_token != NULL) { // traversing all words in a line
      // action: insert word_token into data structure wip->word_array[]
      int found = 0;
      for(int i = 0; i < j; i++){
        if(strcmp(wip->word_array[i].word, word_token) == 0){
          //printf("%s %s %d\n", wip->word_array[i].word, word_token, strcmp(wip->word_array[i].word, word_token));
          wip->word_array[i].frequency++;
          found = 1;
        }
      }
      if(!found){
        WORD new_word = {"", 1};
        strcpy(new_word.word, word_token);
        //printf("%s\n", new_word.word);
        wip->word_array[j] = new_word;
        j++;
      }
      wip->word_count++;
      word_token = (char*) strtok(NULL, delimiters); // next word
    }
  }
  fclose(fp);
  wip->distinct_word_count = j;
}

int save_to_file(char *outfilename, WORDINFO *wip)
{
  FILE *fp = fopen(outfilename, "w");
  if (fp == NULL) { perror("file opening error"); return 1; }
  fprintf(fp, "%s:%d\n", "line count", wip->line_count);
  fprintf(fp, "%s:%d\n", "word count", wip->word_count);
  fprintf(fp, "%s:%d\n", "distinct word count", wip->distinct_word_count);
  int i;
  for (i = 0; i < wip->distinct_word_count; i++) {
    fprintf(fp, "%s:%d\n", wip->word_array[i].word, wip->word_array[i].frequency);
  }
  fclose(fp); return 0;
}