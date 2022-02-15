/*
-------------------------------------
File:    name_list.c
Project: 202201_CP264_Lab06_Queues_Stacks
file description: Source file.
-------------------------------------
Author:  Heider Ali and Rick Magnotta
ID:      xxxxxxxxx
Email:   heali@wlu.ca / rmagnotta@wlu.ca
Version  2020-02-06
Modified 2022-02-11
-------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"
#include "utility_library.h"
#include "name_list_2.h"

 void initialize_name_list(sNAME_LIST *name_list)   // List of names to process.
 //==============================================
 // This routine initializes the "name_list" header node as follows:
 //    - The front and rear pointers set to NULL because the list does NOT contain any nodes, i.e. names.
 //    - The count field is set to ZERO for the same reason.
 {
 static char pname[] = "initialize_name_list";

    push(pname);

    if ( name_list != NULL ) {            // Storage for "name_list" header created successfully.

	   name_list->front = NULL;           // set front of list pointer to NULL pointer.
	   name_list->rear  = NULL;           // set rear  of list pointer to NULL pointer.
	   name_list->count = 0.0;            // list has ZERO names initially.

    }else {
       sprintf(msg[0], "%s%s", "In Function: ", pname);
       sprintf(msg[1], "%s",   "Internal Error: Storage for name_list header node NOT allocated!");
       report_message(msg, MSG_ERROR_FATAL);
    }
    pop();
    return;
 }

 void insert_name_list(sNAME_LIST *name_list,    // List of names to insert into.
                         sNODE    *node     )    // Node to insert in list, if not already present.
 //==========================================
 // Given the name_list and a node, this function inserts the node into the list, but only if the name in the node is not
 // already present in the list. In other words, only UNIQUE names are inserted.
 // A new Node is inserted by appending it at the end of the list, thereby preserving the input name order.
 {
 static  char pname[] = "insert_name_list";
 sNODE  *p_last;                                     // Local pointer used to point to the LAST node in the list.

                                                     // Prototype for "name_in_list(...) subprogram, called from this routine.
                                                     // It scans the name_list, searching for the presence of "node".
 bool name_in_list(const sNAME_LIST *name_list,
                   const sNODE      *node     );

    push(pname);                                     // Push the subprogram name onto the "call_pname" stack to indicate that
                                                     // we are currently executing in the "pname" subprogram.

    if ( name_list != NULL ) {                       // List exists. That is, it's been created.

   	   if ( !name_in_list( name_list, node ) ) {
   		                                             // Name is NOT in the "name_list", so let's add it to the list.
   	      node->next = NULL;

   	      if ( name_list->front == NULL ) {
   		                                             // Case of empty list.
             name_list->front = node;
   	         name_list->rear  = node;
   	      }else {
   		                                             // List has at least ONE name.
   	    	 p_last          = name_list->rear;
   	    	 p_last->next    = node;
   		     name_list->rear = node;
   	      }
   	      name_list->count++;                        // We have added a new name to the list.
       }else {
       	                                       // Name already present in the list, so free storage for the node
    	                                       // and NULL the node pointer because its content is no longer a valid address.
       	  free(node);
       	  node = NULL;
       }
    }else {
   	   sprintf(msg[0], "%s%s", "INTERNAL Error in function: ", pname);
   	   sprintf(msg[1], "%s",   "Node not inserted because list does not exist!");
   	   report_message(msg, MSG_ERROR_FATAL);
    }
    pop();                                     // Pop the "pname" from the "call_pname" stack since we are leaving
                                               // this subprogram.
    return;
 }

 bool name_in_list(const sNAME_LIST *name_list,    // List of names to insert into.
                   const sNODE      *node     )    // Node to insert in list, if not already present.
 //============================================
 // Given the "name_list" linked list of names, and the name (i.e. sNODE) to search, this routine returns
 // TRUE if the name is in the list, FALSE otherwise.
 {
 static char pname[]   = "name_in_list";

 int    n_checked;                             // Number of nodes checked!
 bool   FOUND_MATCH;                           // TRUE if match found, FALSE otherwise.
 sNODE *p_scan;                                // Scan pointer to scan "name_list".

 bool compare_names(const sNAME *list_name,    // Prototype for "compare_names(...)" routine.
		            const sNAME *new_name );

    push(pname);

    FOUND_MATCH = FALSE;                       // Don't have a match at this point.

    if ( name_list != NULL ) {                 // Check if list exists. That is, if it's been created.

 	  if ( (name_list->front != NULL) &&
           (name_list->rear  != NULL) &&
           (name_list->count > 0    )   ) {    // List is NOT empty, so let's search. Note: if list is empty, then this
                                               // routine returns a value of FOUND_MATCH = FALSE, as required!
 		 p_scan      = name_list->front;
 		 n_checked   = 0;
 		 FOUND_MATCH = FALSE;
 		                                                              // Scan the name_list searching for a match, and STOP as
 		                                                              // soon as a match is found, or have checked every name in list.
         while ( (n_checked < name_list->count) && !FOUND_MATCH) {
         	                                                          // Call the "compare_names(...)" routine to do the actual
        	                                                          // work of comparing names.
            FOUND_MATCH = compare_names(&p_scan->name, &node->name);

         	n_checked++;
         	p_scan = p_scan->next;
         }
 	  }
    }else {
   	  sprintf(msg[0], "%s%s", "INTERNAL Error in function: ", pname);
   	  sprintf(msg[1], "%s",   "Node not searched in list because list does not exist!");
   	  report_message(msg, MSG_ERROR_FATAL);
    }
    pop();
    return ( FOUND_MATCH );
 }

 bool compare_names(const sNAME *list_name,    // Current "name_list" member name that is being compared.
		            const sNAME *new_name )    // New name being compared with list_name.
 //========================================
 // Given the two "sName" structures, list_name and new_name, this subprogram compares the members of these structures.
 // Namely, first_name and last_name. It returns TRUE if the list_name and new_name are the same name.
 // FALSE otherwise.
 {
 static char pname[] = "compare_names";
 bool   EQUAL_NAMES;

    push(pname);

    EQUAL_NAMES = FALSE;                           // Assume that the list_name and new_name ARE NOT the same.

    if ( list_name == NULL ) {
    	                                           // Check that we have a name to compare.
       sprintf(msg[0], "%s%s", "INTERNAL FATAL Error in function: ", pname);
       sprintf(msg[1], "%s",   "sNAME *list_name pointer is NULL!");
       report_message(msg, MSG_ERROR_FATAL);

    }else if ( new_name == NULL ) {
    	                                           // Check that we have a target name to compare.
       sprintf(msg[0], "%s%s", "INTERNAL FATAL Error in function: ", pname);
       sprintf(msg[1], "%s",   "sNAME *new_name pointer is NULL!");
       report_message(msg, MSG_ERROR_FATAL);

    }else {
    	                                           // We have data (i.e. names) to compare. So, let's compare the names.
       if ( sEQ(list_name->first_name, new_name->first_name) &&
            sEQ(list_name->last_name,  new_name->last_name )   ) EQUAL_NAMES = TRUE;
    }

    if ( g_SIMULATE_FATAL_ERROR ) {                // Special global flag set to TRUE when simulating a FATAL ERROR condition.
    	 sprintf(msg[0], "%s%s", "INTERNAL FATAL Error in function: ", pname);
    	 sprintf(msg[1], "%s",   "Simulating a FATAL ERROR condition.");
    	 report_message(msg, MSG_ERROR_FATAL);
    }
    pop();
    return (EQUAL_NAMES);
 }

 int output_name_list(const sNAME_LIST *name_list)          // Linked list of names.
 //===============================================
 // Traverse the entire given list of names "name_list" and print it's contents.
 {
 static char pname[] = "output_name_list()";
 int    n_printed;                                          // Number of names output/printed.
 sNODE *p_scan;                                             // Scan pointer used to traverse the "name_list".

    push(pname);
    if ( name_list != NULL ) {                              // Check for undefined/non-existent "name_list".

       if ( (name_list->front != NULL) &&
    		(name_list->rear  != NULL) &&
    		(name_list->count > 0    )   ) {                // Check for empty list.
    	                                                    // ===>List is NOT EMPTY, so let's print it's contents.
          printf(NL);
          printf("List of Names with duplicates REMOVED:\n");     // Always nice to label the output with a descriptive heading.
          printf("======================================\n");

          n_printed = 0;
          p_scan    = name_list->front;                     // Set p_scan to point to the first node in the last.
          while ( n_printed < name_list->count ) {          // Traverse the name_list from beginning to end and output
    	                                                    // the data content of each node.
    	     printf("%s %s %d\n", p_scan->name.first_name,
    		                   p_scan->name.last_name, p_scan->bank);
    	     n_printed++;                                   // Update the counter to keep track of the no. of names printed.
 	         p_scan = p_scan->next;                         // Update the scan pointer to point to the next node.
          }
       }else {
          sprintf(msg[0], "%s%s", "In Function: ", pname);
          sprintf(msg[1], "%s",   "List is EMPTY! Nothing to output/print.");
          report_message(msg, MSG_INFO);
       }
    }else {
       sprintf(msg[0], "%s%s", "In Function: ", pname);
       sprintf(msg[1], "%s",   "Internal Error: List not printed because it does not exist!");
       report_message(msg, MSG_ERROR_NONFATAL);
    }
    pop();
    return (n_printed);
 }

 int free_name_list(sNAME_LIST *name_list )    // Linked list to free its storage.
 //========================================
 // Given the Single-Linked list "name_list", this subprogram CLEANS the list. That is, it frees all of the nodes in the list,
 // including the header node.  It returns a count of the number of nodes freed, and a NULLed name_list pointer.
 {
 static char pname[] = "free_name_list()";

 int    n_freed;                               // Count of number of nodes "freed", including header node.
 sNODE *p_ntf;                                 // Pointer to next "Node-To-Free", or node to "clean".

   push(pname);

   n_freed = 0;
   if ( name_list != NULL ) {                  // Check for undefined/non-existent "name_list".

      if ( (name_list->front != NULL) &&
           (name_list->rear  != NULL) &&
           (name_list->count > 0    )   ) {    // Check for empty list
     	                                       // ==> List is NOT empty!
         while ( name_list->front != name_list->rear ) {
     		                                   // Traverse the name_list from front to rear, and free every node encountered.

 	        p_ntf = name_list->front;         // p_ntf points to the next node to free. This is always the first node in the list.

 	        name_list->front = p_ntf->next;   // "de-link" (i.e. drop/remove) the p_ntf node from the list.
                                                // The node following the p_ntf node is now at the front of the list.

 	        free(p_ntf);                      // free the de-linked p_ntf node.
 	        n_freed++;                        // update freed counter.
         }
     	 free( name_list->front );            // Free the last remaining node in the list.
     	 n_freed++;

      }else {
         sprintf(msg[0], "%s%s", "In Function: ", pname);
         sprintf(msg[1], "%s",   "List is EMPTY! Only header node freed.");
         report_message(msg, MSG_INFO);
      }
      free(name_list);                        // Free header node.
      name_list = NULL;                       // Null the "name_list" pointer because it's content address is no longer valid.
      n_freed++;

   }else {
      sprintf(msg[0], "%s%s", "In Function: ", pname);
      sprintf(msg[1], "%s",   "Internal Error: List not freed because it does not exist!");
      report_message(msg, MSG_ERROR_NONFATAL);
   }
   pop();
   return (n_freed);
}


