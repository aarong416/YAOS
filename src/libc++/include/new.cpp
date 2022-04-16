#include <cstddef.h>
#include <cstdlib/cstdlib.h>

void* operator new(size_t count)
{
  return malloc(count);
}

void* operator new[](size_t count)
{
  return malloc(count);
}
