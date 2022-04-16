#ifndef MEMORY_MANAGER_DRIVER_H
#define MEMORY_MANAGER_DRIVER_H

#define BLOCK_SIZE 4096

#include <cmath/cmath.h>
#include <cstddef.h>
#include <drivers/driver.h>

struct MemoryBlock {
  bool allocated;
  uint32_t block_count;
};

struct FoundBlock {
  uint32_t index;
  uint32_t block_count;
};

template <uint32_t heap_size> class MemoryManagerDriver : public Driver
{
public:
  MemoryManagerDriver<heap_size>(uint32_t heap_start);

  MemoryBlock findFreeBlock();
  void* allocate(size_t n);
  void deallocate(void* ptr);
  FoundBlock indexFromHeapPointer(void* ptr);

private:
  uint32_t m_heap_start;
  uint32_t m_index = 0;
  MemoryBlock m_memory_blocks[(uint32_t) floor(heap_size / BLOCK_SIZE)];
};

#endif
