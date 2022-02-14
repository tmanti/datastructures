#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLLIST BIGINT;
void display_bigint(BIGINT bignumber);
BIGINT bigint(char *digitstr);
BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif