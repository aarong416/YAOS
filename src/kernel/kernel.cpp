#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <iostream/iostream.h>
#include <kernel.h>
#include <logging/logging.h>

// Information that is important for the kernel
KernelInfo kinfo = {};

TtyDriver tty;
MemoryManagerDriver memoryManager;

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

  setup_drivers();

  std::cout << "YAOS booted\n\n";
}

void setup_drivers()
{
  tty = TtyDriver();
  memoryManager = MemoryManagerDriver();

  Driver* drivers[2] = {&tty, &memoryManager};

  tty.initialize();
  memoryManager.initialize(kinfo.mm_start, kinfo.heap_block_count, kinfo.heap_start,
                           kinfo.heap_size);

  tty.write("[*] Installing drivers: ");

  uint32_t driver_count = sizeof(drivers) / sizeof(drivers[0]);

  for (uint32_t i = 0; i < driver_count; i++) {
    Driver* driver = drivers[i];

    DriverManager::installDriver(driver);

    // log(driver->getName(), false);
    std::cout << driver->getName();

    if (i != driver_count - 1) {
      // log(", ", false);
      std::cout << ", ";
    }
  }

  std::cout << "\n[+] Finished installing drivers\n\n";
}
