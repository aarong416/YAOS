#ifndef _KERNEL_H
#define _KERNEL_H

#define MAX_MEMORY_NODES 64

#include <cstdint.h>
#include <multiboot/multiboot2.h>

using namespace std;

extern "C" void kernel_main();
extern uint8_t* kernel_end;

struct KernelInfo {
  uint8_t* kernel_end;
  uint8_t* heap_start;
  uint32_t heap_size;
};

// KernelInfo kernel_info;

#endif
