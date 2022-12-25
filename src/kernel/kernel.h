#ifndef _KERNEL_H
#define _KERNEL_H

#include <cstdint.h>
#include <multiboot/multiboot2.h>

using namespace std;

extern "C" void kernel_main();
extern uint8_t* kernel_end;

struct KernelInfo {
  uint8_t* end;              // The end of the kernel
  uint8_t* mm_start;         // The start of the memory manager driver
  uint32_t heap_block_count; // The total number of blocks in the heap
  uint8_t* heap_start;       // The start of the heap
  uint32_t heap_size;        // The size of the heap, in bytes
  uint8_t* fs_start;         // The starting address of the filesystem in memory
};

void setup_drivers();

#endif
