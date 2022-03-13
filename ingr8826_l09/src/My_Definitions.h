/*
-------------------------------------
File:    My_Definitions.h
Project: CP264
file description
-------------------------------------
Author:  Rick Magnotta
ID:      989002582
Email:   rmagnotta@wlu.ca
Version  2019-11-08
-------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

//#define DEBUG_LEVEL_01  1
//#define DEBUG_LEVEL_02  1

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

#define SUCCESS TRUE
#define FAILURE FALSE

typedef unsigned bool;

#endif /* MY_DEFINITIONS_H_ */
