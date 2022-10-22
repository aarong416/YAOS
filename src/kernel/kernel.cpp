#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <kernel.h>
#include <logging/logger.h>

void setup_drivers()
{
  // Set up the TTY driver first so that we can write to the screen
  // as early as possible
  // TtyDriver tty(false);

  // // TODO: get the size of avaialable memory from GRUB
  // uint32_t heap_size = 100 * 1024 * 1024;
  // uint8_t* block_data_start = kernel_end;
  // uint32_t block_count = ceil(heap_size / BLOCK_SIZE);
  // uint8_t* heap_start = block_data_start = (uint8_t*) (sizeof(MemoryBlock) * block_count);

  // // memset(kernel_end, 0, block_count * sizeof(MemoryBlock));

  // MemoryManagerDriver* memory_manager = (MemoryManagerDriver*) kernel_end;

  // memory_manager->initialize(kernel_end, block_count, heap_start, heap_size);

  // // (kernel_end, 3000, kernel_end, 3000);

  // Driver* drivers[1];

  // drivers[0] = memory_manager;

  // // Store the drivers in memory directly after the kernel
  // DriverManager::initialize(kernel_end + sizeof(MemoryManagerDriver), &tty, drivers);

  // kernel_info.heap_start = initialized_memory.heap_start;
  // kernel_info.heap_size = heap_size;
}

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  // Set up and install all drivers
  // setup_drivers();

  TtyDriver tty(true);
  MemoryManagerDriver* memory_manager;

  Driver drivers[2] = {tty, *memory_manager};

  tty.writeLine("Hello, world!");

  // Logger::log("Logging statement here");

  // Driver** drivers = DriverManager::getAllDrivers();

  // for (int i = 0; i < 2; i++) {
  //   Driver* driver = drivers[i];

  //   if (driver != nullptr) {
  //     tty->write("Name: ");
  //     // tty->writeLine(driver->getName());

  //     // tty->write("Description: ");
  //     // tty->writeLine(driver->getDescription());

  //     // tty->write("Status: ");
  //     // tty->writeLine(driver->isInstalled() ? "Installed" : "Not installed");

  //     // tty->writeLine("");
  //   }
  // }

  // dump((void*) tty_driver, 400);
}
