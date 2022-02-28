/*
 -------------------------------------------------------
 main.c
 Tests various linked structures.
 -------------------------------------------------------
 Author:       Heider Ali & David Brown
 ID:           987654321
 Email:        heali@wlu.ca & dbrown@wlu.ca
 Version:      2019-06-22
 Modified:     2022-02-25
 -------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/resource.h>

#include "data.h"
#include "int_data.h"
#include "tests.h"

/**
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
//==============================
{
	setbuf(stdout, NULL);

	bst_test();

	return (0);
}

