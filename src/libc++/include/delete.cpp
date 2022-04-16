#include <cstdlib/cstdlib.h>

void operator delete(void* ptr)
{
  free(ptr);
}

void operator delete(void* ptr, size_t sz)
{
  free(ptr);
}

void operator delete[](void* ptr)
{
  free(ptr);
}
