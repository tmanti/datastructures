/*--------------------------------------------------
Project: cp264-a6
File:    common.h
Description: node structure and functions for linked list queue and stack
Author:  HBF  
Version: 2022-02-10
--------------------------------------------------
*/
#ifndef COMMON_H
#define COMMON_H

/* node structure for postfix expression by queue and evaluation by stack */ 
typedef struct node {
	int data;  // int data is used for int operand, operator ascii code, or parenthesis assii code 
	int type;  // 0: int operand; 1:operator; 2: left parenthesis 3: right parenthesis 
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void display(NODE *start);
void clean(NODE **startp);

#endif
