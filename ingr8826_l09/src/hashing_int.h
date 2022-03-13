/*
-------------------------------------
File:    hashing_int.h
Project: CP264_Lab10_Hashing_201909
file description
-------------------------------------
Author:  Rick Magnotta
ID:      989002582
Email:   rmagnotta@wlu.ca
Version  2019-11-14
-------------------------------------
 */
#ifndef HASHING_INT_H_
#define HASHING_INT_H_

#include "My_Definitions.h"
                                //:::::::::::::: Function Prototypes
/**
 * Initializes the "hash_table" 1D-array of size HASH_TABLE_SIZE to (int)NULLs.
 * @param hash_table
 * @param HASH_TABLE_SIZE
 */
void initialize_hash_table(int hash_table[],
                           int MAX_HASH_TABLE_SIZE);

/**
 * Asks user to input an "integer" Key/Value and inserts its value into the "hash_table"
 * @param hash_table
 * @param HASH_TABLE_SIZE
 * @return TRUE if successful insertion, FALSE otherwise.
 */
bool insert_hash_table (int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

/**
 * Displays the "current" contents of the "hash_table".
 * @param hash_table
 * @param HASH_TABLE_SIZE
 */
void display_hash_table(int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

/**
 * Asks user to input an "integer" Key/Value and searches the "hash_table" for its value.
 * @param hash_table
 * @param HASH_TABLE_SIZE
 * @return TRUE if found, FALSE otherwise.
 */
bool search_hash_table (int hash_table[],
                        int MAX_HASH_TABLE_SIZE);

#endif /* HASHING_INT_H_ */
