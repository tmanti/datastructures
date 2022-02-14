/*
-------------------------------------
File............: Lab06_solution_main.c
Project.........: 202201_CP264_Lab06_Queues_Stacks_GivenCode
file description: Mainline program.
-------------------------------------
Author:  Heider Ali and Rick Magnotta
ID:      xxxxxxxxx
Email:   heali@wlu.ca / rmagnotta@wlu.ca
Version  2020-02-06
Modified 2022-02-11
-------------------------------------

Correct Output:
===============
(I) g_SIMULATE_FATAL_ERROR = TRUE;
-------------------------------------------------------------------

>>> ERR: INTERNAL FATAL Error in function: compare_names
       : Simulating a FATAL ERROR condition.


>>>>> :::::::::: Program Execution ABORTED :::::::::: <<<<<

>>>>> EXIT MAIN: ======= WITH FATAL ERROR(S) ==============


=====    Subprogram Calling Sequence    =====
=====       (Most recent at TOP)        =====
=============================================
compare_names
name_in_list
insert_name_list
main

------------------------------------------------------------------
------------------------------------------------------------------
(II) Output for Names2.txt
------------------------------------------------------------------
List of Names with duplicates REMOVED:
======================================
Heider Ali 1999
Shaun Gao 1999
David Brown 1998
Sukhjit Singh 1999
Iqbal Amin 1234
Eesha Kanwar 5678
Joseph Power 2468
Jakob Tsekrekos 1357
Iftekhar Mohammed 6666
Zane Hancock 9876
Danish Kumar 2478
Alinkumar Patel 9840

::> MSG: The list contains 12 unique names.
       : Number of names printed =  12

==> END: Program Terminated.
       : Have a great day.


------------------------------------------------------------------

Marking Scheme (Total 8 Marks):
==============  =============
- Correct Output .......................... = 2
  (with g_SIMULATE_FATAL_ERROR = TRUE)

- Push the subprogram name correctly on the
  "call_pname" stack....................... = 1

- Detect STACK OVERFLOW condition for the
  "call_pname" stack and print appropriate
  FATAL ERROR message...................... = 1

- Pop the subprogram name correctly from the
  "call_pname" stack....................... = 1

- Detect STACK UNDERFLOW condition for the
  "call_pname" stack and print appropriate
  FATAL ERROR message...................... = 1

- Enhance program to process the names2.txt
  input file............................... = 1

- Proper indentation,
  descriptive variable names,
  documentation/comments .................. = 1
                                             ---
                                      Total   8
Penalties:
=========
- Hard-coding                                 = -1
- Use of Break, Continue, Go To               = -1 (NOTE: Break allowed in "Switch" statement.)
  (i.e. Spaghetti code)
- Convoluted logic                            = -1
- Multiple "return" from main/subprogram      = -1
- Presence of Compiler Warnings               = -1
- ALL local subprogram variables MUST be
  declared at the beginning of the subprogram = -1  (Only exception: "for (int i=0; ...)"
  (not dispersed throughout subprogram body)

- NOTE: Program MUST Compile clean and MUST Execute, otherwise a mark of ZERO is given for the lab.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "rm_library.h"
#include "utility_library.h"
#include "name_list.h"

int main(int argc, char *argv[]) {
//================================
static char pname[] = "main";

setbuf(stdout, NULL);

char  filename_in[] = "names.txt";    // Input file name.
FILE  *fp_in        = NULL;           // Input file pointer.

int  input_status;                    // Holds status of "fscanf(...)" function.
int  num_printed;                     // Number of names printed/output.
int  return_val;                      // Main program return value to OS (Operating System).

sNODE      *p_node;                   // Declare a pointer to a node in the name_list.
sNAME_LIST *name_list;                // Declare name_list variable

   g_SIMULATE_FATAL_ERROR = FALSE;    // Set to TRUE to simulate a FATAL ERROR condition, set to FALSE otherwise.

   push(pname);
   return_val = 0;                              // Assume all is well.

   initialize_msg_buff(msg);                    // Initialize "msg" message buffer.


   name_list = (sNAME_LIST *)malloc(sizeof(sNAME_LIST));           // Instantiate/create the "name_list" header node.
   initialize_name_list(name_list);                                // Initialize the "name_list" header node.


   if ( (fp_in = fopen(filename_in, "r")) == NULL ) {              // Open input file and check if open is successful.

	  sprintf(msg[0], "%s%s", "Cannot open file ", filename_in);   // Core-to-Core I/O. Could have also used the strcat().
	  report_message(msg, MSG_WARNING);
	  return_val = -1;                                             // Get set to have Main return an ERROR condition to OS.

   }else {                                                         // File open was successful!

	  p_node = (sNODE *)malloc(sizeof(sNODE));                     // Instantiate/Create a sNODE.
                                                                   // Read the first line of the input file.
	  input_status = fscanf(fp_in, "%s%s", p_node->name.first_name,
			                               p_node->name.last_name);
	  while ( input_status != EOF ) {                              // Keep reading and inserting until reach EOF (End-Of-File).

		  insert_name_list(name_list, p_node);
	                                                               // Get ready to read next name from input file.
		  p_node = (sNODE *)malloc(sizeof(sNODE));                 // Must create/allocate storage for a new sNODE because the
		                                                           // previous node was either:
		                                                           //   1) inserted in the name_list, if name was not already in the list, or
		                                                           //   2) the "node" storage was freed/CLEANED, if name was a duplicate.
		  input_status = fscanf(fp_in, "%s%s", p_node->name.first_name,
		  			                           p_node->name.last_name);
	  }
      fclose(fp_in);                                               // Close input file "here" since it was opened successfully.

      num_printed = output_name_list( name_list );                 // Print list of UNIQUE names.

      sprintf(msg[0], "%s %d %s", "The list contains",name_list->count ,"unique names.");
      sprintf(msg[1], "%s %d",    "Number of names printed = ", num_printed);
      report_message(msg, MSG_INFO);

      free_name_list( name_list );                   // Don't forget to clean up ==> Free/Clean the name_list.
   }
                                                     // Print a program terminating message.
   sprintf(msg[0], "%s", "Program Terminated.");
   sprintf(msg[1], "%s", "Have a great day.");
   report_message(msg, MSG_END);

   pop();
   return (return_val);                              // Return to OS.
}
