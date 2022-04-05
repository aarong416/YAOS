#include <drivers/tty_driver.h>
#include <memory/memory.h>
#include <cstddef.h>
#include <cstdlib/cstdlib.h>

extern TtyDriver tty;

void* operator new(std::size_t count)
{
  return std::malloc(count);
}

void* operator new[](std::size_t count)
{
  return std::malloc(count);
}
