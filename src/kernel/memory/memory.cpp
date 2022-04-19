#include <cmath/cmath.h>
#include <cstring/cstring.h>
#include <drivers/memory/memory_manager_driver.h>
#include <kernel.h>
#include <memory/memory.h>

/**
 * Initializes the memory after the kernel that stores information about allocated memory,
 * by setting every byte to 0 (null)
 *
 * @param start       The start address of the block data
 * @param block_count The total number of blocks
 *
 * @returns a pointer to the beginning of the block data
 */
void initialize_memory_blocks(uint8_t* start, uint32_t block_count)
{
  // Zero out all the data for the memory blocks, setting each block as not allocated
  memset(start, 0, block_count * sizeof(MemoryBlock));
}
