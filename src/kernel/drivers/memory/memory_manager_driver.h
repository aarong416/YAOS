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

class MemoryManagerDriver : public Driver
{
  friend class Driver;

public:
  MemoryManagerDriver();
  void initialize(uint8_t* memory_block_array_start, uint32_t block_count, uint8_t* heap_start,
                  uint32_t heap_size);

  uint32_t findFreeBlock(uint32_t block_count);
  void* allocate(size_t n);
  void deallocate(void* ptr);

  // TODO: these methods should be private
  uint32_t getIndexFromHeap(void* ptr);
  uint8_t* heapAddressFromIndex(uint32_t index);

private:
  uint8_t* m_heap_start;
  uint32_t m_heap_size;
  uint32_t m_max_block_count; // The maximum number of blocks that can be allocated
  uint32_t m_index = 0;       // The index from which to start searching for a free block
  MemoryBlock** m_blocks;
};

#endif
