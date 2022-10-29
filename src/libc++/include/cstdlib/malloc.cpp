#include <cstdint.h>
#include <cstdlib/cstdlib.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <logging/logging.h>

void* malloc(size_t size)
{
  if (size == 0) {
    return NULL;
  }

  MemoryManagerDriver* memoryManager =
    (MemoryManagerDriver*) DriverManager::getDriver("memory_manager");

  if (!memoryManager) {
    log("Trying to allocate memory, but no suitable driver was found");

    return NULL;
  }

  return memoryManager->allocate(size);
}
