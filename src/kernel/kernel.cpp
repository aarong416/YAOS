#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <kernel.h>
#include <logging/logger.h>

// Information that is important for the kernel
KernelInfo kinfo = {};

TtyDriver tty;

void setup_drivers()
{
  tty = TtyDriver();
  MemoryManagerDriver memoryManagerDriver(kinfo.mm_start, kinfo.heap_block_count, kinfo.heap_start,
                                          kinfo.heap_size);

  DriverManager::installDriver(&tty);
  DriverManager::installDriver(&memoryManagerDriver);
}

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

  // SEPARATOR
  // SEPARATOR
  // SEPARATOR

  setup_drivers();

  // tty.writeLine(tty.getName());

  TtyDriver* tty = (TtyDriver*) DriverManager::getDriver("tty");

  tty->write("Installed drivers (");
  tty->writeInt(DriverManager::getDriverCount());
  tty->writeLine("):");

  Driver** drivers = DriverManager::getAllDrivers();

  for (uint8_t i = 0; i < DriverManager::getDriverCount(); i++) {
    Driver* driver = drivers[i];

    tty->write("  ");
    tty->write(driver->getName());
    tty->write(": ");
    tty->writeLine(driver->getDescription());
  }
}
