/*
 ============================================================================
 Name        : main.c
 Author      : Thomas Ingram
 Description :
  ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	setbuf(stdout, NULL);                    // turns standard output buffering off

	int i;

   if ( argc == 1 ) {                    // No "User" program parameters specified.
      printf("\n");
      printf("::: NO \"USER\" Program Parameters Given/Specified!\n");
      printf(":::\n");
      printf("::: Argument 1 shown below is a SYSTEM DEFAULT, and is always passed to the MAIN program.\n");
      printf("::: NOTE: Argument 1 is ALWAYS the path/name of the \".exe\" executable file.\n");
      printf("\n");
      printf("argc    = [%3d]\n", argc   );
      printf("argv[0] = [%s]\n" , argv[0]);
      printf("\n");
   }else {                               // "User" program parameters specified.
      printf("\n");
      printf(":::::::::: Program Parameters :::::::::\n");
      printf("argc               argv[]              \n");
      printf("====   ================================\n");

      for (i=0; i<=argc; i++) {
         printf("%3d    %s\n", i, argv[i]);
      }
   }
   return 0;
}
