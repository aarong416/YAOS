#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/memory/memory_manager_driver.h>
#include <iostream/iostream.h>
#include <kernel.h>
#include <setup/setup.h>

// Information that is important for the kernel
KernelInfo kinfo = {};

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  uint32_t memory_size = 64 * 1024 * 1024;       // TODO: get this from GRUB
  uint32_t heap_size = memory_size * (10 / 100); // The heap is currently 10% of the total memory
  uint32_t heap_block_count = floor(heap_size / BLOCK_SIZE);

  kinfo.end = kernel_end;
  kinfo.heap_size = heap_size;

  kinfo.mm_start = (uint8_t*) memset(kinfo.end + 1, 0, heap_block_count * sizeof(MemoryBlock));
  kinfo.heap_start = kinfo.mm_start + (heap_block_count * sizeof(MemoryBlock));
  kinfo.heap_block_count = heap_block_count;

  setupDrivers(kinfo);
  setupHardwareCursor(0, 15);

  std::cout << "YAOS booted\n\n";
}
