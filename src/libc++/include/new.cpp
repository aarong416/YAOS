#include <kernel/memory/memory.h>
#include <libc++/include/cstddef.h>
#include <libc++/include/cstdlib/cstdlib.h>

extern std::uint32_t kernel_end;

void* operator new(std::size_t count)
{
  return std::malloc(count);
}

void* operator new[](std::size_t count)
{
  return std::malloc(count);
}
