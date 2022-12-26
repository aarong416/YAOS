#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <iostream/iostream.h>
#include <setup/setup.h>

TtyDriver tty;
MemoryManagerDriver memoryManager;

void setupDrivers(KernelInfo kinfo)
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