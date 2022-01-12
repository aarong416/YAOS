#ifndef CSTDLIB_H
#define CSTDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define NULL         ((void*) 0)
#define RAND_MAX     4294967296

#include <cstdint.h>

typedef std::uint32_t size_t;

void* malloc(size_t size);

#endif