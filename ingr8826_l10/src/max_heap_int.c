/*
 -------------------------------------
 File:    max_heap_int.c
 Project: data_structures_array
 Maximum Heap Source Code
 -------------------------------------
 Author:  Heider Ali @ David Brown
 ID:      999999999
 Email:   heali@wlu.ca & dbrown@wlu.ca
 Version: 2019-08-03
 Version: 2019-11-08 Rick Magnotta
          Created max_heap_int.c from max_heap.c
 Modified: 2022-03-11
 ------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "max_heap_int.h"

// Macros
//#define LESS_THAN(x,y)          compare((x), (y)) < 0
//#define LESS_THAN_EQUAL(x,y)    compare((x), (y)) <= 0
//#define GREATER_THAN(x,y)       compare((x), (y)) > 0
//#define GREATER_THAN_EQUAL(x,y) compare((x), (y)) >= 0
//#define EQUALS(x,y)             compare((x), (y)) == 0
//#define NOT_EQUALS(x,y)         compare((x), (y)) != 0
//#define COMPARE(x,y)            compare((x), (y))

// ===================================================== local functions

max_heap* max_heap_initialize()
//=============================
{
	max_heap *source;

	source = malloc(sizeof *source);                // Allocate storage for the "source" heap "header".
	assert(source != NULL);
                                                    // Allocate storage for the "values" array of integers to store the "heap".
	source->values = (int *) malloc(MAX_HEAP_SIZE * (sizeof *source->values));
	assert(source->values != NULL);
                                                    // Initialize heap header values.
	source->capacity = MAX_HEAP_SIZE;
	source->size     = 0;

    #ifdef DEBUG_LEVEL_01
	   if ( source->values != NULL ) {
	      printf("MAX_HEAP_SIZE          = [%d]      \n", MAX_HEAP_SIZE);
	      printf("sizeof *source->values = [%d]      \n", (sizeof *source->values));
	      printf("Size of Values array   = [%d] bytes\n", MAX_HEAP_SIZE * (sizeof *source->values));
       }
    #endif
	return ( source );
}

bool max_heap_empty(const max_heap *source)
//=========================================
// Heap is EMPTY if size of heap is ZERO. Otherwise, heap is NOT empty.
{
	bool empty_status;

	if ( source->size == 0 ) empty_status = TRUE;
	else                     empty_status = FALSE;
	return ( empty_status );
}

bool max_heap_full(const max_heap *source)
//========================================
// TRUE if Heap is full, that is, if capacity = size
{
	bool full_status;
	if ( source->size == source->capacity ) full_status = TRUE;
	else                                    full_status = FALSE;
	return ( full_status );
}

int max_heap_size(const max_heap *source)
//=======================================
{
	return (source->size);
}

int max_heap_peek(const max_heap *source)
//=======================================
{
	int return_val;
	//assert(source->size > 0);                                // Cannot peek on an empty heap.

	return_val = -999999;                                      // Have to return something, if heap is EMPTY!
	if ( source->size > 0 ) return_val = *source->values;      // values[0]

	return ( return_val );
}

bool max_heapify(max_heap *source,
		         int       keys[],
				 int       num_keys)
//==================================
// NOTE: Function Not currently used in this lab!
{
   bool heapify_status;

   if ( num_keys > source->capacity ) {
	  heapify_status = FAILURE;

   }else {
      for (int i = 0; i < num_keys; i++) {
	     max_heap_insert(source, keys[i]);
      }
      heapify_status = SUCCESS;
   }
   return ( heapify_status );
}

bool max_heap_insert(      max_heap *source,
		             const int       value )
//==========================================
{
	bool insert_status;

    #ifdef DEBUG_LEVEL_01
       printf(">>> In max_heap_insert()\n");
    #endif

	if ( source->size >= MAX_HEAP_SIZE ) {
	   insert_status = FAILURE;             // Cannot insert because have exceeded declared size of Heap storage;
	}else {

       // ************ <your code here> *****************************
	   // ************ ================ *****************************
	   int *p = source->values;
	   *(p+source->size) = value;
	   source->size++;
	   heapify_up(source);

	   insert_status = SUCCESS;             // SUCCESS;
	}
    #ifdef DEBUG_LEVEL_01
	   printf("<<< Returning from max_heap_insert()\n");
    #endif

	return ( insert_status );
}

void heapify_up(max_heap *source)
//======================================
// Moves a value from location index up the heap until
// it is in its correct location in the heap.
{
	#ifdef DEBUG_LEVEL_01
	   printf(">>> In heapify_up()\n");
    #endif

	// ************ <your code here> *****************************
	// ************ ================ *****************************
	int *p = source->values;
	
	int i = source->size-1;
	int j = (i-1)/2;



	while(i != 0){
		if(*(p+j) < *(p+i)){
			heap_swap((p+j), (p+i));
			i = j;
			j = (i-1)/2;
		} else {
			break;
		}

	}

    #ifdef DEBUG_LEVEL_01
       printf("<<< Returning from heapify_up()\n");
    #endif

    return;
}

/**
  * Moves a value down a heap to its correct position.
 * @param source pointer to a heap.
 */
void heapify_down(max_heap *source)
//=================================
// NOTE: Function not currently used in this lab.
{

	return;
}


void heap_swap(int *a,
		       int *b)
//====================
{
	int  temp;

	temp = *a;
	*a   = *b;
	*b   = temp;
	return;
}

void heap_nice_print(max_heap *source)
//====================================
{
   int max_lvl;                             // Max. level of heap for given heap size: [0,1,2,3,...]
   int lvl;                                 // Current level
   int Lidx;                                // Left-Index of heap array in current level.
   int Ridx;                                // Right-Index of heap array in current level.
   double epsilon;                          // Rounding error compensation value.
   epsilon = 0.00000001;

   printf("\n");
   printf("Heap Structure:\n");
   printf("============== \n");

   if (source->size == 0) {
	  printf("::: Heap is EMPTY!\n");
   }else {
	                                         // Calculate maximul level of heap, for given heap size, taking care to
	                                         // incorporate a fix for the rounding error in log2 calculation.
      max_lvl = (int)(log(source->size)/log(2.0) + epsilon);

      for (lvl = 0; lvl <= max_lvl; lvl++) { // Loop through all levels, lvl being the current level of heap.

         Lidx = (int)pow(2.0, lvl) - 1;                     // Calculate the Left index and the Right index for the current heap level.
         Ridx = (int)fmin( 2*Lidx, source->size -1);

         for (int i = Lidx; i <= Ridx; i++) {               // Print all array values of the current level, on the same output line.
    	    printf("%d  ", source->values[i]);
         }
         printf("\n");
      }
      printf("\n");
   }
   return;
}
