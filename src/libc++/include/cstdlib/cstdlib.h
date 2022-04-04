#ifndef CSTDLIB_H
#define CSTDLIB_H

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1
#define NULL         ((void*) 0)
#define RAND_MAX     4294967296

#define BLOCK_SIZE   4096

#include <cstdint.h>

/**
 * A MemoryNode represents one or more allocated
 * memory blocks. The node states whether the area
 * of memory has been allocated, and how many blocks
 * have been allocated.
 */
struct MemoryNode {
  bool allocated;
  std::uint32_t num_blocks;
};

extern std::uint32_t kernel_end;

namespace std {
  typedef unsigned long size_t;

  void* malloc(size_t size);
  void free(void* ptr);
}

#endif
