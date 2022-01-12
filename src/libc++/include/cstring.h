#ifndef CSTRING_H
#define CSTRING_H

#define NULL ((void*) 0)

#include <cstdint.h>

typedef std::uint32_t size_t;

size_t strlen(const char* str);

#endif