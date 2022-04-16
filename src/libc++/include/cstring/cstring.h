#ifndef CSTRING_H
#define CSTRING_H

#define NULL ((void*) 0)

#include <cstdint.h>

typedef unsigned long size_t;

void* memcpy(void* destination, void* source, size_t num);
char* strcpy(char* destination, const char* src);
char* strncpy(char* destination, const char* src, size_t num);

size_t strlen(const char* str);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);
char* strrev(char* s);

#endif