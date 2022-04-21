#include <cstdlib/cstdlib.h>
#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <kernel.h>
#include <logging/logger.h>
#include <memory/memory.h>

void setup_drivers()
{
  // Set up the TTY driver first so that we can write to the screen
  // as early as possible
  // TtyDriver tty(false);
  // DriverManager::installDriver(&tty);

  // // TODO: get the size of avaialable memory from GRUB
  // uint32_t heap_size = 100 * 1024 * 1024;

  // uint8_t* block_data_start = kernel_end;
  // uint32_t block_count = floor(heap_size / BLOCK_SIZE);
  // uint8_t* heap_start = block_data_start = (uint8_t*) (sizeof(MemoryBlock) * block_count);

  // initialize_memory_blocks(kernel_end, block_count);

  // MemoryManagerDriver memory_manager(block_data_start, block_count, heap_start, heap_size);

  // Driver drivers[] = {memory_manager};
  // Driver drivers[] = {};

  // Store the drivers in memory directly after the kernel
  // DriverManager::initialize(kernel_end, &tty, drivers);

  // kernel_info.heap_start = initialized_memory.heap_start;
  // kernel_info.heap_size = heap_size;
}

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  // kernel_info.kernel_end = kernel_end;

  // Set up and install all drivers
  // setup_drivers();

  TtyDriver tty(true);

  DriverManager::initialize(kernel_end, &tty, {});

  // TtyDriver* tty_driver = (TtyDriver*) DriverManager::getDriver("tty");

  // tty_driver->write("XAB");

  // TtyDriver tty(true);

  // tty.writeInt(kernel_end[62]);

  dump(kernel_end, 305, tty);
}
