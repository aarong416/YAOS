#include <cstring/cstring.h>
#include <debugging/debugging.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <kernel.h>
#include <logging/logger.h>

// Information that is important for the kernel
KernelInfo kinfo = {};

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  uint32_t memory_size = 64 * 1024 * 1024;       // TODO: get this from GRUB
  uint32_t heap_size = memory_size * (10 / 100); // The heap is currently 10% of the total memory
  uint32_t total_memory_blocks = floor(heap_size / BLOCK_SIZE);

  kinfo.end = kernel_end;
  kinfo.heap_size = heap_size;

  kinfo.mm_start = (uint8_t*) memset(kinfo.end + 1, 0, total_memory_blocks * sizeof(MemoryBlock));
  kinfo.heap_start = kinfo.mm_start + (total_memory_blocks * sizeof(MemoryBlock));

  // SEPARATOR
  // SEPARATOR
  // SEPARATOR

  TtyDriver tty(false);
  MemoryManagerDriver memoryManagerDriver(kinfo.mm_start, total_memory_blocks, kinfo.heap_start,
                                          kinfo.heap_size);

  DriverManager driver_manager;

  driver_manager.installDriver(&tty);
  driver_manager.installDriver(&memoryManagerDriver);

  tty.write("Installed drivers (");
  tty.writeInt(driver_manager.getDriverCount());
  tty.writeLine("):");

  memoryManagerDriver.allocate(1024);

  Driver** drivers = driver_manager.getAllDrivers();

  for (uint8_t i = 0; i < driver_manager.getDriverCount(); i++) {
    Driver* driver = drivers[i];

    tty.write("  ");
    tty.write(driver->getName());
    tty.write(": ");
    tty.writeLine(driver->getDescription());
  }
}
