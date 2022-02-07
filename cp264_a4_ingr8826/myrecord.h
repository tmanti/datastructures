// your program signature
 
#ifndef MYRECORD_H
#define MYRECORD_H 

typedef struct {
// your design 
} RECORD;

typedef struct {
// your design
} STATS;

char letter_grade(float score);
int import_data(RECORD dataset[], char *filename);  
STATS report_data(RECORD dataset[], int n, char *filename);
 
#endif