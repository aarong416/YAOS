#include <cmath/cmath.h>
#include <drivers/memory/memory_manager_driver.h>

void MemoryManagerDriver::initialize(uint8_t* block_data_start, uint32_t block_count,
                                     uint8_t* heap_start, uint32_t heap_size)
{
  Driver("memory_manager", "The Kernel's dynamic memory manager", DriverType::MemoryManager);

  m_blocks = ((MemoryBlock**) block_data_start);
  m_heap_start = heap_start;
  m_heap_size = heap_size;
  m_max_block_count = block_count;
}

/**
 * Finds the first free memory block
 *
 * - is the block allocated?
 *   - yes: increase the index by the number of allocated blocks
 *   - no: is the requested number of blocks == 1?
 *     - yes: return the index of the free block
 *     - no: are any of the next b blocks allocated?
 *       - yes: increase the index by the number of stored blocks
 *       - no: return the index of the free block
 *
 * @returns The index of the first free block
 */
uint32_t MemoryManagerDriver::findFreeBlock(uint32_t block_count)
{
  uint32_t index = m_index;
  bool block_found = false;

  while (!block_found) {
    // Don't try searching past the end of the heap.
    // m_max_block_count - 1 since index is always 1 less than the max block count.
    if (index >= (m_max_block_count - 1)) {
      return m_max_block_count;
    }

    MemoryBlock* block = m_blocks[index];

    /* The block has been allocated, move on */
    if (block->allocated) {
      index += block->block_count;

      continue;
    }

    /* A free block has been found */

    // If the requested number of blocks is 1, exit the loop
    if (block_count == 1) {
      block_found = true;
    } else {
      // Determines whether any of the next `block_count` blocks have been allocated.
      // If any of the blocks have been allocated, we can't use them, since
      // the exact requested block count is required to allocate memory.
      bool any_block_allocated = false;

      // Iterate over the next `block_count` blocks and determine
      // if any of them have been allocated.
      //
      // Don't check if the current block has been allocated, since
      // the statement will always be true in this (else) code block.
      for (uint32_t i = 1; i < block_count; i++) {
        MemoryBlock* innerBlock = m_blocks[index + i];

        if (innerBlock->allocated) {
          any_block_allocated = true;

          break;
        }
      }

      // If any of the next `block_count` blocks have been allocated, we cannot use them.
      // Increase the index by the requested number of blocks (plus 1 to go to the
      // next block following the last block checked).
      if (any_block_allocated) {
        index += block_count;

        continue;
      } else {
        // None of the following `block_count - 1) blocks were allocated,
        // so the block at `index`, and its subsequent blocks, can be used
        // for allocating memory
        block_found = true;
      }
    }
  }

  return index;
}

/**
 * Allocates memory on the heap
 *
 * 1. Find the first free block
 * 2. Set the allocated byte for each requested block
 * 3. Store the number of allocated blocks in the first block, while zeroing the subsequent blocks
 * 4. Return a pointer to the beginning of the allocated memory
 *
 * @param n The number of bytes to allocate
 *
 * @returns A pointer to the allocated data
 */
void* MemoryManagerDriver::allocate(size_t n)
{
  if (n == 0) {
    return NULL;
  }

  uint32_t block_count = ceil(n / BLOCK_SIZE);
  uint32_t block_index = findFreeBlock(block_count);

  // Make sure that the block index is not past the end of the heap.
  // m_max_block_count - 1 since index is always 1 less than the max block count.
  if (block_index > (m_max_block_count - 1)) {
    return NULL;
  }

  // Set the allocated byte for each requested block, but only store
  // the block count in the first block, zeroing the stored block
  // count for each subsequent (`block_count` - 1) blocks
  for (uint32_t i = 0; i < block_count; i++) {
    MemoryBlock* block = m_blocks[block_index + i];

    block->allocated = true;
    block->block_count = (i == 0) ? block_count : 0;
  }

  // Increase the search index so that none of the allocated blocks are searched
  // again in the next call to findFreeBlock()
  m_index = block_index + block_count;

  // Return a pointer to the beginning of the allocated memory on the heap
  return heapAddressFromIndex(block_index);
}

/**
 * Deallocates a previously allocated block or blocks of memory.
 *
 * 1. Get the index of the memory block that corresponds with
 *    the address pointer to by `ptr`
 * 2. If there are block to deallocate, deallocate all subsequent
 *    blocks that have been allocated
 *
 * @param ptr The address of the memory to deallocate
 */
void MemoryManagerDriver::deallocate(void* ptr)
{
  uint32_t index = getIndexFromHeap(ptr);

  // Don't try deallocating a block of memory that doesn't exist.
  // `index` will only be greater than `m_max_block_count` if an error occurred.
  // `m_max_block_count` - 1 since index is always 1 less than the max block count.
  if (index > (m_max_block_count - 1)) {
    return;
  }

  MemoryBlock* first_block = m_blocks[index];

  // Only deallocate a block if it has already been allocated
  if (!first_block->allocated) {
    return;
  }

  // Deallocate the first block
  first_block->allocated = false;
  first_block->block_count = 0;

  // Deallocate all subsequent blocks
  for (uint32_t i = 1; i < first_block->block_count; i++) {
    MemoryBlock* next_block = m_blocks[index + i];

    next_block->allocated = false;
    next_block->block_count = 0;
  }
}

/**
 * Calculates the index of the data block representing the allocated memory
 * pointed to by `ptr`.
 *
 * The index is calculated with the following expression:
 *
 * index = (pointer address - heap start) / BLOCK_SIZE
 *
 * @param ptr A pointer to an address on the heap
 *
 * @returns The index in `m_blocks` to which `ptr` corresponds.
 *
 *          If `heap start < ptr < heap end` is not true (not in the heap range),
 *          then an index greater than the maximum number of blocks that can be
 *          allocated will be returned, indicating an error, since no such
 *          index exists for the address that this pointer points to.
 */
uint32_t MemoryManagerDriver::getIndexFromHeap(void* ptr)
{
  // Convert the pointer to a char so that pointer address can be added and compared
  uint8_t* ptr_char = (uint8_t*) ptr;

  // The pointer is out of range of the heap, so return an index greater the the
  // maximum number of blocks that can be allocated, indicating an error
  if (ptr_char > (m_heap_start + m_heap_size)) {
    return m_max_block_count;
  }

  // `ptr` should always be divisible by `BLOCK_SIZE`. If it is not,
  // it means that a pointer was passed to this function that was not
  // returned from a call to allocate(), or its address was altered,
  // and the result will be a decimal value, but the decimal will be
  // lost since the function returns an integer.
  return ((uint8_t*) ptr - m_heap_start) / BLOCK_SIZE;
}

/**
 * Returns the memory address on the heap that corresponds with the given index
 *
 * @param index The index into m_blocks
 *
 * @returns The memory address on the heap
 */
uint8_t* MemoryManagerDriver::heapAddressFromIndex(uint32_t index)
{
  return (m_heap_start + (index * BLOCK_SIZE));
}
