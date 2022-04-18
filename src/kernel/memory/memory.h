#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint.h>

struct InitializedMemory {
  uint8_t* block_data_start;
  uint8_t* heap_start;
  uint32_t heap_size;
};

InitializedMemory initialize_memory_blocks(uint8_t* start, uint32_t heap_size);

#endif
