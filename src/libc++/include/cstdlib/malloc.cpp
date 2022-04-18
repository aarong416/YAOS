#include <cstdint.h>
#include <cstdlib/cstdlib.h>
#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>

void* malloc(size_t size)
{
  if (size == 0) {
    return NULL;
  }

  // TODO: don't access the memory manager driver directly
  MemoryManagerDriver* memory_manager =
    (MemoryManagerDriver*) DriverManager::getDriver("memory_manager");

  if (memory_manager == nullptr) {
    return NULL;
  }

  // TODO: call the allocate() method of MemoryManagerDriver
  return NULL;
}
