#include <cmath/cmath.h>
#include <cstring/cstring.h>
#include <drivers/memory/memory_manager_driver.h>
#include <kernel.h>
#include <memory/memory.h>

/**
 * Initializes the memory after the kernel that stores information about allocated memory,
 * by setting every byte to 0 (null)
 *
 * @param start     The start address of the `m_blocks` data blocks
 * @param heap_size The size of the heap in bytes. The number of blocks is calculated from this
 *                  value
 *
 * @returns a pointer to the beginning of the block data
 */
InitializedMemory initialize_memory_blocks(uint8_t* start, uint32_t heap_size)
{
  /*
   * block_count:      the total number of blocks that can be allocated
   * block_data_count: the amount of bytes needed to store information
   *                    about the allocated blocks
   */
  uint32_t block_count = floor(heap_size / BLOCK_SIZE);
  uint32_t block_data_count = block_count * sizeof(MemoryBlock);

  // kernel_end is the beginning of the block data
  MemoryBlock** memory_blocks = (MemoryBlock**) start;

  // Zero out all the data for the memory blocks, setting each block as not allocated
  memset(memory_blocks, 0, block_data_count);

  // Return a struct containing pointers to the beginning of the data blocks,
  // and the beginning of the heap
  struct InitializedMemory initialized_memory;

  initialized_memory.block_data_start = start;
  initialized_memory.heap_start = kernel_end + block_data_count;
  initialized_memory.heap_size = heap_size;

  return initialized_memory;
}
