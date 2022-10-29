#include <cstdlib/cstdlib.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <logging/logging.h>

void free(__attribute__((unused)) void* ptr)
{
  if (!ptr) {
    return;
  }

  MemoryManagerDriver* memoryManager =
    (MemoryManagerDriver*) DriverManager::getDriver("memory_manager");

  if (!memoryManager) {
    log("Trying to allocate memory, but no suitable driver was found");

    return;
  }

  memoryManager->deallocate(ptr);
}
