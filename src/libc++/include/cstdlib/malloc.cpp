#include <cmath/cmath.h>
#include <cstdint.h>
#include <cstdlib/cstdlib.h>
#include <drivers/driver_manager.h>
#include <drivers/tty_driver.h>

uint8_t* pos = (uint8_t*) &kernel_end;

// Make sure the first byte on the stack is not allocated

void* malloc(size_t size)
{
  if (size == 0) {
    return (void*) NULL;
  }

  bool block_found = false;

  /* Keep looping over the blocks until we find a free block.
   * If the block is not free, increase pos, otherwise
   * return a pointer to the beginning of the block (after the header)
   */
  while (!block_found) {
    /* If the allocated bit is not set, set it and store the number of blocks
     * needed as a short */
    MemoryNode* node = (MemoryNode*) pos;

    if (!node->allocated) {
      node->allocated = true;

      /* Calculate the number of blocks needed based on the requested size, and
       * store it. If the size requested is a multiple of BLOCK_SIZE, do not
       * round up the number of blocks needed, otherwise round it up.
       */
      uint32_t blocks_needed = (size % BLOCK_SIZE) == 0
                                 ? (size / BLOCK_SIZE)
                                 : ceil(size / BLOCK_SIZE);

      node->num_blocks = blocks_needed;

      /* We have found a block, exit the loop */
      block_found = true;
    } else {
      /* Retrieve the number of allocated blocks */
      uint32_t blocks_allocated = node->num_blocks;

      /* Increase pos by the number of allocated blocks * BLOCK_SIZE */
      pos += (blocks_allocated * BLOCK_SIZE) + (blocks_allocated * 5) + 5;
    }
  }

  /* Returns a pointer to the beginning of the block (after the header) */
  return (pos + 5);
}
