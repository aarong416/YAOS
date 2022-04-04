#include <memory/memory.h>
#include <cstdlib/cstdlib.h>

void operator delete(void* ptr)
{
  std::free(ptr);
}

void operator delete(void* ptr, std::size_t sz)
{
  std::free(ptr);
}

void operator delete[](void* ptr)
{
  std::free(ptr);
}
