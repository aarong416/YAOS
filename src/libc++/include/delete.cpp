#include <cstdlib/cstdlib.h>

void operator delete(void* ptr)
{
  free(ptr);
}

void operator delete(void* ptr, __attribute__((unused)) size_t sz)
{
  free(ptr);
}

void operator delete[](void* ptr)
{
  free(ptr);
}

void operator delete[](void* ptr, long unsigned int)
{
  free(ptr);
}
