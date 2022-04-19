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
  // // DriverManager::installDriver(tty);

  // // TODO: get the size of avaialable memory from GRUB
  // uint32_t heap_size = 100 * 1024 * 1024;

  // uint8_t* block_data_start = kernel_end;
  // uint32_t block_count = floor(heap_size / BLOCK_SIZE);
  // uint8_t* heap_start = block_data_start = (uint8_t*) (sizeof(MemoryBlock) * block_count);

  // initialize_memory_blocks(kernel_end, block_count);

  // MemoryManagerDriver memory_manager(block_data_start, block_count, heap_start, heap_size);

  // Driver drivers[] = {memory_manager};

  // Store the drivers in memory directly after the kernel
  // DriverManager::initialize(kernel_end, drivers);

  // kernel_info.heap_start = initialized_memory.heap_start;
  // kernel_info.heap_size = heap_size;
}

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  // kernel_info.kernel_end = kernel_end;

  // Set up and install all drivers
  // setup_drivers();

  // TtyDriver tty(true);

  // DriverManager::initialize(kernel_end, &tty, {});

  // TtyDriver* tty_driver = (TtyDriver*) DriverManager::getDriver("tty");

  // tty_driver->write("XAB");

  // memset(kernel_end, 10, 100);

  // char s[5];

  // itoh('65', s);

  // TtyDriver tty(true);

  // tty.writeLine(s);

  kernel_end[0] = 'H';
  kernel_end[1] = 'e';
  kernel_end[2] = 'l';
  kernel_end[3] = 'l';
  kernel_end[4] = 'o';
  kernel_end[5] = ',';
  kernel_end[6] = ' ';
  kernel_end[7] = 'w';
  kernel_end[8] = 'o';
  kernel_end[9] = 'r';
  kernel_end[10] = 'l';
  kernel_end[11] = 'd';
  kernel_end[12] = '!';
  kernel_end[13] = '\0';

  kernel_end[20] = 'A';
  kernel_end[21] = 'B';
  kernel_end[22] = 'C';
  kernel_end[24] = 'Z';

  memset(kernel_end, 0, 100);

  dump(kernel_end, 41);

  // tty.writeLine("tty");
  // tty_driver->writeLine("tty_driver");
}
