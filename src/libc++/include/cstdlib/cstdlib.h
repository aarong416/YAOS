#ifndef CSTDLIB_H
#define CSTDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define NULL         ((void*) 0)
#define RAND_MAX     4294967296

#define BLOCK_SIZE   4096

#include <cstdint.h>

// The end of the kernel, from where we can start dynamically allocating memory
extern std::uint32_t kernel_end;

/**
 * A MemoryNode represents an allocated
 * memory block. The node states whether the area
 * of memory has been allocated, and how many blocks
 * have been allocated.
 */
struct MemoryNode {
  bool          allocated;
  std::uint32_t num_blocks;
};

typedef unsigned long size_t;

void* malloc(size_t size);
void free(void* ptr);

char itoa(int value, char* s, int base);

#endif
