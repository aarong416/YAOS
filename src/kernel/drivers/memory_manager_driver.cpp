#include <drivers/memory_manager_driver.h>

MemoryManagerDriver<heap_size>::MemoryManagerDriver(uint32_t heap_start)
  : Driver("memory_manager", "Manages Memory", DriverType::MemoryManager),
    m_heap_start(heap_start)
{
}
