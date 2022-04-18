#include <drivers/driver_manager.h>
#include <drivers/memory/memory_manager_driver.h>
#include <drivers/tty/tty_driver.h>
#include <kernel.h>
#include <logging/logger.h>
#include <memory/memory.h>

// void setup_drivers()
// {
//   uint32_t heap_size = 100 * 1024 * 1024; // TODO: get this from GRUB
//   InitializedMemory initialized_memory = initialize_memory_blocks(kernel_end, heap_size);

//   MemoryManagerDriver memory_manager(initialized_memory.block_data_start,
//  initialized_memory.heap_start, heap_size);
// TtyDriver tty;

// DriverManager::installDriver(&memory_manager);
// DriverManager::installDriver(&tty);

// kernel_info.heap_start = initialized_memory.heap_start;
// kernel_info.heap_size = heap_size;
// }

// The entry point for the kernel after it has been loaded by the bootloader
void kernel_main()
{
  // kernel_info.kernel_end = kernel_end;
  // MemoryManagerDriver* memory_manager =
  //   (MemoryManagerDriver*) DriverManager::getDriver("memory_manager");

  DriverManager::initialize(kernel_end);

  TtyDriver tty;

  DriverManager::installDriver(tty);

  tty.write(tty.getDescription());

  // DriverManager::installDriver(memory_manager);

  // DriverManager::getDriver("tty");

  // tty.getName();

  

  // if (tty_driver == nullptr) {
  //   tty.write("Null pointer");
  // } else {
  //   tty.write("Not a null pointer");
  // }

  // tty.write(tty.getName());

  // setup_drivers();
}
