#ifndef CSTDLIB_H
#define CSTDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define NULL ((void*) 0)
#define RAND_MAX 4294967296

#define BLOCK_SIZE 4096

#include <cstdint.h>

typedef unsigned long size_t;

void* malloc(size_t size);
void free(void* ptr);

char itoa(int value, char* s, int base);
void itoh(int n, char* s);

#endif
